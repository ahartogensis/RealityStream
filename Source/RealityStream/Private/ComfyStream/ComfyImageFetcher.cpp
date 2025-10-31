#include "ComfyStream/ComfyImageFetcher.h"
#include "ComfyStream/ComfyPngDecoder.h"
#include "IWebSocket.h"
#include "WebSocketsModule.h"
#include "Async/Async.h"

UComfyImageFetcher::UComfyImageFetcher()
{
	//Initialize default configuration
	Config = FComfyStreamConfig();
	PngDecoder = nullptr;
	ConnectionStatus = EComfyConnectionStatus::Disconnected;
	bIsPolling = false;
	CurrentChannel = 1;
	WebSocketPort = 8001;
}

void UComfyImageFetcher::StartPolling(const FString& ServerURL, int32 ChannelNumber)
{
	// Stop existing connection
	StopPolling();

	// Create PNG decoder if not already created
	if (!PngDecoder)
	{
		PngDecoder = NewObject<UComfyPngDecoder>(this);
	}

	CurrentServerURL = ServerURL;
	CurrentChannel = ChannelNumber;
	bIsPolling = true;

	SetConnectionStatus(EComfyConnectionStatus::Connecting);

	// Build WebSocket URL: ws://server:8001/image?channel=N
	FString WebSocketURL = BuildWebSocketURL(ServerURL, ChannelNumber);

	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Connecting to WebSocket: %s"), *WebSocketURL);

	// Create WebSocket connection
	WebSocket = FWebSocketsModule::Get().CreateWebSocket(WebSocketURL);

	if (WebSocket.IsValid())
	{
		// Bind WebSocket events
		WebSocket->OnConnected().AddUObject(this, &UComfyImageFetcher::OnWebSocketConnected);
		WebSocket->OnConnectionError().AddUObject(this, &UComfyImageFetcher::OnWebSocketConnectionError);
		WebSocket->OnClosed().AddUObject(this, &UComfyImageFetcher::OnWebSocketClosed);
		WebSocket->OnRawMessage().AddUObject(this, &UComfyImageFetcher::OnWebSocketMessage);
		WebSocket->OnMessageSent().AddUObject(this, &UComfyImageFetcher::OnWebSocketMessageSent);

		// Connect
		WebSocket->Connect();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher] Failed to create WebSocket"));
		SetConnectionStatus(EComfyConnectionStatus::Error);
		OnError.Broadcast(TEXT("Failed to create WebSocket connection"));
	}
}

void UComfyImageFetcher::StopPolling()
{
	bIsPolling = false;

	if (WebSocket.IsValid() && WebSocket->IsConnected())
	{
		WebSocket->Close();
	}

	WebSocket.Reset();

	// Clear this instance's buffer
	ChunkBuffer.Empty();
	bReceivingChunks = false;

	SetConnectionStatus(EComfyConnectionStatus::Disconnected);

	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher][Ch%d] Stopped polling"), CurrentChannel);
}

bool UComfyImageFetcher::IsPolling() const
{
	return bIsPolling && WebSocket.IsValid() && WebSocket->IsConnected();
}

void UComfyImageFetcher::OnWebSocketConnected()
{
	// WebSocket callbacks may be called from worker threads
	if (!IsInGameThread())
	{
		AsyncTask(ENamedThreads::GameThread, [this]()
		{
			OnWebSocketConnected_GameThread();
		});
		return;
	}
	
	OnWebSocketConnected_GameThread();
}

void UComfyImageFetcher::OnWebSocketConnected_GameThread()
{
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] WebSocket connected to channel %d"), CurrentChannel);
	SetConnectionStatus(EComfyConnectionStatus::Connected);
}

void UComfyImageFetcher::OnWebSocketConnectionError(const FString& Error)
{
	// WebSocket callbacks may be called from worker threads
	if (!IsInGameThread())
	{
		FString ErrorCopy = Error; // Copy string for async task
		AsyncTask(ENamedThreads::GameThread, [this, ErrorCopy]()
		{
			OnWebSocketConnectionError_GameThread(ErrorCopy);
		});
		return;
	}
	
	OnWebSocketConnectionError_GameThread(Error);
}

void UComfyImageFetcher::OnWebSocketConnectionError_GameThread(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher] WebSocket connection error: %s"), *Error);
	SetConnectionStatus(EComfyConnectionStatus::Error);
	OnError.Broadcast(FString::Printf(TEXT("WebSocket connection error: %s"), *Error));
}

void UComfyImageFetcher::OnWebSocketClosed(int32 StatusCode, const FString& Reason, bool bWasClean)
{
	// WebSocket callbacks may be called from worker threads
	if (!IsInGameThread())
	{
		FString ReasonCopy = Reason; // Copy string for async task
		AsyncTask(ENamedThreads::GameThread, [this, StatusCode, ReasonCopy, bWasClean]()
		{
			OnWebSocketClosed_GameThread(StatusCode, ReasonCopy, bWasClean);
		});
		return;
	}
	
	OnWebSocketClosed_GameThread(StatusCode, Reason, bWasClean);
}

void UComfyImageFetcher::OnWebSocketClosed_GameThread(int32 StatusCode, const FString& Reason, bool bWasClean)
{
	UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] WebSocket closed. Code: %d, Reason: %s, Clean: %s"), 
		StatusCode, *Reason, bWasClean ? TEXT("Yes") : TEXT("No"));
	
	SetConnectionStatus(EComfyConnectionStatus::Disconnected);

	// Attempt reconnection if still polling
	if (bIsPolling && Config.bAutoReconnect)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Attempting reconnection in %.1f seconds..."), Config.ReconnectDelay);
		// TODO: Implement reconnection timer
	}
}

void UComfyImageFetcher::OnWebSocketMessage(const void* Data, SIZE_T Size, SIZE_T BytesRemaining)
{
	// WebSocket callbacks may be called from worker threads, so we need to ensure
	// we're on the game thread before accessing UObjects and broadcasting delegates
	if (!IsInGameThread())
	{
		// Queue this for execution on the game thread
		AsyncTask(ENamedThreads::GameThread, [this, Data, Size, BytesRemaining]()
		{
			// Create a local copy of the data since the original may be invalid after this callback
			TArray<uint8> DataCopy;
			DataCopy.Append(static_cast<const uint8*>(Data), Size);
			
			OnWebSocketMessage_GameThread(DataCopy.GetData(), Size, BytesRemaining);
		});
		return;
	}
	
	OnWebSocketMessage_GameThread(Data, Size, BytesRemaining);
}

void UComfyImageFetcher::OnWebSocketMessage_GameThread(const void* Data, SIZE_T Size, SIZE_T BytesRemaining)
{
	if (!Data || Size == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher][Ch%d] Received empty WebSocket message"), CurrentChannel);
		return;
	}

	UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Received WebSocket message: %llu bytes (remaining: %llu)"), 
		CurrentChannel, Size, BytesRemaining);

	// If we're not currently receiving chunks and buffer has old data, clear it (new message starting)
	if (!bReceivingChunks && ChunkBuffer.Num() > 0)
	{
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Clearing old buffer (%d bytes) for new message"), CurrentChannel, ChunkBuffer.Num());
		ChunkBuffer.Empty();
	}

	//Append data to buffer
	const uint8* ByteData = static_cast<const uint8*>(Data);
	ChunkBuffer.Append(ByteData, Size);

	//Check if we have more chunks coming
	if (BytesRemaining > 0)
	{
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Buffered %llu bytes, waiting for %llu more..."), CurrentChannel, Size, BytesRemaining);
		bReceivingChunks = true;
		return;
	}

	//All chunks received, process the complete image
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher][Ch%d] Complete message received: %d bytes total"), 
		CurrentChannel, ChunkBuffer.Num());
	
	//Process the complete image data
	ProcessImageData(ChunkBuffer);
	
	//Clear buffer for next message
	ChunkBuffer.Empty();
	bReceivingChunks = false;
}

void UComfyImageFetcher::OnWebSocketMessageSent(const FString& MessageString)
{
	UE_LOG(LogTemp, VeryVerbose, TEXT("[ComfyImageFetcher] Message sent: %s"), *MessageString);
}

void UComfyImageFetcher::ProcessImageData(const TArray<uint8>& Data)
{
	// Ensure we're on the game thread
	if (!IsInGameThread())
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher] ProcessImageData called from non-game thread!"));
		return;
	}

	//WebViewer protocol: 8-byte header + image data
	//Header: 2x uint32 - try both big-endian and little-endian formats
	if (Data.Num() < 8)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] Data too small to contain header (%d bytes)"), Data.Num());
		return;
	}

	// Try big-endian first (original format)
	uint32 Header1_BE = (Data[0] << 24) | (Data[1] << 16) | (Data[2] << 8) | Data[3];
	uint32 Header2_BE = (Data[4] << 24) | (Data[5] << 16) | (Data[6] << 8) | Data[7];
	
	// Try little-endian format
	uint32 Header1_LE = Data[0] | (Data[1] << 8) | (Data[2] << 16) | (Data[3] << 24);
	uint32 Header2_LE = Data[4] | (Data[5] << 8) | (Data[6] << 16) | (Data[7] << 24);
	
	// Check if data starts with PNG signature (89 50 4E 47) - might be raw PNG without header
	bool bIsPNGSignature = (Data.Num() >= 4) && (Data[0] == 0x89 && Data[1] == 0x50 && Data[2] == 0x4E && Data[3] == 0x47);
	
	int32 ImageDataOffset = 0;
	
	// Validate header - ComfyUI WebViewer should send [1, 2]
	if (Header1_BE == 1 && Header2_BE == 2)
	{
		// Big-endian format confirmed
		ImageDataOffset = 8;
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher] Valid header (big-endian): [1, 2]"));
	}
	else if (Header1_LE == 1 && Header2_LE == 2)
	{
		// Little-endian format confirmed
		ImageDataOffset = 8;
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher] Valid header (little-endian): [1, 2]"));
	}
	else if (bIsPNGSignature)
	{
		// No header, raw PNG data - use entire buffer
		ImageDataOffset = 0;
		UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] No header detected, treating as raw PNG data"));
	}
	else
	{
		// Invalid header - log and skip
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] Invalid header values [BE: %u, %u] [LE: %u, %u], expected [1, 2]. First 8 bytes: %02X %02X %02X %02X %02X %02X %02X %02X. Skipping message."), 
			Header1_BE, Header2_BE, Header1_LE, Header2_LE,
			Data[0], Data[1], Data[2], Data[3], Data[4], Data[5], Data[6], Data[7]);
		return;
	}

	// Extract image data (skip header if present)
	TArray<uint8> ImageBytes;
	if (ImageDataOffset > 0)
	{
		ImageBytes.Append(&Data[ImageDataOffset], Data.Num() - ImageDataOffset);
	}
	else
	{
		// Raw PNG data, use entire buffer
		ImageBytes = Data;
	}

	if (ImageBytes.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] No image data after header"));
		return;
	}

	// Decode the image
	if (PngDecoder)
	{
		UTexture2D* DecodedTexture = PngDecoder->DecodePNGToTexture(ImageBytes);
		
		if (DecodedTexture)
		{
			UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher][Ch%d] Successfully decoded image: %dx%d"), 
				CurrentChannel, DecodedTexture->GetSizeX(), DecodedTexture->GetSizeY());
			
			// Broadcast the texture (we're already on game thread)
			OnTextureReceived.Broadcast(DecodedTexture);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher][Ch%d] Failed to decode image"), CurrentChannel);
			
			// Clear the buffer for this instance to prevent future corruption
			ChunkBuffer.Empty();
			bReceivingChunks = false;
			
			OnError.Broadcast(TEXT("Failed to decode image from WebSocket"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher][Ch%d] PNG decoder not initialized"), CurrentChannel);
	}
}

void UComfyImageFetcher::SetConnectionStatus(EComfyConnectionStatus NewStatus)
{
	// Ensure we're on game thread before broadcasting delegates
	if (!IsInGameThread())
	{
		AsyncTask(ENamedThreads::GameThread, [this, NewStatus]()
		{
			SetConnectionStatus(NewStatus);
		});
		return;
	}
	
	ConnectionStatus = NewStatus;
	OnConnectionStatusChanged.Broadcast(NewStatus == EComfyConnectionStatus::Connected);
}

FString UComfyImageFetcher::BuildWebSocketURL(const FString& ServerURL, int32 ChannelNumber)
{
	// Extract host from URL (supports http://, https://, ws://, or plain host)
	FString Host = ServerURL;
	
	//Remove all possible protocols
	Host.RemoveFromStart(TEXT("http://"));
	Host.RemoveFromStart(TEXT("https://"));
	Host.RemoveFromStart(TEXT("ws://"));
	Host.RemoveFromStart(TEXT("wss://"));
	
	//Remove port if present (e.g., "localhost:8188" -> "localhost")
	int32 ColonIndex;
	if (Host.FindChar(':', ColonIndex))
	{
		Host = Host.Left(ColonIndex);
	}
	
	//Remove trailing slash
	Host.RemoveFromEnd(TEXT("/"));

	//Build WebSocket URL: ws://host:8001/image?channel=N
	FString WebSocketURL = FString::Printf(TEXT("ws://%s:%d/image?channel=%d"), 
		*Host, WebSocketPort, ChannelNumber);

	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Built WebSocket URL: %s"), *WebSocketURL);
	
	return WebSocketURL;
}


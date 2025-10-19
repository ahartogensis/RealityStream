#include "ComfyImageFetcher.h"
#include "ComfyPngDecoder.h"
#include "IWebSocket.h"
#include "WebSocketsModule.h"

UComfyImageFetcher::UComfyImageFetcher()
{
	// Initialize default configuration
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

	// Clear this instance's buffer from static maps
	static TMap<UComfyImageFetcher*, TArray<uint8>> MessageBuffers;
	static TMap<UComfyImageFetcher*, bool> ReceivingChunksMap;
	MessageBuffers.Remove(this);
	ReceivingChunksMap.Remove(this);

	SetConnectionStatus(EComfyConnectionStatus::Disconnected);

	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher][Ch%d] Stopped polling"), CurrentChannel);
}

bool UComfyImageFetcher::IsPolling() const
{
	return bIsPolling && WebSocket.IsValid() && WebSocket->IsConnected();
}

void UComfyImageFetcher::OnWebSocketConnected()
{
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] WebSocket connected to channel %d"), CurrentChannel);
	SetConnectionStatus(EComfyConnectionStatus::Connected);
}

void UComfyImageFetcher::OnWebSocketConnectionError(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher] WebSocket connection error: %s"), *Error);
	SetConnectionStatus(EComfyConnectionStatus::Error);
	OnError.Broadcast(FString::Printf(TEXT("WebSocket connection error: %s"), *Error));
}

void UComfyImageFetcher::OnWebSocketClosed(int32 StatusCode, const FString& Reason, bool bWasClean)
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
	// Per-instance buffer (each channel has its own fetcher, so this is safe)
	// Using a map keyed by 'this' pointer to ensure each instance has its own buffer
	static TMap<UComfyImageFetcher*, TArray<uint8>> MessageBuffers;
	static TMap<UComfyImageFetcher*, bool> ReceivingChunksMap;
	
	if (!Data || Size == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher][Ch%d] Received empty WebSocket message"), CurrentChannel);
		return;
	}

	UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Received WebSocket message: %llu bytes (remaining: %llu)"), 
		CurrentChannel, Size, BytesRemaining);

	// Get or create buffer for this instance
	TArray<uint8>& MessageBuffer = MessageBuffers.FindOrAdd(this);
	bool& bReceivingChunks = ReceivingChunksMap.FindOrAdd(this, false);

	// If we're not currently receiving chunks and buffer has old data, clear it (new message starting)
	if (!bReceivingChunks && MessageBuffer.Num() > 0)
	{
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Clearing old buffer (%d bytes) for new message"), CurrentChannel, MessageBuffer.Num());
		MessageBuffer.Empty();
	}

	// Append data to buffer
	const uint8* ByteData = static_cast<const uint8*>(Data);
	MessageBuffer.Append(ByteData, Size);

	// Check if we have more chunks coming
	if (BytesRemaining > 0)
	{
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyImageFetcher][Ch%d] Buffered %llu bytes, waiting for %llu more..."), CurrentChannel, Size, BytesRemaining);
		bReceivingChunks = true;
		return;
	}

	// All chunks received, process the complete image
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher][Ch%d] Complete message received: %d bytes total"), 
		CurrentChannel, MessageBuffer.Num());
	
	// Process the complete image data
	ProcessImageData(MessageBuffer);
	
	// Clear buffer for next message
	MessageBuffer.Empty();
	bReceivingChunks = false;
}

void UComfyImageFetcher::OnWebSocketMessageSent(const FString& MessageString)
{
	UE_LOG(LogTemp, VeryVerbose, TEXT("[ComfyImageFetcher] Message sent: %s"), *MessageString);
}

void UComfyImageFetcher::ProcessImageData(const TArray<uint8>& Data)
{
	// WebViewer protocol: 8-byte header + image data
	// Header: 2x uint32 (big endian)
	if (Data.Num() < 8)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] Data too small to contain header (%d bytes)"), Data.Num());
		return;
	}

	// Parse header (big endian)
	uint32 Header1 = (Data[0] << 24) | (Data[1] << 16) | (Data[2] << 8) | Data[3];
	uint32 Header2 = (Data[4] << 24) | (Data[5] << 16) | (Data[6] << 8) | Data[7];

	
	// Validate header - ComfyUI WebViewer should send [1, 2]
	if (Header1 != 1 || Header2 != 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyImageFetcher] Invalid header values [%u, %u], expected [1, 2]. Skipping corrupted message."), 
			Header1, Header2);
		return;
	}

	// Extract image data (skip 8-byte header)
	TArray<uint8> ImageBytes;
	ImageBytes.Append(&Data[8], Data.Num() - 8);

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
			
			// Broadcast the texture
			OnTextureReceived.Broadcast(DecodedTexture);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[ComfyImageFetcher][Ch%d] Failed to decode image"), CurrentChannel);
			
			// Clear the static buffer for this instance to prevent future corruption
			static TMap<UComfyImageFetcher*, TArray<uint8>> MessageBuffers;
			static TMap<UComfyImageFetcher*, bool> ReceivingChunksMap;
			MessageBuffers.Remove(this);
			ReceivingChunksMap.Remove(this);
			
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
	if (ConnectionStatus != NewStatus)
	{
		ConnectionStatus = NewStatus;
		OnConnectionStatusChanged.Broadcast(NewStatus == EComfyConnectionStatus::Connected);
	}
}

FString UComfyImageFetcher::BuildWebSocketURL(const FString& ServerURL, int32 ChannelNumber)
{
	// Extract host from URL (supports http://, https://, ws://, or plain host)
	FString Host = ServerURL;
	
	// Remove all possible protocols
	Host.RemoveFromStart(TEXT("http://"));
	Host.RemoveFromStart(TEXT("https://"));
	Host.RemoveFromStart(TEXT("ws://"));
	Host.RemoveFromStart(TEXT("wss://"));
	
	// Remove port if present (e.g., "localhost:8188" -> "localhost")
	int32 ColonIndex;
	if (Host.FindChar(':', ColonIndex))
	{
		Host = Host.Left(ColonIndex);
	}
	
	// Remove trailing slash
	Host.RemoveFromEnd(TEXT("/"));

	// Build WebSocket URL: ws://host:8001/image?channel=N
	FString WebSocketURL = FString::Printf(TEXT("ws://%s:%d/image?channel=%d"), 
		*Host, WebSocketPort, ChannelNumber);

	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Built WebSocket URL: %s"), *WebSocketURL);
	
	return WebSocketURL;
}

void UComfyImageFetcher::TestServerConnection(const FString& ServerURL)
{
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Testing WebSocket connection to: %s"), *ServerURL);
	
	// Build test URL
	FString TestURL = BuildWebSocketURL(ServerURL, 1);
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Test URL: %s"), *TestURL);
	UE_LOG(LogTemp, Display, TEXT("[ComfyImageFetcher] Use StartPolling() to establish connection"));
}

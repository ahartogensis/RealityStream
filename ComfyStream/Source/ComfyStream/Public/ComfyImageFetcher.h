#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ComfyStreamTypes.h"

// Forward declaration
class UComfyPngDecoder;
class IWebSocket;

#include "ComfyImageFetcher.generated.h"

/**
 * WebSocket-based image fetcher for ComfyUI
 * Connects to ComfyUI WebViewer server on port 8001
 */
UCLASS()
class COMFYSTREAM_API UComfyImageFetcher : public UObject
{
	GENERATED_BODY()

public:
	UComfyImageFetcher();

	// Events
	UPROPERTY(BlueprintAssignable)
	FOnTextureReceived OnTextureReceived;

	UPROPERTY(BlueprintAssignable)
	FOnConnectionStatusChanged OnConnectionStatusChanged;

	UPROPERTY(BlueprintAssignable)
	FOnError OnError;

	// Connection functions
	UFUNCTION(BlueprintCallable, Category = "ComfyImageFetcher")
	void StartPolling(const FString& ServerURL, int32 ChannelNumber = 1);

	UFUNCTION(BlueprintCallable, Category = "ComfyImageFetcher")
	void StopPolling();

	UFUNCTION(BlueprintCallable, Category = "ComfyImageFetcher")
	bool IsPolling() const;
	
	// WebSocket port (ComfyUI WebViewer uses 8001 by default)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyImageFetcher")
	int32 WebSocketPort = 8001;

	// Configuration
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyImageFetcher")
	FComfyStreamConfig Config;

	// Test function to verify server connection
	UFUNCTION(BlueprintCallable, Category = "ComfyImageFetcher")
	void TestServerConnection(const FString& ServerURL);

private:
	// PNG decoder
	UPROPERTY()
	UComfyPngDecoder* PngDecoder;

	// Connection status
	EComfyConnectionStatus ConnectionStatus = EComfyConnectionStatus::Disconnected;

	// WebSocket connection
	TSharedPtr<IWebSocket> WebSocket;
	bool bIsPolling = false;
	FString CurrentServerURL;
	int32 CurrentChannel = 1;

	// WebSocket event handlers
	void OnWebSocketConnected();
	void OnWebSocketConnectionError(const FString& Error);
	void OnWebSocketClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
	void OnWebSocketMessage(const void* Data, SIZE_T Size, SIZE_T BytesRemaining);
	void OnWebSocketMessageSent(const FString& MessageString);

	// Internal functions
	void SetConnectionStatus(EComfyConnectionStatus NewStatus);
	FString BuildWebSocketURL(const FString& ServerURL, int32 ChannelNumber);
	void ProcessImageData(const TArray<uint8>& Data);
};

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "ComfyStreamTypes.generated.h"

// Event for when a new texture is received from ComfyUI
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTextureReceived, UTexture2D*, Texture);

// Event for when a connection status changes
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectionStatusChanged, bool, bConnected);

// Event for when an error occurs
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnError, const FString&, ErrorMessage);

// Channel types for different ComfyUI streams
UENUM(BlueprintType)
enum class EComfyChannel : uint8
{
	RGBA		UMETA(DisplayName = "RGBA Map"),
	Depth		UMETA(DisplayName = "Depth Map"),
	Mask		UMETA(DisplayName = "Mask Map"),
	Custom		UMETA(DisplayName = "Custom Channel")
};

// Connection status
UENUM(BlueprintType)
enum class EComfyConnectionStatus : uint8
{
	Disconnected	UMETA(DisplayName = "Disconnected"),
	Connecting		UMETA(DisplayName = "Connecting"),
	Connected		UMETA(DisplayName = "Connected"),
	Error			UMETA(DisplayName = "Error")
};

// Configuration structure for ComfyUI connection
USTRUCT(BlueprintType)
struct FComfyStreamConfig
{
	GENERATED_BODY()

	// Base URL for ComfyUI server (HTTP URL, will be converted to WebSocket)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	FString ServerURL = TEXT("http://192.168.1.247:8188");

	// Channel number for this stream
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	int32 ChannelNumber = 1;

	// Channel type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	EComfyChannel ChannelType = EComfyChannel::Depth;

	// Keep-alive ping interval in seconds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	float PingInterval = 20.0f;

	// Auto-reconnect on disconnect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	bool bAutoReconnect = true;

	// Reconnect delay in seconds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyUI")
	float ReconnectDelay = 5.0f;

	FComfyStreamConfig()
	{
		ServerURL = TEXT("http://192.168.1.247:8188");
		ChannelNumber = 1;
		ChannelType = EComfyChannel::Depth;
		PingInterval = 20.0f;
		bAutoReconnect = true;
		ReconnectDelay = 5.0f;
	}
};

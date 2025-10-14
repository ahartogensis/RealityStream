#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "ComfyStreamTypes.h"
#include "ComfyStreamComponent.generated.h"

class UComfyImageFetcher;
class UComfyPngDecoder;

/**
 * Component for receiving ComfyUI websocket streams and creating dynamic materials
 * This component can handle multiple channels (depth, RGBA, etc.) and automatically
 * updates material parameters when new textures are received.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMFYSTREAM_API UComfyStreamComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UComfyStreamComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// Events
	UPROPERTY(BlueprintAssignable, Category = "ComfyStream")
	FOnTextureReceived OnTextureReceived;

	UPROPERTY(BlueprintAssignable, Category = "ComfyStream")
	FOnConnectionStatusChanged OnConnectionStatusChanged;

	UPROPERTY(BlueprintAssignable, Category = "ComfyStream")
	FOnError OnError;

	// Configuration (internal use, set by ComfyStreamActor)
	FComfyStreamConfig StreamConfig;

	// Parameter names for the material (internal use, set by ComfyStreamActor)
	FName DepthMapParameterName = TEXT("Depth_Map");
	FName RGBMapParameterName = TEXT("RGB_Map");
	FName MaskMapParameterName = TEXT("Mask_Map");

	// Base material reference (set internally by ComfyStreamActor)
	UMaterialInterface* BaseMaterial;

	// Blueprint functions
	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	bool IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	EComfyConnectionStatus GetConnectionStatus() const;

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	UMaterialInstanceDynamic* GetDynamicMaterial() const { return DynamicMaterial; }

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void SetChannelNumber(int32 NewChannelNumber);

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void SetServerURL(const FString& NewServerURL);

	// Internal functions
	UFUNCTION()
	void OnTextureReceivedInternal(UTexture2D* Texture);
	
	UFUNCTION()
	void OnConnectionStatusChangedInternal(bool bConnected);
	
	UFUNCTION()
	void OnErrorInternal(const FString& ErrorMessage);

private:
	// Image fetcher (HTTP-based alternative to WebSocket)
	UPROPERTY()
	UComfyImageFetcher* ImageFetcher;

	// PNG decoder
	UPROPERTY()
	UComfyPngDecoder* PngDecoder;

	// Dynamic material instance
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	// Connection status
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ComfyStream", meta = (AllowPrivateAccess = "true"))
	EComfyConnectionStatus ConnectionStatus = EComfyConnectionStatus::Disconnected;

	// Timer for keep-alive pings
	FTimerHandle PingTimer;

	// Timer for reconnection attempts
	FTimerHandle ReconnectTimer;

	// Lerp state for smooth texture transitions
	FComfyLerpState LerpState;

	// Internal functions
	void CreateDynamicMaterial();
	void StartPingTimer();
	void StopPingTimer();
	void SendPing();
	void AttemptReconnect();
	void UpdateLerpTransition(float DeltaTime);
};

#include "ComfyStreamComponent.h"
#include "ComfyImageFetcher.h"
#include "ComfyPngDecoder.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "Engine/World.h"

UComfyStreamComponent::UComfyStreamComponent()
{
	// Enable Tick for lerp-based smoothing (can be toggled at runtime)
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	
	// Initialize default configuration
	StreamConfig = FComfyStreamConfig();
	BaseMaterial = nullptr;
	DepthMapParameterName = TEXT("Depth_Map");
	RGBMapParameterName = TEXT("RGB_Map");
	
	ConnectionStatus = EComfyConnectionStatus::Disconnected;
	DynamicMaterial = nullptr;
	ImageFetcher = nullptr;
	PngDecoder = nullptr;
}

void UComfyStreamComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Create PNG decoder
	PngDecoder = NewObject<UComfyPngDecoder>(this);
	
	// Create image fetcher
	ImageFetcher = NewObject<UComfyImageFetcher>(this);
	ImageFetcher->Config = StreamConfig;
	
	// Bind events with safety checks
	// Ensure this component is valid for dynamic delegate binding
	if (ImageFetcher && IsValid(this))
	{
		ImageFetcher->OnTextureReceived.AddDynamic(this, &UComfyStreamComponent::OnTextureReceivedInternal);
		ImageFetcher->OnConnectionStatusChanged.AddDynamic(this, &UComfyStreamComponent::OnConnectionStatusChangedInternal);
		ImageFetcher->OnError.AddDynamic(this, &UComfyStreamComponent::OnErrorInternal);
	}
	
	// Create dynamic material
	CreateDynamicMaterial();
	
	// Auto-connect if configured
	if (StreamConfig.bAutoReconnect)
	{
		Connect();
	}
}

void UComfyStreamComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Stop timers
	StopPingTimer();
	
	// Disconnect Image Fetcher
	if (ImageFetcher)
	{
		ImageFetcher->StopPolling();
	}
	
	Super::EndPlay(EndPlayReason);
}

void UComfyStreamComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// Only tick if lerp smoothing is enabled
	if (StreamConfig.bEnableLerpSmoothing)
	{
		UpdateLerpTransition(DeltaTime);
	}
}

void UComfyStreamComponent::Connect()
{
	if (ImageFetcher)
	{
		// Start polling for images
		ImageFetcher->StartPolling(StreamConfig.ServerURL, StreamConfig.ChannelNumber);
	}
}

void UComfyStreamComponent::Disconnect()
{
	if (ImageFetcher)
	{
		ImageFetcher->StopPolling();
	}
}

bool UComfyStreamComponent::IsConnected() const
{
	return ImageFetcher ? ImageFetcher->IsPolling() : false;
}

EComfyConnectionStatus UComfyStreamComponent::GetConnectionStatus() const
{
	return ConnectionStatus;
}

void UComfyStreamComponent::SetChannelNumber(int32 NewChannelNumber)
{
	StreamConfig.ChannelNumber = NewChannelNumber;
	
	// Reconnect if currently connected
	if (IsConnected())
	{
		Disconnect();
		Connect();
	}
}

void UComfyStreamComponent::SetServerURL(const FString& NewServerURL)
{
	StreamConfig.ServerURL = NewServerURL;
	
	// Reconnect if currently connected
	if (IsConnected())
	{
		Disconnect();
		Connect();
	}
}

void UComfyStreamComponent::OnTextureReceivedInternal(UTexture2D* Texture)
{
	if (!Texture)
	{
		return;
	}
	
	// Handle texture updates with optional lerp smoothing
	if (StreamConfig.bEnableLerpSmoothing)
	{
		// Start lerp transition to new texture
		LerpState.StartLerp(Texture);
		
		// The actual material update will happen in UpdateLerpTransition
		// which is called from TickComponent
	}
	else
	{
		// Immediate update without lerp smoothing
		if (DynamicMaterial)
		{
			switch (StreamConfig.ChannelType)
			{
				case EComfyChannel::RGBA:
					DynamicMaterial->SetTextureParameterValue(RGBMapParameterName, Texture);
					break;
					
				case EComfyChannel::Depth:
					DynamicMaterial->SetTextureParameterValue(DepthMapParameterName, Texture);
					break;
					
				case EComfyChannel::Mask:
					DynamicMaterial->SetTextureParameterValue(MaskMapParameterName, Texture);
					break;
					
				case EComfyChannel::Custom:
					// For custom channels, you might want to add additional logic
					DynamicMaterial->SetTextureParameterValue(DepthMapParameterName, Texture);
					break;
			}
		}
	}
	
	// Broadcast the event
	OnTextureReceived.Broadcast(Texture);
}

void UComfyStreamComponent::OnConnectionStatusChangedInternal(bool bConnected)
{
	ConnectionStatus = bConnected ? EComfyConnectionStatus::Connected : EComfyConnectionStatus::Disconnected;
	OnConnectionStatusChanged.Broadcast(bConnected);
	
	// Handle reconnection
	if (!bConnected && StreamConfig.bAutoReconnect)
	{
		GetWorld()->GetTimerManager().SetTimer(
			ReconnectTimer,
			this,
			&UComfyStreamComponent::AttemptReconnect,
			StreamConfig.ReconnectDelay,
			false
		);
	}
}

void UComfyStreamComponent::OnErrorInternal(const FString& ErrorMessage)
{
	ConnectionStatus = EComfyConnectionStatus::Error;
	OnError.Broadcast(ErrorMessage);
}

void UComfyStreamComponent::CreateDynamicMaterial()
{
	if (BaseMaterial)
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	}
}

void UComfyStreamComponent::StartPingTimer()
{
	// Not needed for HTTP polling
}

void UComfyStreamComponent::StopPingTimer()
{
	// Not needed for HTTP polling
}

void UComfyStreamComponent::SendPing()
{
	// Not needed for HTTP polling
}

void UComfyStreamComponent::AttemptReconnect()
{
	if (!IsConnected())
	{
		Connect();
	}
}

void UComfyStreamComponent::UpdateLerpTransition(float DeltaTime)
{
	// Update the lerp state
	LerpState.UpdateLerp(DeltaTime, StreamConfig.LerpSpeed, StreamConfig.LerpThreshold);
	
	// Update material parameters with lerped value
	if (DynamicMaterial && LerpState.bIsLerping)
	{
		// Get the blend alpha
		float BlendAlpha = LerpState.GetBlendAlpha();
		
		// Update material parameter based on channel type
		// Note: For proper texture blending, your material should support a blend alpha parameter
		// and have logic to blend between two texture inputs
		FName AlphaParamName;
		FName TargetTexParamName;
		
		switch (StreamConfig.ChannelType)
		{
			case EComfyChannel::RGBA:
				AlphaParamName = TEXT("RGB_Blend_Alpha");
				TargetTexParamName = TEXT("RGB_Map_Target");
				DynamicMaterial->SetTextureParameterValue(TargetTexParamName, LerpState.TargetTexture);
				DynamicMaterial->SetScalarParameterValue(AlphaParamName, BlendAlpha);
				break;
				
			case EComfyChannel::Depth:
				AlphaParamName = TEXT("Depth_Blend_Alpha");
				TargetTexParamName = TEXT("Depth_Map_Target");
				DynamicMaterial->SetTextureParameterValue(TargetTexParamName, LerpState.TargetTexture);
				DynamicMaterial->SetScalarParameterValue(AlphaParamName, BlendAlpha);
				break;
				
			case EComfyChannel::Mask:
				AlphaParamName = TEXT("Mask_Blend_Alpha");
				TargetTexParamName = TEXT("Mask_Map_Target");
				DynamicMaterial->SetTextureParameterValue(TargetTexParamName, LerpState.TargetTexture);
				DynamicMaterial->SetScalarParameterValue(AlphaParamName, BlendAlpha);
				break;
				
			case EComfyChannel::Custom:
				AlphaParamName = TEXT("Depth_Blend_Alpha");
				TargetTexParamName = TEXT("Depth_Map_Target");
				DynamicMaterial->SetTextureParameterValue(TargetTexParamName, LerpState.TargetTexture);
				DynamicMaterial->SetScalarParameterValue(AlphaParamName, BlendAlpha);
				break;
		}
	}
	else if (DynamicMaterial && !LerpState.bIsLerping && LerpState.CurrentTexture)
	{
		// Lerp is complete, set the final texture
		switch (StreamConfig.ChannelType)
		{
			case EComfyChannel::RGBA:
				DynamicMaterial->SetTextureParameterValue(RGBMapParameterName, LerpState.CurrentTexture);
				break;
				
			case EComfyChannel::Depth:
				DynamicMaterial->SetTextureParameterValue(DepthMapParameterName, LerpState.CurrentTexture);
				break;
				
			case EComfyChannel::Mask:
				DynamicMaterial->SetTextureParameterValue(MaskMapParameterName, LerpState.CurrentTexture);
				break;
				
			case EComfyChannel::Custom:
				DynamicMaterial->SetTextureParameterValue(DepthMapParameterName, LerpState.CurrentTexture);
				break;
		}
	}
}

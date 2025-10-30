#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ComfyStreamComponent.h"
#include "ComfyFrameBuffer.h"
#include "ComfyReconstruction.h"
#include "ComfyStreamActor.generated.h"

//receives 3 texture maps from ComfyUI and applies to to a material 
UCLASS()
class COMFYSTREAM_API AComfyStreamActor : public AActor
{
	GENERATED_BODY()

public:
	AComfyStreamActor();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	//visualize streamed textures on display mesh 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* DisplayMesh;

	//Comfy stream component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UComfyStreamComponent* ComfyStreamComponent;

	//base material made with parameters RGB, Mask, and Depth
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* BaseMaterial;

	//network config for segmentation channel
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FComfyStreamConfig SegmentationChannelConfig;

	//Blueprint events 
	UFUNCTION(BlueprintImplementableEvent)
	void OnTextureReceived(UTexture2D* Texture, EComfyChannel ChannelType);
	UFUNCTION(BlueprintImplementableEvent)
	void OnConnectionStatusChanged(bool bConnected, EComfyChannel ChannelType);
	UFUNCTION(BlueprintImplementableEvent)
	void OnError(const FString& ErrorMessage, EComfyChannel ChannelType);

	//connect and disconnect functions 
	UFUNCTION(BlueprintCallable) void ConnectSegmentationChannel();
	UFUNCTION(BlueprintCallable) void DisconnectAll();

private:
	//External helper functions 
	UPROPERTY() UComfyFrameBuffer*    FrameBuffer = nullptr;
	UPROPERTY() UComfyReconstruction* Reconstruction = nullptr;
	UPROPERTY() UMaterialInstanceDynamic* DynMat = nullptr;

	//once buffer completes, last frame 
	FComfyFrame LatestFrame;

	//sequence index for textures 
	int32 SeqIndex = 0;

	//Internal helper functions 
	UFUNCTION() void HandleStreamTexture(UTexture2D* Texture);
	UFUNCTION() void HandleConnectionChanged(bool bConnected);
	UFUNCTION() void HandleStreamError(const FString& Error);

	//When FrameBuffer emits a complete triplet
	UFUNCTION() void HandleFullFrame(const FComfyFrame& Frame);

	//Place DisplayMesh based on depth
	void UpdatePlacementFromDepth(const FComfyFrame& Frame);
	//Apply textures to the material
	void ApplyTexturesToMaterial(const FComfyFrame& Frame);
};
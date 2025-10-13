#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ComfyStreamComponent.h"
#include "ComfyStreamActor.generated.h"

/**
 * Example actor that demonstrates how to use the ComfyStream plugin
 * This actor receives depth and RGBA maps from ComfyUI and applies them to a material
 */
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
	// The mesh to display the material on
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ComfyStream")
	UStaticMeshComponent* DisplayMesh;

	// ComfyStream component for handling the websocket connection
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ComfyStream")
	UComfyStreamComponent* ComfyStreamComponent;

	// Base material to use for the displacement effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream")
	UMaterialInterface* BaseMaterial;

	// Enable 3D reconstruction mode (spawn separate meshes per object)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	bool bEnable3DReconstruction = false;

	// Only update reconstruction when mask changes (prevents clearing on every texture update)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	bool bUpdateOnMaskOnly = true;

	// Accumulate objects instead of clearing them (add new objects to scene)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	bool bAccumulateObjects = true;

	// Depth scale factor (how far objects are placed based on depth)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	float DepthScale = 100.0f;

	// Scale factor for spawned objects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	float ObjectScale = 1.0f;

	// Spawn one object per mask update (simple mode) vs segment by color
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	bool bSpawnSingleObject = true;
	
	// Minimum object size in pixels to spawn a mesh (only used if segmenting by color)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	int32 MinObjectSize = 10000;
	
	// Color tolerance for mask segmentation (higher = fewer objects, groups similar colors)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	int32 ColorTolerance = 50;

	// Mesh to use for spawned objects (defaults to plane)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream|3D Reconstruction")
	UStaticMesh* ObjectMesh;

	// Configuration for RGB channel (Channel 1)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream")
	FComfyStreamConfig RGBAChannelConfig;

	// Configuration for depth channel (Channel 2)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream")
	FComfyStreamConfig DepthChannelConfig;

	// Configuration for mask channel (Channel 3)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream")
	FComfyStreamConfig MaskChannelConfig;

	// Blueprint events
	UFUNCTION(BlueprintImplementableEvent, Category = "ComfyStream")
	void OnTextureReceived(UTexture2D* Texture, EComfyChannel ChannelType);

	UFUNCTION(BlueprintImplementableEvent, Category = "ComfyStream")
	void OnConnectionStatusChanged(bool bConnected, EComfyChannel ChannelType);

	UFUNCTION(BlueprintImplementableEvent, Category = "ComfyStream")
	void OnError(const FString& ErrorMessage, EComfyChannel ChannelType);

	// Blueprint functions
	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectRGBAChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectDepthChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectMaskChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void DisconnectAll();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectAllChannels();

	// Manually clear all spawned objects
	UFUNCTION(BlueprintCallable, Category = "ComfyStream|3D Reconstruction")
	void ClearAllSpawnedObjects();

private:
	// Internal event handlers
	UFUNCTION()
	void OnRGBATextureReceived(UTexture2D* Texture);

	UFUNCTION()
	void OnDepthTextureReceived(UTexture2D* Texture);

	UFUNCTION()
	void OnMaskTextureReceived(UTexture2D* Texture);

	UFUNCTION()
	void OnRGBAConnectionStatusChanged(bool bConnected);

	UFUNCTION()
	void OnDepthConnectionStatusChanged(bool bConnected);

	UFUNCTION()
	void OnMaskConnectionStatusChanged(bool bConnected);

	UFUNCTION()
	void OnRGBAError(const FString& ErrorMessage);

	UFUNCTION()
	void OnDepthError(const FString& ErrorMessage);

	UFUNCTION()
	void OnMaskError(const FString& ErrorMessage);

	// RGBA channel component (Channel 1)
	UPROPERTY()
	UComfyStreamComponent* RGBAChannelComponent;

	// Depth channel component (Channel 2)
	UPROPERTY()
	UComfyStreamComponent* DepthChannelComponent;

	// Mask channel component (Channel 3)
	UPROPERTY()
	UComfyStreamComponent* MaskChannelComponent;

	// Dynamic material instance
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	// Latest received textures for 3D reconstruction
	UPROPERTY()
	UTexture2D* LatestRGBATexture;

	UPROPERTY()
	UTexture2D* LatestDepthTexture;

	UPROPERTY()
	UTexture2D* LatestMaskTexture;

	// Array of spawned object meshes for 3D reconstruction
	UPROPERTY()
	TArray<AActor*> SpawnedObjects;

	// Internal functions for 3D reconstruction
	void ProcessReconstructionIfReady();
	void Perform3DReconstruction();
	void ClearSpawnedObjects();
	void UpdateExistingObjectMaterials();
	
	struct FObjectData
	{
		TArray<FIntPoint> Pixels;
		FLinearColor MaskColor;
		float AverageDepth;
		FVector WorldPosition;
	};
	
	TArray<FObjectData> SegmentObjects(const TArray<FColor>& MaskPixels, int32 Width, int32 Height);
};

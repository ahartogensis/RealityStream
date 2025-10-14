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

	// Configuration for RGB channel (Channel 1)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyStream")
	FComfyStreamConfig RGBChannelConfig;

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
	void ConnectRGBChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectDepthChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectMaskChannel();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void DisconnectAll();

	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ConnectAllChannels();

	// Manually clear all spawned objects
	UFUNCTION(BlueprintCallable, Category = "ComfyStream")
	void ClearAllSpawnedObjects();

private:
	// ========================================================================
	// 3D RECONSTRUCTION SETTINGS (Internal - Do not expose to users)
	// ========================================================================
	
	// Enable 3D reconstruction mode (spawn separate meshes per object)
	bool bEnable3DReconstruction = true;  // Always enabled by default
	
	// Only update reconstruction when mask changes (prevents clearing on every texture update)
	bool bUpdateOnMaskOnly = false;  // Update on any texture since RGB has alpha
	
	// Accumulate objects instead of clearing them (add new objects to scene)
	bool bAccumulateObjects = true;
	
	// Depth scale factor (maximum distance for depth = 0, in world units)
	float DepthScale = 100.0f;
	
	// Focal length scale for pinhole camera projection (affects perspective spread)
	// Lower = wider field of view (objects more spread out)
	// Higher = narrower field of view (objects more centered)
	float FocalLengthScale = 1.0f;
	
	// Scale factor for spawned objects
	float ObjectScale = 1.0f;
	
	// Spawn one object per update (RGB has alpha transparency baked in)
	bool bSpawnSingleObject = true;
	
	// Minimum object size in pixels to spawn a mesh (only used if segmenting by color)
	int32 MinObjectSize = 100;  // Lowered to allow smaller objects
	
	// Color tolerance for mask segmentation (higher = fewer objects, groups similar colors)
	int32 ColorTolerance = 50;
	
	// Mesh to use for spawned objects (defaults to plane)
	UStaticMesh* ObjectMesh = nullptr;

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

	// Sequential image tracking (for when ComfyUI sends 3 images on same channel)
	int32 SequenceCounter = 0;
	
	// Last reconstruction timestamp (to prevent duplicate triggers)
	double LastReconstructionTime = 0.0;
	float MinReconstructionInterval = 0.01f;  // Minimum 0.01 seconds (10ms) between reconstructions - only to prevent true duplicates
	
	// Internal functions for 3D reconstruction
	void ProcessReconstructionIfReady();
	void Perform3DReconstruction();
	void ClearSpawnedObjects();
	void UpdateExistingObjectMaterials();
	UTexture2D* GenerateRGBAFromRGB(UTexture2D* RGBTexture, float BlackThreshold = 0.1f);
	
	// Object data structure for 3D reconstruction
	struct FObjectData
	{
		TArray<FIntPoint> Pixels;
		FLinearColor MaskColor;
		float AverageDepth;
		FVector WorldPosition;
	};
	
	// Batch image processing functions
	UTexture2D* ExtractRegionFromBatch(UTexture2D* BatchTexture, int32 StartX, int32 StartY, int32 Width, int32 Height);
	void ProcessBatchImage(UTexture2D* BatchTexture);
	
	// Mask segmentation function
	TArray<FObjectData> SegmentObjectsFromMask(UTexture2D* MaskTexture, const TArray<FColor>& DepthPixels, int32 Width, int32 Height);
	
	TArray<FObjectData> SegmentObjects(const TArray<FColor>& MaskPixels, int32 Width, int32 Height);
};

#include "ComfyStreamActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"

AComfyStreamActor::AComfyStreamActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create display mesh
	DisplayMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DisplayMesh"));
	DisplayMesh->SetupAttachment(RootComponent);

	// Create main ComfyStream component
	ComfyStreamComponent = CreateDefaultSubobject<UComfyStreamComponent>(TEXT("ComfyStreamComponent"));

	// Initialize default configurations
	// ┌─────────────────────────────────────────────────────────────┐
	// │ ComfyUI WebViewer Channel Mapping (WebSocket Port 8001)    │
	// ├─────────────────────────────────────────────────────────────┤
	// │ Channel 1 → RGB/Color Map (main image texture)             │
	// │ Channel 2 → Depth Map (white = near, black = far)          │
	// │ Channel 3 → Mask Map (for object segmentation)             │
	// └─────────────────────────────────────────────────────────────┘

	RGBChannelConfig = FComfyStreamConfig();
	RGBChannelConfig.ChannelNumber = 1;  // RGB Color
	RGBChannelConfig.ChannelType = EComfyChannel::RGBA;

	DepthChannelConfig = FComfyStreamConfig();
	DepthChannelConfig.ChannelNumber = 2;  // Depth (white=near, black=far)
	DepthChannelConfig.ChannelType = EComfyChannel::Depth;

	MaskChannelConfig = FComfyStreamConfig();
	MaskChannelConfig.ChannelNumber = 3;  // Mask (segmentation)
	MaskChannelConfig.ChannelType = EComfyChannel::Mask;
	MaskChannelConfig.bAutoReconnect = false;  // Mask channel disabled - using RGB alpha instead

	// Initialize components
	DepthChannelComponent = nullptr;
	RGBAChannelComponent = nullptr;
	MaskChannelComponent = nullptr;
	DynamicMaterial = nullptr;

	// Initialize 3D reconstruction properties
	bEnable3DReconstruction = true;
	bUpdateOnMaskOnly = false;  // Update on any texture (RGB or Depth)
	bAccumulateObjects = true;
	bSpawnSingleObject = true;  // Single object mode (RGB has alpha transparency)
	DepthScale = 100.0f;
	FocalLengthScale = 1.0f;
	ObjectScale = 1.0f;
	MinObjectSize = 100;  // Allow smaller objects
	ColorTolerance = 50;
	ObjectMesh = nullptr;
	LatestRGBATexture = nullptr;
	LatestDepthTexture = nullptr;
	LatestMaskTexture = nullptr;
}

void AComfyStreamActor::BeginPlay()
{
	Super::BeginPlay();

	// Create dynamic material (only for non-reconstruction mode)
	if (BaseMaterial && !bEnable3DReconstruction)
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
		DisplayMesh->SetMaterial(0, DynamicMaterial);
	}

	// Hide the main display mesh if using 3D reconstruction
	if (bEnable3DReconstruction)
	{
		DisplayMesh->SetVisibility(false);
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🙈 Display mesh hidden (3D Reconstruction mode)"));
	}

	// Create RGB channel component (Channel 1)
	RGBAChannelComponent = NewObject<UComfyStreamComponent>(this);
	RGBAChannelComponent->StreamConfig = RGBChannelConfig;
	RGBAChannelComponent->BaseMaterial = BaseMaterial;
	RGBAChannelComponent->DepthMapParameterName = TEXT("Depth_Map");
	RGBAChannelComponent->RGBMapParameterName = TEXT("RGB_Map");
	RGBAChannelComponent->MaskMapParameterName = TEXT("Mask_Map");
	RGBAChannelComponent->RegisterComponent();

	// Create depth channel component (Channel 2)
	DepthChannelComponent = NewObject<UComfyStreamComponent>(this);
	DepthChannelComponent->StreamConfig = DepthChannelConfig;
	DepthChannelComponent->BaseMaterial = BaseMaterial;
	DepthChannelComponent->DepthMapParameterName = TEXT("Depth_Map");
	DepthChannelComponent->RGBMapParameterName = TEXT("RGB_Map");
	DepthChannelComponent->MaskMapParameterName = TEXT("Mask_Map");
	DepthChannelComponent->RegisterComponent();

	// Create mask channel component (Channel 3)
	MaskChannelComponent = NewObject<UComfyStreamComponent>(this);
	MaskChannelComponent->StreamConfig = MaskChannelConfig;
	MaskChannelComponent->BaseMaterial = BaseMaterial;
	MaskChannelComponent->DepthMapParameterName = TEXT("Depth_Map");
	MaskChannelComponent->RGBMapParameterName = TEXT("RGB_Map");
	MaskChannelComponent->MaskMapParameterName = TEXT("Mask_Map");
	MaskChannelComponent->RegisterComponent();

	// Bind events for RGBA channel with safety checks
	if (RGBAChannelComponent)
	{
		RGBAChannelComponent->OnTextureReceived.AddDynamic(this, &AComfyStreamActor::OnRGBATextureReceived);
		RGBAChannelComponent->OnConnectionStatusChanged.AddDynamic(this, &AComfyStreamActor::OnRGBAConnectionStatusChanged);
		RGBAChannelComponent->OnError.AddDynamic(this, &AComfyStreamActor::OnRGBAError);
	}

	// Bind events for depth channel with safety checks
	if (DepthChannelComponent)
	{
		DepthChannelComponent->OnTextureReceived.AddDynamic(this, &AComfyStreamActor::OnDepthTextureReceived);
		DepthChannelComponent->OnConnectionStatusChanged.AddDynamic(this, &AComfyStreamActor::OnDepthConnectionStatusChanged);
		DepthChannelComponent->OnError.AddDynamic(this, &AComfyStreamActor::OnDepthError);
	}

	// Bind events for mask channel with safety checks
	if (MaskChannelComponent)
	{
		MaskChannelComponent->OnTextureReceived.AddDynamic(this, &AComfyStreamActor::OnMaskTextureReceived);
		MaskChannelComponent->OnConnectionStatusChanged.AddDynamic(this, &AComfyStreamActor::OnMaskConnectionStatusChanged);
		MaskChannelComponent->OnError.AddDynamic(this, &AComfyStreamActor::OnMaskError);
	}

	// Log 3D reconstruction status
	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ========================================"));
	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] 🎮 3D RECONSTRUCTION MODE = %s"), 
		bEnable3DReconstruction ? TEXT("ENABLED ✓") : TEXT("DISABLED ✗"));
	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] 📦 ACCUMULATE OBJECTS = %s"), 
		bAccumulateObjects ? TEXT("YES") : TEXT("NO"));
	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ========================================"));

	// Auto-connect if configured
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔌 Auto-connect status: RGB=%s, Depth=%s, Mask=%s"), 
		RGBChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"),
		DepthChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"),
		MaskChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"));

	if (RGBChannelConfig.bAutoReconnect)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] Connecting RGB Channel (Channel %d)..."), RGBChannelConfig.ChannelNumber);
		ConnectRGBChannel();
	}
	if (DepthChannelConfig.bAutoReconnect)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] Connecting Depth Channel (Channel %d)..."), DepthChannelConfig.ChannelNumber);
		ConnectDepthChannel();
	}
	if (MaskChannelConfig.bAutoReconnect)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ⚠️ MASK CHANNEL AUTO-CONNECT (Channel %d)..."), MaskChannelConfig.ChannelNumber);
		ConnectMaskChannel();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ MASK CHANNEL NOT AUTO-CONNECTING! Set Mask Channel Config -> Auto Reconnect = TRUE"));
	}
}

void AComfyStreamActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DisconnectAll();
	Super::EndPlay(EndPlayReason);
}

void AComfyStreamActor::ConnectRGBChannel()
{
	if (RGBAChannelComponent)
	{
		RGBAChannelComponent->Connect();
	}
}

void AComfyStreamActor::ConnectDepthChannel()
{
	if (DepthChannelComponent)
	{
		DepthChannelComponent->Connect();
	}
}

void AComfyStreamActor::ConnectMaskChannel()
{
	if (MaskChannelComponent)
	{
		MaskChannelComponent->Connect();
	}
}

void AComfyStreamActor::DisconnectAll()
{
	if (RGBAChannelComponent)
	{
		RGBAChannelComponent->Disconnect();
	}
	if (DepthChannelComponent)
	{
		DepthChannelComponent->Disconnect();
	}
	if (MaskChannelComponent)
	{
		MaskChannelComponent->Disconnect();
	}
}

void AComfyStreamActor::ConnectAllChannels()
{
	ConnectRGBChannel();
	ConnectDepthChannel();
	ConnectMaskChannel();
}

void AComfyStreamActor::ClearAllSpawnedObjects()
{
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🧹 Manual clear requested"));
	ClearSpawnedObjects();
}

void AComfyStreamActor::UpdateExistingObjectMaterials()
{
	// Update materials on all existing spawned objects without respawning them
	for (AActor* Actor : SpawnedObjects)
	{
		if (!Actor)
		{
			continue;
		}

		UStaticMeshComponent* MeshComp = Actor->FindComponentByClass<UStaticMeshComponent>();
		if (MeshComp)
		{
			UMaterialInstanceDynamic* Mat = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(0));
			if (Mat)
			{
				if (LatestRGBATexture)
				{
					Mat->SetTextureParameterValue(TEXT("RGB_Map"), LatestRGBATexture);
				}
				if (LatestDepthTexture)
				{
					Mat->SetTextureParameterValue(TEXT("Depth_Map"), LatestDepthTexture);
				}
				if (LatestMaskTexture)
				{
					Mat->SetTextureParameterValue(TEXT("Mask_Map"), LatestMaskTexture);
				}
			}
		}
	}
	
	UE_LOG(LogTemp, Verbose, TEXT("[ComfyStreamActor] 🔄 Updated materials on %d existing objects"), SpawnedObjects.Num());
}

void AComfyStreamActor::OnRGBATextureReceived(UTexture2D* Texture)
{
	if (!Texture)
	{
		return;
	}
	
	// Check if this is a batch image (RGB + Depth + Mask combined)
	// Batch images are typically larger and have width divisible by 3 (horizontal concatenation from ComfyUI ImageBatch)
	int32 Width = Texture->GetSizeX();
	int32 Height = Texture->GetSizeY();
	bool bIsBatchImage = (Width >= 1024 && Height >= 512 && Width % 3 == 0);
	
	// Debug: Log image dimensions for troubleshooting
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔍 Image dimensions: %dx%d (Batch: %s)"), 
		Width, Height, bIsBatchImage ? TEXT("YES") : TEXT("NO"));
	
	if (bIsBatchImage)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔄 Detected batch image %dx%d - processing regions..."), Width, Height);
		ProcessBatchImage(Texture);
		return; // ProcessBatchImage handles everything
	}

	// Sequential image mode: Track which image in the sequence this is
	// ComfyUI sends: RGB (0), Depth (1), Mask (2) on the same channel
	int32 ImageIndex = SequenceCounter % 3;
	SequenceCounter++;
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 Sequential image #%d received %dx%d (Type: %s)"), 
		SequenceCounter, Width, Height,
		ImageIndex == 0 ? TEXT("RGB") : (ImageIndex == 1 ? TEXT("Depth") : TEXT("Mask")));
	
	// Assign to the correct texture based on sequence position
	if (ImageIndex == 0)
	{
		// First image: RGB
		LatestRGBATexture = Texture;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Stored as RGB texture"));
		
		// Update the dynamic material (only in non-reconstruction mode)
		if (DynamicMaterial && Texture && !bEnable3DReconstruction)
		{
			DynamicMaterial->SetTextureParameterValue(TEXT("RGB_Map"), Texture);
		}
		OnTextureReceived(Texture, EComfyChannel::RGBA);
	}
	else if (ImageIndex == 1)
	{
		// Second image: Depth
		LatestDepthTexture = Texture;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Stored as Depth texture"));
		
		// Update the dynamic material (only in non-reconstruction mode)
		if (DynamicMaterial && Texture && !bEnable3DReconstruction)
		{
			DynamicMaterial->SetTextureParameterValue(TEXT("Depth_Map"), Texture);
		}
		OnTextureReceived(Texture, EComfyChannel::Depth);
	}
	else if (ImageIndex == 2)
	{
		// Third image: Mask
		LatestMaskTexture = Texture;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Stored as Mask texture"));
		
		// Update the dynamic material (only in non-reconstruction mode)
		if (DynamicMaterial && Texture && !bEnable3DReconstruction)
		{
			DynamicMaterial->SetTextureParameterValue(TEXT("Mask_Map"), Texture);
		}
		OnTextureReceived(Texture, EComfyChannel::Mask);
	}
	
	// In reconstruction mode, only trigger when the 3rd image (Mask) is received
	if (bEnable3DReconstruction && ImageIndex == 2)
	{
		// Check if we have all 3 textures needed for reconstruction
		if (LatestRGBATexture && LatestDepthTexture && LatestMaskTexture)
		{
			// Debounce: Check if enough time has passed since last reconstruction
			double CurrentTime = FPlatformTime::Seconds();
			double TimeSinceLastReconstruction = CurrentTime - LastReconstructionTime;
			
			if (TimeSinceLastReconstruction >= MinReconstructionInterval)
			{
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎯 Complete set received (RGB+Depth+Mask) - starting 3D reconstruction..."));
				LastReconstructionTime = CurrentTime;
				ProcessReconstructionIfReady();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⏱️ DEBOUNCED: Only %.2fs since last reconstruction (min: %.2fs)"), 
					TimeSinceLastReconstruction, MinReconstructionInterval);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Mask received but missing other textures! RGB:%s Depth:%s Mask:%s"), 
				LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
				LatestDepthTexture ? TEXT("✓") : TEXT("✗"), 
				LatestMaskTexture ? TEXT("✓") : TEXT("✗"));
		}
	}
	else if (bEnable3DReconstruction && ImageIndex != 2)
	{
		// Just log that we're waiting for the full set
		UE_LOG(LogTemp, Verbose, TEXT("[ComfyStreamActor] ⏳ Waiting for complete set... RGB:%s Depth:%s Mask:%s"), 
			LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
			LatestDepthTexture ? TEXT("✓") : TEXT("✗"), 
			LatestMaskTexture ? TEXT("✓") : TEXT("✗"));
	}
}

void AComfyStreamActor::OnDepthTextureReceived(UTexture2D* Texture)
{
	// Store latest texture
	LatestDepthTexture = Texture;

	// Update the dynamic material with the depth texture (only in non-reconstruction mode)
	if (DynamicMaterial && Texture && !bEnable3DReconstruction)
	{
		DynamicMaterial->SetTextureParameterValue(TEXT("Depth_Map"), Texture);
	}

	// Broadcast Blueprint event
	OnTextureReceived(Texture, EComfyChannel::Depth);

	// Note: This handler is for Channel 2 (separate depth channel)
	// In the current workflow, all images come through Channel 1 (RGB handler with sequence tracking)
	// So this won't be triggered unless you reconfigure to use separate channels
	if (bEnable3DReconstruction)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 Depth texture received via Channel 2 (separate channel mode)"));
		UpdateExistingObjectMaterials();
	}
}

void AComfyStreamActor::OnMaskTextureReceived(UTexture2D* Texture)
{
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎭 MASK TEXTURE RECEIVED! Size: %dx%d"), 
		Texture ? Texture->GetSizeX() : 0, 
		Texture ? Texture->GetSizeY() : 0);

	// Store latest texture
	LatestMaskTexture = Texture;

	// Update the dynamic material with the mask texture (only in non-reconstruction mode)
	if (DynamicMaterial && Texture && !bEnable3DReconstruction)
	{
		DynamicMaterial->SetTextureParameterValue(TEXT("Mask_Map"), Texture);
	}

	// Broadcast Blueprint event
	OnTextureReceived(Texture, EComfyChannel::Mask);

	// Note: This handler is for Channel 3 (separate mask channel)
	// In the current workflow, all images come through Channel 1 (RGB handler with sequence tracking)
	// So this won't be triggered unless you reconfigure to use separate channels
	if (bEnable3DReconstruction)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎭 Mask texture received via Channel 3 (separate channel mode)"));
	}
}

void AComfyStreamActor::OnRGBAConnectionStatusChanged(bool bConnected)
{
	// Broadcast Blueprint event
	OnConnectionStatusChanged(bConnected, EComfyChannel::RGBA);
}

void AComfyStreamActor::OnDepthConnectionStatusChanged(bool bConnected)
{
	// Broadcast Blueprint event
	OnConnectionStatusChanged(bConnected, EComfyChannel::Depth);
}

void AComfyStreamActor::OnMaskConnectionStatusChanged(bool bConnected)
{
	// Broadcast Blueprint event
	OnConnectionStatusChanged(bConnected, EComfyChannel::Mask);
}

void AComfyStreamActor::OnRGBAError(const FString& ErrorMessage)
{
	// Broadcast Blueprint event
	OnError(ErrorMessage, EComfyChannel::RGBA);
}

void AComfyStreamActor::OnDepthError(const FString& ErrorMessage)
{
	// Broadcast Blueprint event
	OnError(ErrorMessage, EComfyChannel::Depth);
}

void AComfyStreamActor::OnMaskError(const FString& ErrorMessage)
{
	// Broadcast Blueprint event
	OnError(ErrorMessage, EComfyChannel::Mask);
}

void AComfyStreamActor::ProcessReconstructionIfReady()
{
	// Only process if 3D reconstruction is enabled
	if (!bEnable3DReconstruction)
	{
		return;
	}

	// Log current texture status
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📋 Texture Status: RGB=%s, Depth=%s"), 
		LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
		LatestDepthTexture ? TEXT("✓") : TEXT("✗"));

	// New workflow: RGB has alpha transparency, no mask needed
	// Just need RGB texture (Depth is optional)
	if (LatestRGBATexture)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎯 Starting 3D reconstruction... (RGB=%s, Depth=%s)"),
			LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
			LatestDepthTexture ? TEXT("✓") : TEXT("✗"));
		
		Perform3DReconstruction();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⏳ Waiting for RGB texture (with alpha transparency)"));
	}
}

void AComfyStreamActor::Perform3DReconstruction()
{
	// LOG: Track reconstruction calls
	static int32 ReconstructionCount = 0;
	ReconstructionCount++;
	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] 🔨 RECONSTRUCTION #%d STARTING (Total spawned so far: %d)"), 
		ReconstructionCount, SpawnedObjects.Num());
	
	if (!LatestRGBATexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Missing RGB texture for 3D reconstruction"));
		return;
	}

	// Clear previous objects (only if not accumulating)
	if (!bAccumulateObjects)
	{
		ClearSpawnedObjects();
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🗑️ Cleared previous objects (non-accumulation mode)"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ➕ Accumulation mode: Adding to existing %d objects"), SpawnedObjects.Num());
	}

	// Get texture dimensions from RGB texture
	int32 Width = LatestRGBATexture->GetSizeX();
	int32 Height = LatestRGBATexture->GetSizeY();

	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📊 Processing %dx%d textures (RGB with alpha transparency)"), Width, Height);

	// Read depth texture pixels (optional - use black if not available)
	TArray<FColor> DepthPixels;
	if (LatestDepthTexture)
	{
		FTexture2DMipMap& DepthMip = LatestDepthTexture->GetPlatformData()->Mips[0];
		const FColor* DepthData = static_cast<const FColor*>(DepthMip.BulkData.LockReadOnly());
		if (!DepthData)
		{
			UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock depth texture"));
			return;
		}
		DepthPixels.Append(DepthData, Width * Height);
		DepthMip.BulkData.Unlock();
	}
	else
	{
		// No depth texture - use default (all black = far)
		DepthPixels.SetNum(Width * Height);
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ No depth texture, using default depth"));
	}

	// For accumulation mode, spawn ONLY ONE ACTOR per reconstruction
	// (not one per mask segment - that would be too many)
	TArray<FObjectData> Objects;
	
	FObjectData SingleObject;
	SingleObject.AverageDepth = 0.0f;
	SingleObject.WorldPosition = GetActorLocation();
	
	// Calculate offset for accumulation mode
	if (bAccumulateObjects)
	{
		// Spread objects out along X axis
		float OffsetDistance = SpawnedObjects.Num() * 150.0f;  // 150 units per object
		SingleObject.WorldPosition = GetActorLocation() + FVector(OffsetDistance, 0, 0);
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📦 Spawning 1 object #%d at offset %.1f (ignoring mask segmentation)"), 
		       SpawnedObjects.Num() + 1, OffsetDistance);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📦 Spawning 1 object at actor center (ignoring mask segmentation)"));
	}
	
	Objects.Add(SingleObject);

	// For each object, calculate depth and spawn mesh
	for (FObjectData& Obj : Objects)
	{
		// Skip objects that are too small
		if (Obj.Pixels.Num() > 0 && Obj.Pixels.Num() < MinObjectSize)
		{
			UE_LOG(LogTemp, Verbose, TEXT("[ComfyStreamActor] ⏩ Skipping small object (%d pixels)"), Obj.Pixels.Num());
			continue;
		}

		FVector LocalPosition = FVector::ZeroVector;
		FRotator WorldRotation = GetActorRotation();
		
		// Use depth-based positioning for all objects
		if (Obj.Pixels.Num() > 0)
		{
			// Complex mode: calculate position from depth
			float TotalDepth = 0.0f;
			float MinDepth = 1.0f;
			float MaxDepth = 0.0f;
			float CenterDepth = 0.0f;
			
			// Calculate centroid first
			FVector2D Centroid(0, 0);
			for (const FIntPoint& Pixel : Obj.Pixels)
			{
				Centroid.X += Pixel.X;
				Centroid.Y += Pixel.Y;
			}
			Centroid /= Obj.Pixels.Num();
			
			// Get depth at center pixel
			int32 CenterX = FMath::RoundToInt(Centroid.X);
			int32 CenterY = FMath::RoundToInt(Centroid.Y);
			int32 CenterIndex = CenterY * Width + CenterX;
			if (CenterIndex >= 0 && CenterIndex < DepthPixels.Num())
			{
				CenterDepth = FMath::Max3(
					DepthPixels[CenterIndex].R / 255.0f,
					DepthPixels[CenterIndex].G / 255.0f,
					DepthPixels[CenterIndex].B / 255.0f
				);
			}
			
			// Calculate stats
			for (const FIntPoint& Pixel : Obj.Pixels)
			{
				int32 Index = Pixel.Y * Width + Pixel.X;
				if (Index < DepthPixels.Num())
				{
					float DepthValue = FMath::Max3(
						DepthPixels[Index].R / 255.0f,
						DepthPixels[Index].G / 255.0f,
						DepthPixels[Index].B / 255.0f
					);
					TotalDepth += DepthValue;
					MinDepth = FMath::Min(MinDepth, DepthValue);
					MaxDepth = FMath::Max(MaxDepth, DepthValue);
				}
			}
			float AvgDepth = TotalDepth / Obj.Pixels.Num();
			
			// Use average depth instead of center for more stable positioning
			// Fallback to center if average is too low
			float DepthToUse = (AvgDepth > 0.01f) ? AvgDepth : FMath::Max(CenterDepth, MaxDepth * 0.5f);
			Obj.AverageDepth = DepthToUse;
			
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎨 Object Color: R=%d G=%d B=%d | Depth: Center=%.3f, Min=%.3f, Max=%.3f, Avg=%.3f, Using=%.3f"), 
				(int)(Obj.MaskColor.R * 255), (int)(Obj.MaskColor.G * 255), (int)(Obj.MaskColor.B * 255),
				CenterDepth, MinDepth, MaxDepth, AvgDepth, DepthToUse);

			// Pinhole camera projection:
			// Convert depth from [0,1] to actual distance
			// In depth maps: white (1.0) = near, black (0.0) = far
			// So we invert: distance = (1.0 - depth) to get actual distance
			float NormalizedDepth = FMath::Clamp(DepthToUse, 0.0f, 1.0f);
			float Distance = (1.0f - NormalizedDepth) * DepthScale;
			
			// If depth is too low (far away), clamp to a reasonable minimum
			if (Distance > DepthScale * 0.95f)
			{
				Distance = DepthScale * 0.75f;  // Don't place too far
			}
			
			// Normalize pixel coordinates to [-0.5, 0.5] range centered at image center
			float NormalizedX = (Centroid.X / Width) - 0.5f;
			float NormalizedY = (Centroid.Y / Height) - 0.5f;
			
			// Pinhole camera projection: 3D position from 2D + depth
			// Assuming a field of view, the relationship is:
			// X_world = (x_normalized / focal_length) * Z_distance
			// For simplicity, use aspect-aware scaling
			float AspectRatio = (float)Width / (float)Height;
			
			// Calculate 3D position using pinhole projection
			// Z-axis: depth (distance from camera)
			float LocalZ = Distance;
			
			// X and Y positions scale with distance (further = more spread out)
			// This creates proper perspective projection
			float LocalX = NormalizedX * Distance * FocalLengthScale * AspectRatio;
			float LocalY = NormalizedY * Distance * FocalLengthScale;
			
			LocalPosition = FVector(LocalZ, LocalX, LocalY);  // Z forward, X right, Y up
			Obj.WorldPosition = GetActorTransform().TransformPosition(LocalPosition);
		}
		else
		{
			// Fallback for objects without pixels (shouldn't happen with mask segmentation)
			// Spawn at actor center with offset for accumulation
			FVector BaseLocation = GetActorLocation();
			
			if (bAccumulateObjects)
			{
				float OffsetDistance = SpawnedObjects.Num() * 150.0f;
				Obj.WorldPosition = BaseLocation + FVector(OffsetDistance, 0, 0);
				UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Object without pixels - using fixed offset %.1f"), OffsetDistance);
			}
			else
			{
				Obj.WorldPosition = BaseLocation;
				UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Object without pixels - spawning at actor center"));
			}
		}

		// Spawn mesh for this object
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(AActor::StaticClass(), Obj.WorldPosition, WorldRotation, SpawnParams);

		if (SpawnedActor)
		{
			// Add static mesh component
			UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(SpawnedActor);
			if (ObjectMesh)
			{
				MeshComponent->SetStaticMesh(ObjectMesh);
			}
			else
			{
				MeshComponent->SetStaticMesh(DisplayMesh->GetStaticMesh());
			}
			
			// Register first before setting properties
			MeshComponent->RegisterComponent();
			SpawnedActor->SetRootComponent(MeshComponent);
			
			// Set scale to make objects visible (use relative scale since we're already in world space)
			SpawnedActor->SetActorScale3D(FVector(ObjectScale, ObjectScale, ObjectScale));
			
			// Ensure rotation matches parent actor
			SpawnedActor->SetActorRotation(WorldRotation);
			
			// Disable Nanite if material is translucent
			MeshComponent->bDisallowNanite = true;

			// Create material for this object
			UMaterialInstanceDynamic* ObjectMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, SpawnedActor);
			if (ObjectMaterial)
			{
				// Set available textures (some might be null if decoding failed)
				if (LatestRGBATexture)
				{
					// Use original RGB texture directly (mask handles transparency)
					ObjectMaterial->SetTextureParameterValue(TEXT("RGB_Map"), LatestRGBATexture);
					UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Applied RGB texture to object (RGB_Map)"));
				}
				if (LatestDepthTexture)
				{
					ObjectMaterial->SetTextureParameterValue(TEXT("Depth_Map"), LatestDepthTexture);
				}
				if (LatestMaskTexture)
				{
					ObjectMaterial->SetTextureParameterValue(TEXT("Mask_Map"), LatestMaskTexture);
				}
				MeshComponent->SetMaterial(0, ObjectMaterial);
				
				// Debug: Log material parameters
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📋 Material Parameters Set:"));
				UE_LOG(LogTemp, Display, TEXT("    RGB_Map: %s"), LatestRGBATexture ? TEXT("✓ SET") : TEXT("✗ NULL"));
				UE_LOG(LogTemp, Display, TEXT("    Depth_Map: %s"), LatestDepthTexture ? TEXT("✓ SET") : TEXT("✗ NULL"));
				UE_LOG(LogTemp, Display, TEXT("    Mask_Map: %s"), LatestMaskTexture ? TEXT("✓ SET") : TEXT("✗ NULL"));
				UE_LOG(LogTemp, Display, TEXT("    Material Blend Mode: Check if Translucent in editor!"));
				UE_LOG(LogTemp, Display, TEXT("    IMPORTANT: Mask_Map → Opacity Mask must be connected!"));
			}

			SpawnedObjects.Add(SpawnedActor);

			if (bSpawnSingleObject)
			{
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Spawned single object at WORLD (%.1f, %.1f, %.1f) Scale=%.1f"), 
					Obj.WorldPosition.X, Obj.WorldPosition.Y, Obj.WorldPosition.Z, ObjectScale);
			}
			else
			{
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Spawned object at WORLD (%.1f, %.1f, %.1f) LOCAL (%.1f, %.1f, %.1f) Scale=%.1f, Rot=(%.1f, %.1f, %.1f), %d pixels, depth: %.2f"), 
					Obj.WorldPosition.X, Obj.WorldPosition.Y, Obj.WorldPosition.Z,
					LocalPosition.X, LocalPosition.Y, LocalPosition.Z, ObjectScale,
					WorldRotation.Pitch, WorldRotation.Yaw, WorldRotation.Roll,
					Obj.Pixels.Num(), Obj.AverageDepth);
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] 🎉 RECONSTRUCTION COMPLETE! Total objects in scene: %d (just added %d new objects)"), 
		SpawnedObjects.Num(), Objects.Num());
}

 void AComfyStreamActor::ClearSpawnedObjects()
{
	int32 ClearedCount = SpawnedObjects.Num();
	for (AActor* Actor : SpawnedObjects)
	{
		if (Actor)
		{
			Actor->Destroy();
		}
	}
	SpawnedObjects.Empty();
	
	if (ClearedCount > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🗑️ Cleared %d spawned objects"), ClearedCount);
	}
}

TArray<AComfyStreamActor::FObjectData> AComfyStreamActor::SegmentObjects(const TArray<FColor>& MaskPixels, int32 Width, int32 Height)
{
	TArray<FObjectData> Objects;
	TMap<uint32, int32> ColorToObjectIndex;

	// Segment by unique colors in mask
	// Use color tolerance to group similar colors (in case of compression artifacts)
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎨 Segmenting with ColorTolerance=%d, MinObjectSize=%d"), 
		ColorTolerance, MinObjectSize);
	
	for (int32 Y = 0; Y < Height; Y++)
	{
		for (int32 X = 0; X < Width; X++)
		{
			int32 Index = Y * Width + X;
			if (Index >= MaskPixels.Num())
			{
				continue;
			}

			FColor PixelColor = MaskPixels[Index];
			
			// Skip very dark pixels (background)
			if (PixelColor.R < 15 && PixelColor.G < 15 && PixelColor.B < 15)
			{
				continue;
			}

			// Quantize color to reduce variations
			// Use instance's ColorTolerance property
			uint8 QuantR = (PixelColor.R / ColorTolerance) * ColorTolerance;
			uint8 QuantG = (PixelColor.G / ColorTolerance) * ColorTolerance;
			uint8 QuantB = (PixelColor.B / ColorTolerance) * ColorTolerance;
			
			// Create unique ID from quantized color
			uint32 ColorID = (QuantR << 16) | (QuantG << 8) | QuantB;

			// Find or create object for this color
			int32* ObjectIndexPtr = ColorToObjectIndex.Find(ColorID);
			int32 ObjectIndex;

			if (!ObjectIndexPtr)
			{
				// New object
				ObjectIndex = Objects.Num();
				ColorToObjectIndex.Add(ColorID, ObjectIndex);

				FObjectData NewObject;
				NewObject.MaskColor = FLinearColor(PixelColor);
				Objects.Add(NewObject);
			}
			else
			{
				ObjectIndex = *ObjectIndexPtr;
			}

			// Add pixel to object
			Objects[ObjectIndex].Pixels.Add(FIntPoint(X, Y));
		}
	}

	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎨 Segmented %d unique objects from mask"), Objects.Num());

	return Objects;
}

UTexture2D* AComfyStreamActor::GenerateRGBAFromRGB(UTexture2D* RGBTexture, float BlackThreshold)
{
	if (!RGBTexture)
	{
		return nullptr;
	}
	
	int32 Width = RGBTexture->GetSizeX();
	int32 Height = RGBTexture->GetSizeY();
	
	// Create new RGBA texture with alpha support
	UTexture2D* RGBATexture = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
	if (!RGBATexture)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to create RGBA texture"));
		return nullptr;
	}
	
	// Configure texture to preserve alpha channel
	RGBATexture->CompressionSettings = TC_Default;
	RGBATexture->SRGB = true;
	RGBATexture->Filter = TF_Bilinear;
	RGBATexture->AddressX = TA_Clamp;
	RGBATexture->AddressY = TA_Clamp;
	
	// Lock source RGB texture for reading
	FTexture2DMipMap& SourceMip = RGBTexture->GetPlatformData()->Mips[0];
	const FColor* SourceData = static_cast<const FColor*>(SourceMip.BulkData.LockReadOnly());
	if (!SourceData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock source RGB texture"));
		return nullptr;
	}
	
	// Lock destination RGBA texture for writing
	FTexture2DMipMap& DestMip = RGBATexture->GetPlatformData()->Mips[0];
	FColor* DestData = static_cast<FColor*>(DestMip.BulkData.Lock(LOCK_READ_WRITE));
	if (!DestData)
	{
		SourceMip.BulkData.Unlock();
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock RGBA texture for writing"));
		return nullptr;
	}
	
	// Convert RGB to RGBA: make black/near-black pixels transparent
	int32 TransparentCount = 0;
	for (int32 i = 0; i < Width * Height; i++)
	{
		FColor SourceColor = SourceData[i];
		
		// Calculate brightness (0-1)
		float Brightness = (SourceColor.R + SourceColor.G + SourceColor.B) / (3.0f * 255.0f);
		
		// If pixel is black or near-black, make it transparent
		if (Brightness < BlackThreshold)
		{
			DestData[i] = FColor(0, 0, 0, 0);  // Fully transparent
			TransparentCount++;
		}
		else
		{
			// Keep color, set full opacity
			DestData[i] = SourceColor;
			DestData[i].A = 255;  // Full opacity
		}
	}
	
	// Unlock both textures
	SourceMip.BulkData.Unlock();
	DestMip.BulkData.Unlock();
	
	// Update the texture resource
	RGBATexture->UpdateResource();
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Generated RGBA texture: %dx%d, made %d pixels transparent (%.1f%%)"),
	       Width, Height, TransparentCount, (TransparentCount * 100.0f) / (Width * Height));
	
	return RGBATexture;
}

UTexture2D* AComfyStreamActor::ExtractRegionFromBatch(UTexture2D* BatchTexture, int32 StartX, int32 StartY, int32 Width, int32 Height)
{
	if (!BatchTexture)
	{
		return nullptr;
	}
	
	int32 BatchWidth = BatchTexture->GetSizeX();
	int32 BatchHeight = BatchTexture->GetSizeY();
	
	// Validate region bounds
	if (StartX < 0 || StartY < 0 || StartX + Width > BatchWidth || StartY + Height > BatchHeight)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Invalid region bounds: StartX=%d, StartY=%d, Width=%d, Height=%d, BatchSize=%dx%d"),
			StartX, StartY, Width, Height, BatchWidth, BatchHeight);
		return nullptr;
	}
	
	// Create new texture for the extracted region
	UTexture2D* ExtractedTexture = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
	if (!ExtractedTexture)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to create extracted texture"));
		return nullptr;
	}
	
	// Configure texture
	ExtractedTexture->CompressionSettings = TC_Default;
	ExtractedTexture->SRGB = true;
	ExtractedTexture->Filter = TF_Bilinear;
	ExtractedTexture->AddressX = TA_Clamp;
	ExtractedTexture->AddressY = TA_Clamp;
	
	// Lock source texture
	FTexture2DMipMap& SourceMip = BatchTexture->GetPlatformData()->Mips[0];
	const FColor* SourceData = static_cast<const FColor*>(SourceMip.BulkData.LockReadOnly());
	if (!SourceData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock batch texture"));
		return nullptr;
	}
	
	// Lock destination texture
	FTexture2DMipMap& DestMip = ExtractedTexture->GetPlatformData()->Mips[0];
	FColor* DestData = static_cast<FColor*>(DestMip.BulkData.Lock(LOCK_READ_WRITE));
	if (!DestData)
	{
		SourceMip.BulkData.Unlock();
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock extracted texture"));
		return nullptr;
	}
	
	// Copy region
	for (int32 y = 0; y < Height; y++)
	{
		for (int32 x = 0; x < Width; x++)
		{
			int32 SourceIndex = (StartY + y) * BatchWidth + (StartX + x);
			int32 DestIndex = y * Width + x;
			
			if (SourceIndex >= 0 && SourceIndex < BatchWidth * BatchHeight)
			{
				DestData[DestIndex] = SourceData[SourceIndex];
			}
			else
			{
				DestData[DestIndex] = FColor::Black;
			}
		}
	}
	
	// Unlock textures
	SourceMip.BulkData.Unlock();
	DestMip.BulkData.Unlock();
	ExtractedTexture->UpdateResource();
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Extracted region %dx%d at (%d,%d) from batch %dx%d"),
		Width, Height, StartX, StartY, BatchWidth, BatchHeight);
	
	return ExtractedTexture;
}

void AComfyStreamActor::ProcessBatchImage(UTexture2D* BatchTexture)
{
	if (!BatchTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ No batch texture to process"));
		return;
	}
	
	int32 BatchWidth = BatchTexture->GetSizeX();
	int32 BatchHeight = BatchTexture->GetSizeY();
	
	// Calculate region sizes (horizontal concatenation: RGB | Depth | Mask)
	int32 RegionWidth = BatchWidth / 3;  // Each region is 1/3 of total width
	int32 RegionHeight = BatchHeight;
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔄 Processing batch image %dx%d -> horizontal regions %dx%d"),
		BatchWidth, BatchHeight, RegionWidth, RegionHeight);
	
	// Extract regions (horizontal concatenation from ComfyUI ImageBatch):
	// Left third: RGB
	UTexture2D* RGBRegion = ExtractRegionFromBatch(BatchTexture, 0, 0, RegionWidth, RegionHeight);
	// Middle third: Depth  
	UTexture2D* DepthRegion = ExtractRegionFromBatch(BatchTexture, RegionWidth, 0, RegionWidth, RegionHeight);
	// Right third: Mask
	UTexture2D* MaskRegion = ExtractRegionFromBatch(BatchTexture, RegionWidth * 2, 0, RegionWidth, RegionHeight);
	
	// Update our texture references
	if (RGBRegion)
	{
		LatestRGBATexture = RGBRegion;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 RGB region extracted"));
	}
	
	if (DepthRegion)
	{
		LatestDepthTexture = DepthRegion;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 Depth region extracted"));
	}
	
	if (MaskRegion)
	{
		LatestMaskTexture = MaskRegion;
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 Mask region extracted"));
	}
	
	// Trigger 3D reconstruction with all three textures
	if (LatestRGBATexture)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎯 Starting 3D reconstruction from batch image..."));
		ProcessReconstructionIfReady();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ No RGB region extracted from batch"));
	}
}

TArray<AComfyStreamActor::FObjectData> AComfyStreamActor::SegmentObjectsFromMask(UTexture2D* MaskTexture, const TArray<FColor>& DepthPixels, int32 Width, int32 Height)
{
	TArray<FObjectData> Objects;
	
	if (!MaskTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ No mask texture for segmentation"));
		return Objects;
	}
	
	// Lock mask texture
	FTexture2DMipMap& MaskMip = MaskTexture->GetPlatformData()->Mips[0];
	const FColor* MaskData = static_cast<const FColor*>(MaskMip.BulkData.LockReadOnly());
	if (!MaskData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock mask texture"));
		return Objects;
	}
	
	// Find unique colors in mask (each color represents an object)
	TSet<FColor> UniqueColors;
	for (int32 i = 0; i < Width * Height; i++)
	{
		FColor MaskColor = MaskData[i];
		// Skip black pixels (background)
		if (MaskColor.R > 10 || MaskColor.G > 10 || MaskColor.B > 10)
		{
			UniqueColors.Add(MaskColor);
		}
	}
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔍 Found %d unique colors in mask"), UniqueColors.Num());
	
	// Create object data for each unique color
	for (const FColor& MaskColor : UniqueColors)
	{
		FObjectData Object;
		Object.MaskColor = FLinearColor(MaskColor);
		Object.AverageDepth = 0.0f;
		Object.WorldPosition = GetActorLocation();
		
		float TotalDepth = 0.0f;
		int32 ValidPixels = 0;
		
		// Find all pixels with this color and calculate average depth
		for (int32 y = 0; y < Height; y++)
		{
			for (int32 x = 0; x < Width; x++)
			{
				int32 Index = y * Width + x;
				FColor PixelColor = MaskData[Index];
				
				// Check if pixel matches this object's color (with tolerance)
				if (FMath::Abs(PixelColor.R - MaskColor.R) <= ColorTolerance &&
				    FMath::Abs(PixelColor.G - MaskColor.G) <= ColorTolerance &&
				    FMath::Abs(PixelColor.B - MaskColor.B) <= ColorTolerance)
				{
					Object.Pixels.Add(FIntPoint(x, y));
					
					// Calculate depth for this pixel
					if (Index < DepthPixels.Num())
					{
						FColor DepthColor = DepthPixels[Index];
						float Depth = (DepthColor.R + DepthColor.G + DepthColor.B) / (3.0f * 255.0f);
						TotalDepth += Depth;
						ValidPixels++;
					}
				}
			}
		}
		
		// Calculate average depth
		if (ValidPixels > 0)
		{
			Object.AverageDepth = TotalDepth / ValidPixels;
		}
		
		// Only add objects with sufficient size
		if (Object.Pixels.Num() >= MinObjectSize)
		{
			Objects.Add(Object);
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ✅ Object: %d pixels, avg depth %.3f, color RGB(%d,%d,%d)"),
				Object.Pixels.Num(), Object.AverageDepth, MaskColor.R, MaskColor.G, MaskColor.B);
		}
		else
		{
			UE_LOG(LogTemp, Verbose, TEXT("[ComfyStreamActor] ⚠️ Skipped small object: %d pixels (min: %d)"),
				Object.Pixels.Num(), MinObjectSize);
		}
	}
	
	MaskMip.BulkData.Unlock();
	
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎯 Mask segmentation complete: %d valid objects"), Objects.Num());
	return Objects;
}


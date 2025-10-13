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

	RGBAChannelConfig = FComfyStreamConfig();
	RGBAChannelConfig.ChannelNumber = 1;  // RGB Color
	RGBAChannelConfig.ChannelType = EComfyChannel::RGBA;

	DepthChannelConfig = FComfyStreamConfig();
	DepthChannelConfig.ChannelNumber = 2;  // Depth (white=near, black=far)
	DepthChannelConfig.ChannelType = EComfyChannel::Depth;

	MaskChannelConfig = FComfyStreamConfig();
	MaskChannelConfig.ChannelNumber = 3;  // Mask (segmentation)
	MaskChannelConfig.ChannelType = EComfyChannel::Mask;

	// Initialize components
	DepthChannelComponent = nullptr;
	RGBAChannelComponent = nullptr;
	MaskChannelComponent = nullptr;
	DynamicMaterial = nullptr;

	// Initialize 3D reconstruction properties
	bEnable3DReconstruction = false;
	bUpdateOnMaskOnly = true;
	bAccumulateObjects = true;
	bSpawnSingleObject = true;
	DepthScale = 100.0f;
	ObjectScale = 1.0f;  // Make objects 100x larger
	MinObjectSize = 10000;
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

	// Create RGBA channel component (Channel 1)
	RGBAChannelComponent = NewObject<UComfyStreamComponent>(this);
	RGBAChannelComponent->StreamConfig = RGBAChannelConfig;
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
		RGBAChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"),
		DepthChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"),
		MaskChannelConfig.bAutoReconnect ? TEXT("ON") : TEXT("OFF"));

	if (RGBAChannelConfig.bAutoReconnect)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] Connecting RGB Channel (Channel %d)..."), RGBAChannelConfig.ChannelNumber);
		ConnectRGBAChannel();
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

void AComfyStreamActor::ConnectRGBAChannel()
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
	ConnectRGBAChannel();
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
	// Store latest texture
	LatestRGBATexture = Texture;

	// Update the dynamic material with the RGBA texture (only in non-reconstruction mode)
	if (DynamicMaterial && Texture && !bEnable3DReconstruction)
	{
		DynamicMaterial->SetTextureParameterValue(TEXT("RGB_Map"), Texture);
	}

	// Broadcast Blueprint event
	OnTextureReceived(Texture, EComfyChannel::RGBA);

	// In reconstruction mode, update materials
	if (bEnable3DReconstruction)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 RGB texture received"));
		
		// Update existing objects' materials if not in mask-only mode
		if (!bUpdateOnMaskOnly)
		{
			UpdateExistingObjectMaterials();
			ProcessReconstructionIfReady();
		}
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

	// In reconstruction mode, update materials
	if (bEnable3DReconstruction)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📥 Depth texture received"));
		
		// Update existing objects' materials if not in mask-only mode
		if (!bUpdateOnMaskOnly)
		{
			UpdateExistingObjectMaterials();
			ProcessReconstructionIfReady();
		}
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

	// In reconstruction mode, trigger reconstruction when mask updates
	if (bEnable3DReconstruction)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎭 Mask texture received, triggering reconstruction..."));
		ProcessReconstructionIfReady();
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
	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📋 Texture Status: RGB=%s, Depth=%s, Mask=%s"), 
		LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
		LatestDepthTexture ? TEXT("✓") : TEXT("✗"),
		LatestMaskTexture ? TEXT("✓") : TEXT("✗"));

	// Require at least mask + one other texture for reconstruction
	bool bHasMask = LatestMaskTexture != nullptr;
	bool bHasRGBorDepth = (LatestRGBATexture != nullptr) || (LatestDepthTexture != nullptr);
	
	if (bHasMask && bHasRGBorDepth)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎯 Starting 3D reconstruction... (RGB=%s, Depth=%s, Mask=%s)"),
			LatestRGBATexture ? TEXT("✓") : TEXT("✗"),
			LatestDepthTexture ? TEXT("✓") : TEXT("✗"),
			LatestMaskTexture ? TEXT("✓") : TEXT("✗"));
		
		Perform3DReconstruction();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⏳ Need mask + at least one data texture (RGB or Depth)"));
	}
}

void AComfyStreamActor::Perform3DReconstruction()
{
	if (!LatestMaskTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Missing mask texture for 3D reconstruction"));
		return;
	}
	
	// We can work with just mask + depth, or mask + RGB
	if (!LatestDepthTexture && !LatestRGBATexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ComfyStreamActor] ⚠️ Need at least RGB or Depth texture"));
		return;
	}

	// Clear previous objects (only if not accumulating)
	if (!bAccumulateObjects)
	{
		ClearSpawnedObjects();
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] ➕ Accumulation mode: Adding to existing %d objects"), SpawnedObjects.Num());
	}

	// Get texture dimensions
	int32 Width = LatestMaskTexture->GetSizeX();
	int32 Height = LatestMaskTexture->GetSizeY();

	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📊 Processing %dx%d textures for object segmentation"), Width, Height);

	// Read mask texture pixels
	TArray<FColor> MaskPixels;
	FTexture2DMipMap& MaskMip = LatestMaskTexture->GetPlatformData()->Mips[0];
	const FColor* MaskData = static_cast<const FColor*>(MaskMip.BulkData.LockReadOnly());
	if (!MaskData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyStreamActor] ❌ Failed to lock mask texture"));
		return;
	}
	MaskPixels.Append(MaskData, Width * Height);
	MaskMip.BulkData.Unlock();

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

	TArray<FObjectData> Objects;
	
	if (bSpawnSingleObject)
	{
		// Simple mode: spawn one object at actor center with all textures
		// Only clear in single object mode if accumulation is disabled
		if (!bAccumulateObjects && SpawnedObjects.Num() > 0)
		{
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔄 Single object mode (no accumulation): Replacing existing object"));
			ClearSpawnedObjects();
		}
		
		FObjectData SingleObject;
		SingleObject.AverageDepth = 0.0f;
		SingleObject.WorldPosition = GetActorLocation();
		Objects.Add(SingleObject);
		
		if (bAccumulateObjects)
		{
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📦 Single object mode (accumulation): Adding object #%d at actor center"), SpawnedObjects.Num() + 1);
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📦 Single object mode: Spawning 1 object at actor center"));
		}
	}
	else
	{
		// Complex mode: segment by mask colors
		Objects = SegmentObjects(MaskPixels, Width, Height);
		UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🔍 Found %d unique objects in mask"), Objects.Num());
	}

	// For each object, calculate depth and spawn mesh
	for (FObjectData& Obj : Objects)
	{
		// Skip size check in single object mode
		if (!bSpawnSingleObject && Obj.Pixels.Num() < MinObjectSize)
		{
			UE_LOG(LogTemp, Verbose, TEXT("[ComfyStreamActor] ⏩ Skipping small object (%d pixels)"), Obj.Pixels.Num());
			continue;
		}

		// In single object mode, just use actor position
		FVector LocalPosition = FVector::ZeroVector;
		FRotator WorldRotation = GetActorRotation();
		
		if (bSpawnSingleObject)
		{
			// Spawn at actor center with offset for accumulation
			FVector BaseLocation = GetActorLocation();
			
			if (bAccumulateObjects)
			{
				// Offset each new object slightly so they don't overlap completely
				float OffsetDistance = SpawnedObjects.Num() * 150.0f;  // 150 units per object
				Obj.WorldPosition = BaseLocation + FVector(OffsetDistance, 0, 0);
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📍 Single object mode (accumulation): Spawning object #%d at offset %.1f"), 
					SpawnedObjects.Num() + 1, OffsetDistance);
			}
			else
			{
				Obj.WorldPosition = BaseLocation;
				UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 📍 Single object spawning at actor center"));
			}
		}
		else
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
			Obj.AverageDepth = CenterDepth;
			
			UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎨 Object Color: R=%d G=%d B=%d | Depth: Center=%.3f, Min=%.3f, Max=%.3f, Avg=%.3f"), 
				(int)(Obj.MaskColor.R * 255), (int)(Obj.MaskColor.G * 255), (int)(Obj.MaskColor.B * 255),
				CenterDepth, MinDepth, MaxDepth, AvgDepth);

			// Convert to local space
			float NormalizedX = (Centroid.X / Width) - 0.5f;
			float NormalizedY = (Centroid.Y / Height) - 0.5f;
			float LocalX = NormalizedX * 100.0f;
			float LocalY = NormalizedY * 100.0f;
			float LocalZ = (1.0f - Obj.AverageDepth) * DepthScale;
			
			LocalPosition = FVector(LocalX, LocalY, LocalZ);
			Obj.WorldPosition = GetActorTransform().TransformPosition(LocalPosition);
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
					ObjectMaterial->SetTextureParameterValue(TEXT("RGB_Map"), LatestRGBATexture);
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

	UE_LOG(LogTemp, Display, TEXT("[ComfyStreamActor] 🎉 3D Reconstruction complete! Spawned %d objects"), SpawnedObjects.Num());
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


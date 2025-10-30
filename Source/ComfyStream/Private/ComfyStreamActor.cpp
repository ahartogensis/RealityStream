#include "ComfyStreamActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"

//Actor that receives 3 texture maps from ComfyUI and applies to to a material 

AComfyStreamActor::AComfyStreamActor()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	DisplayMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DisplayMesh"));
	DisplayMesh->SetupAttachment(RootComponent);

	ComfyStreamComponent = CreateDefaultSubobject<UComfyStreamComponent>(TEXT("ComfyStreamComponent"));

	SegmentationChannelConfig.ChannelNumber = 1;
	SegmentationChannelConfig.ChannelType   = EComfyChannel::Segmentation;
}

void AComfyStreamActor::BeginPlay()
{
	Super::BeginPlay();

	//Create external helpers for pairing and placement 
	FrameBuffer   = NewObject<UComfyFrameBuffer>(this);
	Reconstruction = NewObject<UComfyReconstruction>(this);

	//Create material
	if (BaseMaterial)
	{
		DynMat = UMaterialInstanceDynamic::Create(BaseMaterial, this);
		if (DynMat)
			DisplayMesh->SetMaterial(0, DynMat);
	}

	//Bind buffer completion
	if (FrameBuffer)
	{
		FrameBuffer->OnFullFrameReady.AddDynamic(this, &AComfyStreamActor::HandleFullFrame);
	}

	//Bind component events 
	if (ComfyStreamComponent)
	{
		ComfyStreamComponent->StreamConfig = SegmentationChannelConfig;

		ComfyStreamComponent->OnTextureReceived.AddDynamic(this, &AComfyStreamActor::HandleStreamTexture);
		ComfyStreamComponent->OnConnectionStatusChanged.AddDynamic(this, &AComfyStreamActor::HandleConnectionChanged);
		ComfyStreamComponent->OnError.AddDynamic(this, &AComfyStreamActor::HandleStreamError);

		if (SegmentationChannelConfig.bAutoReconnect)
		{
			ConnectSegmentationChannel();
		}
	}
}

void AComfyStreamActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DisconnectAll();
	Super::EndPlay(EndPlayReason);
}

void AComfyStreamActor::ConnectSegmentationChannel()
{
	if (ComfyStreamComponent)
		ComfyStreamComponent->Connect();
}

void AComfyStreamActor::DisconnectAll()
{
	if (ComfyStreamComponent)
		ComfyStreamComponent->Disconnect();
}

void AComfyStreamActor::HandleStreamTexture(UTexture2D* Texture)
{
	if (!Texture || !FrameBuffer)
		return;

	//Sequentially push textures into the FrameBuffer
	const int32 Index = SeqIndex % 3;
	FrameBuffer->PushTexture(Texture, Index);
	SeqIndex++;

	//Notify Blueprint
	OnTextureReceived.Broadcast(Texture);
}


void AComfyStreamActor::HandleConnectionChanged(bool bConnected)
{
	OnConnectionStatusChanged(bConnected, EComfyChannel::Segmentation);
}

void AComfyStreamActor::HandleStreamError(const FString& Error)
{
	OnError(Error, EComfyChannel::Segmentation);
}

void AComfyStreamActor::HandleFullFrame(const FComfyFrame& Frame)
{
	LatestFrame = Frame;
	ApplyTexturesToMaterial(Frame);
	UpdatePlacementFromDepth(Frame);
}

void AComfyStreamActor::ApplyTexturesToMaterial(const FComfyFrame& Frame)
{
	if (!DynMat) return;

	static const FName RGBParam  = TEXT("RGB_Map");
	static const FName DepthParam= TEXT("Depth_Map");
	static const FName MaskParam = TEXT("Mask_Map");

	if (Frame.RGB)   DynMat->SetTextureParameterValue(RGBParam,   Frame.RGB);
	if (Frame.Depth) DynMat->SetTextureParameterValue(DepthParam, Frame.Depth);
	if (Frame.Mask)  DynMat->SetTextureParameterValue(MaskParam,  Frame.Mask);
}

void AComfyStreamActor::UpdatePlacementFromDepth(const FComfyFrame& Frame)
{
	if (!Reconstruction || !Frame.Depth) return;

	//1) average depth in masked area
	float d01 = 0.5f;
	if (!Reconstruction->AverageNormalizedDepth(Frame.Depth, Frame.Mask, d01, 8))
	{
		//fallback 
		d01 = 0.5f;
	}

	//2) map to world-units 
	//for DepthAnything: d01~1.0 near, ~0.0 far
	const float Far = Reconstruction->DepthScaleUnits;
	const float Near= Far * 0.05f;//avoid zero depth 
	const float Zdist = FMath::Lerp(Far, Near, FMath::Clamp(d01, 0.0f, 1.0f));

	//3) estimate intrinsics from RGB size or depth based on what is available
	const int32 W = Frame.RGB ? Frame.RGB->GetSizeX() : Frame.Depth->GetSizeX();
	const int32 H = Frame.RGB ? Frame.RGB->GetSizeY() : Frame.Depth->GetSizeY();

	float fx, fy, cx, cy;
	Reconstruction->EstimateIntrinsics(W, H, fx, fy, cx, cy);

	//4) pick a representative pixel (image center)
	const int32 Px = (W - 1) / 2;
	const int32 Py = (H - 1) / 2;

	//5) back-project to world-relative vector and place the mesh
	const FVector Local = Reconstruction->DepthToWorld(Px, Py, Zdist, W, H, fx, fy, cx, cy);

	//place the display mesh relative to actor origin
	SetActorLocation(GetActorTransform().TransformPosition(Local));
}

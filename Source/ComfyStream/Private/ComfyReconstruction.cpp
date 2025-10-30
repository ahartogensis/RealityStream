#include "ComfyReconstruction.h"
#include "Engine/Texture2D.h"

//Converts depth to world projection 
//Assumes DepthAnything webcam depth format
//Auto intrinsics: fx=fy = width * FocalScale, cx,cy = image center
//Depth mapping: d_norm in [0..1], treat 1.0 ≈ near, 0.0 ≈ far
//Converts (px,py,depth) to UE coordinates (Z forward, X right, Y up)
void UComfyReconstruction::EstimateIntrinsics(int32 Width, int32 Height, float& OutFx, float& OutFy, float& OutCx, float& OutCy) const
{
	//Assume DepthAnything and webcamera intrinsics
	OutFx = FMath::Max(1.0f, Width * FocalScale);
	OutFy = OutFx;
	OutCx = (Width  - 1) * 0.5f;
	OutCy = (Height - 1) * 0.5f;
}

FVector UComfyReconstruction::DepthToWorld(
	int32 Px, int32 Py, float DepthUnits, int32 Width, int32 Height, float Fx, float Fy, float Cx, float Cy) const
{
    //pinhole back-projection
    //x_cam = (px - cx) * Z / fx
	//y_cam = (py - cy) * Z / fy
	const float Z = FMath::Max(DepthUnits, DepthEpsilon); // Changed: avoid zero Z
	const float X = (Px - Cx) * Z / FMath::Max(Fx, DepthEpsilon);
	const float Y = (Py - Cy) * Z / FMath::Max(Fy, DepthEpsilon);

	//UE convention: Z forward, X right, Y up
	return FVector(Z, X, -Y);
}

bool UComfyReconstruction::AverageNormalizedDepth(UTexture2D* DepthTex, UTexture2D* MaskTex, float& OutAvgDepth01, int32 Step) const
{
    //average normalized depth in [0..1] for masked pixels
	OutAvgDepth01 = 0.5f;
	if (!DepthTex) return false;

	const FColor* DepthPtr = nullptr;
	int32 W=0, H=0;
	if (!LockReadFColor(DepthTex, DepthPtr, W, H)) return false;

	const FColor* MaskPtr = nullptr;
	int32 MW=0, MH=0;
	if (MaskTex && !LockReadFColor(MaskTex, MaskPtr, MW, MH))
	{
		Unlock(DepthTex);
		return false;
	}

	//samples only step pixels for speed
	double Sum = 0.0;
	int64 Count = 0;
	for (int32 y=0; y<H; y+=Step)
	{
		for (int32 x=0; x<W; x+=Step)
		{
			const int32 i = y*W + x;

			//if there is a mask, skip masked-out pixels 
			if (MaskPtr)
			{
				const FColor M = MaskPtr[i];
				if (M.R < 8 && M.G < 8 && M.B < 8)
					continue;
			}

			const FColor D = DepthPtr[i];
			//use max channel because DepthAnything encodes depth/disparity similarly in R,G,B
			const float d = FMath::Max3(D.R, D.G, D.B) / 255.0f; //0..1
			Sum += d;
			++Count;
		}
	}

	if (MaskPtr) Unlock(const_cast<UTexture2D*>(MaskTex));
	Unlock(DepthTex);

	if (Count == 0) return false;
	OutAvgDepth01 = static_cast<float>(Sum / (double)Count);
	return true;
}

bool UComfyReconstruction::LockReadFColor(UTexture2D* Tex, const FColor*& OutPtr, int32& OutW, int32& OutH)
{
	if (!Tex || !Tex->GetPlatformData() || Tex->GetPlatformData()->Mips.Num()==0) return false;
	FTexture2DMipMap& Mip = Tex->GetPlatformData()->Mips[0];
	OutPtr = static_cast<const FColor*>(Mip.BulkData.LockReadOnly());
	if (!OutPtr) return false;
	OutW = Tex->GetSizeX();
	OutH = Tex->GetSizeY();
	return true;
}

void UComfyReconstruction::Unlock(UTexture2D* Tex)
{
	if (!Tex || !Tex->GetPlatformData() || Tex->GetPlatformData()->Mips.Num()==0) return;
	Tex->GetPlatformData()->Mips[0].BulkData.Unlock();
}

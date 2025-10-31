#include "ComfyStream/ComfyPngDecoder.h"
#include "IImageWrapperModule.h"
#include "IImageWrapper.h"
#include "Engine/Texture2D.h"
#include "Modules/ModuleManager.h"

//Decodes PNG and JPEG images into UTexture2D
//Assume depth images are DepthAnything PNGs
//Use UE's built-in image wrapper module for decoding
UTexture2D* UComfyPngDecoder::DecodePNGToTexture(const TArray<uint8>& PNGData)
{
	return DecodePNGToTextureWithFormat(PNGData, PF_R8G8B8A8);
}

UTexture2D* UComfyPngDecoder::DecodePNGToTextureWithFormat(const TArray<uint8>& PNGData, TEnumAsByte<EPixelFormat> PixelFormat)
{	
	//use UE's built-in image wrapper 
	IImageWrapperModule& ImageWrapperModule = 
		FModuleManager::LoadModuleChecked<IImageWrapperModule>("ImageWrapper");

		//detect either PNG or JPEG
	EImageFormat Format =
		IsValidPNGData(PNGData) ? EImageFormat::PNG :
		(IsValidJPEGData(PNGData) ? EImageFormat::JPEG : EImageFormat::Invalid);
	
	if (Format == EImageFormat::Invalid)
		return nullptr;

	//create wrapper for format then parse data 
	TSharedPtr<IImageWrapper> Wrapper = ImageWrapperModule.CreateImageWrapper(Format);
	if (!Wrapper.IsValid() || !Wrapper->SetCompressed(PNGData.GetData(), PNGData.Num()))
		return nullptr;

	int32 W = Wrapper->GetWidth();
	int32 H = Wrapper->GetHeight();

	TArray<uint8> Raw;
	if (!Wrapper->GetRaw(ERGBFormat::RGBA, 8, Raw)) return nullptr;
	
	return CreateTextureFromData(Raw, W, H, PixelFormat);
}

UTexture2D* UComfyPngDecoder::CreateTextureFromData(const TArray<uint8>& Data, int32 W, int32 H, EPixelFormat Format)
{
	UTexture2D* Texture = UTexture2D::CreateTransient(W, H, Format);
	if (!Texture) return nullptr;

	//for depth maps to attain full color fidelity 
	Texture->CompressionSettings = TC_VectorDisplacementmap; //prevent color compression 
	Texture->SRGB = true; //DepthAnything mask uses grayscale but RGB should be gamma
	Texture->Filter = TF_Bilinear;

	//copy data into textures 
	void* TexData = Texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TexData, Data.GetData(), Data.Num());
	Texture->GetPlatformData()->Mips[0].BulkData.Unlock();

	Texture->UpdateResource();
	return Texture;
}

bool UComfyPngDecoder::IsValidPNGData(const TArray<uint8>& Data) {
	return Data.Num() >= 8 && FMemory::Memcmp(Data.GetData(), "\x89PNG\r\n\x1A\n", 8) == 0;
}

bool UComfyPngDecoder::IsValidJPEGData(const TArray<uint8>& Data) {
	return Data.Num() >= 3 && Data[0] == 0xFF && Data[1] == 0xD8 && Data[2] == 0xFF;
}

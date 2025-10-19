#include "ComfyPngDecoder.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Engine/Texture2D.h"
#include "Modules/ModuleManager.h"
#include "Engine/Engine.h"

UComfyPngDecoder::UComfyPngDecoder()
{
}

UTexture2D* UComfyPngDecoder::DecodePNGToTexture(const TArray<uint8>& PNGData)
{
	return DecodePNGToTextureWithFormat(PNGData, PF_R8G8B8A8);
}

UTexture2D* UComfyPngDecoder::DecodePNGToTextureWithFormat(const TArray<uint8>& PNGData, TEnumAsByte<EPixelFormat> PixelFormat)
{
	// Auto-detect image format
	EImageFormat ImageFormat = EImageFormat::Invalid;
	FString FormatName;
	
	if (IsValidPNGData(PNGData))
	{
		ImageFormat = EImageFormat::PNG;
		FormatName = TEXT("PNG");
	}
	else if (IsValidJPEGData(PNGData))
	{
		ImageFormat = EImageFormat::JPEG;
		FormatName = TEXT("JPEG");
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Invalid image data (not PNG or JPEG)"));
		return nullptr;
	}


	// Load ImageWrapper module
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);

	if (!ImageWrapper.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Failed to create image wrapper for %s"), *FormatName);
		return nullptr;
	}

	// Set compressed data
	if (!ImageWrapper->SetCompressed(PNGData.GetData(), PNGData.Num()))
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Failed to parse %s data"), *FormatName);
		return nullptr;
	}

	// Get image dimensions
	int32 Width = ImageWrapper->GetWidth();
	int32 Height = ImageWrapper->GetHeight();

	if (Width <= 0 || Height <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Invalid image dimensions: %dx%d"), Width, Height);
		return nullptr;
	}

	// Decompress the image
	TArray<uint8> UncompressedRGBA;
	ERGBFormat RGBFormat = ERGBFormat::RGBA;
	int32 BitDepth = 8;

	if (!ImageWrapper->GetRaw(RGBFormat, BitDepth, UncompressedRGBA))
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Failed to decompress PNG"));
		return nullptr;
	}

	// Create texture from uncompressed data
	return CreateTextureFromData(UncompressedRGBA, Width, Height, PixelFormat);
}

bool UComfyPngDecoder::IsValidPNGData(const TArray<uint8>& PNGData)
{
	if (PNGData.Num() < 8)
	{
		return false;
	}

	// Check PNG signature (first 8 bytes): 0x89 0x50 0x4E 0x47 0x0D 0x0A 0x1A 0x0A
	const uint8 PNGSignature[8] = { 137, 80, 78, 71, 13, 10, 26, 10 };
	return FMemory::Memcmp(PNGData.GetData(), PNGSignature, 8) == 0;
}

bool UComfyPngDecoder::IsValidJPEGData(const TArray<uint8>& ImageData)
{
	if (ImageData.Num() < 3)
	{
		return false;
	}

	// Check JPEG signature (first 3 bytes): 0xFF 0xD8 0xFF
	return ImageData[0] == 0xFF && ImageData[1] == 0xD8 && ImageData[2] == 0xFF;
}

UTexture2D* UComfyPngDecoder::CreateTextureFromData(const TArray<uint8>& UncompressedData, int32 Width, int32 Height, EPixelFormat PixelFormat)
{
	// Create transient texture
	UTexture2D* Texture = UTexture2D::CreateTransient(Width, Height, PixelFormat);
	if (!Texture)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Failed to create texture"));
		return nullptr;
	}

	// Lock the texture for writing
	void* TextureData = Texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	if (!TextureData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ComfyPNG] Failed to lock texture data"));
		return nullptr;
	}

	// Copy pixel data
	FMemory::Memcpy(TextureData, UncompressedData.GetData(), UncompressedData.Num());

	// Unlock the texture
	Texture->GetPlatformData()->Mips[0].BulkData.Unlock();

	// Update the texture resource
	Texture->UpdateResource();


	return Texture;
}

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/Texture2D.h"
#include "ComfyPngDecoder.generated.h"

/**
 * PNG decoder utility for converting raw PNG data to Unreal textures
 */
UCLASS()
class COMFYSTREAM_API UComfyPngDecoder : public UObject
{
	GENERATED_BODY()

public:
	UComfyPngDecoder();

	/**
	 * Decode PNG data to a texture
	 * @param PNGData Raw PNG data
	 * @return Created texture or nullptr if failed
	 */
	UFUNCTION(BlueprintCallable, Category = "ComfyPNG")
	UTexture2D* DecodePNGToTexture(const TArray<uint8>& PNGData);

	/**
	 * Decode PNG data to a texture with specific format
	 * @param PNGData Raw PNG data
	 * @param PixelFormat Desired pixel format
	 * @return Created texture or nullptr if failed
	 */
	UFUNCTION(BlueprintCallable, Category = "ComfyPNG")
	UTexture2D* DecodePNGToTextureWithFormat(const TArray<uint8>& PNGData, TEnumAsByte<EPixelFormat> PixelFormat);

	/**
	 * Check if PNG data is valid
	 * @param PNGData Raw PNG data
	 * @return True if valid PNG data
	 */
	UFUNCTION(BlueprintCallable, Category = "ComfyPNG")
	bool IsValidPNGData(const TArray<uint8>& PNGData);

	/**
	 * Check if JPEG data is valid
	 * @param ImageData Raw JPEG data
	 * @return True if valid JPEG data
	 */
	UFUNCTION(BlueprintCallable, Category = "ComfyPNG")
	bool IsValidJPEGData(const TArray<uint8>& ImageData);

private:
	/**
	 * Internal function to create texture from uncompressed data
	 * @param UncompressedData Raw pixel data
	 * @param Width Texture width
	 * @param Height Texture height
	 * @param PixelFormat Pixel format
	 * @return Created texture or nullptr if failed
	 */
	UTexture2D* CreateTextureFromData(const TArray<uint8>& UncompressedData, int32 Width, int32 Height, EPixelFormat PixelFormat);
};

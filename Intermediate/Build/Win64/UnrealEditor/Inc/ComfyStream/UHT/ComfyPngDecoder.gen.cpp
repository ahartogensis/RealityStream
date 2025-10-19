// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyPngDecoder.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyPngDecoder() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder();
COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_EPixelFormat();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyPngDecoder Function DecodePNGToTexture *****************************
struct Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics
{
	struct ComfyPngDecoder_eventDecodePNGToTexture_Parms
	{
		TArray<uint8> PNGData;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyPNG" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Decode PNG data to a texture\n\x09 * @param PNGData Raw PNG data\n\x09 * @return Created texture or nullptr if failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decode PNG data to a texture\n@param PNGData Raw PNG data\n@return Created texture or nullptr if failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PNGData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_PNGData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PNGData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_PNGData_Inner = { "PNGData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_PNGData = { "PNGData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventDecodePNGToTexture_Parms, PNGData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PNGData_MetaData), NewProp_PNGData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventDecodePNGToTexture_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_PNGData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_PNGData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyPngDecoder, nullptr, "DecodePNGToTexture", Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::ComfyPngDecoder_eventDecodePNGToTexture_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::ComfyPngDecoder_eventDecodePNGToTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyPngDecoder::execDecodePNGToTexture)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_PNGData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=P_THIS->DecodePNGToTexture(Z_Param_Out_PNGData);
	P_NATIVE_END;
}
// ********** End Class UComfyPngDecoder Function DecodePNGToTexture *******************************

// ********** Begin Class UComfyPngDecoder Function DecodePNGToTextureWithFormat *******************
struct Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics
{
	struct ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms
	{
		TArray<uint8> PNGData;
		TEnumAsByte<EPixelFormat> PixelFormat;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyPNG" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Decode PNG data to a texture with specific format\n\x09 * @param PNGData Raw PNG data\n\x09 * @param PixelFormat Desired pixel format\n\x09 * @return Created texture or nullptr if failed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decode PNG data to a texture with specific format\n@param PNGData Raw PNG data\n@param PixelFormat Desired pixel format\n@return Created texture or nullptr if failed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PNGData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_PNGData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PNGData;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PixelFormat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PNGData_Inner = { "PNGData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PNGData = { "PNGData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms, PNGData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PNGData_MetaData), NewProp_PNGData_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PixelFormat = { "PixelFormat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms, PixelFormat), Z_Construct_UEnum_CoreUObject_EPixelFormat, METADATA_PARAMS(0, nullptr) }; // 2051073252
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PNGData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PNGData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_PixelFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyPngDecoder, nullptr, "DecodePNGToTextureWithFormat", Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::ComfyPngDecoder_eventDecodePNGToTextureWithFormat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyPngDecoder::execDecodePNGToTextureWithFormat)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_PNGData);
	P_GET_PROPERTY(FByteProperty,Z_Param_PixelFormat);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=P_THIS->DecodePNGToTextureWithFormat(Z_Param_Out_PNGData,EPixelFormat(Z_Param_PixelFormat));
	P_NATIVE_END;
}
// ********** End Class UComfyPngDecoder Function DecodePNGToTextureWithFormat *********************

// ********** Begin Class UComfyPngDecoder Function IsValidJPEGData ********************************
struct Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics
{
	struct ComfyPngDecoder_eventIsValidJPEGData_Parms
	{
		TArray<uint8> ImageData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyPNG" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if JPEG data is valid\n\x09 * @param ImageData Raw JPEG data\n\x09 * @return True if valid JPEG data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if JPEG data is valid\n@param ImageData Raw JPEG data\n@return True if valid JPEG data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ImageData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ImageData_Inner = { "ImageData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ImageData = { "ImageData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventIsValidJPEGData_Parms, ImageData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageData_MetaData), NewProp_ImageData_MetaData) };
void Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ComfyPngDecoder_eventIsValidJPEGData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyPngDecoder_eventIsValidJPEGData_Parms), &Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ImageData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ImageData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyPngDecoder, nullptr, "IsValidJPEGData", Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::ComfyPngDecoder_eventIsValidJPEGData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::ComfyPngDecoder_eventIsValidJPEGData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyPngDecoder::execIsValidJPEGData)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_ImageData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidJPEGData(Z_Param_Out_ImageData);
	P_NATIVE_END;
}
// ********** End Class UComfyPngDecoder Function IsValidJPEGData **********************************

// ********** Begin Class UComfyPngDecoder Function IsValidPNGData *********************************
struct Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics
{
	struct ComfyPngDecoder_eventIsValidPNGData_Parms
	{
		TArray<uint8> PNGData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyPNG" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if PNG data is valid\n\x09 * @param PNGData Raw PNG data\n\x09 * @return True if valid PNG data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if PNG data is valid\n@param PNGData Raw PNG data\n@return True if valid PNG data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PNGData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_PNGData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PNGData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_PNGData_Inner = { "PNGData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_PNGData = { "PNGData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyPngDecoder_eventIsValidPNGData_Parms, PNGData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PNGData_MetaData), NewProp_PNGData_MetaData) };
void Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ComfyPngDecoder_eventIsValidPNGData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyPngDecoder_eventIsValidPNGData_Parms), &Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_PNGData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_PNGData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyPngDecoder, nullptr, "IsValidPNGData", Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::ComfyPngDecoder_eventIsValidPNGData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::ComfyPngDecoder_eventIsValidPNGData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyPngDecoder::execIsValidPNGData)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_PNGData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidPNGData(Z_Param_Out_PNGData);
	P_NATIVE_END;
}
// ********** End Class UComfyPngDecoder Function IsValidPNGData ***********************************

// ********** Begin Class UComfyPngDecoder *********************************************************
void UComfyPngDecoder::StaticRegisterNativesUComfyPngDecoder()
{
	UClass* Class = UComfyPngDecoder::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DecodePNGToTexture", &UComfyPngDecoder::execDecodePNGToTexture },
		{ "DecodePNGToTextureWithFormat", &UComfyPngDecoder::execDecodePNGToTextureWithFormat },
		{ "IsValidJPEGData", &UComfyPngDecoder::execIsValidJPEGData },
		{ "IsValidPNGData", &UComfyPngDecoder::execIsValidPNGData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyPngDecoder;
UClass* UComfyPngDecoder::GetPrivateStaticClass()
{
	using TClass = UComfyPngDecoder;
	if (!Z_Registration_Info_UClass_UComfyPngDecoder.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyPngDecoder"),
			Z_Registration_Info_UClass_UComfyPngDecoder.InnerSingleton,
			StaticRegisterNativesUComfyPngDecoder,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UComfyPngDecoder.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister()
{
	return UComfyPngDecoder::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyPngDecoder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PNG decoder utility for converting raw PNG data to Unreal textures\n */" },
#endif
		{ "IncludePath", "ComfyPngDecoder.h" },
		{ "ModuleRelativePath", "Public/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PNG decoder utility for converting raw PNG data to Unreal textures" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTexture, "DecodePNGToTexture" }, // 4002069386
		{ &Z_Construct_UFunction_UComfyPngDecoder_DecodePNGToTextureWithFormat, "DecodePNGToTextureWithFormat" }, // 2060361727
		{ &Z_Construct_UFunction_UComfyPngDecoder_IsValidJPEGData, "IsValidJPEGData" }, // 3810678237
		{ &Z_Construct_UFunction_UComfyPngDecoder_IsValidPNGData, "IsValidPNGData" }, // 3030801165
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyPngDecoder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UComfyPngDecoder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyPngDecoder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyPngDecoder_Statics::ClassParams = {
	&UComfyPngDecoder::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyPngDecoder_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyPngDecoder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyPngDecoder()
{
	if (!Z_Registration_Info_UClass_UComfyPngDecoder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyPngDecoder.OuterSingleton, Z_Construct_UClass_UComfyPngDecoder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyPngDecoder.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyPngDecoder);
UComfyPngDecoder::~UComfyPngDecoder() {}
// ********** End Class UComfyPngDecoder ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyPngDecoder_h__Script_ComfyStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyPngDecoder, UComfyPngDecoder::StaticClass, TEXT("UComfyPngDecoder"), &Z_Registration_Info_UClass_UComfyPngDecoder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyPngDecoder), 398104471U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyPngDecoder_h__Script_ComfyStream_2727054688(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyPngDecoder_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyPngDecoder_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyFrameBundle.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyFrameBundle() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyFrame();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FComfyFrame *******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FComfyFrame;
class UScriptStruct* FComfyFrame::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyFrame.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FComfyFrame.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FComfyFrame, (UObject*)Z_Construct_UPackage__Script_RealityStream(), TEXT("ComfyFrame"));
	}
	return Z_Registration_Info_UScriptStruct_FComfyFrame.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FComfyFrame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The Blueprint stuct for RGB, Depth, and Mask Maps\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBundle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Blueprint stuct for RGB, Depth, and Mask Maps" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RGB_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBundle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBundle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mask_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBundle.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RGB;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mask;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FComfyFrame>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_RGB = { "RGB", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyFrame, RGB), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RGB_MetaData), NewProp_RGB_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyFrame, Depth), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Depth_MetaData), NewProp_Depth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_Mask = { "Mask", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyFrame, Mask), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mask_MetaData), NewProp_Mask_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FComfyFrame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_RGB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyFrame_Statics::NewProp_Mask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyFrame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FComfyFrame_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
	nullptr,
	&NewStructOps,
	"ComfyFrame",
	Z_Construct_UScriptStruct_FComfyFrame_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyFrame_Statics::PropPointers),
	sizeof(FComfyFrame),
	alignof(FComfyFrame),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyFrame_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FComfyFrame_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FComfyFrame()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyFrame.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FComfyFrame.InnerSingleton, Z_Construct_UScriptStruct_FComfyFrame_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FComfyFrame.InnerSingleton;
}
// ********** End ScriptStruct FComfyFrame *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBundle_h__Script_RealityStream_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FComfyFrame::StaticStruct, Z_Construct_UScriptStruct_FComfyFrame_Statics::NewStructOps, TEXT("ComfyFrame"), &Z_Registration_Info_UScriptStruct_FComfyFrame, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FComfyFrame), 493399616U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBundle_h__Script_RealityStream_1794265841(TEXT("/Script/RealityStream"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBundle_h__Script_RealityStream_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBundle_h__Script_RealityStream_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

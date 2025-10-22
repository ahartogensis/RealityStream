// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldExplorerSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWorldExplorerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem();
COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWorldExplorerSubsystem Function GenerateGaussianSplat *******************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics
{
	struct WorldExplorerSubsystem_eventGenerateGaussianSplat_Parms
	{
		FString VideoPath;
		FString OutputDir;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Generate a Gaussian Splat from a video file using WorldExplorer\n     * @param VideoPath - Full path to the video file to process\n     * @param OutputDir - Optional custom output directory. If empty, uses default location\n     */" },
#endif
		{ "CPP_Default_OutputDir", "" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generate a Gaussian Splat from a video file using WorldExplorer\n@param VideoPath - Full path to the video file to process\n@param OutputDir - Optional custom output directory. If empty, uses default location" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputDir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputDir;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventGenerateGaussianSplat_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::NewProp_OutputDir = { "OutputDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventGenerateGaussianSplat_Parms, OutputDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputDir_MetaData), NewProp_OutputDir_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::NewProp_VideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::NewProp_OutputDir,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "GenerateGaussianSplat", Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::WorldExplorerSubsystem_eventGenerateGaussianSplat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::WorldExplorerSubsystem_eventGenerateGaussianSplat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execGenerateGaussianSplat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_OutputDir);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateGaussianSplat(Z_Param_VideoPath,Z_Param_OutputDir);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function GenerateGaussianSplat *********************

// ********** Begin Class UWorldExplorerSubsystem Function GetDefaultOutputDirectory ***************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics
{
	struct WorldExplorerSubsystem_eventGetDefaultOutputDirectory_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Get the default output directory for WorldExplorer results\n     */" },
#endif
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the default output directory for WorldExplorer results" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventGetDefaultOutputDirectory_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "GetDefaultOutputDirectory", Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::WorldExplorerSubsystem_eventGetDefaultOutputDirectory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::WorldExplorerSubsystem_eventGetDefaultOutputDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execGetDefaultOutputDirectory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetDefaultOutputDirectory();
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function GetDefaultOutputDirectory *****************

// ********** Begin Class UWorldExplorerSubsystem Function ImportExistingSplat *********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Import an existing Gaussian Splat from the outputs directory\n     * Useful for testing or importing previously generated splats\n     */" },
#endif
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Import an existing Gaussian Splat from the outputs directory\nUseful for testing or importing previously generated splats" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ImportExistingSplat", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execImportExistingSplat)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ImportExistingSplat();
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ImportExistingSplat ***********************

// ********** Begin Class UWorldExplorerSubsystem Function RunGaussianSplatFromVideo ***************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics
{
	struct WorldExplorerSubsystem_eventRunGaussianSplatFromVideo_Parms
	{
		FString VideoPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Run Gaussian Splatting from video using Docker container\n     * @param VideoPath - Full path to the video file to process\n     */" },
#endif
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Run Gaussian Splatting from video using Docker container\n@param VideoPath - Full path to the video file to process" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventRunGaussianSplatFromVideo_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::NewProp_VideoPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "RunGaussianSplatFromVideo", Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::WorldExplorerSubsystem_eventRunGaussianSplatFromVideo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::WorldExplorerSubsystem_eventRunGaussianSplatFromVideo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execRunGaussianSplatFromVideo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RunGaussianSplatFromVideo(Z_Param_VideoPath);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function RunGaussianSplatFromVideo *****************

// ********** Begin Class UWorldExplorerSubsystem **************************************************
void UWorldExplorerSubsystem::StaticRegisterNativesUWorldExplorerSubsystem()
{
	UClass* Class = UWorldExplorerSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateGaussianSplat", &UWorldExplorerSubsystem::execGenerateGaussianSplat },
		{ "GetDefaultOutputDirectory", &UWorldExplorerSubsystem::execGetDefaultOutputDirectory },
		{ "ImportExistingSplat", &UWorldExplorerSubsystem::execImportExistingSplat },
		{ "RunGaussianSplatFromVideo", &UWorldExplorerSubsystem::execRunGaussianSplatFromVideo },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWorldExplorerSubsystem;
UClass* UWorldExplorerSubsystem::GetPrivateStaticClass()
{
	using TClass = UWorldExplorerSubsystem;
	if (!Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WorldExplorerSubsystem"),
			Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton,
			StaticRegisterNativesUWorldExplorerSubsystem,
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
	return Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister()
{
	return UWorldExplorerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWorldExplorerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handles launching WorldExplorer and auto-importing Gaussian splats\n * Works at both runtime and in editor\n */" },
#endif
		{ "IncludePath", "WorldExplorerSubsystem.h" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles launching WorldExplorer and auto-importing Gaussian splats\nWorks at both runtime and in editor" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_GenerateGaussianSplat, "GenerateGaussianSplat" }, // 3088916850
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_GetDefaultOutputDirectory, "GetDefaultOutputDirectory" }, // 192457656
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat, "ImportExistingSplat" }, // 3037907354
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplatFromVideo, "RunGaussianSplatFromVideo" }, // 100236311
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWorldExplorerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UWorldExplorerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldExplorerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWorldExplorerSubsystem_Statics::ClassParams = {
	&UWorldExplorerSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldExplorerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UWorldExplorerSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWorldExplorerSubsystem()
{
	if (!Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton, Z_Construct_UClass_UWorldExplorerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton;
}
UWorldExplorerSubsystem::UWorldExplorerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWorldExplorerSubsystem);
UWorldExplorerSubsystem::~UWorldExplorerSubsystem() {}
// ********** End Class UWorldExplorerSubsystem ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWorldExplorerSubsystem, UWorldExplorerSubsystem::StaticClass, TEXT("UWorldExplorerSubsystem"), &Z_Registration_Info_UClass_UWorldExplorerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWorldExplorerSubsystem), 1230656274U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_3084704434(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

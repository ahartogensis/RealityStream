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

// ********** Begin Class UWorldExplorerSubsystem Function CheckAndImportSplat *********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics
{
	struct WorldExplorerSubsystem_eventCheckAndImportSplat_Parms
	{
		FString VideoPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Only Blueprint-callable function - handles everything automatically\n" },
#endif
		{ "CPP_Default_VideoPath", "" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Only Blueprint-callable function - handles everything automatically" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventCheckAndImportSplat_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::NewProp_VideoPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "CheckAndImportSplat", Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::WorldExplorerSubsystem_eventCheckAndImportSplat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::WorldExplorerSubsystem_eventCheckAndImportSplat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execCheckAndImportSplat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CheckAndImportSplat(Z_Param_VideoPath);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function CheckAndImportSplat ***********************

// ********** Begin Class UWorldExplorerSubsystem **************************************************
void UWorldExplorerSubsystem::StaticRegisterNativesUWorldExplorerSubsystem()
{
	UClass* Class = UWorldExplorerSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CheckAndImportSplat", &UWorldExplorerSubsystem::execCheckAndImportSplat },
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
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * WorldExplorer subsystem for handling Gaussian splat conversions\n */" },
#endif
		{ "IncludePath", "WorldExplorerSubsystem.h" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WorldExplorer subsystem for handling Gaussian splat conversions" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat, "CheckAndImportSplat" }, // 3617721378
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
		{ Z_Construct_UClass_UWorldExplorerSubsystem, UWorldExplorerSubsystem::StaticClass, TEXT("UWorldExplorerSubsystem"), &Z_Registration_Info_UClass_UWorldExplorerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWorldExplorerSubsystem), 614726779U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_1090077428(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

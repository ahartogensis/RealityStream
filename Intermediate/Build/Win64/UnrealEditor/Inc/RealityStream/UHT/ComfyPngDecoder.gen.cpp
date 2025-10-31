// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyPngDecoder.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyPngDecoder() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyPngDecoder *********************************************************
void UComfyPngDecoder::StaticRegisterNativesUComfyPngDecoder()
{
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
		{ "Comment", "//Decodes PNG and JPEG images into UTexture2D\n//Assume depth images are DepthAnything PNGs\n//Use UE's built-in image wrapper module for decoding\n" },
#endif
		{ "IncludePath", "ComfyStream/ComfyPngDecoder.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyPngDecoder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decodes PNG and JPEG images into UTexture2D\nAssume depth images are DepthAnything PNGs\nUse UE's built-in image wrapper module for decoding" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyPngDecoder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UComfyPngDecoder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyPngDecoder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyPngDecoder_Statics::ClassParams = {
	&UComfyPngDecoder::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
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
UComfyPngDecoder::UComfyPngDecoder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyPngDecoder);
UComfyPngDecoder::~UComfyPngDecoder() {}
// ********** End Class UComfyPngDecoder ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyPngDecoder_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyPngDecoder, UComfyPngDecoder::StaticClass, TEXT("UComfyPngDecoder"), &Z_Registration_Info_UClass_UComfyPngDecoder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyPngDecoder), 3464616733U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyPngDecoder_h__Script_RealityStream_3289954887(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyPngDecoder_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyPngDecoder_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

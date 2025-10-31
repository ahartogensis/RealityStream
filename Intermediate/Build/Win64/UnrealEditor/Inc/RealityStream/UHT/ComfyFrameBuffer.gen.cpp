// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyFrameBuffer.h"
#include "ComfyStream/ComfyFrameBundle.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyFrameBuffer() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyFrameBuffer();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyFrameBuffer_NoRegister();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyFrame();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnFullFrameReady *****************************************************
struct Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics
{
	struct _Script_RealityStream_eventOnFullFrameReady_Parms
	{
		FComfyFrame Frame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Fires event when all 3 textures arrive (RGB, Depth, Mask)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBuffer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fires event when all 3 textures arrive (RGB, Depth, Mask)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frame_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Frame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::NewProp_Frame = { "Frame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_RealityStream_eventOnFullFrameReady_Parms, Frame), Z_Construct_UScriptStruct_FComfyFrame, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frame_MetaData), NewProp_Frame_MetaData) }; // 493399616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::NewProp_Frame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_RealityStream, nullptr, "OnFullFrameReady__DelegateSignature", Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::_Script_RealityStream_eventOnFullFrameReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::_Script_RealityStream_eventOnFullFrameReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnFullFrameReady_DelegateWrapper(const FMulticastScriptDelegate& OnFullFrameReady, FComfyFrame const& Frame)
{
	struct _Script_RealityStream_eventOnFullFrameReady_Parms
	{
		FComfyFrame Frame;
	};
	_Script_RealityStream_eventOnFullFrameReady_Parms Parms;
	Parms.Frame=Frame;
	OnFullFrameReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnFullFrameReady *******************************************************

// ********** Begin Class UComfyFrameBuffer ********************************************************
void UComfyFrameBuffer::StaticRegisterNativesUComfyFrameBuffer()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyFrameBuffer;
UClass* UComfyFrameBuffer::GetPrivateStaticClass()
{
	using TClass = UComfyFrameBuffer;
	if (!Z_Registration_Info_UClass_UComfyFrameBuffer.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyFrameBuffer"),
			Z_Registration_Info_UClass_UComfyFrameBuffer.InnerSingleton,
			StaticRegisterNativesUComfyFrameBuffer,
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
	return Z_Registration_Info_UClass_UComfyFrameBuffer.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyFrameBuffer_NoRegister()
{
	return UComfyFrameBuffer::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyFrameBuffer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ComfyStream/ComfyFrameBuffer.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBuffer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFullFrameReady_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Event triggered when all 3 textures have been recieved \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyFrameBuffer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event triggered when all 3 textures have been recieved" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFullFrameReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyFrameBuffer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyFrameBuffer_Statics::NewProp_OnFullFrameReady = { "OnFullFrameReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyFrameBuffer, OnFullFrameReady), Z_Construct_UDelegateFunction_RealityStream_OnFullFrameReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFullFrameReady_MetaData), NewProp_OnFullFrameReady_MetaData) }; // 3406701497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComfyFrameBuffer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyFrameBuffer_Statics::NewProp_OnFullFrameReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyFrameBuffer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UComfyFrameBuffer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyFrameBuffer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyFrameBuffer_Statics::ClassParams = {
	&UComfyFrameBuffer::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UComfyFrameBuffer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UComfyFrameBuffer_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyFrameBuffer_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyFrameBuffer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyFrameBuffer()
{
	if (!Z_Registration_Info_UClass_UComfyFrameBuffer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyFrameBuffer.OuterSingleton, Z_Construct_UClass_UComfyFrameBuffer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyFrameBuffer.OuterSingleton;
}
UComfyFrameBuffer::UComfyFrameBuffer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyFrameBuffer);
UComfyFrameBuffer::~UComfyFrameBuffer() {}
// ********** End Class UComfyFrameBuffer **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyFrameBuffer, UComfyFrameBuffer::StaticClass, TEXT("UComfyFrameBuffer"), &Z_Registration_Info_UClass_UComfyFrameBuffer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyFrameBuffer), 2416823087U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h__Script_RealityStream_2767924470(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

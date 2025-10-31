// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyImageFetcher.h"
#include "ComfyStream/ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyImageFetcher() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyImageFetcher();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyImageFetcher_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyImageFetcher Function IsPolling ************************************
struct Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics
{
	struct ComfyImageFetcher_eventIsPolling_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ComfyImageFetcher_eventIsPolling_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyImageFetcher_eventIsPolling_Parms), &Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyImageFetcher, nullptr, "IsPolling", Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::ComfyImageFetcher_eventIsPolling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::ComfyImageFetcher_eventIsPolling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyImageFetcher_IsPolling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyImageFetcher_IsPolling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyImageFetcher::execIsPolling)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPolling();
	P_NATIVE_END;
}
// ********** End Class UComfyImageFetcher Function IsPolling **************************************

// ********** Begin Class UComfyImageFetcher Function StartPolling *********************************
struct Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics
{
	struct ComfyImageFetcher_eventStartPolling_Parms
	{
		FString ServerURL;
		int32 ChannelNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_ChannelNumber", "1" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerURL_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerURL;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChannelNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::NewProp_ServerURL = { "ServerURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyImageFetcher_eventStartPolling_Parms, ServerURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerURL_MetaData), NewProp_ServerURL_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::NewProp_ChannelNumber = { "ChannelNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyImageFetcher_eventStartPolling_Parms, ChannelNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::NewProp_ServerURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::NewProp_ChannelNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyImageFetcher, nullptr, "StartPolling", Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::ComfyImageFetcher_eventStartPolling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::ComfyImageFetcher_eventStartPolling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyImageFetcher_StartPolling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyImageFetcher_StartPolling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyImageFetcher::execStartPolling)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ServerURL);
	P_GET_PROPERTY(FIntProperty,Z_Param_ChannelNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartPolling(Z_Param_ServerURL,Z_Param_ChannelNumber);
	P_NATIVE_END;
}
// ********** End Class UComfyImageFetcher Function StartPolling ***********************************

// ********** Begin Class UComfyImageFetcher Function StopPolling **********************************
struct Z_Construct_UFunction_UComfyImageFetcher_StopPolling_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyImageFetcher_StopPolling_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyImageFetcher, nullptr, "StopPolling", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyImageFetcher_StopPolling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyImageFetcher_StopPolling_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyImageFetcher_StopPolling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyImageFetcher_StopPolling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyImageFetcher::execStopPolling)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopPolling();
	P_NATIVE_END;
}
// ********** End Class UComfyImageFetcher Function StopPolling ************************************

// ********** Begin Class UComfyImageFetcher *******************************************************
void UComfyImageFetcher::StaticRegisterNativesUComfyImageFetcher()
{
	UClass* Class = UComfyImageFetcher::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "IsPolling", &UComfyImageFetcher::execIsPolling },
		{ "StartPolling", &UComfyImageFetcher::execStartPolling },
		{ "StopPolling", &UComfyImageFetcher::execStopPolling },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyImageFetcher;
UClass* UComfyImageFetcher::GetPrivateStaticClass()
{
	using TClass = UComfyImageFetcher;
	if (!Z_Registration_Info_UClass_UComfyImageFetcher.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyImageFetcher"),
			Z_Registration_Info_UClass_UComfyImageFetcher.InnerSingleton,
			StaticRegisterNativesUComfyImageFetcher,
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
	return Z_Registration_Info_UClass_UComfyImageFetcher.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyImageFetcher_NoRegister()
{
	return UComfyImageFetcher::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyImageFetcher_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Handles connection between ComfyUI and Unreal Engine 5.6 thourgh websockets\n" },
#endif
		{ "IncludePath", "ComfyStream/ComfyImageFetcher.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles connection between ComfyUI and Unreal Engine 5.6 thourgh websockets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextureReceived_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnConnectionStatusChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WebSocketPort_MetaData[] = {
		{ "Category", "ComfyImageFetcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//default websocket port is 8001 \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default websocket port is 8001" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "ComfyImageFetcher" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PngDecoder_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Decodes png files \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyImageFetcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decodes png files" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextureReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectionStatusChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WebSocketPort;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PngDecoder;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComfyImageFetcher_IsPolling, "IsPolling" }, // 4022285553
		{ &Z_Construct_UFunction_UComfyImageFetcher_StartPolling, "StartPolling" }, // 1240829926
		{ &Z_Construct_UFunction_UComfyImageFetcher_StopPolling, "StopPolling" }, // 1832123907
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyImageFetcher>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnTextureReceived = { "OnTextureReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, OnTextureReceived), Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextureReceived_MetaData), NewProp_OnTextureReceived_MetaData) }; // 3136099786
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnConnectionStatusChanged = { "OnConnectionStatusChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, OnConnectionStatusChanged), Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnConnectionStatusChanged_MetaData), NewProp_OnConnectionStatusChanged_MetaData) }; // 692129119
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, OnError), Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 2422426028
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_WebSocketPort = { "WebSocketPort", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, WebSocketPort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WebSocketPort_MetaData), NewProp_WebSocketPort_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, Config), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 306865604
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_PngDecoder = { "PngDecoder", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyImageFetcher, PngDecoder), Z_Construct_UClass_UComfyPngDecoder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PngDecoder_MetaData), NewProp_PngDecoder_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComfyImageFetcher_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnTextureReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnConnectionStatusChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_OnError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_WebSocketPort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_Config,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyImageFetcher_Statics::NewProp_PngDecoder,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyImageFetcher_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UComfyImageFetcher_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyImageFetcher_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyImageFetcher_Statics::ClassParams = {
	&UComfyImageFetcher::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UComfyImageFetcher_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UComfyImageFetcher_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyImageFetcher_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyImageFetcher_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyImageFetcher()
{
	if (!Z_Registration_Info_UClass_UComfyImageFetcher.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyImageFetcher.OuterSingleton, Z_Construct_UClass_UComfyImageFetcher_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyImageFetcher.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyImageFetcher);
UComfyImageFetcher::~UComfyImageFetcher() {}
// ********** End Class UComfyImageFetcher *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyImageFetcher_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyImageFetcher, UComfyImageFetcher::StaticClass, TEXT("UComfyImageFetcher"), &Z_Registration_Info_UClass_UComfyImageFetcher, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyImageFetcher), 3487118311U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyImageFetcher_h__Script_RealityStream_2469326972(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyImageFetcher_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyImageFetcher_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStreamActor.h"
#include "ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyStreamActor() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor();
COMFYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister();
COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister();
COMFYSTREAM_API UEnum* Z_Construct_UEnum_ComfyStream_EComfyChannel();
COMFYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AComfyStreamActor Function ClearAllSpawnedObjects ************************
struct Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Manually clear all spawned objects\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manually clear all spawned objects" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ClearAllSpawnedObjects", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execClearAllSpawnedObjects)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAllSpawnedObjects();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ClearAllSpawnedObjects **************************

// ********** Begin Class AComfyStreamActor Function ConnectAllChannels ****************************
struct Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ConnectAllChannels", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execConnectAllChannels)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectAllChannels();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ConnectAllChannels ******************************

// ********** Begin Class AComfyStreamActor Function ConnectDepthChannel ***************************
struct Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ConnectDepthChannel", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execConnectDepthChannel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectDepthChannel();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ConnectDepthChannel *****************************

// ********** Begin Class AComfyStreamActor Function ConnectMaskChannel ****************************
struct Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ConnectMaskChannel", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execConnectMaskChannel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectMaskChannel();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ConnectMaskChannel ******************************

// ********** Begin Class AComfyStreamActor Function ConnectRGBChannel *****************************
struct Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ConnectRGBChannel", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execConnectRGBChannel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectRGBChannel();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ConnectRGBChannel *******************************

// ********** Begin Class AComfyStreamActor Function DisconnectAll *********************************
struct Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "DisconnectAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_DisconnectAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execDisconnectAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DisconnectAll();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function DisconnectAll ***********************************

// ********** Begin Class AComfyStreamActor Function OnConnectionStatusChanged *********************
struct ComfyStreamActor_eventOnConnectionStatusChanged_Parms
{
	bool bConnected;
	EComfyChannel ChannelType;
};
static FName NAME_AComfyStreamActor_OnConnectionStatusChanged = FName(TEXT("OnConnectionStatusChanged"));
void AComfyStreamActor::OnConnectionStatusChanged(bool bConnected, EComfyChannel ChannelType)
{
	ComfyStreamActor_eventOnConnectionStatusChanged_Parms Parms;
	Parms.bConnected=bConnected ? true : false;
	Parms.ChannelType=ChannelType;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnConnectionStatusChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ChannelType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ChannelType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventOnConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventOnConnectionStatusChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_ChannelType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_ChannelType = { "ChannelType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnConnectionStatusChanged_Parms, ChannelType), Z_Construct_UEnum_ComfyStream_EComfyChannel, METADATA_PARAMS(0, nullptr) }; // 1194890099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_ChannelType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_ChannelType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnConnectionStatusChanged", Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::PropPointers), sizeof(ComfyStreamActor_eventOnConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ComfyStreamActor_eventOnConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AComfyStreamActor Function OnConnectionStatusChanged ***********************

// ********** Begin Class AComfyStreamActor Function OnDepthConnectionStatusChanged ****************
struct Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics
{
	struct ComfyStreamActor_eventOnDepthConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventOnDepthConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventOnDepthConnectionStatusChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnDepthConnectionStatusChanged", Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::ComfyStreamActor_eventOnDepthConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::ComfyStreamActor_eventOnDepthConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnDepthConnectionStatusChanged)
{
	P_GET_UBOOL(Z_Param_bConnected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDepthConnectionStatusChanged(Z_Param_bConnected);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnDepthConnectionStatusChanged ******************

// ********** Begin Class AComfyStreamActor Function OnDepthError **********************************
struct Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics
{
	struct ComfyStreamActor_eventOnDepthError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnDepthError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnDepthError", Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::ComfyStreamActor_eventOnDepthError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::ComfyStreamActor_eventOnDepthError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnDepthError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnDepthError_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnDepthError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDepthError(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnDepthError ************************************

// ********** Begin Class AComfyStreamActor Function OnDepthTextureReceived ************************
struct Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics
{
	struct ComfyStreamActor_eventOnDepthTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnDepthTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnDepthTextureReceived", Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::ComfyStreamActor_eventOnDepthTextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::ComfyStreamActor_eventOnDepthTextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnDepthTextureReceived)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDepthTextureReceived(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnDepthTextureReceived **************************

// ********** Begin Class AComfyStreamActor Function OnError ***************************************
struct ComfyStreamActor_eventOnError_Parms
{
	FString ErrorMessage;
	EComfyChannel ChannelType;
};
static FName NAME_AComfyStreamActor_OnError = FName(TEXT("OnError"));
void AComfyStreamActor::OnError(const FString& ErrorMessage, EComfyChannel ChannelType)
{
	ComfyStreamActor_eventOnError_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ChannelType=ChannelType;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnError);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnError_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ChannelType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ChannelType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ChannelType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ChannelType = { "ChannelType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnError_Parms, ChannelType), Z_Construct_UEnum_ComfyStream_EComfyChannel, METADATA_PARAMS(0, nullptr) }; // 1194890099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ErrorMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ChannelType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ChannelType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnError", Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::PropPointers), sizeof(ComfyStreamActor_eventOnError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ComfyStreamActor_eventOnError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AComfyStreamActor Function OnError *****************************************

// ********** Begin Class AComfyStreamActor Function OnMaskConnectionStatusChanged *****************
struct Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics
{
	struct ComfyStreamActor_eventOnMaskConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventOnMaskConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventOnMaskConnectionStatusChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnMaskConnectionStatusChanged", Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::ComfyStreamActor_eventOnMaskConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::ComfyStreamActor_eventOnMaskConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnMaskConnectionStatusChanged)
{
	P_GET_UBOOL(Z_Param_bConnected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMaskConnectionStatusChanged(Z_Param_bConnected);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnMaskConnectionStatusChanged *******************

// ********** Begin Class AComfyStreamActor Function OnMaskError ***********************************
struct Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics
{
	struct ComfyStreamActor_eventOnMaskError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnMaskError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnMaskError", Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::ComfyStreamActor_eventOnMaskError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::ComfyStreamActor_eventOnMaskError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnMaskError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnMaskError_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnMaskError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMaskError(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnMaskError *************************************

// ********** Begin Class AComfyStreamActor Function OnMaskTextureReceived *************************
struct Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics
{
	struct ComfyStreamActor_eventOnMaskTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnMaskTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnMaskTextureReceived", Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::ComfyStreamActor_eventOnMaskTextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::ComfyStreamActor_eventOnMaskTextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnMaskTextureReceived)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMaskTextureReceived(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnMaskTextureReceived ***************************

// ********** Begin Class AComfyStreamActor Function OnRGBAConnectionStatusChanged *****************
struct Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics
{
	struct ComfyStreamActor_eventOnRGBAConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventOnRGBAConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventOnRGBAConnectionStatusChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnRGBAConnectionStatusChanged", Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::ComfyStreamActor_eventOnRGBAConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::ComfyStreamActor_eventOnRGBAConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnRGBAConnectionStatusChanged)
{
	P_GET_UBOOL(Z_Param_bConnected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRGBAConnectionStatusChanged(Z_Param_bConnected);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnRGBAConnectionStatusChanged *******************

// ********** Begin Class AComfyStreamActor Function OnRGBAError ***********************************
struct Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics
{
	struct ComfyStreamActor_eventOnRGBAError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnRGBAError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnRGBAError", Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::ComfyStreamActor_eventOnRGBAError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::ComfyStreamActor_eventOnRGBAError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnRGBAError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnRGBAError_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnRGBAError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRGBAError(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnRGBAError *************************************

// ********** Begin Class AComfyStreamActor Function OnRGBATextureReceived *************************
struct Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics
{
	struct ComfyStreamActor_eventOnRGBATextureReceived_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Internal event handlers\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal event handlers" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnRGBATextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnRGBATextureReceived", Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::ComfyStreamActor_eventOnRGBATextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::ComfyStreamActor_eventOnRGBATextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execOnRGBATextureReceived)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRGBATextureReceived(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function OnRGBATextureReceived ***************************

// ********** Begin Class AComfyStreamActor Function OnTextureReceived *****************************
struct ComfyStreamActor_eventOnTextureReceived_Parms
{
	UTexture2D* Texture;
	EComfyChannel ChannelType;
};
static FName NAME_AComfyStreamActor_OnTextureReceived = FName(TEXT("OnTextureReceived"));
void AComfyStreamActor::OnTextureReceived(UTexture2D* Texture, EComfyChannel ChannelType)
{
	ComfyStreamActor_eventOnTextureReceived_Parms Parms;
	Parms.Texture=Texture;
	Parms.ChannelType=ChannelType;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnTextureReceived);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint events\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint events" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ChannelType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ChannelType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_ChannelType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_ChannelType = { "ChannelType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnTextureReceived_Parms, ChannelType), Z_Construct_UEnum_ComfyStream_EComfyChannel, METADATA_PARAMS(0, nullptr) }; // 1194890099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_Texture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_ChannelType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_ChannelType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "OnTextureReceived", Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::PropPointers), sizeof(ComfyStreamActor_eventOnTextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ComfyStreamActor_eventOnTextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AComfyStreamActor Function OnTextureReceived *******************************

// ********** Begin Class AComfyStreamActor ********************************************************
void AComfyStreamActor::StaticRegisterNativesAComfyStreamActor()
{
	UClass* Class = AComfyStreamActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearAllSpawnedObjects", &AComfyStreamActor::execClearAllSpawnedObjects },
		{ "ConnectAllChannels", &AComfyStreamActor::execConnectAllChannels },
		{ "ConnectDepthChannel", &AComfyStreamActor::execConnectDepthChannel },
		{ "ConnectMaskChannel", &AComfyStreamActor::execConnectMaskChannel },
		{ "ConnectRGBChannel", &AComfyStreamActor::execConnectRGBChannel },
		{ "DisconnectAll", &AComfyStreamActor::execDisconnectAll },
		{ "OnDepthConnectionStatusChanged", &AComfyStreamActor::execOnDepthConnectionStatusChanged },
		{ "OnDepthError", &AComfyStreamActor::execOnDepthError },
		{ "OnDepthTextureReceived", &AComfyStreamActor::execOnDepthTextureReceived },
		{ "OnMaskConnectionStatusChanged", &AComfyStreamActor::execOnMaskConnectionStatusChanged },
		{ "OnMaskError", &AComfyStreamActor::execOnMaskError },
		{ "OnMaskTextureReceived", &AComfyStreamActor::execOnMaskTextureReceived },
		{ "OnRGBAConnectionStatusChanged", &AComfyStreamActor::execOnRGBAConnectionStatusChanged },
		{ "OnRGBAError", &AComfyStreamActor::execOnRGBAError },
		{ "OnRGBATextureReceived", &AComfyStreamActor::execOnRGBATextureReceived },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AComfyStreamActor;
UClass* AComfyStreamActor::GetPrivateStaticClass()
{
	using TClass = AComfyStreamActor;
	if (!Z_Registration_Info_UClass_AComfyStreamActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyStreamActor"),
			Z_Registration_Info_UClass_AComfyStreamActor.InnerSingleton,
			StaticRegisterNativesAComfyStreamActor,
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
	return Z_Registration_Info_UClass_AComfyStreamActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister()
{
	return AComfyStreamActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AComfyStreamActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Example actor that demonstrates how to use the ComfyStream plugin\n * This actor receives depth and RGBA maps from ComfyUI and applies them to a material\n */" },
#endif
		{ "IncludePath", "ComfyStreamActor.h" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Example actor that demonstrates how to use the ComfyStream plugin\nThis actor receives depth and RGBA maps from ComfyUI and applies them to a material" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayMesh_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The mesh to display the material on\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The mesh to display the material on" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComfyStreamComponent_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ComfyStream component for handling the websocket connection\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ComfyStream component for handling the websocket connection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMaterial_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Base material to use for the displacement effect\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base material to use for the displacement effect" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RGBChannelConfig_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration for RGB channel (Channel 1)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration for RGB channel (Channel 1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepthChannelConfig_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration for depth channel (Channel 2)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration for depth channel (Channel 2)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskChannelConfig_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration for mask channel (Channel 3)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration for mask channel (Channel 3)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RGBAChannelComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// RGBA channel component (Channel 1)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RGBA channel component (Channel 1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepthChannelComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Depth channel component (Channel 2)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Depth channel component (Channel 2)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskChannelComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Mask channel component (Channel 3)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mask channel component (Channel 3)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMaterial_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Dynamic material instance\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dynamic material instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LatestRGBATexture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Latest received textures for 3D reconstruction\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Latest received textures for 3D reconstruction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LatestDepthTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LatestMaskTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedObjects_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Array of spawned object meshes for 3D reconstruction\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Array of spawned object meshes for 3D reconstruction" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DisplayMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ComfyStreamComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RGBChannelConfig;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DepthChannelConfig;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaskChannelConfig;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RGBAChannelComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DepthChannelComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaskChannelComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LatestRGBATexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LatestDepthTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LatestMaskTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedObjects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedObjects;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AComfyStreamActor_ClearAllSpawnedObjects, "ClearAllSpawnedObjects" }, // 2427445640
		{ &Z_Construct_UFunction_AComfyStreamActor_ConnectAllChannels, "ConnectAllChannels" }, // 5303677
		{ &Z_Construct_UFunction_AComfyStreamActor_ConnectDepthChannel, "ConnectDepthChannel" }, // 3037174007
		{ &Z_Construct_UFunction_AComfyStreamActor_ConnectMaskChannel, "ConnectMaskChannel" }, // 2299822171
		{ &Z_Construct_UFunction_AComfyStreamActor_ConnectRGBChannel, "ConnectRGBChannel" }, // 87892284
		{ &Z_Construct_UFunction_AComfyStreamActor_DisconnectAll, "DisconnectAll" }, // 1489004772
		{ &Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged, "OnConnectionStatusChanged" }, // 791290975
		{ &Z_Construct_UFunction_AComfyStreamActor_OnDepthConnectionStatusChanged, "OnDepthConnectionStatusChanged" }, // 2735037943
		{ &Z_Construct_UFunction_AComfyStreamActor_OnDepthError, "OnDepthError" }, // 4055870597
		{ &Z_Construct_UFunction_AComfyStreamActor_OnDepthTextureReceived, "OnDepthTextureReceived" }, // 189903670
		{ &Z_Construct_UFunction_AComfyStreamActor_OnError, "OnError" }, // 927916734
		{ &Z_Construct_UFunction_AComfyStreamActor_OnMaskConnectionStatusChanged, "OnMaskConnectionStatusChanged" }, // 3979952879
		{ &Z_Construct_UFunction_AComfyStreamActor_OnMaskError, "OnMaskError" }, // 1262469240
		{ &Z_Construct_UFunction_AComfyStreamActor_OnMaskTextureReceived, "OnMaskTextureReceived" }, // 5875644
		{ &Z_Construct_UFunction_AComfyStreamActor_OnRGBAConnectionStatusChanged, "OnRGBAConnectionStatusChanged" }, // 3221205795
		{ &Z_Construct_UFunction_AComfyStreamActor_OnRGBAError, "OnRGBAError" }, // 1291555698
		{ &Z_Construct_UFunction_AComfyStreamActor_OnRGBATextureReceived, "OnRGBATextureReceived" }, // 995810761
		{ &Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived, "OnTextureReceived" }, // 2439810804
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AComfyStreamActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DisplayMesh = { "DisplayMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, DisplayMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayMesh_MetaData), NewProp_DisplayMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_ComfyStreamComponent = { "ComfyStreamComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, ComfyStreamComponent), Z_Construct_UClass_UComfyStreamComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComfyStreamComponent_MetaData), NewProp_ComfyStreamComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_BaseMaterial = { "BaseMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, BaseMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMaterial_MetaData), NewProp_BaseMaterial_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_RGBChannelConfig = { "RGBChannelConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, RGBChannelConfig), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RGBChannelConfig_MetaData), NewProp_RGBChannelConfig_MetaData) }; // 631194733
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DepthChannelConfig = { "DepthChannelConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, DepthChannelConfig), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepthChannelConfig_MetaData), NewProp_DepthChannelConfig_MetaData) }; // 631194733
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_MaskChannelConfig = { "MaskChannelConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, MaskChannelConfig), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskChannelConfig_MetaData), NewProp_MaskChannelConfig_MetaData) }; // 631194733
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_RGBAChannelComponent = { "RGBAChannelComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, RGBAChannelComponent), Z_Construct_UClass_UComfyStreamComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RGBAChannelComponent_MetaData), NewProp_RGBAChannelComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DepthChannelComponent = { "DepthChannelComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, DepthChannelComponent), Z_Construct_UClass_UComfyStreamComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepthChannelComponent_MetaData), NewProp_DepthChannelComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_MaskChannelComponent = { "MaskChannelComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, MaskChannelComponent), Z_Construct_UClass_UComfyStreamComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskChannelComponent_MetaData), NewProp_MaskChannelComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DynamicMaterial = { "DynamicMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, DynamicMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMaterial_MetaData), NewProp_DynamicMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestRGBATexture = { "LatestRGBATexture", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, LatestRGBATexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LatestRGBATexture_MetaData), NewProp_LatestRGBATexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestDepthTexture = { "LatestDepthTexture", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, LatestDepthTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LatestDepthTexture_MetaData), NewProp_LatestDepthTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestMaskTexture = { "LatestMaskTexture", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, LatestMaskTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LatestMaskTexture_MetaData), NewProp_LatestMaskTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedObjects_Inner = { "SpawnedObjects", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedObjects = { "SpawnedObjects", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, SpawnedObjects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedObjects_MetaData), NewProp_SpawnedObjects_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DisplayMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_ComfyStreamComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_BaseMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_RGBChannelConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DepthChannelConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_MaskChannelConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_RGBAChannelComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DepthChannelComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_MaskChannelComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DynamicMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestRGBATexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestDepthTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LatestMaskTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedObjects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedObjects,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AComfyStreamActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AComfyStreamActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AComfyStreamActor_Statics::ClassParams = {
	&AComfyStreamActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AComfyStreamActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AComfyStreamActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AComfyStreamActor()
{
	if (!Z_Registration_Info_UClass_AComfyStreamActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AComfyStreamActor.OuterSingleton, Z_Construct_UClass_AComfyStreamActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AComfyStreamActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AComfyStreamActor);
AComfyStreamActor::~AComfyStreamActor() {}
// ********** End Class AComfyStreamActor **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h__Script_ComfyStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AComfyStreamActor, AComfyStreamActor::StaticClass, TEXT("AComfyStreamActor"), &Z_Registration_Info_UClass_AComfyStreamActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AComfyStreamActor), 3109585179U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h__Script_ComfyStream_1467106483(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyStreamTypes() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UEnum* Z_Construct_UEnum_ComfyStream_EComfyChannel();
COMFYSTREAM_API UEnum* Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus();
COMFYSTREAM_API UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature();
COMFYSTREAM_API UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature();
COMFYSTREAM_API UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature();
COMFYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnTextureReceived ****************************************************
struct Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics
{
	struct _Script_ComfyStream_eventOnTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when a new texture is received from ComfyUI\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event for when a new texture is received from ComfyUI" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ComfyStream_eventOnTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ComfyStream, nullptr, "OnTextureReceived__DelegateSignature", Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::_Script_ComfyStream_eventOnTextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::_Script_ComfyStream_eventOnTextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ComfyStream_OnTextureReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTextureReceived_DelegateWrapper(const FMulticastScriptDelegate& OnTextureReceived, UTexture2D* Texture)
{
	struct _Script_ComfyStream_eventOnTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
	_Script_ComfyStream_eventOnTextureReceived_Parms Parms;
	Parms.Texture=Texture;
	OnTextureReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTextureReceived ******************************************************

// ********** Begin Delegate FOnConnectionStatusChanged ********************************************
struct Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics
{
	struct _Script_ComfyStream_eventOnConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when a connection status changes\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event for when a connection status changes" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((_Script_ComfyStream_eventOnConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_ComfyStream_eventOnConnectionStatusChanged_Parms), &Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ComfyStream, nullptr, "OnConnectionStatusChanged__DelegateSignature", Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::_Script_ComfyStream_eventOnConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::_Script_ComfyStream_eventOnConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ComfyStream_OnConnectionStatusChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnConnectionStatusChanged_DelegateWrapper(const FMulticastScriptDelegate& OnConnectionStatusChanged, bool bConnected)
{
	struct _Script_ComfyStream_eventOnConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
	_Script_ComfyStream_eventOnConnectionStatusChanged_Parms Parms;
	Parms.bConnected=bConnected ? true : false;
	OnConnectionStatusChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnConnectionStatusChanged **********************************************

// ********** Begin Delegate FOnError **************************************************************
struct Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics
{
	struct _Script_ComfyStream_eventOnError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when an error occurs\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event for when an error occurs" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ComfyStream_eventOnError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ComfyStream, nullptr, "OnError__DelegateSignature", Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::_Script_ComfyStream_eventOnError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::_Script_ComfyStream_eventOnError_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnError_DelegateWrapper(const FMulticastScriptDelegate& OnError, const FString& ErrorMessage)
{
	struct _Script_ComfyStream_eventOnError_Parms
	{
		FString ErrorMessage;
	};
	_Script_ComfyStream_eventOnError_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnError.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnError ****************************************************************

// ********** Begin Enum EComfyChannel *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EComfyChannel;
static UEnum* EComfyChannel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EComfyChannel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EComfyChannel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ComfyStream_EComfyChannel, (UObject*)Z_Construct_UPackage__Script_ComfyStream(), TEXT("EComfyChannel"));
	}
	return Z_Registration_Info_UEnum_EComfyChannel.OuterSingleton;
}
template<> COMFYSTREAM_API UEnum* StaticEnum<EComfyChannel>()
{
	return EComfyChannel_StaticEnum();
}
struct Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Channel types for different ComfyUI streams\n" },
#endif
		{ "Custom.DisplayName", "Custom Channel" },
		{ "Custom.Name", "EComfyChannel::Custom" },
		{ "Depth.DisplayName", "Depth Map" },
		{ "Depth.Name", "EComfyChannel::Depth" },
		{ "Mask.DisplayName", "Mask Map" },
		{ "Mask.Name", "EComfyChannel::Mask" },
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
		{ "RGBA.DisplayName", "RGBA Map" },
		{ "RGBA.Name", "EComfyChannel::RGBA" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel types for different ComfyUI streams" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EComfyChannel::RGBA", (int64)EComfyChannel::RGBA },
		{ "EComfyChannel::Depth", (int64)EComfyChannel::Depth },
		{ "EComfyChannel::Mask", (int64)EComfyChannel::Mask },
		{ "EComfyChannel::Custom", (int64)EComfyChannel::Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ComfyStream,
	nullptr,
	"EComfyChannel",
	"EComfyChannel",
	Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ComfyStream_EComfyChannel()
{
	if (!Z_Registration_Info_UEnum_EComfyChannel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EComfyChannel.InnerSingleton, Z_Construct_UEnum_ComfyStream_EComfyChannel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EComfyChannel.InnerSingleton;
}
// ********** End Enum EComfyChannel ***************************************************************

// ********** Begin Enum EComfyConnectionStatus ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EComfyConnectionStatus;
static UEnum* EComfyConnectionStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EComfyConnectionStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EComfyConnectionStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus, (UObject*)Z_Construct_UPackage__Script_ComfyStream(), TEXT("EComfyConnectionStatus"));
	}
	return Z_Registration_Info_UEnum_EComfyConnectionStatus.OuterSingleton;
}
template<> COMFYSTREAM_API UEnum* StaticEnum<EComfyConnectionStatus>()
{
	return EComfyConnectionStatus_StaticEnum();
}
struct Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Connection status\n" },
#endif
		{ "Connected.DisplayName", "Connected" },
		{ "Connected.Name", "EComfyConnectionStatus::Connected" },
		{ "Connecting.DisplayName", "Connecting" },
		{ "Connecting.Name", "EComfyConnectionStatus::Connecting" },
		{ "Disconnected.DisplayName", "Disconnected" },
		{ "Disconnected.Name", "EComfyConnectionStatus::Disconnected" },
		{ "Error.DisplayName", "Error" },
		{ "Error.Name", "EComfyConnectionStatus::Error" },
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connection status" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EComfyConnectionStatus::Disconnected", (int64)EComfyConnectionStatus::Disconnected },
		{ "EComfyConnectionStatus::Connecting", (int64)EComfyConnectionStatus::Connecting },
		{ "EComfyConnectionStatus::Connected", (int64)EComfyConnectionStatus::Connected },
		{ "EComfyConnectionStatus::Error", (int64)EComfyConnectionStatus::Error },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ComfyStream,
	nullptr,
	"EComfyConnectionStatus",
	"EComfyConnectionStatus",
	Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus()
{
	if (!Z_Registration_Info_UEnum_EComfyConnectionStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EComfyConnectionStatus.InnerSingleton, Z_Construct_UEnum_ComfyStream_EComfyConnectionStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EComfyConnectionStatus.InnerSingleton;
}
// ********** End Enum EComfyConnectionStatus ******************************************************

// ********** Begin ScriptStruct FComfyStreamConfig ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FComfyStreamConfig;
class UScriptStruct* FComfyStreamConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyStreamConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FComfyStreamConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FComfyStreamConfig, (UObject*)Z_Construct_UPackage__Script_ComfyStream(), TEXT("ComfyStreamConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FComfyStreamConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FComfyStreamConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration structure for ComfyUI connection\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration structure for ComfyUI connection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerURL_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Base URL for ComfyUI server (HTTP URL, will be converted to WebSocket)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base URL for ComfyUI server (HTTP URL, will be converted to WebSocket)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChannelNumber_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Channel number for this stream\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel number for this stream" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChannelType_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Channel type\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PingInterval_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Keep-alive ping interval in seconds\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keep-alive ping interval in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoReconnect_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Auto-reconnect on disconnect\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-reconnect on disconnect" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconnectDelay_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reconnect delay in seconds\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reconnect delay in seconds" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerURL;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChannelNumber;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ChannelType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ChannelType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PingInterval;
	static void NewProp_bAutoReconnect_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoReconnect;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReconnectDelay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FComfyStreamConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ServerURL = { "ServerURL", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ServerURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerURL_MetaData), NewProp_ServerURL_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelNumber = { "ChannelNumber", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ChannelNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChannelNumber_MetaData), NewProp_ChannelNumber_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType = { "ChannelType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ChannelType), Z_Construct_UEnum_ComfyStream_EComfyChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChannelType_MetaData), NewProp_ChannelType_MetaData) }; // 1194890099
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_PingInterval = { "PingInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, PingInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PingInterval_MetaData), NewProp_PingInterval_MetaData) };
void Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect_SetBit(void* Obj)
{
	((FComfyStreamConfig*)Obj)->bAutoReconnect = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect = { "bAutoReconnect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FComfyStreamConfig), &Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoReconnect_MetaData), NewProp_bAutoReconnect_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ReconnectDelay = { "ReconnectDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ReconnectDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconnectDelay_MetaData), NewProp_ReconnectDelay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ServerURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_PingInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ReconnectDelay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
	nullptr,
	&NewStructOps,
	"ComfyStreamConfig",
	Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers),
	sizeof(FComfyStreamConfig),
	alignof(FComfyStreamConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyStreamConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FComfyStreamConfig.InnerSingleton, Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FComfyStreamConfig.InnerSingleton;
}
// ********** End ScriptStruct FComfyStreamConfig **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EComfyChannel_StaticEnum, TEXT("EComfyChannel"), &Z_Registration_Info_UEnum_EComfyChannel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1194890099U) },
		{ EComfyConnectionStatus_StaticEnum, TEXT("EComfyConnectionStatus"), &Z_Registration_Info_UEnum_EComfyConnectionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3405395111U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FComfyStreamConfig::StaticStruct, Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewStructOps, TEXT("ComfyStreamConfig"), &Z_Registration_Info_UScriptStruct_FComfyStreamConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FComfyStreamConfig), 249633148U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_3166245189(TEXT("/Script/ComfyStream"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamTypes_h__Script_ComfyStream_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

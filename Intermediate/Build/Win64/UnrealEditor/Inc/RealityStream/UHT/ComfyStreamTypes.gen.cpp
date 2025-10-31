// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyStreamTypes() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REALITYSTREAM_API UEnum* Z_Construct_UEnum_RealityStream_EComfyChannel();
REALITYSTREAM_API UEnum* Z_Construct_UEnum_RealityStream_EComfyConnectionStatus();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyLerpState();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnTextureReceived ****************************************************
struct Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics
{
	struct _Script_RealityStream_eventOnTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when a new texture is received from ComfyUI\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event for when a new texture is received from ComfyUI" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_RealityStream_eventOnTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_RealityStream, nullptr, "OnTextureReceived__DelegateSignature", Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::_Script_RealityStream_eventOnTextureReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::_Script_RealityStream_eventOnTextureReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTextureReceived_DelegateWrapper(const FMulticastScriptDelegate& OnTextureReceived, UTexture2D* Texture)
{
	struct _Script_RealityStream_eventOnTextureReceived_Parms
	{
		UTexture2D* Texture;
	};
	_Script_RealityStream_eventOnTextureReceived_Parms Parms;
	Parms.Texture=Texture;
	OnTextureReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTextureReceived ******************************************************

// ********** Begin Delegate FOnConnectionStatusChanged ********************************************
struct Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics
{
	struct _Script_RealityStream_eventOnConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when a connection status changes\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
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
void Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((_Script_RealityStream_eventOnConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_RealityStream_eventOnConnectionStatusChanged_Parms), &Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_RealityStream, nullptr, "OnConnectionStatusChanged__DelegateSignature", Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::_Script_RealityStream_eventOnConnectionStatusChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::_Script_RealityStream_eventOnConnectionStatusChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnConnectionStatusChanged_DelegateWrapper(const FMulticastScriptDelegate& OnConnectionStatusChanged, bool bConnected)
{
	struct _Script_RealityStream_eventOnConnectionStatusChanged_Parms
	{
		bool bConnected;
	};
	_Script_RealityStream_eventOnConnectionStatusChanged_Parms Parms;
	Parms.bConnected=bConnected ? true : false;
	OnConnectionStatusChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnConnectionStatusChanged **********************************************

// ********** Begin Delegate FOnError **************************************************************
struct Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics
{
	struct _Script_RealityStream_eventOnError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event for when an error occurs\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_RealityStream_eventOnError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_RealityStream, nullptr, "OnError__DelegateSignature", Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::_Script_RealityStream_eventOnError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::_Script_RealityStream_eventOnError_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnError_DelegateWrapper(const FMulticastScriptDelegate& OnError, const FString& ErrorMessage)
{
	struct _Script_RealityStream_eventOnError_Parms
	{
		FString ErrorMessage;
	};
	_Script_RealityStream_eventOnError_Parms Parms;
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
		Z_Registration_Info_UEnum_EComfyChannel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_RealityStream_EComfyChannel, (UObject*)Z_Construct_UPackage__Script_RealityStream(), TEXT("EComfyChannel"));
	}
	return Z_Registration_Info_UEnum_EComfyChannel.OuterSingleton;
}
template<> REALITYSTREAM_API UEnum* StaticEnum<EComfyChannel>()
{
	return EComfyChannel_StaticEnum();
}
struct Z_Construct_UEnum_RealityStream_EComfyChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//one channel, segmentation \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
		{ "Segmentation.DisplayName", "Segmentation Channel" },
		{ "Segmentation.Name", "EComfyChannel::Segmentation" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "one channel, segmentation" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EComfyChannel::Segmentation", (int64)EComfyChannel::Segmentation },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_RealityStream,
	nullptr,
	"EComfyChannel",
	"EComfyChannel",
	Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_RealityStream_EComfyChannel()
{
	if (!Z_Registration_Info_UEnum_EComfyChannel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EComfyChannel.InnerSingleton, Z_Construct_UEnum_RealityStream_EComfyChannel_Statics::EnumParams);
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
		Z_Registration_Info_UEnum_EComfyConnectionStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_RealityStream_EComfyConnectionStatus, (UObject*)Z_Construct_UPackage__Script_RealityStream(), TEXT("EComfyConnectionStatus"));
	}
	return Z_Registration_Info_UEnum_EComfyConnectionStatus.OuterSingleton;
}
template<> REALITYSTREAM_API UEnum* StaticEnum<EComfyConnectionStatus>()
{
	return EComfyConnectionStatus_StaticEnum();
}
struct Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics
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
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
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
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_RealityStream,
	nullptr,
	"EComfyConnectionStatus",
	"EComfyConnectionStatus",
	Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_RealityStream_EComfyConnectionStatus()
{
	if (!Z_Registration_Info_UEnum_EComfyConnectionStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EComfyConnectionStatus.InnerSingleton, Z_Construct_UEnum_RealityStream_EComfyConnectionStatus_Statics::EnumParams);
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
		Z_Registration_Info_UScriptStruct_FComfyStreamConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FComfyStreamConfig, (UObject*)Z_Construct_UPackage__Script_RealityStream(), TEXT("ComfyStreamConfig"));
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
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration structure for ComfyUI connection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerURL_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Base URL for ComfyUI WebViewer WebSocket server\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base URL for ComfyUI WebViewer WebSocket server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChannelNumber_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Channel number for this stream\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel number for this stream" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChannelType_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Channel type\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PingInterval_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Keep-alive ping interval in seconds\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keep-alive ping interval in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoReconnect_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Auto-reconnect on disconnect\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-reconnect on disconnect" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconnectDelay_MetaData[] = {
		{ "Category", "ComfyUI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reconnect delay in seconds\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reconnect delay in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableLerpSmoothing_MetaData[] = {
		{ "Category", "ComfyUI|Interpolation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enable smooth interpolation between texture updates\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable smooth interpolation between texture updates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LerpSpeed_MetaData[] = {
		{ "Category", "ComfyUI|Interpolation" },
		{ "ClampMax", "20.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Lerp speed (alpha per second). Higher = faster blend.\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lerp speed (alpha per second). Higher = faster blend." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LerpThreshold_MetaData[] = {
		{ "Category", "ComfyUI|Interpolation" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.001" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Threshold for considering lerp complete (0-1)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Threshold for considering lerp complete (0-1)" },
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
	static void NewProp_bEnableLerpSmoothing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableLerpSmoothing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LerpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LerpThreshold;
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
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType = { "ChannelType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ChannelType), Z_Construct_UEnum_RealityStream_EComfyChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChannelType_MetaData), NewProp_ChannelType_MetaData) }; // 3976293377
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_PingInterval = { "PingInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, PingInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PingInterval_MetaData), NewProp_PingInterval_MetaData) };
void Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect_SetBit(void* Obj)
{
	((FComfyStreamConfig*)Obj)->bAutoReconnect = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect = { "bAutoReconnect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FComfyStreamConfig), &Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoReconnect_MetaData), NewProp_bAutoReconnect_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ReconnectDelay = { "ReconnectDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, ReconnectDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconnectDelay_MetaData), NewProp_ReconnectDelay_MetaData) };
void Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bEnableLerpSmoothing_SetBit(void* Obj)
{
	((FComfyStreamConfig*)Obj)->bEnableLerpSmoothing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bEnableLerpSmoothing = { "bEnableLerpSmoothing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FComfyStreamConfig), &Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bEnableLerpSmoothing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableLerpSmoothing_MetaData), NewProp_bEnableLerpSmoothing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_LerpSpeed = { "LerpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, LerpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LerpSpeed_MetaData), NewProp_LerpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_LerpThreshold = { "LerpThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyStreamConfig, LerpThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LerpThreshold_MetaData), NewProp_LerpThreshold_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ServerURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ChannelType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_PingInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bAutoReconnect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_ReconnectDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_bEnableLerpSmoothing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_LerpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewProp_LerpThreshold,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
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

// ********** Begin ScriptStruct FComfyLerpState ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FComfyLerpState;
class UScriptStruct* FComfyLerpState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyLerpState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FComfyLerpState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FComfyLerpState, (UObject*)Z_Construct_UPackage__Script_RealityStream(), TEXT("ComfyLerpState"));
	}
	return Z_Registration_Info_UScriptStruct_FComfyLerpState.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FComfyLerpState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Structure for managing lerp-based texture transitions\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure for managing lerp-based texture transitions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTexture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current texture being displayed\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current texture being displayed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetTexture_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Target texture to lerp towards\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target texture to lerp towards" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAlpha_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current lerp alpha (0-1)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current lerp alpha (0-1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsLerping_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Whether we're currently lerping\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether we're currently lerping" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetTexture;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentAlpha;
	static void NewProp_bIsLerping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLerping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FComfyLerpState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_CurrentTexture = { "CurrentTexture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyLerpState, CurrentTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTexture_MetaData), NewProp_CurrentTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_TargetTexture = { "TargetTexture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyLerpState, TargetTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetTexture_MetaData), NewProp_TargetTexture_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_CurrentAlpha = { "CurrentAlpha", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FComfyLerpState, CurrentAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAlpha_MetaData), NewProp_CurrentAlpha_MetaData) };
void Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_bIsLerping_SetBit(void* Obj)
{
	((FComfyLerpState*)Obj)->bIsLerping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_bIsLerping = { "bIsLerping", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FComfyLerpState), &Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_bIsLerping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsLerping_MetaData), NewProp_bIsLerping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FComfyLerpState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_CurrentTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_TargetTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_CurrentAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewProp_bIsLerping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyLerpState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FComfyLerpState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
	nullptr,
	&NewStructOps,
	"ComfyLerpState",
	Z_Construct_UScriptStruct_FComfyLerpState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyLerpState_Statics::PropPointers),
	sizeof(FComfyLerpState),
	alignof(FComfyLerpState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FComfyLerpState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FComfyLerpState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FComfyLerpState()
{
	if (!Z_Registration_Info_UScriptStruct_FComfyLerpState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FComfyLerpState.InnerSingleton, Z_Construct_UScriptStruct_FComfyLerpState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FComfyLerpState.InnerSingleton;
}
// ********** End ScriptStruct FComfyLerpState *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EComfyChannel_StaticEnum, TEXT("EComfyChannel"), &Z_Registration_Info_UEnum_EComfyChannel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3976293377U) },
		{ EComfyConnectionStatus_StaticEnum, TEXT("EComfyConnectionStatus"), &Z_Registration_Info_UEnum_EComfyConnectionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3105149635U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FComfyStreamConfig::StaticStruct, Z_Construct_UScriptStruct_FComfyStreamConfig_Statics::NewStructOps, TEXT("ComfyStreamConfig"), &Z_Registration_Info_UScriptStruct_FComfyStreamConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FComfyStreamConfig), 306865604U) },
		{ FComfyLerpState::StaticStruct, Z_Construct_UScriptStruct_FComfyLerpState_Statics::NewStructOps, TEXT("ComfyLerpState"), &Z_Registration_Info_UScriptStruct_FComfyLerpState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FComfyLerpState), 2365986095U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_2008314646(TEXT("/Script/RealityStream"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h__Script_RealityStream_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

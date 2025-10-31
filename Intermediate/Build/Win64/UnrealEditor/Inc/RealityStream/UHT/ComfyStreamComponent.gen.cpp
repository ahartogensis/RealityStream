// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyStreamComponent.h"
#include "ComfyStream/ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyStreamComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyImageFetcher_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister();
REALITYSTREAM_API UEnum* Z_Construct_UEnum_RealityStream_EComfyConnectionStatus();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature();
REALITYSTREAM_API UFunction* Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyStreamComponent Function Connect ***********************************
struct Z_Construct_UFunction_UComfyStreamComponent_Connect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Connection control\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connection control" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_Connect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "Connect", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_Connect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_Connect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyStreamComponent_Connect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_Connect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execConnect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Connect();
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function Connect *************************************

// ********** Begin Class UComfyStreamComponent Function Disconnect ********************************
struct Z_Construct_UFunction_UComfyStreamComponent_Disconnect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_Disconnect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "Disconnect", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_Disconnect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_Disconnect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyStreamComponent_Disconnect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_Disconnect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execDisconnect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Disconnect();
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function Disconnect **********************************

// ********** Begin Class UComfyStreamComponent Function GetConnectionStatus ***********************
struct Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics
{
	struct ComfyStreamComponent_eventGetConnectionStatus_Parms
	{
		EComfyConnectionStatus ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamComponent_eventGetConnectionStatus_Parms, ReturnValue), Z_Construct_UEnum_RealityStream_EComfyConnectionStatus, METADATA_PARAMS(0, nullptr) }; // 3105149635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "GetConnectionStatus", Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::ComfyStreamComponent_eventGetConnectionStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::ComfyStreamComponent_eventGetConnectionStatus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execGetConnectionStatus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EComfyConnectionStatus*)Z_Param__Result=P_THIS->GetConnectionStatus();
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function GetConnectionStatus *************************

// ********** Begin Class UComfyStreamComponent Function IsConnected *******************************
struct Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics
{
	struct ComfyStreamComponent_eventIsConnected_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ComfyStreamComponent_eventIsConnected_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamComponent_eventIsConnected_Parms), &Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "IsConnected", Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::ComfyStreamComponent_eventIsConnected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::ComfyStreamComponent_eventIsConnected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyStreamComponent_IsConnected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_IsConnected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execIsConnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsConnected();
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function IsConnected *********************************

// ********** Begin Class UComfyStreamComponent Function OnConnectionStatusChangedInternal *********
struct Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics
{
	struct ComfyStreamComponent_eventOnConnectionStatusChangedInternal_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamComponent_eventOnConnectionStatusChangedInternal_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamComponent_eventOnConnectionStatusChangedInternal_Parms), &Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "OnConnectionStatusChangedInternal", Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::ComfyStreamComponent_eventOnConnectionStatusChangedInternal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::ComfyStreamComponent_eventOnConnectionStatusChangedInternal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execOnConnectionStatusChangedInternal)
{
	P_GET_UBOOL(Z_Param_bConnected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnConnectionStatusChangedInternal(Z_Param_bConnected);
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function OnConnectionStatusChangedInternal ***********

// ********** Begin Class UComfyStreamComponent Function OnErrorInternal ***************************
struct Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics
{
	struct ComfyStreamComponent_eventOnErrorInternal_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamComponent_eventOnErrorInternal_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "OnErrorInternal", Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::ComfyStreamComponent_eventOnErrorInternal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::ComfyStreamComponent_eventOnErrorInternal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execOnErrorInternal)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnErrorInternal(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function OnErrorInternal *****************************

// ********** Begin Class UComfyStreamComponent Function OnTextureReceivedInternal *****************
struct Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics
{
	struct ComfyStreamComponent_eventOnTextureReceivedInternal_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamComponent_eventOnTextureReceivedInternal_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyStreamComponent, nullptr, "OnTextureReceivedInternal", Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::ComfyStreamComponent_eventOnTextureReceivedInternal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::ComfyStreamComponent_eventOnTextureReceivedInternal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyStreamComponent::execOnTextureReceivedInternal)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTextureReceivedInternal(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class UComfyStreamComponent Function OnTextureReceivedInternal *******************

// ********** Begin Class UComfyStreamComponent ****************************************************
void UComfyStreamComponent::StaticRegisterNativesUComfyStreamComponent()
{
	UClass* Class = UComfyStreamComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Connect", &UComfyStreamComponent::execConnect },
		{ "Disconnect", &UComfyStreamComponent::execDisconnect },
		{ "GetConnectionStatus", &UComfyStreamComponent::execGetConnectionStatus },
		{ "IsConnected", &UComfyStreamComponent::execIsConnected },
		{ "OnConnectionStatusChangedInternal", &UComfyStreamComponent::execOnConnectionStatusChangedInternal },
		{ "OnErrorInternal", &UComfyStreamComponent::execOnErrorInternal },
		{ "OnTextureReceivedInternal", &UComfyStreamComponent::execOnTextureReceivedInternal },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyStreamComponent;
UClass* UComfyStreamComponent::GetPrivateStaticClass()
{
	using TClass = UComfyStreamComponent;
	if (!Z_Registration_Info_UClass_UComfyStreamComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyStreamComponent"),
			Z_Registration_Info_UClass_UComfyStreamComponent.InnerSingleton,
			StaticRegisterNativesUComfyStreamComponent,
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
	return Z_Registration_Info_UClass_UComfyStreamComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister()
{
	return UComfyStreamComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyStreamComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Connects to one ComfyUI websocket channel and sets up texture broadcasting \n//pairs textures as they arrive \n" },
#endif
		{ "IncludePath", "ComfyStream/ComfyStreamComponent.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connects to one ComfyUI websocket channel and sets up texture broadcasting\npairs textures as they arrive" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextureReceived_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Events\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Events" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnConnectionStatusChanged_MetaData[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StreamConfig_MetaData[] = {
		{ "Category", "ComfyStream" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//before BeginPlay, connect configs \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "before BeginPlay, connect configs" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FocalScale_MetaData[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Intrinsics knobs for DepthAnything webcam\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Intrinsics knobs for DepthAnything webcam" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepthScaleUnits_MetaData[] = {
		{ "Category", "Reconstruction" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageFetcher_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PngDecoder_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectionStatus_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ComfyStream" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextureReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectionStatusChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StreamConfig;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FocalScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthScaleUnits;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageFetcher;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PngDecoder;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ConnectionStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ConnectionStatus;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComfyStreamComponent_Connect, "Connect" }, // 3362760747
		{ &Z_Construct_UFunction_UComfyStreamComponent_Disconnect, "Disconnect" }, // 4178421443
		{ &Z_Construct_UFunction_UComfyStreamComponent_GetConnectionStatus, "GetConnectionStatus" }, // 3497519130
		{ &Z_Construct_UFunction_UComfyStreamComponent_IsConnected, "IsConnected" }, // 3688680935
		{ &Z_Construct_UFunction_UComfyStreamComponent_OnConnectionStatusChangedInternal, "OnConnectionStatusChangedInternal" }, // 4045117169
		{ &Z_Construct_UFunction_UComfyStreamComponent_OnErrorInternal, "OnErrorInternal" }, // 3062893290
		{ &Z_Construct_UFunction_UComfyStreamComponent_OnTextureReceivedInternal, "OnTextureReceivedInternal" }, // 1914042203
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyStreamComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnTextureReceived = { "OnTextureReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, OnTextureReceived), Z_Construct_UDelegateFunction_RealityStream_OnTextureReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextureReceived_MetaData), NewProp_OnTextureReceived_MetaData) }; // 3136099786
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnConnectionStatusChanged = { "OnConnectionStatusChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, OnConnectionStatusChanged), Z_Construct_UDelegateFunction_RealityStream_OnConnectionStatusChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnConnectionStatusChanged_MetaData), NewProp_OnConnectionStatusChanged_MetaData) }; // 692129119
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, OnError), Z_Construct_UDelegateFunction_RealityStream_OnError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 2422426028
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_StreamConfig = { "StreamConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, StreamConfig), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StreamConfig_MetaData), NewProp_StreamConfig_MetaData) }; // 306865604
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_FocalScale = { "FocalScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, FocalScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FocalScale_MetaData), NewProp_FocalScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_DepthScaleUnits = { "DepthScaleUnits", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, DepthScaleUnits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepthScaleUnits_MetaData), NewProp_DepthScaleUnits_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ImageFetcher = { "ImageFetcher", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, ImageFetcher), Z_Construct_UClass_UComfyImageFetcher_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageFetcher_MetaData), NewProp_ImageFetcher_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_PngDecoder = { "PngDecoder", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, PngDecoder), Z_Construct_UClass_UComfyPngDecoder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PngDecoder_MetaData), NewProp_PngDecoder_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ConnectionStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ConnectionStatus = { "ConnectionStatus", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyStreamComponent, ConnectionStatus), Z_Construct_UEnum_RealityStream_EComfyConnectionStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectionStatus_MetaData), NewProp_ConnectionStatus_MetaData) }; // 3105149635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComfyStreamComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnTextureReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnConnectionStatusChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_OnError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_StreamConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_FocalScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_DepthScaleUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ImageFetcher,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_PngDecoder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ConnectionStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyStreamComponent_Statics::NewProp_ConnectionStatus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyStreamComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UComfyStreamComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyStreamComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyStreamComponent_Statics::ClassParams = {
	&UComfyStreamComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UComfyStreamComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UComfyStreamComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyStreamComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyStreamComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyStreamComponent()
{
	if (!Z_Registration_Info_UClass_UComfyStreamComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyStreamComponent.OuterSingleton, Z_Construct_UClass_UComfyStreamComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyStreamComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyStreamComponent);
UComfyStreamComponent::~UComfyStreamComponent() {}
// ********** End Class UComfyStreamComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyStreamComponent, UComfyStreamComponent::StaticClass, TEXT("UComfyStreamComponent"), &Z_Registration_Info_UClass_UComfyStreamComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyStreamComponent), 2228085278U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h__Script_RealityStream_4091026607(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

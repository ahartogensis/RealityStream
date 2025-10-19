// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyHttpClient.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyHttpClient() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyHttpClient();
COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyHttpClient_NoRegister();
COMFYSTREAM_API UFunction* Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyHttpClient Function GetHistory *************************************
struct Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics
{
	struct ComfyHttpClient_eventGetHistory_Parms
	{
		FString PromptID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
		{ "CPP_Default_PromptID", "" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PromptID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::NewProp_PromptID = { "PromptID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyHttpClient_eventGetHistory_Parms, PromptID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptID_MetaData), NewProp_PromptID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::NewProp_PromptID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "GetHistory", Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::ComfyHttpClient_eventGetHistory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::ComfyHttpClient_eventGetHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyHttpClient_GetHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_GetHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execGetHistory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PromptID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetHistory(Z_Param_PromptID);
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function GetHistory ***************************************

// ********** Begin Class UComfyHttpClient Function GetQueueStatus *********************************
struct Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "GetQueueStatus", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execGetQueueStatus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetQueueStatus();
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function GetQueueStatus ***********************************

// ********** Begin Class UComfyHttpClient Function GetServerURL ***********************************
struct Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics
{
	struct ComfyHttpClient_eventGetServerURL_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyHttpClient_eventGetServerURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "GetServerURL", Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::ComfyHttpClient_eventGetServerURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::ComfyHttpClient_eventGetServerURL_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyHttpClient_GetServerURL()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_GetServerURL_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execGetServerURL)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetServerURL();
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function GetServerURL *************************************

// ********** Begin Class UComfyHttpClient Function GetSystemStats *********************************
struct Z_Construct_UFunction_UComfyHttpClient_GetSystemStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_GetSystemStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "GetSystemStats", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_GetSystemStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_GetSystemStats_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyHttpClient_GetSystemStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_GetSystemStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execGetSystemStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetSystemStats();
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function GetSystemStats ***********************************

// ********** Begin Class UComfyHttpClient Function InterruptQueue *********************************
struct Z_Construct_UFunction_UComfyHttpClient_InterruptQueue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_InterruptQueue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "InterruptQueue", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_InterruptQueue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_InterruptQueue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UComfyHttpClient_InterruptQueue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_InterruptQueue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execInterruptQueue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InterruptQueue();
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function InterruptQueue ***********************************

// ********** Begin Class UComfyHttpClient Function SendPrompt *************************************
struct Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics
{
	struct ComfyHttpClient_eventSendPrompt_Parms
	{
		FString PromptJSON;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// HTTP functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HTTP functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptJSON_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PromptJSON;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::NewProp_PromptJSON = { "PromptJSON", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyHttpClient_eventSendPrompt_Parms, PromptJSON), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptJSON_MetaData), NewProp_PromptJSON_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::NewProp_PromptJSON,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "SendPrompt", Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::ComfyHttpClient_eventSendPrompt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::ComfyHttpClient_eventSendPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyHttpClient_SendPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_SendPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execSendPrompt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PromptJSON);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendPrompt(Z_Param_PromptJSON);
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function SendPrompt ***************************************

// ********** Begin Class UComfyHttpClient Function SetServerURL ***********************************
struct Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics
{
	struct ComfyHttpClient_eventSetServerURL_Parms
	{
		FString NewServerURL;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComfyHTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Utility functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Utility functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewServerURL_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewServerURL;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::NewProp_NewServerURL = { "NewServerURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyHttpClient_eventSetServerURL_Parms, NewServerURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewServerURL_MetaData), NewProp_NewServerURL_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::NewProp_NewServerURL,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyHttpClient, nullptr, "SetServerURL", Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::ComfyHttpClient_eventSetServerURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::ComfyHttpClient_eventSetServerURL_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyHttpClient_SetServerURL()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyHttpClient_SetServerURL_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyHttpClient::execSetServerURL)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NewServerURL);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetServerURL(Z_Param_NewServerURL);
	P_NATIVE_END;
}
// ********** End Class UComfyHttpClient Function SetServerURL *************************************

// ********** Begin Class UComfyHttpClient *********************************************************
void UComfyHttpClient::StaticRegisterNativesUComfyHttpClient()
{
	UClass* Class = UComfyHttpClient::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetHistory", &UComfyHttpClient::execGetHistory },
		{ "GetQueueStatus", &UComfyHttpClient::execGetQueueStatus },
		{ "GetServerURL", &UComfyHttpClient::execGetServerURL },
		{ "GetSystemStats", &UComfyHttpClient::execGetSystemStats },
		{ "InterruptQueue", &UComfyHttpClient::execInterruptQueue },
		{ "SendPrompt", &UComfyHttpClient::execSendPrompt },
		{ "SetServerURL", &UComfyHttpClient::execSetServerURL },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyHttpClient;
UClass* UComfyHttpClient::GetPrivateStaticClass()
{
	using TClass = UComfyHttpClient;
	if (!Z_Registration_Info_UClass_UComfyHttpClient.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyHttpClient"),
			Z_Registration_Info_UClass_UComfyHttpClient.InnerSingleton,
			StaticRegisterNativesUComfyHttpClient,
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
	return Z_Registration_Info_UClass_UComfyHttpClient.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyHttpClient_NoRegister()
{
	return UComfyHttpClient::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyHttpClient_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * HTTP client for ComfyUI server communication\n * Used for sending prompts, checking status, and other HTTP operations\n */" },
#endif
		{ "IncludePath", "ComfyHttpClient.h" },
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HTTP client for ComfyUI server communication\nUsed for sending prompts, checking status, and other HTTP operations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Events\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Events" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerURL_MetaData[] = {
		{ "Category", "ComfyHTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyHttpClient.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerURL;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComfyHttpClient_GetHistory, "GetHistory" }, // 1053600972
		{ &Z_Construct_UFunction_UComfyHttpClient_GetQueueStatus, "GetQueueStatus" }, // 2785022053
		{ &Z_Construct_UFunction_UComfyHttpClient_GetServerURL, "GetServerURL" }, // 1057291225
		{ &Z_Construct_UFunction_UComfyHttpClient_GetSystemStats, "GetSystemStats" }, // 2194597292
		{ &Z_Construct_UFunction_UComfyHttpClient_InterruptQueue, "InterruptQueue" }, // 116903380
		{ &Z_Construct_UFunction_UComfyHttpClient_SendPrompt, "SendPrompt" }, // 825901849
		{ &Z_Construct_UFunction_UComfyHttpClient_SetServerURL, "SetServerURL" }, // 2587416647
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyHttpClient>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UComfyHttpClient_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyHttpClient, OnError), Z_Construct_UDelegateFunction_ComfyStream_OnError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 822237839
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UComfyHttpClient_Statics::NewProp_ServerURL = { "ServerURL", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyHttpClient, ServerURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerURL_MetaData), NewProp_ServerURL_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComfyHttpClient_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyHttpClient_Statics::NewProp_OnError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyHttpClient_Statics::NewProp_ServerURL,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyHttpClient_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UComfyHttpClient_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyHttpClient_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyHttpClient_Statics::ClassParams = {
	&UComfyHttpClient::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UComfyHttpClient_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UComfyHttpClient_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyHttpClient_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyHttpClient_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyHttpClient()
{
	if (!Z_Registration_Info_UClass_UComfyHttpClient.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyHttpClient.OuterSingleton, Z_Construct_UClass_UComfyHttpClient_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyHttpClient.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyHttpClient);
UComfyHttpClient::~UComfyHttpClient() {}
// ********** End Class UComfyHttpClient ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyHttpClient_h__Script_ComfyStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyHttpClient, UComfyHttpClient::StaticClass, TEXT("UComfyHttpClient"), &Z_Registration_Info_UClass_UComfyHttpClient, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyHttpClient), 2896388652U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyHttpClient_h__Script_ComfyStream_3624713655(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyHttpClient_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyUI_streaming_plugin_for_unreal_main_Source_ComfyStream_Public_ComfyHttpClient_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

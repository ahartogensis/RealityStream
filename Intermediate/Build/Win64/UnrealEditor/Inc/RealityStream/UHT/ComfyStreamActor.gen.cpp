// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyStreamActor.h"
#include "ComfyStream/ComfyFrameBundle.h"
#include "ComfyStream/ComfyStreamTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyStreamActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor();
REALITYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyFrameBuffer_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyReconstruction_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyFrame();
REALITYSTREAM_API UScriptStruct* Z_Construct_UScriptStruct_FComfyStreamConfig();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AComfyStreamActor Function ConnectSegmentationChannel ********************
struct Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//connect and disconnect functions \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "connect and disconnect functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "ConnectSegmentationChannel", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execConnectSegmentationChannel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectSegmentationChannel();
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function ConnectSegmentationChannel **********************

// ********** Begin Class AComfyStreamActor Function DisconnectAll *********************************
struct Z_Construct_UFunction_AComfyStreamActor_DisconnectAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
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

// ********** Begin Class AComfyStreamActor Function HandleConnectionChanged ***********************
struct Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics
{
	struct ComfyStreamActor_eventHandleConnectionChanged_Parms
	{
		bool bConnected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventHandleConnectionChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventHandleConnectionChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::NewProp_bConnected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "HandleConnectionChanged", Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::ComfyStreamActor_eventHandleConnectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::ComfyStreamActor_eventHandleConnectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execHandleConnectionChanged)
{
	P_GET_UBOOL(Z_Param_bConnected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleConnectionChanged(Z_Param_bConnected);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function HandleConnectionChanged *************************

// ********** Begin Class AComfyStreamActor Function HandleFullFrame *******************************
struct Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics
{
	struct ComfyStreamActor_eventHandleFullFrame_Parms
	{
		FComfyFrame Frame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//When FrameBuffer emits a complete triplet\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When FrameBuffer emits a complete triplet" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frame_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Frame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::NewProp_Frame = { "Frame", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventHandleFullFrame_Parms, Frame), Z_Construct_UScriptStruct_FComfyFrame, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frame_MetaData), NewProp_Frame_MetaData) }; // 493399616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::NewProp_Frame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "HandleFullFrame", Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::ComfyStreamActor_eventHandleFullFrame_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::ComfyStreamActor_eventHandleFullFrame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execHandleFullFrame)
{
	P_GET_STRUCT_REF(FComfyFrame,Z_Param_Out_Frame);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFullFrame(Z_Param_Out_Frame);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function HandleFullFrame *********************************

// ********** Begin Class AComfyStreamActor Function HandleStreamError *****************************
struct Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics
{
	struct ComfyStreamActor_eventHandleStreamError_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventHandleStreamError_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "HandleStreamError", Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::ComfyStreamActor_eventHandleStreamError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::ComfyStreamActor_eventHandleStreamError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_HandleStreamError()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_HandleStreamError_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execHandleStreamError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStreamError(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function HandleStreamError *******************************

// ********** Begin Class AComfyStreamActor Function HandleStreamTexture ***************************
struct Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics
{
	struct ComfyStreamActor_eventHandleStreamTexture_Parms
	{
		UTexture2D* Texture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Internal helper functions (must be UFUNCTION for dynamic delegate binding)\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal helper functions (must be UFUNCTION for dynamic delegate binding)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventHandleStreamTexture_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AComfyStreamActor, nullptr, "HandleStreamTexture", Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::PropPointers), sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::ComfyStreamActor_eventHandleStreamTexture_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::ComfyStreamActor_eventHandleStreamTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AComfyStreamActor::execHandleStreamTexture)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStreamTexture(Z_Param_Texture);
	P_NATIVE_END;
}
// ********** End Class AComfyStreamActor Function HandleStreamTexture *****************************

// ********** Begin Class AComfyStreamActor Function OnConnectionStatusChanged *********************
struct ComfyStreamActor_eventOnConnectionStatusChanged_Parms
{
	bool bConnected;
};
static FName NAME_AComfyStreamActor_OnConnectionStatusChanged = FName(TEXT("OnConnectionStatusChanged"));
void AComfyStreamActor::OnConnectionStatusChanged(bool bConnected)
{
	ComfyStreamActor_eventOnConnectionStatusChanged_Parms Parms;
	Parms.bConnected=bConnected ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnConnectionStatusChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConnected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected_SetBit(void* Obj)
{
	((ComfyStreamActor_eventOnConnectionStatusChanged_Parms*)Obj)->bConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected = { "bConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyStreamActor_eventOnConnectionStatusChanged_Parms), &Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged_Statics::NewProp_bConnected,
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

// ********** Begin Class AComfyStreamActor Function OnError ***************************************
struct ComfyStreamActor_eventOnError_Parms
{
	FString ErrorMessage;
};
static FName NAME_AComfyStreamActor_OnError = FName(TEXT("OnError"));
void AComfyStreamActor::OnError(const FString& ErrorMessage)
{
	ComfyStreamActor_eventOnError_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnError);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnError_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnError_Statics::NewProp_ErrorMessage,
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

// ********** Begin Class AComfyStreamActor Function OnTextureReceived *****************************
struct ComfyStreamActor_eventOnTextureReceived_Parms
{
	UTexture2D* Texture;
};
static FName NAME_AComfyStreamActor_OnTextureReceived = FName(TEXT("OnTextureReceived"));
void AComfyStreamActor::OnTextureReceived(UTexture2D* Texture)
{
	ComfyStreamActor_eventOnTextureReceived_Parms Parms;
	Parms.Texture=Texture;
	UFunction* Func = FindFunctionChecked(NAME_AComfyStreamActor_OnTextureReceived);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Blueprint events \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint events" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyStreamActor_eventOnTextureReceived_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived_Statics::NewProp_Texture,
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
		{ "ConnectSegmentationChannel", &AComfyStreamActor::execConnectSegmentationChannel },
		{ "DisconnectAll", &AComfyStreamActor::execDisconnectAll },
		{ "HandleConnectionChanged", &AComfyStreamActor::execHandleConnectionChanged },
		{ "HandleFullFrame", &AComfyStreamActor::execHandleFullFrame },
		{ "HandleStreamError", &AComfyStreamActor::execHandleStreamError },
		{ "HandleStreamTexture", &AComfyStreamActor::execHandleStreamTexture },
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
		{ "Comment", "//receives 3 texture maps from ComfyUI and applies to to a material \n" },
#endif
		{ "IncludePath", "ComfyStream/ComfyStreamActor.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "receives 3 texture maps from ComfyUI and applies to to a material" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayMesh_MetaData[] = {
		{ "Category", "ComfyStreamActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//visualize streamed textures on display mesh \n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "visualize streamed textures on display mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComfyStreamComponent_MetaData[] = {
		{ "Category", "ComfyStreamActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Comfy stream component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Comfy stream component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMaterial_MetaData[] = {
		{ "Category", "ComfyStreamActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//base material made with parameters RGB, Mask, and Depth\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "base material made with parameters RGB, Mask, and Depth" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SegmentationChannelConfig_MetaData[] = {
		{ "Category", "ComfyStreamActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//network config for segmentation channel\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "network config for segmentation channel" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorLifetimeSeconds_MetaData[] = {
		{ "Category", "Actor Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Actor lifetime and lerp settings\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor lifetime and lerp settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LerpSpeed_MetaData[] = {
		{ "Category", "Actor Spawning" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocationThreshold_MetaData[] = {
		{ "Category", "Actor Spawning" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FadeOutDuration_MetaData[] = {
		{ "Category", "Actor Spawning" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameBuffer_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//External helper functions \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "External helper functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reconstruction_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynMat_MetaData[] = {
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedTextureActors_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Spawned actors from textures\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyStreamActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawned actors from textures" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DisplayMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ComfyStreamComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SegmentationChannelConfig;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActorLifetimeSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LerpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LocationThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FadeOutDuration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FrameBuffer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Reconstruction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedTextureActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedTextureActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AComfyStreamActor_ConnectSegmentationChannel, "ConnectSegmentationChannel" }, // 3495272314
		{ &Z_Construct_UFunction_AComfyStreamActor_DisconnectAll, "DisconnectAll" }, // 2259344126
		{ &Z_Construct_UFunction_AComfyStreamActor_HandleConnectionChanged, "HandleConnectionChanged" }, // 434804821
		{ &Z_Construct_UFunction_AComfyStreamActor_HandleFullFrame, "HandleFullFrame" }, // 833959452
		{ &Z_Construct_UFunction_AComfyStreamActor_HandleStreamError, "HandleStreamError" }, // 4070853282
		{ &Z_Construct_UFunction_AComfyStreamActor_HandleStreamTexture, "HandleStreamTexture" }, // 2571396988
		{ &Z_Construct_UFunction_AComfyStreamActor_OnConnectionStatusChanged, "OnConnectionStatusChanged" }, // 319436288
		{ &Z_Construct_UFunction_AComfyStreamActor_OnError, "OnError" }, // 913022412
		{ &Z_Construct_UFunction_AComfyStreamActor_OnTextureReceived, "OnTextureReceived" }, // 3318474958
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SegmentationChannelConfig = { "SegmentationChannelConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, SegmentationChannelConfig), Z_Construct_UScriptStruct_FComfyStreamConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SegmentationChannelConfig_MetaData), NewProp_SegmentationChannelConfig_MetaData) }; // 306865604
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_ActorLifetimeSeconds = { "ActorLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, ActorLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorLifetimeSeconds_MetaData), NewProp_ActorLifetimeSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LerpSpeed = { "LerpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, LerpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LerpSpeed_MetaData), NewProp_LerpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LocationThreshold = { "LocationThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, LocationThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocationThreshold_MetaData), NewProp_LocationThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_FadeOutDuration = { "FadeOutDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, FadeOutDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FadeOutDuration_MetaData), NewProp_FadeOutDuration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_FrameBuffer = { "FrameBuffer", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, FrameBuffer), Z_Construct_UClass_UComfyFrameBuffer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameBuffer_MetaData), NewProp_FrameBuffer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_Reconstruction = { "Reconstruction", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, Reconstruction), Z_Construct_UClass_UComfyReconstruction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reconstruction_MetaData), NewProp_Reconstruction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DynMat = { "DynMat", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, DynMat), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynMat_MetaData), NewProp_DynMat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedTextureActors_Inner = { "SpawnedTextureActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedTextureActors = { "SpawnedTextureActors", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComfyStreamActor, SpawnedTextureActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedTextureActors_MetaData), NewProp_SpawnedTextureActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DisplayMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_ComfyStreamComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_BaseMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SegmentationChannelConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_ActorLifetimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LerpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_LocationThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_FadeOutDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_FrameBuffer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_Reconstruction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_DynMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedTextureActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComfyStreamActor_Statics::NewProp_SpawnedTextureActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AComfyStreamActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AComfyStreamActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
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
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AComfyStreamActor, AComfyStreamActor::StaticClass, TEXT("AComfyStreamActor"), &Z_Registration_Info_UClass_AComfyStreamActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AComfyStreamActor), 2041762319U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h__Script_RealityStream_3874548032(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

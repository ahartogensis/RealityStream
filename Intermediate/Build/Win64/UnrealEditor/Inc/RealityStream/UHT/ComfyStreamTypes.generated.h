// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStream/ComfyStreamTypes.h"

#ifdef REALITYSTREAM_ComfyStreamTypes_generated_h
#error "ComfyStreamTypes.generated.h already included, missing '#pragma once' in ComfyStreamTypes.h"
#endif
#define REALITYSTREAM_ComfyStreamTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;

// ********** Begin Delegate FOnTextureReceived ****************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h_8_DELEGATE \
REALITYSTREAM_API void FOnTextureReceived_DelegateWrapper(const FMulticastScriptDelegate& OnTextureReceived, UTexture2D* Texture);


// ********** End Delegate FOnTextureReceived ******************************************************

// ********** Begin Delegate FOnConnectionStatusChanged ********************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h_11_DELEGATE \
REALITYSTREAM_API void FOnConnectionStatusChanged_DelegateWrapper(const FMulticastScriptDelegate& OnConnectionStatusChanged, bool bConnected);


// ********** End Delegate FOnConnectionStatusChanged **********************************************

// ********** Begin Delegate FOnError **************************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h_14_DELEGATE \
REALITYSTREAM_API void FOnError_DelegateWrapper(const FMulticastScriptDelegate& OnError, const FString& ErrorMessage);


// ********** End Delegate FOnError ****************************************************************

// ********** Begin ScriptStruct FComfyStreamConfig ************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h_38_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FComfyStreamConfig_Statics; \
	REALITYSTREAM_API static class UScriptStruct* StaticStruct();


struct FComfyStreamConfig;
// ********** End ScriptStruct FComfyStreamConfig **************************************************

// ********** Begin ScriptStruct FComfyLerpState ***************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h_96_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FComfyLerpState_Statics; \
	REALITYSTREAM_API static class UScriptStruct* StaticStruct();


struct FComfyLerpState;
// ********** End ScriptStruct FComfyLerpState *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamTypes_h

// ********** Begin Enum EComfyChannel *************************************************************
#define FOREACH_ENUM_ECOMFYCHANNEL(op) \
	op(EComfyChannel::Segmentation) 

enum class EComfyChannel : uint8;
template<> struct TIsUEnumClass<EComfyChannel> { enum { Value = true }; };
template<> REALITYSTREAM_API UEnum* StaticEnum<EComfyChannel>();
// ********** End Enum EComfyChannel ***************************************************************

// ********** Begin Enum EComfyConnectionStatus ****************************************************
#define FOREACH_ENUM_ECOMFYCONNECTIONSTATUS(op) \
	op(EComfyConnectionStatus::Disconnected) \
	op(EComfyConnectionStatus::Connecting) \
	op(EComfyConnectionStatus::Connected) \
	op(EComfyConnectionStatus::Error) 

enum class EComfyConnectionStatus : uint8;
template<> struct TIsUEnumClass<EComfyConnectionStatus> { enum { Value = true }; };
template<> REALITYSTREAM_API UEnum* StaticEnum<EComfyConnectionStatus>();
// ********** End Enum EComfyConnectionStatus ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

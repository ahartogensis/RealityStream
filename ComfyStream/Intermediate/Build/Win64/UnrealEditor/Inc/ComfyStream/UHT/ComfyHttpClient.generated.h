// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyHttpClient.h"

#ifdef COMFYSTREAM_ComfyHttpClient_generated_h
#error "ComfyHttpClient.generated.h already included, missing '#pragma once' in ComfyHttpClient.h"
#endif
#define COMFYSTREAM_ComfyHttpClient_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UComfyHttpClient *********************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetServerURL); \
	DECLARE_FUNCTION(execSetServerURL); \
	DECLARE_FUNCTION(execGetSystemStats); \
	DECLARE_FUNCTION(execInterruptQueue); \
	DECLARE_FUNCTION(execGetHistory); \
	DECLARE_FUNCTION(execGetQueueStatus); \
	DECLARE_FUNCTION(execSendPrompt);


COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyHttpClient_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComfyHttpClient(); \
	friend struct Z_Construct_UClass_UComfyHttpClient_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyHttpClient_NoRegister(); \
public: \
	DECLARE_CLASS2(UComfyHttpClient, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComfyStream"), Z_Construct_UClass_UComfyHttpClient_NoRegister) \
	DECLARE_SERIALIZER(UComfyHttpClient)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComfyHttpClient(UComfyHttpClient&&) = delete; \
	UComfyHttpClient(const UComfyHttpClient&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComfyHttpClient); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComfyHttpClient); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UComfyHttpClient) \
	NO_API virtual ~UComfyHttpClient();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_14_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComfyHttpClient;

// ********** End Class UComfyHttpClient ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyHttpClient_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

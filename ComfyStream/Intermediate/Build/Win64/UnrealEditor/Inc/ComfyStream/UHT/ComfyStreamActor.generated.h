// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStreamActor.h"

#ifdef COMFYSTREAM_ComfyStreamActor_generated_h
#error "ComfyStreamActor.generated.h already included, missing '#pragma once' in ComfyStreamActor.h"
#endif
#define COMFYSTREAM_ComfyStreamActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;
enum class EComfyChannel : uint8;

// ********** Begin Class AComfyStreamActor ********************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnMaskError); \
	DECLARE_FUNCTION(execOnDepthError); \
	DECLARE_FUNCTION(execOnRGBAError); \
	DECLARE_FUNCTION(execOnMaskConnectionStatusChanged); \
	DECLARE_FUNCTION(execOnDepthConnectionStatusChanged); \
	DECLARE_FUNCTION(execOnRGBAConnectionStatusChanged); \
	DECLARE_FUNCTION(execOnMaskTextureReceived); \
	DECLARE_FUNCTION(execOnDepthTextureReceived); \
	DECLARE_FUNCTION(execOnRGBATextureReceived); \
	DECLARE_FUNCTION(execClearAllSpawnedObjects); \
	DECLARE_FUNCTION(execConnectAllChannels); \
	DECLARE_FUNCTION(execDisconnectAll); \
	DECLARE_FUNCTION(execConnectMaskChannel); \
	DECLARE_FUNCTION(execConnectDepthChannel); \
	DECLARE_FUNCTION(execConnectRGBAChannel);


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_CALLBACK_WRAPPERS
COMFYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAComfyStreamActor(); \
	friend struct Z_Construct_UClass_AComfyStreamActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMFYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AComfyStreamActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ComfyStream"), Z_Construct_UClass_AComfyStreamActor_NoRegister) \
	DECLARE_SERIALIZER(AComfyStreamActor)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AComfyStreamActor(AComfyStreamActor&&) = delete; \
	AComfyStreamActor(const AComfyStreamActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AComfyStreamActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AComfyStreamActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AComfyStreamActor) \
	NO_API virtual ~AComfyStreamActor();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_13_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_CALLBACK_WRAPPERS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AComfyStreamActor;

// ********** End Class AComfyStreamActor **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyStreamActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

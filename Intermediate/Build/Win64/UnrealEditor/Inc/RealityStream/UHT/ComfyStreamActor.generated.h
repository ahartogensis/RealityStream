// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStream/ComfyStreamActor.h"

#ifdef REALITYSTREAM_ComfyStreamActor_generated_h
#error "ComfyStreamActor.generated.h already included, missing '#pragma once' in ComfyStreamActor.h"
#endif
#define REALITYSTREAM_ComfyStreamActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;
struct FComfyFrame;

// ********** Begin Class AComfyStreamActor ********************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleFullFrame); \
	DECLARE_FUNCTION(execHandleStreamError); \
	DECLARE_FUNCTION(execHandleConnectionChanged); \
	DECLARE_FUNCTION(execHandleStreamTexture); \
	DECLARE_FUNCTION(execDisconnectAll); \
	DECLARE_FUNCTION(execConnectSegmentationChannel);


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_CALLBACK_WRAPPERS
REALITYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAComfyStreamActor(); \
	friend struct Z_Construct_UClass_AComfyStreamActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REALITYSTREAM_API UClass* Z_Construct_UClass_AComfyStreamActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AComfyStreamActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RealityStream"), Z_Construct_UClass_AComfyStreamActor_NoRegister) \
	DECLARE_SERIALIZER(AComfyStreamActor)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AComfyStreamActor(AComfyStreamActor&&) = delete; \
	AComfyStreamActor(const AComfyStreamActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AComfyStreamActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AComfyStreamActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AComfyStreamActor) \
	NO_API virtual ~AComfyStreamActor();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_12_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_CALLBACK_WRAPPERS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AComfyStreamActor;

// ********** End Class AComfyStreamActor **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

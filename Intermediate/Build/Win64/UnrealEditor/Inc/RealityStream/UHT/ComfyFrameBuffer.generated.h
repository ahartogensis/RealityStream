// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStream/ComfyFrameBuffer.h"

#ifdef REALITYSTREAM_ComfyFrameBuffer_generated_h
#error "ComfyFrameBuffer.generated.h already included, missing '#pragma once' in ComfyFrameBuffer.h"
#endif
#define REALITYSTREAM_ComfyFrameBuffer_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FComfyFrame;

// ********** Begin Delegate FOnFullFrameReady *****************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_8_DELEGATE \
REALITYSTREAM_API void FOnFullFrameReady_DelegateWrapper(const FMulticastScriptDelegate& OnFullFrameReady, FComfyFrame const& Frame);


// ********** End Delegate FOnFullFrameReady *******************************************************

// ********** Begin Class UComfyFrameBuffer ********************************************************
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyFrameBuffer_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComfyFrameBuffer(); \
	friend struct Z_Construct_UClass_UComfyFrameBuffer_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyFrameBuffer_NoRegister(); \
public: \
	DECLARE_CLASS2(UComfyFrameBuffer, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RealityStream"), Z_Construct_UClass_UComfyFrameBuffer_NoRegister) \
	DECLARE_SERIALIZER(UComfyFrameBuffer)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UComfyFrameBuffer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComfyFrameBuffer(UComfyFrameBuffer&&) = delete; \
	UComfyFrameBuffer(const UComfyFrameBuffer&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComfyFrameBuffer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComfyFrameBuffer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UComfyFrameBuffer) \
	NO_API virtual ~UComfyFrameBuffer();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_10_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComfyFrameBuffer;

// ********** End Class UComfyFrameBuffer **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyFrameBuffer_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

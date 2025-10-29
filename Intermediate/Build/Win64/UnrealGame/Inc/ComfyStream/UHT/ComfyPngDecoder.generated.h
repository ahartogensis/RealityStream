// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyPngDecoder.h"

#ifdef COMFYSTREAM_ComfyPngDecoder_generated_h
#error "ComfyPngDecoder.generated.h already included, missing '#pragma once' in ComfyPngDecoder.h"
#endif
#define COMFYSTREAM_ComfyPngDecoder_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;

// ********** Begin Class UComfyPngDecoder *********************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsValidJPEGData); \
	DECLARE_FUNCTION(execIsValidPNGData); \
	DECLARE_FUNCTION(execDecodePNGToTextureWithFormat); \
	DECLARE_FUNCTION(execDecodePNGToTexture);


COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComfyPngDecoder(); \
	friend struct Z_Construct_UClass_UComfyPngDecoder_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMFYSTREAM_API UClass* Z_Construct_UClass_UComfyPngDecoder_NoRegister(); \
public: \
	DECLARE_CLASS2(UComfyPngDecoder, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComfyStream"), Z_Construct_UClass_UComfyPngDecoder_NoRegister) \
	DECLARE_SERIALIZER(UComfyPngDecoder)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComfyPngDecoder(UComfyPngDecoder&&) = delete; \
	UComfyPngDecoder(const UComfyPngDecoder&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComfyPngDecoder); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComfyPngDecoder); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UComfyPngDecoder) \
	NO_API virtual ~UComfyPngDecoder();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_11_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComfyPngDecoder;

// ********** End Class UComfyPngDecoder ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_ComfyPngDecoder_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

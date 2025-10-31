// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStream/ComfyReconstruction.h"

#ifdef REALITYSTREAM_ComfyReconstruction_generated_h
#error "ComfyReconstruction.generated.h already included, missing '#pragma once' in ComfyReconstruction.h"
#endif
#define REALITYSTREAM_ComfyReconstruction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;

// ********** Begin Class UComfyReconstruction *****************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAverageNormalizedDepth); \
	DECLARE_FUNCTION(execDepthToWorld); \
	DECLARE_FUNCTION(execEstimateIntrinsics);


REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyReconstruction_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComfyReconstruction(); \
	friend struct Z_Construct_UClass_UComfyReconstruction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyReconstruction_NoRegister(); \
public: \
	DECLARE_CLASS2(UComfyReconstruction, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RealityStream"), Z_Construct_UClass_UComfyReconstruction_NoRegister) \
	DECLARE_SERIALIZER(UComfyReconstruction)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UComfyReconstruction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComfyReconstruction(UComfyReconstruction&&) = delete; \
	UComfyReconstruction(const UComfyReconstruction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComfyReconstruction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComfyReconstruction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UComfyReconstruction) \
	NO_API virtual ~UComfyReconstruction();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_15_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComfyReconstruction;

// ********** End Class UComfyReconstruction *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

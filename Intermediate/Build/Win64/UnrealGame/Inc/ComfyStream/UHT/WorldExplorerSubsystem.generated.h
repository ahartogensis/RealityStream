// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldExplorerSubsystem.h"

#ifdef COMFYSTREAM_WorldExplorerSubsystem_generated_h
#error "WorldExplorerSubsystem.generated.h already included, missing '#pragma once' in WorldExplorerSubsystem.h"
#endif
#define COMFYSTREAM_WorldExplorerSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;

// ********** Begin Class UWorldExplorerSubsystem **************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execProcessVideoToMesh); \
	DECLARE_FUNCTION(execConvertAndSpawnPLY); \
	DECLARE_FUNCTION(execImportAndSpawnOBJMesh); \
	DECLARE_FUNCTION(execConvertPLYToOBJ); \
	DECLARE_FUNCTION(execCheckAndImportSplat); \
	DECLARE_FUNCTION(execRunGaussianSplat); \
	DECLARE_FUNCTION(execImportExistingSplat);


COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWorldExplorerSubsystem(); \
	friend struct Z_Construct_UClass_UWorldExplorerSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UWorldExplorerSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComfyStream"), Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UWorldExplorerSubsystem)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWorldExplorerSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWorldExplorerSubsystem(UWorldExplorerSubsystem&&) = delete; \
	UWorldExplorerSubsystem(const UWorldExplorerSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWorldExplorerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWorldExplorerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWorldExplorerSubsystem) \
	NO_API virtual ~UWorldExplorerSubsystem();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_11_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWorldExplorerSubsystem;

// ********** End Class UWorldExplorerSubsystem ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

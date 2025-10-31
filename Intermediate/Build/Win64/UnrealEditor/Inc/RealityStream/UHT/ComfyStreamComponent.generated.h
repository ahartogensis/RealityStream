// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ComfyStream/ComfyStreamComponent.h"

#ifdef REALITYSTREAM_ComfyStreamComponent_generated_h
#error "ComfyStreamComponent.generated.h already included, missing '#pragma once' in ComfyStreamComponent.h"
#endif
#define REALITYSTREAM_ComfyStreamComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UTexture2D;
enum class EComfyConnectionStatus : uint8;

// ********** Begin Class UComfyStreamComponent ****************************************************
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnErrorInternal); \
	DECLARE_FUNCTION(execOnConnectionStatusChangedInternal); \
	DECLARE_FUNCTION(execOnTextureReceivedInternal); \
	DECLARE_FUNCTION(execGetConnectionStatus); \
	DECLARE_FUNCTION(execIsConnected); \
	DECLARE_FUNCTION(execDisconnect); \
	DECLARE_FUNCTION(execConnect);


REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister();

#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComfyStreamComponent(); \
	friend struct Z_Construct_UClass_UComfyStreamComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyStreamComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UComfyStreamComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RealityStream"), Z_Construct_UClass_UComfyStreamComponent_NoRegister) \
	DECLARE_SERIALIZER(UComfyStreamComponent)


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComfyStreamComponent(UComfyStreamComponent&&) = delete; \
	UComfyStreamComponent(const UComfyStreamComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComfyStreamComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComfyStreamComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UComfyStreamComponent) \
	NO_API virtual ~UComfyStreamComponent();


#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_14_PROLOG
#define FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComfyStreamComponent;

// ********** End Class UComfyStreamComponent ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyStreamComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

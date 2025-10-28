// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldExplorerSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWorldExplorerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem();
COMFYSTREAM_API UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ComfyStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWorldExplorerSubsystem Function CheckAndImportSplat *********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics
{
	struct WorldExplorerSubsystem_eventCheckAndImportSplat_Parms
	{
		FString VideoPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "CPP_Default_VideoPath", "" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventCheckAndImportSplat_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::NewProp_VideoPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "CheckAndImportSplat", Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::WorldExplorerSubsystem_eventCheckAndImportSplat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::WorldExplorerSubsystem_eventCheckAndImportSplat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execCheckAndImportSplat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CheckAndImportSplat(Z_Param_VideoPath);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function CheckAndImportSplat ***********************

// ********** Begin Class UWorldExplorerSubsystem Function ConvertAndSpawnPLY **********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics
{
	struct WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms
	{
		FString PLYPath;
		FVector SpawnLocation;
		FRotator SpawnRotation;
		FVector SpawnScale;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "CPP_Default_SpawnLocation", "" },
		{ "CPP_Default_SpawnRotation", "90.000000,0.000000,0.000000" },
		{ "CPP_Default_SpawnScale", "400.000000,400.000000,400.000000" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PLYPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PLYPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_PLYPath = { "PLYPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms, PLYPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PLYPath_MetaData), NewProp_PLYPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnLocation = { "SpawnLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms, SpawnLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnRotation = { "SpawnRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms, SpawnRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnScale = { "SpawnScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms, SpawnScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_PLYPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::NewProp_SpawnScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ConvertAndSpawnPLY", Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::WorldExplorerSubsystem_eventConvertAndSpawnPLY_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execConvertAndSpawnPLY)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PLYPath);
	P_GET_STRUCT(FVector,Z_Param_SpawnLocation);
	P_GET_STRUCT(FRotator,Z_Param_SpawnRotation);
	P_GET_STRUCT(FVector,Z_Param_SpawnScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConvertAndSpawnPLY(Z_Param_PLYPath,Z_Param_SpawnLocation,Z_Param_SpawnRotation,Z_Param_SpawnScale);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ConvertAndSpawnPLY ************************

// ********** Begin Class UWorldExplorerSubsystem Function ConvertPLYToOBJ *************************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics
{
	struct WorldExplorerSubsystem_eventConvertPLYToOBJ_Parms
	{
		FString PLYPath;
		FString OBJPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PLYPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OBJPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PLYPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OBJPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::NewProp_PLYPath = { "PLYPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertPLYToOBJ_Parms, PLYPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PLYPath_MetaData), NewProp_PLYPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::NewProp_OBJPath = { "OBJPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventConvertPLYToOBJ_Parms, OBJPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OBJPath_MetaData), NewProp_OBJPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::NewProp_PLYPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::NewProp_OBJPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ConvertPLYToOBJ", Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::WorldExplorerSubsystem_eventConvertPLYToOBJ_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::WorldExplorerSubsystem_eventConvertPLYToOBJ_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execConvertPLYToOBJ)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PLYPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_OBJPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConvertPLYToOBJ(Z_Param_PLYPath,Z_Param_OBJPath);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ConvertPLYToOBJ ***************************

// ********** Begin Class UWorldExplorerSubsystem Function ImportAndSpawnOBJMesh *******************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics
{
	struct WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms
	{
		FString OBJPath;
		FVector SpawnLocation;
		FRotator SpawnRotation;
		FVector SpawnScale;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "CPP_Default_SpawnLocation", "" },
		{ "CPP_Default_SpawnRotation", "90.000000,0.000000,0.000000" },
		{ "CPP_Default_SpawnScale", "400.000000,400.000000,400.000000" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OBJPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_OBJPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_OBJPath = { "OBJPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms, OBJPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OBJPath_MetaData), NewProp_OBJPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnLocation = { "SpawnLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms, SpawnLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnRotation = { "SpawnRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms, SpawnRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnScale = { "SpawnScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms, SpawnScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_OBJPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_SpawnScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ImportAndSpawnOBJMesh", Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::WorldExplorerSubsystem_eventImportAndSpawnOBJMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execImportAndSpawnOBJMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_OBJPath);
	P_GET_STRUCT(FVector,Z_Param_SpawnLocation);
	P_GET_STRUCT(FRotator,Z_Param_SpawnRotation);
	P_GET_STRUCT(FVector,Z_Param_SpawnScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->ImportAndSpawnOBJMesh(Z_Param_OBJPath,Z_Param_SpawnLocation,Z_Param_SpawnRotation,Z_Param_SpawnScale);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ImportAndSpawnOBJMesh *********************

// ********** Begin Class UWorldExplorerSubsystem Function ImportExistingSplat *********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// WorldExplorer functionality - Blueprint callable for runtime use\n" },
#endif
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WorldExplorer functionality - Blueprint callable for runtime use" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ImportExistingSplat", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execImportExistingSplat)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ImportExistingSplat();
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ImportExistingSplat ***********************

// ********** Begin Class UWorldExplorerSubsystem Function ProcessVideoToMesh **********************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics
{
	struct WorldExplorerSubsystem_eventProcessVideoToMesh_Parms
	{
		FString VideoPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WorldExplorerSubsystem_eventProcessVideoToMesh_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::NewProp_VideoPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "ProcessVideoToMesh", Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::WorldExplorerSubsystem_eventProcessVideoToMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::WorldExplorerSubsystem_eventProcessVideoToMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execProcessVideoToMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ProcessVideoToMesh(Z_Param_VideoPath);
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function ProcessVideoToMesh ************************

// ********** Begin Class UWorldExplorerSubsystem Function RunGaussianSplat ************************
struct Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WorldExplorer" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWorldExplorerSubsystem, nullptr, "RunGaussianSplat", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWorldExplorerSubsystem::execRunGaussianSplat)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RunGaussianSplat();
	P_NATIVE_END;
}
// ********** End Class UWorldExplorerSubsystem Function RunGaussianSplat **************************

// ********** Begin Class UWorldExplorerSubsystem **************************************************
void UWorldExplorerSubsystem::StaticRegisterNativesUWorldExplorerSubsystem()
{
	UClass* Class = UWorldExplorerSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CheckAndImportSplat", &UWorldExplorerSubsystem::execCheckAndImportSplat },
		{ "ConvertAndSpawnPLY", &UWorldExplorerSubsystem::execConvertAndSpawnPLY },
		{ "ConvertPLYToOBJ", &UWorldExplorerSubsystem::execConvertPLYToOBJ },
		{ "ImportAndSpawnOBJMesh", &UWorldExplorerSubsystem::execImportAndSpawnOBJMesh },
		{ "ImportExistingSplat", &UWorldExplorerSubsystem::execImportExistingSplat },
		{ "ProcessVideoToMesh", &UWorldExplorerSubsystem::execProcessVideoToMesh },
		{ "RunGaussianSplat", &UWorldExplorerSubsystem::execRunGaussianSplat },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWorldExplorerSubsystem;
UClass* UWorldExplorerSubsystem::GetPrivateStaticClass()
{
	using TClass = UWorldExplorerSubsystem;
	if (!Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WorldExplorerSubsystem"),
			Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton,
			StaticRegisterNativesUWorldExplorerSubsystem,
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
	return Z_Registration_Info_UClass_UWorldExplorerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UWorldExplorerSubsystem_NoRegister()
{
	return UWorldExplorerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWorldExplorerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * WorldExplorer subsystem for handling Gaussian splat conversions\n */" },
#endif
		{ "IncludePath", "WorldExplorerSubsystem.h" },
		{ "ModuleRelativePath", "Public/WorldExplorerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WorldExplorer subsystem for handling Gaussian splat conversions" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_CheckAndImportSplat, "CheckAndImportSplat" }, // 647586090
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertAndSpawnPLY, "ConvertAndSpawnPLY" }, // 1023220292
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ConvertPLYToOBJ, "ConvertPLYToOBJ" }, // 1775218876
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ImportAndSpawnOBJMesh, "ImportAndSpawnOBJMesh" }, // 673477442
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ImportExistingSplat, "ImportExistingSplat" }, // 2493624001
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_ProcessVideoToMesh, "ProcessVideoToMesh" }, // 1425344190
		{ &Z_Construct_UFunction_UWorldExplorerSubsystem_RunGaussianSplat, "RunGaussianSplat" }, // 2946863483
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWorldExplorerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UWorldExplorerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ComfyStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldExplorerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWorldExplorerSubsystem_Statics::ClassParams = {
	&UWorldExplorerSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWorldExplorerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UWorldExplorerSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWorldExplorerSubsystem()
{
	if (!Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton, Z_Construct_UClass_UWorldExplorerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWorldExplorerSubsystem.OuterSingleton;
}
UWorldExplorerSubsystem::UWorldExplorerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWorldExplorerSubsystem);
UWorldExplorerSubsystem::~UWorldExplorerSubsystem() {}
// ********** End Class UWorldExplorerSubsystem ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWorldExplorerSubsystem, UWorldExplorerSubsystem::StaticClass, TEXT("UWorldExplorerSubsystem"), &Z_Registration_Info_UClass_UWorldExplorerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWorldExplorerSubsystem), 1969971810U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_2326362450(TEXT("/Script/ComfyStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_ComfyStream_Source_ComfyStream_Public_WorldExplorerSubsystem_h__Script_ComfyStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

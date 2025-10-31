// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComfyStream/ComfyReconstruction.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeComfyReconstruction() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyReconstruction();
REALITYSTREAM_API UClass* Z_Construct_UClass_UComfyReconstruction_NoRegister();
UPackage* Z_Construct_UPackage__Script_RealityStream();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UComfyReconstruction Function AverageNormalizedDepth *********************
struct Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics
{
	struct ComfyReconstruction_eventAverageNormalizedDepth_Parms
	{
		UTexture2D* DepthTex;
		UTexture2D* MaskTex;
		float OutAvgDepth01;
		int32 Step;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Compute normalized depth for masked pixels for speed \n" },
#endif
		{ "CPP_Default_Step", "8" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compute normalized depth for masked pixels for speed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DepthTex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaskTex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutAvgDepth01;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Step;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_DepthTex = { "DepthTex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventAverageNormalizedDepth_Parms, DepthTex), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_MaskTex = { "MaskTex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventAverageNormalizedDepth_Parms, MaskTex), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_OutAvgDepth01 = { "OutAvgDepth01", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventAverageNormalizedDepth_Parms, OutAvgDepth01), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_Step = { "Step", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventAverageNormalizedDepth_Parms, Step), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ComfyReconstruction_eventAverageNormalizedDepth_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ComfyReconstruction_eventAverageNormalizedDepth_Parms), &Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_DepthTex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_MaskTex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_OutAvgDepth01,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_Step,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyReconstruction, nullptr, "AverageNormalizedDepth", Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::ComfyReconstruction_eventAverageNormalizedDepth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::ComfyReconstruction_eventAverageNormalizedDepth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyReconstruction::execAverageNormalizedDepth)
{
	P_GET_OBJECT(UTexture2D,Z_Param_DepthTex);
	P_GET_OBJECT(UTexture2D,Z_Param_MaskTex);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutAvgDepth01);
	P_GET_PROPERTY(FIntProperty,Z_Param_Step);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AverageNormalizedDepth(Z_Param_DepthTex,Z_Param_MaskTex,Z_Param_Out_OutAvgDepth01,Z_Param_Step);
	P_NATIVE_END;
}
// ********** End Class UComfyReconstruction Function AverageNormalizedDepth ***********************

// ********** Begin Class UComfyReconstruction Function DepthToWorld *******************************
struct Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics
{
	struct ComfyReconstruction_eventDepthToWorld_Parms
	{
		int32 Px;
		int32 Py;
		float DepthUnits;
		int32 Width;
		int32 Height;
		float Fx;
		float Fy;
		float Cx;
		float Cy;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Convert pixel + depth to world space \n// returns vector in UE coords: Z forward, X right, Y up \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert pixel + depth to world space\nreturns vector in UE coords: Z forward, X right, Y up" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Px;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Py;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthUnits;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Fx;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Fy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Cx;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Cy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Px = { "Px", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Px), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Py = { "Py", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Py), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_DepthUnits = { "DepthUnits", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, DepthUnits), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Width), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Fx = { "Fx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Fx), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Fy = { "Fy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Fy), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Cx = { "Cx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Cx), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Cy = { "Cy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, Cy), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventDepthToWorld_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Px,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Py,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_DepthUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Width,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Fx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Fy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Cx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_Cy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyReconstruction, nullptr, "DepthToWorld", Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::ComfyReconstruction_eventDepthToWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::ComfyReconstruction_eventDepthToWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyReconstruction_DepthToWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyReconstruction_DepthToWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyReconstruction::execDepthToWorld)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Px);
	P_GET_PROPERTY(FIntProperty,Z_Param_Py);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DepthUnits);
	P_GET_PROPERTY(FIntProperty,Z_Param_Width);
	P_GET_PROPERTY(FIntProperty,Z_Param_Height);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Fx);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Fy);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Cx);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Cy);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->DepthToWorld(Z_Param_Px,Z_Param_Py,Z_Param_DepthUnits,Z_Param_Width,Z_Param_Height,Z_Param_Fx,Z_Param_Fy,Z_Param_Cx,Z_Param_Cy);
	P_NATIVE_END;
}
// ********** End Class UComfyReconstruction Function DepthToWorld *********************************

// ********** Begin Class UComfyReconstruction Function EstimateIntrinsics *************************
struct Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics
{
	struct ComfyReconstruction_eventEstimateIntrinsics_Parms
	{
		int32 Width;
		int32 Height;
		float OutFx;
		float OutFy;
		float OutCx;
		float OutCy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Estimate intrinsics from image size and focal scale \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Estimate intrinsics from image size and focal scale" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutFx;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutFy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutCx;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutCy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, Width), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutFx = { "OutFx", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, OutFx), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutFy = { "OutFy", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, OutFy), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutCx = { "OutCx", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, OutCx), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutCy = { "OutCy", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComfyReconstruction_eventEstimateIntrinsics_Parms, OutCy), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_Width,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutFx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutFy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutCx,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::NewProp_OutCy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComfyReconstruction, nullptr, "EstimateIntrinsics", Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::PropPointers), sizeof(Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::ComfyReconstruction_eventEstimateIntrinsics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::ComfyReconstruction_eventEstimateIntrinsics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComfyReconstruction::execEstimateIntrinsics)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Width);
	P_GET_PROPERTY(FIntProperty,Z_Param_Height);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutFx);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutFy);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutCx);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutCy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EstimateIntrinsics(Z_Param_Width,Z_Param_Height,Z_Param_Out_OutFx,Z_Param_Out_OutFy,Z_Param_Out_OutCx,Z_Param_Out_OutCy);
	P_NATIVE_END;
}
// ********** End Class UComfyReconstruction Function EstimateIntrinsics ***************************

// ********** Begin Class UComfyReconstruction *****************************************************
void UComfyReconstruction::StaticRegisterNativesUComfyReconstruction()
{
	UClass* Class = UComfyReconstruction::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AverageNormalizedDepth", &UComfyReconstruction::execAverageNormalizedDepth },
		{ "DepthToWorld", &UComfyReconstruction::execDepthToWorld },
		{ "EstimateIntrinsics", &UComfyReconstruction::execEstimateIntrinsics },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UComfyReconstruction;
UClass* UComfyReconstruction::GetPrivateStaticClass()
{
	using TClass = UComfyReconstruction;
	if (!Z_Registration_Info_UClass_UComfyReconstruction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ComfyReconstruction"),
			Z_Registration_Info_UClass_UComfyReconstruction.InnerSingleton,
			StaticRegisterNativesUComfyReconstruction,
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
	return Z_Registration_Info_UClass_UComfyReconstruction.InnerSingleton;
}
UClass* Z_Construct_UClass_UComfyReconstruction_NoRegister()
{
	return UComfyReconstruction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComfyReconstruction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ComfyStream/ComfyReconstruction.h" },
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FocalScale_MetaData[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Focal length scale factor\n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Focal length scale factor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepthScaleUnits_MetaData[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Depth scale in world units (1.0 = 1 cm) \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Depth scale in world units (1.0 = 1 cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepthEpsilon_MetaData[] = {
		{ "Category", "Reconstruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Avoid division and near-zero depth issues \n" },
#endif
		{ "ModuleRelativePath", "Public/ComfyStream/ComfyReconstruction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Avoid division and near-zero depth issues" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FocalScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthScaleUnits;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthEpsilon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComfyReconstruction_AverageNormalizedDepth, "AverageNormalizedDepth" }, // 358487195
		{ &Z_Construct_UFunction_UComfyReconstruction_DepthToWorld, "DepthToWorld" }, // 3982219187
		{ &Z_Construct_UFunction_UComfyReconstruction_EstimateIntrinsics, "EstimateIntrinsics" }, // 4165470225
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComfyReconstruction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_FocalScale = { "FocalScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyReconstruction, FocalScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FocalScale_MetaData), NewProp_FocalScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_DepthScaleUnits = { "DepthScaleUnits", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyReconstruction, DepthScaleUnits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepthScaleUnits_MetaData), NewProp_DepthScaleUnits_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_DepthEpsilon = { "DepthEpsilon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UComfyReconstruction, DepthEpsilon), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepthEpsilon_MetaData), NewProp_DepthEpsilon_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComfyReconstruction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_FocalScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_DepthScaleUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComfyReconstruction_Statics::NewProp_DepthEpsilon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyReconstruction_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UComfyReconstruction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_RealityStream,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyReconstruction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComfyReconstruction_Statics::ClassParams = {
	&UComfyReconstruction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UComfyReconstruction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UComfyReconstruction_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComfyReconstruction_Statics::Class_MetaDataParams), Z_Construct_UClass_UComfyReconstruction_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UComfyReconstruction()
{
	if (!Z_Registration_Info_UClass_UComfyReconstruction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComfyReconstruction.OuterSingleton, Z_Construct_UClass_UComfyReconstruction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComfyReconstruction.OuterSingleton;
}
UComfyReconstruction::UComfyReconstruction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UComfyReconstruction);
UComfyReconstruction::~UComfyReconstruction() {}
// ********** End Class UComfyReconstruction *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h__Script_RealityStream_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComfyReconstruction, UComfyReconstruction::StaticClass, TEXT("UComfyReconstruction"), &Z_Registration_Info_UClass_UComfyReconstruction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComfyReconstruction), 3361726819U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h__Script_RealityStream_2166434972(TEXT("/Script/RealityStream"),
	Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h__Script_RealityStream_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alexi_OneDrive_Documents_Unreal_Projects_Reconstruction_3D_Plugins_RealityStream_Source_RealityStream_Public_ComfyStream_ComfyReconstruction_h__Script_RealityStream_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

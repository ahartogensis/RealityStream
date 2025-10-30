#include "WorldExplorerSubsystem.h"
#include "ProceduralMeshComponent.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"

//reconstruction to mesh importer from WorldExplorer to Unreal Engine 5.6 

void UWorldExplorerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Subsystem initialized"));
}

void UWorldExplorerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Subsystem deinitialized"));
}

// =====================================================
//  MAIN ENTRY
// =====================================================

void UWorldExplorerSubsystem::CheckAndImportSplat(const FString& VideoPath)
{
	const FString OutputDir = GetOutputDirectory();
	const FString PlyFile = OutputDir / TEXT("point_cloud.ply");
	const FString ObjFile = OutputDir / TEXT("point_cloud.obj");

	if (FPaths::FileExists(PlyFile))
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Found existing PLY, converting..."));
		ConvertPLYToOBJ(PlyFile, ObjFile);
		return;
	}

	if (!VideoPath.IsEmpty() && FPaths::FileExists(VideoPath))
	{
		ProcessVideoToMesh(VideoPath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] No PLY or valid video file found."));
	}
}

// =====================================================
//  FILE PATH HELPERS
// =====================================================

FString UWorldExplorerSubsystem::GetProjectDirectory() const
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
}

FString UWorldExplorerSubsystem::GetOutputDirectory() const
{
	return GetProjectDirectory() / TEXT("Plugins/ComfyStream/WorldExplorerOutputs");
}

FString UWorldExplorerSubsystem::GetDataDirectory() const
{
	return GetProjectDirectory() / TEXT("Plugins/ComfyStream/WorldExplorerData");
}

// =====================================================
//  PLY → OBJ CONVERSION
// =====================================================

bool UWorldExplorerSubsystem::ConvertPLYToOBJ(const FString& PLYPath, const FString& OBJPath)
{
	FString PythonScript = GetProjectDirectory() / TEXT("Plugins/ComfyStream/convert_gaussian_ply.py");
	FString Command = FString::Printf(TEXT("python \"%s\" \"%s\" \"%s\""), *PythonScript, *PLYPath, *OBJPath);

	int32 Code = 0;
	FString Out, Err;
	bool bSuccess = FPlatformProcess::ExecProcess(*Command, TEXT(""), &Code, &Out, &Err);

	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Converting PLY → OBJ (%s): %s"), 
		bSuccess && Code == 0 ? TEXT("OK") : TEXT("FAILED"), *OBJPath);

	if (FPaths::FileExists(OBJPath))
	{
		ImportAndSpawnOBJMesh(OBJPath, FVector(0,0,-300), FRotator(90,0,0), FVector(500));
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] OBJ not found after conversion"));
	return false;
}

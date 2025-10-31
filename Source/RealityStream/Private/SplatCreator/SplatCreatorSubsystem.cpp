#include "SplatCreator/SplatCreatorSubsystem.h"
#include "ProceduralMeshComponent.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "GameFramework/Actor.h"
#include "Misc/Parse.h"
#include "Materials/MaterialInterface.h"
#include "Materials/Material.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Async/Async.h"
#include "HAL/RunnableThread.h"

//reconstruction to mesh importer from World Explorer to Unreal Engine 5.6 

void USplatCreatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Subsystem initialized"));

    // Reset shutdown flag
    bIsShuttingDown = false;

    StartDockerContainer();
    ScanForPLYFiles();

    // Start 45-second loop
    GetWorld()->GetTimerManager().SetTimer(
        LoopTimer,
        this,
        &USplatCreatorSubsystem::CycleMeshes,
        45.0f,
        true
    );
}

void USplatCreatorSubsystem::Deinitialize()
{
	// Mark as shutting down to prevent async callbacks from accessing destroyed subsystem
	bIsShuttingDown = true;

	// Clear the timer
	if (LoopTimer.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(LoopTimer);
	}

	// Clean up current mesh actor
	if (CurrentMeshActor)
	{
		CurrentMeshActor->Destroy();
		CurrentMeshActor = nullptr;
	}

	// Stop the Docker container when play stops (non-blocking, but set flag first)
	StopDockerContainer();

	Super::Deinitialize();
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Subsystem deinitialized"));
}

// =====================================================
//  DOCKER CONTAINER MANAGEMENT
// =====================================================
bool USplatCreatorSubsystem::IsDockerContainerRunning()
{
    FString DockerExe = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe");
    FString Arguments = TEXT("ps -q -f name=splat_stream");
    
    FString Out, Err;
    int32 Code;
    
    bool bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *Arguments, &Code, &Out, &Err);
    
    // If output is not empty, container exists and is running
    FString TrimmedOutput = Out.TrimStartAndEnd();
    return bSuccess && !TrimmedOutput.IsEmpty();
}

bool USplatCreatorSubsystem::EnsureDockerContainerRunning()
{
    // Check if container is already running
    if (IsDockerContainerRunning())
    {
        UE_LOG(LogTemp, Display, TEXT("[Docker] Container splat_stream is already running"));
        return true;
    }
    
    FString DockerExe = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe");
    
    // First check if container exists (but is stopped)
    FString CheckArgs = TEXT("ps -a -q -f name=splat_stream");
    FString Out, Err;
    int32 Code;
    
    FPlatformProcess::ExecProcess(*DockerExe, *CheckArgs, &Code, &Out, &Err);
    FString TrimmedOutput = Out.TrimStartAndEnd();
    
    if (!TrimmedOutput.IsEmpty())
    {
        // Container exists but is stopped, start it
        UE_LOG(LogTemp, Display, TEXT("[Docker] Container exists but is stopped, starting it..."));
        FString StartArgs = TEXT("start splat_stream");
        bool bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *StartArgs, &Code, &Out, &Err);
        
        if (bSuccess && Code == 0)
        {
            UE_LOG(LogTemp, Display, TEXT("[Docker] Container started successfully"));
            return true;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("[Docker] Failed to start container. Code: %d, Error: %s"), Code, *Err);
            return false;
        }
    }
    else
    {
        // Container doesn't exist, create and start it
        UE_LOG(LogTemp, Display, TEXT("[Docker] Container doesn't exist, creating it..."));
        FString RunArgs = FString::Printf(
            TEXT("run -d --name splat_stream -v \"%s:/workspace/data\" gaussian-splatting:optimized sleep infinity"),
            *GetOutputDirectory()
        );
        
        bool bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *RunArgs, &Code, &Out, &Err);
        
        if (bSuccess && Code == 0)
        {
            UE_LOG(LogTemp, Display, TEXT("[Docker] Container created and started. ID: %s"), *Out.TrimStartAndEnd());
            return true;
        }
        else
        {
            // If it's a name conflict error, the container might exist but in a weird state
            // Try to start it instead of removing and recreating
            if (Err.Contains(TEXT("already in use")) || Err.Contains(TEXT("Conflict")))
            {
                UE_LOG(LogTemp, Display, TEXT("[Docker] Container name conflict detected, attempting to start existing container..."));
                FString StartArgs = TEXT("start splat_stream");
                bool bStartSuccess = FPlatformProcess::ExecProcess(*DockerExe, *StartArgs, &Code, &Out, &Err);
                
                if (bStartSuccess && Code == 0)
                {
                    UE_LOG(LogTemp, Display, TEXT("[Docker] Existing container started successfully"));
                    return true;
                }
                else
                {
                    // If starting failed, container might be corrupted, remove and recreate
                    UE_LOG(LogTemp, Warning, TEXT("[Docker] Failed to start existing container, removing and recreating..."));
                    FString RemoveArgs = TEXT("rm -f splat_stream");
                    FPlatformProcess::ExecProcess(*DockerExe, *RemoveArgs, &Code, &Out, &Err);
                    
                    // Retry creating the container
                    bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *RunArgs, &Code, &Out, &Err);
                    if (bSuccess && Code == 0)
                    {
                        UE_LOG(LogTemp, Display, TEXT("[Docker] Container recreated successfully. ID: %s"), *Out.TrimStartAndEnd());
                        return true;
                    }
                }
            }
            
            UE_LOG(LogTemp, Error, TEXT("[Docker] Failed to create container. Code: %d, Output: %s, Error: %s"), Code, *Out, *Err);
            return false;
        }
    }
}

void USplatCreatorSubsystem::StartDockerContainer()
{
    // Run container check/start asynchronously to avoid blocking
    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]()
    {
        if (!bIsShuttingDown && IsValid(this))
        {
            EnsureDockerContainerRunning();
        }
    });
}

void USplatCreatorSubsystem::StopDockerContainer()
{
    // Stop container asynchronously to avoid blocking
    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]()
    {
        // Check if we're shutting down - still try to stop container, but don't access subsystem members
        if (!IsDockerContainerRunning())
        {
            if (!bIsShuttingDown)
            {
                UE_LOG(LogTemp, Display, TEXT("[Docker] Container is not running, nothing to stop"));
            }
            return;
        }

        FString DockerExe = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe");
        FString StopArgs = TEXT("stop splat_stream");
        
        FString Out, Err;
        int32 Code;
        
        if (!bIsShuttingDown)
        {
            UE_LOG(LogTemp, Display, TEXT("[Docker] Stopping container..."));
        }
        bool bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *StopArgs, &Code, &Out, &Err);
        
        if (bSuccess && Code == 0)
        {
            UE_LOG(LogTemp, Display, TEXT("[Docker] Container stopped successfully"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("[Docker] Failed to stop container. Code: %d, Error: %s"), Code, *Err);
        }
    });
}

void USplatCreatorSubsystem::ScanForPLYFiles()
{
    FString Dir = GetOutputDirectory();
    TArray<FString> ObjFiles;
    TArray<FString> TempPlyFiles;
    
    // Scan for both PLY and OBJ files
    IFileManager::Get().FindFiles(TempPlyFiles, *(Dir + "/*.ply"), true, false);
    IFileManager::Get().FindFiles(ObjFiles, *(Dir + "/*.obj"), true, false);
    
    // First add all PLY files
    PlyFiles = TempPlyFiles;
    
    // Add OBJ files that don't have corresponding PLY files
    for (const FString& ObjFile : ObjFiles)
    {
        // Check if corresponding PLY file exists in the directory
        FString ObjPath = Dir / ObjFile;
        FString PlyPath = ObjPath.Replace(TEXT(".obj"), TEXT(".ply"));
        
        if (!FPaths::FileExists(PlyPath))
        {
            // No corresponding PLY, so we can add this OBJ to the list
            PlyFiles.AddUnique(ObjFile);
        }
    }
    
    PlyFiles.Sort();

    UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Found %d mesh files (PLY/OBJ)"), PlyFiles.Num());
}

void USplatCreatorSubsystem::CycleMeshes()
{
    if (PlyFiles.Num() == 0) return;

    FString MeshFile = GetOutputDirectory() / PlyFiles[CurrentFileIndex];
    FString ObjFile;
    bool bFileHandled = false; // Track if we successfully handled this file
    
    // Check if file is already OBJ
    if (MeshFile.EndsWith(TEXT(".obj")))
    {
        ObjFile = MeshFile;
        UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Using existing OBJ file: %s"), *ObjFile);
        
        // Spawn mesh immediately
        if (FPaths::FileExists(ObjFile))
        {
            // Delete previous mesh only when we're about to spawn a new one
            if (CurrentMeshActor)
            {
                CurrentMeshActor->Destroy();
                CurrentMeshActor = nullptr;
            }
            
            CurrentMeshActor = ImportAndSpawnOBJMesh(
                ObjFile,
                FVector(100,0,100),
                FRotator(180,0,0),
                FVector(400)
            );
            bFileHandled = true;
        }
    }
    else
    {
        // It's a PLY file, check if OBJ already exists
        ObjFile = MeshFile.Replace(TEXT(".ply"), TEXT(".obj"));
        
        if (FPaths::FileExists(ObjFile))
        {
            UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Found existing OBJ, skipping conversion: %s"), *ObjFile);
            
            // Delete previous mesh only when we're about to spawn a new one
            if (CurrentMeshActor)
            {
                CurrentMeshActor->Destroy();
                CurrentMeshActor = nullptr;
            }
            
            // Spawn mesh immediately
            CurrentMeshActor = ImportAndSpawnOBJMesh(
                ObjFile,
                FVector(100,0,100),
                FRotator(180,0,0),
                FVector(400)
            );
            bFileHandled = true;
        }
        else
        {
            // OBJ doesn't exist - check if we're already converting this file
            if (CurrentlyConvertingFile == MeshFile)
            {
                UE_LOG(LogTemp, Display, TEXT("[SplatCreator] File is already being converted, waiting: %s"), *MeshFile);
                // Don't delete mesh or increment index - just wait for conversion to complete
                bFileHandled = false;
                return; // Exit early, keep current mesh visible
            }
            else
            {
                // Mark this file as being converted
                CurrentlyConvertingFile = MeshFile;
                
                // Convert PLY → OBJ asynchronously
                UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Converting PLY to OBJ (async): %s"), *MeshFile);
                
                FString MeshFileCopy = MeshFile;
                FString ObjFileCopy = ObjFile;
                
                // Run conversion on background thread
                // Capture the filename and index to spawn and increment when done
                FString ExpectedFileName = PlyFiles[CurrentFileIndex];
                int32 FileIndexForThisConversion = CurrentFileIndex;
                
                AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, MeshFileCopy, ObjFileCopy, ExpectedFileName, FileIndexForThisConversion]()
                {
                    // Check if shutting down before starting conversion
                    if (bIsShuttingDown)
                    {
                        UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Shutting down, cancelling conversion"));
                        return;
                    }
                    
                    bool bSuccess = ConvertPLYToOBJ_Internal(MeshFileCopy, ObjFileCopy);
                    
                    // When conversion completes, spawn the mesh on game thread
                    if (bSuccess && FPaths::FileExists(ObjFileCopy) && !bIsShuttingDown)
                    {
                        AsyncTask(ENamedThreads::GameThread, [this, ObjFileCopy, ExpectedFileName, FileIndexForThisConversion]()
                        {
                            // Check if subsystem is still valid and not shutting down
                            if (bIsShuttingDown || !IsValid(this))
                            {
                                UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Subsystem shutting down, skipping mesh spawn"));
                                return;
                            }
                            
                            // Spawn the mesh - even if timer has moved on, spawn it
                            // Delete any existing mesh before spawning new one
                            if (CurrentMeshActor)
                            {
                                CurrentMeshActor->Destroy();
                                CurrentMeshActor = nullptr;
                            }
                            
                            CurrentMeshActor = ImportAndSpawnOBJMesh(
                                ObjFileCopy,
                                FVector(100,0,100),
                                FRotator(180,0,0),
                                FVector(400)
                            );
                            
                            if (CurrentMeshActor)
                            {
                                UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Async conversion completed and mesh spawned"));
                                
                                // Clear the converting flag and increment to next file since we've handled this one
                                CurrentlyConvertingFile.Empty();
                                
                                // Check if we're still on the same file to avoid race conditions
                                if (PlyFiles.IsValidIndex(CurrentFileIndex) && PlyFiles[CurrentFileIndex] == ExpectedFileName)
                                {
                                    CurrentFileIndex = (CurrentFileIndex + 1) % PlyFiles.Num();
                                    UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Moved to next file: %d/%d"), CurrentFileIndex + 1, PlyFiles.Num());
                                }
                            }
                        });
                    }
                    else if (!bIsShuttingDown)
                    {
                        // Conversion failed, clear the flag
                        AsyncTask(ENamedThreads::GameThread, [this, ExpectedFileName]()
                        {
                            if (!bIsShuttingDown && IsValid(this) && CurrentlyConvertingFile == ExpectedFileName)
                            {
                                CurrentlyConvertingFile.Empty();
                            }
                        });
                    }
                });
                
                // Don't increment index yet - wait for async completion
                bFileHandled = false;
            }
        }
    }

    // Only increment to next file if we handled it immediately (not async)
    if (bFileHandled)
    {
        CurrentFileIndex = (CurrentFileIndex + 1) % PlyFiles.Num();
        UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Moved to next file: %d/%d"), CurrentFileIndex + 1, PlyFiles.Num());
    }
}


// =====================================================
//  MAIN ENTRY
// =====================================================

void USplatCreatorSubsystem::CheckAndImportSplat(const FString& VideoPath)
{
	const FString OutputDir = GetOutputDirectory();
	
	// Scan for any PLY or OBJ files
	TArray<FString> FoundPlyFiles;
	TArray<FString> FoundObjFiles;
	IFileManager::Get().FindFiles(FoundPlyFiles, *(OutputDir + "/*.ply"), true, false);
	IFileManager::Get().FindFiles(FoundObjFiles, *(OutputDir + "/*.obj"), true, false);
	
	// Rescan and update the file list
	ScanForPLYFiles();
	
	// If we found OBJ files, use cycle meshes to place them
	if (FoundObjFiles.Num() > 0 || PlyFiles.Num() > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Found %d OBJ files and %d PLY files"), FoundObjFiles.Num(), FoundPlyFiles.Num());
		
		// Reset to start from the beginning
		CurrentFileIndex = 0;
		
		// Trigger cycle meshes to place the first mesh
		CycleMeshes();
		
		return;
	}

	// If no files found, process video if provided
	if (!VideoPath.IsEmpty() && FPaths::FileExists(VideoPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] No existing mesh files found, processing video..."));
		ProcessVideoToMesh(VideoPath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[SplatCreator] No PLY, OBJ, or valid video file found."));
	}
}

// =====================================================
//  FILE PATH HELPERS
// =====================================================

FString USplatCreatorSubsystem::GetProjectDirectory() const
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
}

FString USplatCreatorSubsystem::GetOutputDirectory() const
{
	return GetProjectDirectory() / TEXT("Plugins/RealityStream/SplatCreatorOutputs");
}

FString USplatCreatorSubsystem::GetDataDirectory() const
{
	return GetProjectDirectory() / TEXT("Plugins/RealityStream/SplatCreatorData");
}

// =====================================================
//  PLY → OBJ CONVERSION
// =====================================================

bool USplatCreatorSubsystem::ConvertPLYToOBJ(const FString& PLYPath, const FString& OBJPath)
{
	// This function is now called synchronously for compatibility, but the actual work is done async
	// For immediate calls, we'll still do it synchronously but with minimal blocking
	
	FString PlyPathCopy = PLYPath;
	FString ObjPathCopy = OBJPath;
	
	// Run the conversion asynchronously
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, PlyPathCopy, ObjPathCopy]()
	{
		ConvertPLYToOBJ_Internal(PlyPathCopy, ObjPathCopy);
	});
	
	// For now, return true to indicate we've started the conversion
	// The actual result will be handled when spawning the mesh
	return true;
}

bool USplatCreatorSubsystem::ConvertPLYToOBJ_Internal(const FString& PLYPath, const FString& OBJPath)
{
	// Ensure container is running before executing commands
	if (!EnsureDockerContainerRunning())
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] Failed to ensure Docker container is running"));
		return false;
	}
	
	FString OutputDir = GetOutputDirectory();
	
	// Convert Windows paths to container paths (mounted at /workspace/data)
	FString PlyFileName = FPaths::GetCleanFilename(PLYPath);
	FString ObjFileName = FPaths::GetCleanFilename(OBJPath);
	
	FString ContainerPlyPath = FString::Printf(TEXT("/workspace/data/%s"), *PlyFileName);
	FString ContainerObjPath = FString::Printf(TEXT("/workspace/data/%s"), *ObjFileName);
	
	// Docker executable path
	FString DockerExe = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe");
	
	// Build the arguments for docker exec - use container paths
	// Note: The Dockerfile copies the script to /workspace/scripts/Plugins/RealityStream/
	FString Arguments = FString::Printf(
		TEXT("exec splat_stream python3 /workspace/scripts/Plugins/RealityStream/convert_gaussian_ply.py \"%s\" \"%s\""),
		*ContainerPlyPath, *ContainerObjPath
	);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Executing: %s %s"), *DockerExe, *Arguments);
	
	bool bSuccess = FPlatformProcess::ExecProcess(*DockerExe, *Arguments, &ReturnCode, &Output, &Errors);
	
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Docker execution result: %d"), ReturnCode);
	if (!Output.IsEmpty())
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Docker output: %s"), *Output);
	}
	if (!Errors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[SplatCreator] Docker errors: %s"), *Errors);
	}
	
	// Wait a bit for file system to update
	FPlatformProcess::Sleep(0.5f);
	
	if (bSuccess && ReturnCode == 0 && FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Successfully converted PLY to OBJ: %s"), *OBJPath);
		return true;
	}

	if (!FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] OBJ file not found after conversion: %s"), *OBJPath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] Docker command failed with return code: %d"), ReturnCode);
	}
	return false;
}

void USplatCreatorSubsystem::ProcessVideoToMesh(const FString& VideoPath)
{
	UE_LOG(LogTemp, Warning, TEXT("ProcessVideoToMesh() not implemented yet. Video: %s"), *VideoPath);
}

AActor* USplatCreatorSubsystem::ImportAndSpawnOBJMesh(
	const FString& ObjPath, 
	FVector Location, 
	FRotator Rotation, 
	FVector Scale)
{
	if (!FPaths::FileExists(ObjPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] OBJ file not found: %s"), *ObjPath);
		return nullptr;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] No world context"));
		return nullptr;
	}

	AActor* MeshActor = World->SpawnActor<AActor>();
	if (!MeshActor)
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] Failed to spawn actor"));
		return nullptr;
	}

	UProceduralMeshComponent* MeshComp = CreateProceduralMeshFromOBJ(ObjPath, MeshActor);
	if (MeshComp)
	{
		MeshComp->SetMobility(EComponentMobility::Movable);
		MeshActor->SetRootComponent(MeshComp);
		
		// Apply transform AFTER root component is set
		MeshActor->SetActorLocation(Location);
		MeshActor->SetActorRotation(Rotation);
		MeshActor->SetActorScale3D(Scale);
		
		// Also apply transform to the root component directly to ensure it sticks
		if (USceneComponent* RootComp = MeshActor->GetRootComponent())
		{
			RootComp->SetWorldLocation(Location);
			RootComp->SetWorldRotation(Rotation);
			RootComp->SetWorldScale3D(Scale);
		}
		
		// Load and apply M_VertexColor material with fallbacks
		UMaterial* VertexColorMat = LoadObject<UMaterial>(nullptr, TEXT("/Game/_GENERATED/Materials/M_VertexColor.M_VertexColor"));
		if (!VertexColorMat)
		{
			VertexColorMat = LoadObject<UMaterial>(nullptr, TEXT("/Game/M_VertexColor.M_VertexColor"));
		}
		if (!VertexColorMat)
		{
			VertexColorMat = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EditorMaterials/WidgetVertexColorMaterial"));
		}
		if (VertexColorMat)
		{
			MeshComp->SetMaterial(0, VertexColorMat);
			UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Applied M_VertexColor material"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[SplatCreator] M_VertexColor material not found in any location"));
		}
	}

	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Spawned mesh at %s"), *Location.ToString());
	return MeshActor;
}

UProceduralMeshComponent* USplatCreatorSubsystem::CreateProceduralMeshFromOBJ(const FString& OBJPath, AActor* Owner)
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FColor> Colors;

	if (!ParseOBJFile(OBJPath, Vertices, Triangles, Normals, Colors))
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] Failed to parse OBJ file"));
		return nullptr;
	}

	UProceduralMeshComponent* MeshComp = NewObject<UProceduralMeshComponent>(Owner);
	if (!MeshComp)
	{
		return nullptr;
	}

	MeshComp->SetupAttachment(Owner->GetRootComponent());
	
	TArray<FVector2D> EmptyUVs;
	TArray<FProcMeshTangent> EmptyTangents;
	
	MeshComp->CreateMeshSection(0, Vertices, Triangles, Normals, EmptyUVs, Colors, EmptyTangents, false);
	MeshComp->RegisterComponent();

	return MeshComp;
}

bool USplatCreatorSubsystem::ParseOBJFile(const FString& OBJPath, TArray<FVector>& OutVertices, TArray<int32>& OutTriangles, TArray<FVector>& OutNormals, TArray<FColor>& OutColors)
{
	TArray<FString> Lines;
	if (!FFileHelper::LoadFileToStringArray(Lines, *OBJPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] Failed to load OBJ file"));
		return false;
	}

	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FColor> Colors;

	// First pass: parse vertex positions, normals, and colors
	for (const FString& Line : Lines)
	{
		if (Line.StartsWith(TEXT("v ")))
		{
			// Vertex position (may have color)
			TArray<FString> Parts;
			Line.ParseIntoArray(Parts, TEXT(" "), true);
			
			if (Parts.Num() >= 4)
			{
				FVector Pos(
					FCString::Atof(*Parts[1]),
					FCString::Atof(*Parts[2]),
					FCString::Atof(*Parts[3])
				);
				Positions.Add(Pos);
				
				// Check for vertex colors (if present)
				if (Parts.Num() >= 7)
				{
					// Reduce brightness to 50% to prevent glowing
					float BrightnessFactor = 0.5f;
					FColor Color(
						FMath::Clamp(FCString::Atof(*Parts[4]) * 255 * BrightnessFactor, 0.0f, 255.0f),
						FMath::Clamp(FCString::Atof(*Parts[5]) * 255 * BrightnessFactor, 0.0f, 255.0f),
						FMath::Clamp(FCString::Atof(*Parts[6]) * 255 * BrightnessFactor, 0.0f, 255.0f),
						255
					);
					Colors.Add(Color);
				}
			}
		}
		else if (Line.StartsWith(TEXT("vn ")))
		{
			// Vertex normal
			TArray<FString> Parts;
			Line.ParseIntoArray(Parts, TEXT(" "), true);
			
			if (Parts.Num() >= 4)
			{
				FVector Normal(
					FCString::Atof(*Parts[1]),
					FCString::Atof(*Parts[2]),
					FCString::Atof(*Parts[3])
				);
				Normals.Add(Normal);
			}
		}
	}

	// Second pass: parse faces and build final vertex/index arrays
	for (const FString& Line : Lines)
	{
		if (Line.StartsWith(TEXT("f ")))
		{
			// Face definition
			TArray<FString> Parts;
			Line.ParseIntoArray(Parts, TEXT(" "), true);
			
			if (Parts.Num() >= 4)
			{
				// Parse face indices (format: v/vt/vn or v//vn or v)
				TArray<int32> FaceIndices;
				for (int32 i = 1; i < Parts.Num(); i++)
				{
					TArray<FString> IndexParts;
					Parts[i].ParseIntoArray(IndexParts, TEXT("/"), false);
					
					if (IndexParts.Num() > 0)
					{
						int32 VertexIndex = FCString::Atoi(*IndexParts[0]) - 1; // OBJ indices are 1-based
						FaceIndices.Add(VertexIndex);
					}
				}
				
				// Triangulate face (assuming convex polygons)
				for (int32 i = 1; i < FaceIndices.Num() - 1; i++)
				{
					int32 V0 = FaceIndices[0];
					int32 V1 = FaceIndices[i];
					int32 V2 = FaceIndices[i + 1];
					
					if (V0 >= 0 && V0 < Positions.Num() && 
					    V1 >= 0 && V1 < Positions.Num() && 
					    V2 >= 0 && V2 < Positions.Num())
					{
						int32 Idx0 = OutVertices.Add(Positions[V0]);
						int32 Idx1 = OutVertices.Add(Positions[V1]);
						int32 Idx2 = OutVertices.Add(Positions[V2]);
						
						OutTriangles.Add(Idx0);
						OutTriangles.Add(Idx1);
						OutTriangles.Add(Idx2);
						
						// Map colors if available
						if (V0 < Colors.Num()) OutColors.Add(Colors[V0]);
						else OutColors.Add(FColor::White);
						
						if (V1 < Colors.Num()) OutColors.Add(Colors[V1]);
						else OutColors.Add(FColor::White);
						
						if (V2 < Colors.Num()) OutColors.Add(Colors[V2]);
						else OutColors.Add(FColor::White);
						
						// Map normals if available
						if (V0 < Normals.Num()) OutNormals.Add(Normals[V0]);
						else OutNormals.Add(FVector(0, 0, 1));
						
						if (V1 < Normals.Num()) OutNormals.Add(Normals[V1]);
						else OutNormals.Add(FVector(0, 0, 1));
						
						if (V2 < Normals.Num()) OutNormals.Add(Normals[V2]);
						else OutNormals.Add(FVector(0, 0, 1));
					}
				}
			}
		}
	}
	
	if (OutVertices.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("[SplatCreator] No vertices parsed from OBJ"));
		return false;
	}

	// Ensure all arrays match
	if (OutColors.Num() < OutVertices.Num())
	{
		int32 Needed = OutVertices.Num() - OutColors.Num();
		for (int32 i = 0; i < Needed; i++)
		{
			OutColors.Add(FColor::White);
		}
	}

	if (OutNormals.Num() < OutVertices.Num())
	{
		int32 Needed = OutVertices.Num() - OutNormals.Num();
		for (int32 i = 0; i < Needed; i++)
		{
			OutNormals.Add(FVector(0, 0, 1));
		}
	}

	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Parsed OBJ: %d vertices, %d triangles, %d colors"), 
		OutVertices.Num(), OutTriangles.Num() / 3, OutColors.Num());

	// Debug: Print first few vertex colors to verify they're loaded
	if (OutColors.Num() > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] ✓ Vertex colors loaded! First 3 colors:"));
		for (int32 i = 0; i < FMath::Min(3, OutColors.Num()); i++)
		{
			FColor Color = OutColors[i];
		}
	}

	return true;
}



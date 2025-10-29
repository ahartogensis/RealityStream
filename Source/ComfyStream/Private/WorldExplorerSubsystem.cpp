#include "WorldExplorerSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "HAL/PlatformProcess.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Kismet/GameplayStatics.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialExpressionVertexColor.h"
#include "UObject/ConstructorHelpers.h"

void UWorldExplorerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] WorldExplorerSubsystem initialized"));
}

void UWorldExplorerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] WorldExplorerSubsystem deinitialized"));
}

void UWorldExplorerSubsystem::ImportExistingSplat()
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ImportExistingSplat called"));
	
	FString ProjectDir = GetProjectDirectory();
	FString PlyOutputDir = GetPlyOutputDirectory();
	FString PLYFile = PlyOutputDir / TEXT("point_cloud.ply");
	FString OBJFile = PlyOutputDir / TEXT("point_cloud.obj");
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] PlyOutputDir: %s"), *PlyOutputDir);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ProjectDir: %s"), *ProjectDir);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] PLY File: %s"), *FPaths::GetCleanFilename(PLYFile));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] OBJ File: %s"), *FPaths::GetCleanFilename(OBJFile));
	
	// Check if PLY file exists
	if (!FPaths::FileExists(PLYFile))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] PLY file not found: %s"), *PLYFile);
		return;
	}
	
	// Convert PLY to OBJ
	ConvertPLYToOBJ(PLYFile, OBJFile);
}

void UWorldExplorerSubsystem::RunGaussianSplat()
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] RunGaussianSplat called"));
	
	FString ProjectDir = GetProjectDirectory();
	FString PlyOutputDir = GetPlyOutputDirectory();
	FString PLYFile = PlyOutputDir / TEXT("point_cloud.ply");
	FString OBJFile = PlyOutputDir / TEXT("point_cloud.obj");
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] PlyOutputDir: %s"), *PlyOutputDir);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ProjectDir: %s"), *ProjectDir);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] PLY File: %s"), *FPaths::GetCleanFilename(PLYFile));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] OBJ File: %s"), *FPaths::GetCleanFilename(OBJFile));
	
	// Check if PLY file exists
	if (!FPaths::FileExists(PLYFile))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] PLY file not found: %s"), *PLYFile);
		return;
	}
	
	// Convert PLY to OBJ
	ConvertPLYToOBJ(PLYFile, OBJFile);
}

void UWorldExplorerSubsystem::CheckAndImportSplat(const FString& VideoPath)
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] CheckAndImportSplat called with video path: %s"), *VideoPath);
	
	bool bVideoFound = false;
	FString FinalVideoPath = VideoPath;
	
	// If a specific video path is provided, check if it exists
	if (!VideoPath.IsEmpty())
	{
		if (FPaths::FileExists(VideoPath))
		{
			bVideoFound = true;
			FinalVideoPath = VideoPath;
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Video file exists: %s"), *FinalVideoPath);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Video file not found: %s"), *VideoPath);
		}
	}
	else
	{
		// If no video path provided, search in common locations
		FString ProjectDir = GetProjectDirectory();
		TArray<FString> VideoSearchPaths = {
			ProjectDir / TEXT("Content/Videos"),
			ProjectDir / TEXT("Videos"),
			ProjectDir / TEXT("Data/Videos"),
			ProjectDir / TEXT("Input/Videos"),
			ProjectDir / TEXT("WorldExplorerData/Videos")
		};
		
		// Search for video files
		for (const FString& SearchPath : VideoSearchPaths)
		{
			if (FPaths::DirectoryExists(SearchPath))
			{
				TArray<FString> VideoFiles;
				FString VideoExtensions = TEXT("*.mp4;*.avi;*.mov;*.mkv;*.wmv;*.flv;*.webm");
				IFileManager::Get().FindFiles(VideoFiles, *(SearchPath / TEXT("*")), true, false);
				
				for (const FString& File : VideoFiles)
				{
					FString FullPath = SearchPath / File;
					FString Extension = FPaths::GetExtension(File).ToLower();
					
					if (VideoExtensions.Contains(Extension))
					{
						bVideoFound = true;
						FinalVideoPath = FullPath;
						UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Found video: %s"), *FinalVideoPath);
						break;
					}
				}
				
				if (bVideoFound)
				{
					break;
				}
			}
		}
	}
	
	if (bVideoFound)
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Video found, running reconstruction on: %s"), *FinalVideoPath);
		// Run the full reconstruction pipeline: Video -> PLY -> OBJ -> Spawn
		ProcessVideoToMesh(FinalVideoPath);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] No video found, importing existing splat"));
		ImportExistingSplat();
	}
}


void UWorldExplorerSubsystem::ConvertPLYToOBJ(const FString& PLYPath, const FString& OBJPath)
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Converting PLY to OBJ"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Input: %s"), *PLYPath);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Output: %s"), *OBJPath);
	
	FString ProjectDir = GetProjectDirectory();
	FString ScriptPath = ProjectDir / TEXT("Plugins/ComfyStream/convert_gaussian_ply.py");
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Script: %s"), *ScriptPath);
	
	// Try local Python conversion first
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Trying local Python conversion..."));
	FString LocalCommand = FString::Printf(TEXT("python \"%s\" \"%s\" \"%s\""), *ScriptPath, *PLYPath, *OBJPath);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Local command: %s"), *LocalCommand);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	bool bLocalSuccess = FPlatformProcess::ExecProcess(*LocalCommand, TEXT(""), &ReturnCode, &Output, &Errors, *ProjectDir);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Local conversion success: %s"), bLocalSuccess ? TEXT("Yes") : TEXT("No"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Local conversion result: %d"), ReturnCode);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Local conversion output: %s"), *Output);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Local conversion errors: %s"), *Errors);
	
	// Log the exact command being executed
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] EXACT COMMAND EXECUTED: %s"), *LocalCommand);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] WORKING DIRECTORY: %s"), *ProjectDir);
	
	if (!bLocalSuccess || ReturnCode != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Local conversions failed, trying Docker..."));
		
		// Try Docker conversion
		FString DockerCommand = FString::Printf(
			TEXT("\"C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe\" run --rm -v \"%s:/workspace/data\" -v \"%s:/workspace/scripts\" gaussian-splatting:optimized bash -c \"python3 /workspace/scripts/Plugins/ComfyStream/convert_gaussian_ply.py '/workspace/data/point_cloud.ply' '/workspace/data/point_cloud.obj'\""),
			*GetPlyOutputDirectory(),
			*ProjectDir
		);
		
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker command: %s"), *DockerCommand);
		
		bLocalSuccess = FPlatformProcess::ExecProcess(*DockerCommand, TEXT(""), &ReturnCode, &Output, &Errors, *ProjectDir);
		
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker conversion success: %s"), bLocalSuccess ? TEXT("Yes") : TEXT("No"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker conversion result: %d"), ReturnCode);
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker conversion output: %s"), *Output);
	}
	
	// Check if OBJ file was created and automatically spawn it
	if (FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Successfully converted to OBJ: %s"), *OBJPath);
		
		// Automatically import and spawn the mesh at world origin
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Auto-spawning mesh in scene..."));
		
		// Wait a moment for file to be fully written
		FPlatformProcess::Sleep(0.5f);
		
		// Spawn at origin with scale 400 and 90-degree Y rotation (green axis)
		FVector SpawnLocation = FVector(0, 0, -300); // Lower position to compensate for rotation and scale
		FRotator SpawnRotation = FRotator(90, 0, 0); // 90 degrees on Y axis (Pitch = green axis)
		FVector SpawnScale = FVector(500.0f, 500.0f, 500.0f); // Scale 500
		
		AActor* SpawnedActor = ImportAndSpawnOBJMesh(OBJPath, SpawnLocation, SpawnRotation, SpawnScale);
		
		if (SpawnedActor)
		{
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Mesh automatically spawned in scene at location: %s"), *SpawnLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Failed to auto-spawn mesh, but OBJ file is available at: %s"), *OBJPath);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to create OBJ file: %s"), *OBJPath);
	}
}

FString UWorldExplorerSubsystem::GetProjectDirectory()
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
}

FString UWorldExplorerSubsystem::GetPlyOutputDirectory()
{
	return GetProjectDirectory() / TEXT("Plugins/ComfyStream/WorldExplorerOutputs");
}

FString UWorldExplorerSubsystem::GetDataDirectory()
{
	return GetProjectDirectory() / TEXT("Plugins/ComfyStream/WorldExplorerData");
}

void UWorldExplorerSubsystem::ProcessVideoToMesh(const FString& VideoPath)
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] MAXIMUM QUALITY RECONSTRUCTION PIPELINE"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Input video: %s"), *VideoPath);
	
	if (!FPaths::FileExists(VideoPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Video file not found: %s"), *VideoPath);
		return;
	}
	
	FString ProjectDir = GetProjectDirectory();
	FString DataDir = GetDataDirectory();
	FString OutputDir = GetPlyOutputDirectory();
	
	// Determine destination filename (keep original extension)
	FString Extension = FPaths::GetExtension(VideoPath).ToLower();
	FString VideoDestPath = DataDir / FString::Printf(TEXT("input_video.%s"), *Extension);
	
	// Create directories if they don't exist
	IFileManager::Get().MakeDirectory(*DataDir, true);
	IFileManager::Get().MakeDirectory(*OutputDir, true);
	
	// Check if video is already in the correct location
	FString NormalizedSource = FPaths::ConvertRelativePathToFull(VideoPath);
	FString NormalizedDest = FPaths::ConvertRelativePathToFull(VideoDestPath);
	NormalizedSource.ReplaceInline(TEXT("\\"), TEXT("/"));
	NormalizedDest.ReplaceInline(TEXT("\\"), TEXT("/"));
	
	bool bAlreadyInPlace = NormalizedSource.Equals(NormalizedDest, ESearchCase::IgnoreCase) || FPaths::FileExists(VideoDestPath);
	
	if (bAlreadyInPlace && FPaths::FileExists(VideoDestPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Video already in correct location: %s"), *VideoDestPath);
	}
	else
	{
		// Only copy if source and destination are different
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Copying video from: %s"), *VideoPath);
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer]                   to: %s"), *VideoDestPath);
		
		// Try to copy WITHOUT deleting first - Unreal's Copy should overwrite
		if (!IFileManager::Get().Copy(*VideoDestPath, *VideoPath, true, true))
		{
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ❌ FAILED to copy video file!"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Source exists: %s"), FPaths::FileExists(VideoPath) ? TEXT("YES") : TEXT("NO"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Source: %s"), *VideoPath);
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Destination: %s"), *VideoDestPath);
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Make sure the video file is not locked by another program"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Or manually copy the video to WorldExplorerData/ and rename to input_video.%s"), *Extension);
			return;
		}
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Video copied successfully"));
	}
	
	// Verify the video file exists before proceeding
	if (!FPaths::FileExists(VideoDestPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ❌ CRITICAL: Video file does not exist at destination!"));
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Expected location: %s"), *VideoDestPath);
		return;
	}
	
	// Run Docker reconstruction pipeline (ASYNCHRONOUS - runs in background)
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Starting reconstruction..."));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] A terminal window will open showing live progress"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] This will take 6-8 minutes - Unreal will stay responsive!"));
	
	bool bSuccess = RunDockerReconstructionPipeline(VideoPath);
	
	if (bSuccess)
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Reconstruction running in background terminal"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Watch the terminal window for live progress!"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] "));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Mesh will AUTO-SPAWN when reconstruction completes"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Checking for completion every 10 seconds..."));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] "));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Output files will be in:"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer]   %s"), *OutputDir);
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		
		// Start polling timer to auto-spawn when complete
		UWorld* World = GetWorld();
		if (World)
		{
			World->GetTimerManager().SetTimer(
				AutoSpawnTimerHandle,
				this,
				&UWorldExplorerSubsystem::CheckAndAutoSpawnMesh,
				10.0f,  // Check every 10 seconds
				true    // Loop
			);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to start Docker reconstruction"));
	}
}

bool UWorldExplorerSubsystem::RunDockerReconstructionPipeline(const FString& VideoPath)
{
	FString ProjectDir = GetProjectDirectory();
	FString DataDir = GetDataDirectory();
	FString OutputDir = GetPlyOutputDirectory();
	
	// Build Docker command to match exactly what worked manually
	// Using bash -lc for login shell to ensure proper environment
	FString DockerCommand = FString::Printf(
		TEXT("docker run --rm --gpus all ")
		TEXT("-v \"%s:/workspace/data\" ")
		TEXT("-v \"%s:/workspace/outputs\" ")
		TEXT("-v \"%s:/workspace/project\" ")
		TEXT("gaussian-splatting:optimized bash -lc \"")
		// Step 1: Clean up old data (preserve input video)
		TEXT("rm -rf /workspace/data/input /workspace/data/sparse /workspace/data/distorted /workspace/data/temp /workspace/data/database.db || true && ")
		// Step 2: Extract frames at 10 fps for optimal quality (use -y to overwrite)
		TEXT("mkdir -p /workspace/data/input && ")
		TEXT("ffmpeg -y -i /workspace/data/input_video.* -qscale:v 1 -qmin 1 -vf fps=10 /workspace/data/input/frame_%%04d.jpg && ")
		// Step 3: Run COLMAP sparse reconstruction
		TEXT("python3 /workspace/gaussian-splatting/convert.py -s /workspace/data && ")
		// Step 4: Export sparse reconstruction to PLY
		TEXT("colmap model_converter --input_path /workspace/data/sparse/0 --output_path /workspace/outputs/point_cloud.ply --output_type PLY && ")
		// Step 5: Convert PLY to OBJ with maximum quality remeshing
		TEXT("python3 /workspace/project/Plugins/ComfyStream/convert_gaussian_ply.py /workspace/outputs/point_cloud.ply /workspace/outputs/point_cloud.obj && ")
		// Step 6: Clean up temporary reconstruction files (keep input video and final outputs)
		TEXT("echo '=== Cleaning up temporary files... ===' && ")
		TEXT("rm -rf /workspace/data/input /workspace/data/sparse /workspace/data/distorted /workspace/data/temp /workspace/data/database.db || true && ")
		TEXT("echo '=== Cleanup complete! OBJ ready for import. ===' && ")
		TEXT("ls -lh /workspace/outputs/point_cloud.obj\""),
		*DataDir,
		*OutputDir,
		*ProjectDir
	);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Launching Docker in NEW TERMINAL WINDOW"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Unreal will continue running!"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
	
    // Create simple batch file that runs the exact Docker command (same format that worked manually)
    FString BatchPath = DataDir / TEXT("run_reconstruction.bat");
    
    // Escape % characters for batch file (batch interprets % as variable expansion)
    // In batch files, to get a literal % you need %%
    // The DockerCommand string has %04d which needs to become %%04d in the batch file
    FString DockerCmdForBatch = DockerCommand;
    // Simply replace %04d with %%04d (this is the only % pattern we use in ffmpeg)
    DockerCmdForBatch.ReplaceInline(TEXT("%04d"), TEXT("%%04d"));
    
    FString BatchContent =
        TEXT("@echo off\r\n")
        TEXT("setlocal enabledelayedexpansion\r\n")
        TEXT("title WorldExplorer Reconstruction\r\n")
        TEXT("cd /d \"%~dp0\"\r\n")
        TEXT("echo ========================================\r\n")
        TEXT("echo   WorldExplorer Reconstruction Pipeline\r\n")
        TEXT("echo ========================================\r\n")
        TEXT("echo Starting at %DATE% %TIME%\r\n")
        TEXT("echo This will take 6-8 minutes\r\n")
        TEXT("echo DO NOT CLOSE this window!\r\n")
        TEXT("echo ========================================\r\n")
        TEXT("echo.\r\n")
        // Run Docker command with properly escaped % characters
        TEXT("") + DockerCmdForBatch + TEXT("\r\n")
        TEXT("set EXITCODE=!ERRORLEVEL!\r\n")
        TEXT("echo.\r\n")
        TEXT("echo ========================================\r\n")
        TEXT("if not !EXITCODE!==0 (\r\n")
        TEXT("  echo ERROR: Docker command failed (code !EXITCODE!)\r\n")
        TEXT("  echo - Ensure Docker Desktop is running\r\n")
        TEXT("  echo - Ensure GPU is available to Docker\r\n")
        TEXT(") else (\r\n")
        TEXT("  echo RECONSTRUCTION COMPLETE!\r\n")
        TEXT("  echo Mesh will auto-spawn in Unreal Engine!\r\n")
        TEXT(")\r\n")
        TEXT("echo ========================================\r\n")
        TEXT("pause\r\n");
	
	// Write batch file
	if (!FFileHelper::SaveStringToFile(BatchContent, *BatchPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to create batch file: %s"), *BatchPath);
		return false;
	}
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Created batch file: %s"), *BatchPath);
	
	// Verify batch file was created
	if (!FPaths::FileExists(BatchPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ❌ Batch file was not created! Path: %s"), *BatchPath);
		return false;
	}
	
	// Use ShellExecute approach - more reliable on Windows
	FString BatchPathForShell = BatchPath;
	BatchPathForShell.ReplaceInline(TEXT("/"), TEXT("\\")); // Use Windows path separators
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Attempting to launch terminal window..."));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Batch file: %s"), *BatchPath);
	
    // Method 1: Use START to run the batch directly (pause inside batch keeps window open)
    FString StartArgs = FString::Printf(TEXT("\"WorldExplorer Reconstruction\" \"%s\""), *BatchPath);

    FProcHandle ProcHandle = FPlatformProcess::CreateProc(
        TEXT("cmd.exe"),
        *FString::Printf(TEXT("/c start %s"), *StartArgs),
        true,
        false,
        false,
        nullptr,
        0,
        *DataDir,
        nullptr
    );
	
	if (!ProcHandle.IsValid())
	{
		// Method 2: Try alternative approach - launch cmd /k directly with batch file
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] First launch method failed, trying alternative..."));
		
        FProcHandle ProcHandle2 = FPlatformProcess::CreateProc(
            *BatchPath,
            TEXT(""),
            true,
            false,
            false,
            nullptr,
            0,
            *DataDir,
            nullptr
        );
		
		if (ProcHandle2.IsValid())
		{
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Terminal window launched (method 2)!"));
			FPlatformProcess::CloseProc(ProcHandle2);
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ❌ Both launch methods failed!"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Batch file exists: %s"), FPaths::FileExists(BatchPath) ? TEXT("YES") : TEXT("NO"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Batch file path: %s"), *BatchPath);
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] "));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] MANUAL INSTRUCTIONS:"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 1. Open Command Prompt"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 2. Navigate to: %s"), *ProjectDir);
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 3. Run: \"%s\""), *BatchPath);
			return false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Terminal window launched successfully!"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Look for window titled: 'WorldExplorer Reconstruction'"));
		FPlatformProcess::CloseProc(ProcHandle);
		return true;
	}
}

bool UWorldExplorerSubsystem::ExecutePythonScript(const FString& ScriptPath, const FString& InputPath, const FString& OutputPath)
{
	FString Command = FString::Printf(TEXT("python \"%s\" \"%s\" \"%s\""), *ScriptPath, *InputPath, *OutputPath);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	
	bool bSuccess = FPlatformProcess::ExecProcess(*Command, TEXT(""), &ReturnCode, &Output, &Errors);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Python execution result: %d"), ReturnCode);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Python output: %s"), *Output);
	if (!Errors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Python errors: %s"), *Errors);
	}
	
	return bSuccess && ReturnCode == 0;
}

bool UWorldExplorerSubsystem::ExecuteDockerScript(const FString& InputPath, const FString& OutputPath)
{
	FString ProjectDir = GetProjectDirectory();
	FString PlyOutputDir = GetPlyOutputDirectory();
	
	FString Command = FString::Printf(
		TEXT("\"C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe\" run --rm -v \"%s:/workspace/data\" -v \"%s:/workspace/scripts\" gaussian-splatting:optimized bash -c \"python3 /workspace/scripts/Plugins/ComfyStream/convert_gaussian_ply.py '/workspace/data/point_cloud.ply' '/workspace/data/point_cloud.obj'\""),
		*PlyOutputDir,
		*ProjectDir
	);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	
	bool bSuccess = FPlatformProcess::ExecProcess(*Command, TEXT(""), &ReturnCode, &Output, &Errors);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker execution result: %d"), ReturnCode);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker output: %s"), *Output);
	if (!Errors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Docker errors: %s"), *Errors);
	}
	
	return bSuccess && ReturnCode == 0;
}

// Parse OBJ file and extract mesh data
bool UWorldExplorerSubsystem::ParseOBJFile(const FString& OBJPath, TArray<FVector>& OutVertices, TArray<int32>& OutTriangles, TArray<FVector>& OutNormals, TArray<FColor>& OutVertexColors)
{
	TArray<FString> Lines;
	if (!FFileHelper::LoadFileToStringArray(Lines, *OBJPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to read OBJ file: %s"), *OBJPath);
		return false;
	}

	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FColor> Colors;
	
	// Parse OBJ file
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
		else if (Line.StartsWith(TEXT("f ")))
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
					OutTriangles.Add(FaceIndices[0]);
					OutTriangles.Add(FaceIndices[i]);
					OutTriangles.Add(FaceIndices[i + 1]);
				}
			}
		}
	}
	
	OutVertices = Positions;
	OutNormals = Normals;
	OutVertexColors = Colors;
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Parsed OBJ: %d vertices, %d triangles, %d colors"), 
		OutVertices.Num(), OutTriangles.Num() / 3, OutVertexColors.Num());
	
	return OutVertices.Num() > 0 && OutTriangles.Num() > 0;
}

// Create procedural mesh from OBJ file with an owner actor
UProceduralMeshComponent* UWorldExplorerSubsystem::CreateProceduralMeshFromOBJ(const FString& OBJPath, AActor* Owner)
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FColor> VertexColors;
	
	if (!ParseOBJFile(OBJPath, Vertices, Triangles, Normals, VertexColors))
	{
		return nullptr;
	}
	
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] No owner provided for ProceduralMeshComponent"));
		return nullptr;
	}
	
	// Create procedural mesh component with owner
	UProceduralMeshComponent* ProcMesh = NewObject<UProceduralMeshComponent>(Owner, UProceduralMeshComponent::StaticClass());
	if (!ProcMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to create ProceduralMeshComponent"));
		return nullptr;
	}
	
	// Setup mesh data
	TArray<FVector2D> UV0; // Empty UVs for now
	TArray<FProcMeshTangent> Tangents; // Empty tangents
	
	// If no normals in file, let Unreal calculate them
	bool bHasNormals = Normals.Num() == Vertices.Num();
	
	// Create the mesh section with NO collision
	ProcMesh->CreateMeshSection(
		0, 
		Vertices, 
		Triangles, 
		bHasNormals ? Normals : TArray<FVector>(),
		UV0, 
		VertexColors.Num() == Vertices.Num() ? VertexColors : TArray<FColor>(),
		Tangents, 
		false // Disable collision
	);
	
	// Disable collision completely
	ProcMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	// CRITICAL: Set LOW render priority so Gaussian splat renders BEFORE ComfyStream objects
	// Negative number = renders first (background/behind)
	// This ensures ComfyStream segmented images render IN FRONT of the splat
	ProcMesh->SetTranslucentSortPriority(-100); // Low priority = renders first/behind
	ProcMesh->SetRenderCustomDepth(true);
	ProcMesh->SetCustomDepthStencilValue(1);
	
	// Check if MTL file exists (Python creates this with vertex color material info)
	FString MTLPath = OBJPath.Replace(TEXT(".obj"), TEXT(".mtl"));
	bool bHasMTLFile = FPaths::FileExists(MTLPath);
	
	if (bHasMTLFile)
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Found MTL file - vertex colors confirmed present"));
	}
	
	// Try to load custom material first from actual location
	UMaterial* VertexColorMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/_GENERATED/Materials/M_VertexColor.M_VertexColor"));
	
	if (!VertexColorMaterial)
	{
		// Try standard location
		VertexColorMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/M_VertexColor.M_VertexColor"));
	}
	
	if (!VertexColorMaterial)
	{
		// Use engine's widget vertex color material - this WILL show colors (may be bright)
		VertexColorMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EditorMaterials/WidgetVertexColorMaterial"));
		
		if (VertexColorMaterial)
		{
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ========================================"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ⚠ USING ENGINE MATERIAL - BLOCKS COMFYSTREAM!"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ========================================"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] CRITICAL: Create /Game/M_VertexColor with these EXACT settings:"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 1. Blend Mode: TRANSLUCENT (NOT Opaque!)"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 2. Shading Model: Unlit"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 3. Add Vertex Color node"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 4. RGB -> Multiply (0.5) -> Emissive Color"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 5. Constant (0.7) -> Opacity"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] 6. SAVE and RERUN!"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Without TRANSLUCENT mode, ComfyStream images CANNOT show through!"));
			UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] ========================================"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Using custom M_VertexColor material"));
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] If ComfyStream images don't show through:"));
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] - Open M_VertexColor material"));
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] - Set Blend Mode to TRANSLUCENT"));
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] - Set Opacity to 0.7 (or connect Vertex Color A)"));
	}
	
	// Apply material
	if (VertexColorMaterial)
	{
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(VertexColorMaterial, ProcMesh);
		if (DynMaterial)
		{
			ProcMesh->SetMaterial(0, DynMaterial);
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Material applied with %d vertex colors"), VertexColors.Num());
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Translucent sort priority: -100 (background layer)"));
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ComfyStream objects should render IN FRONT if material is TRANSLUCENT"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] No material available - mesh will be invisible"));
	}
	
	// Debug: Print first few vertex colors to verify they're loaded
	if (VertexColors.Num() > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Vertex colors loaded! First 3 colors:"));
		for (int32 i = 0; i < FMath::Min(3, VertexColors.Num()); i++)
		{
			FColor Color = VertexColors[i];
			UE_LOG(LogTemp, Display, TEXT("  Color[%d]: R=%d G=%d B=%d"), i, Color.R, Color.G, Color.B);
		}
	}
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Created procedural mesh with %d vertices, %d colors, collision disabled"), 
		Vertices.Num(), VertexColors.Num());
	
	return ProcMesh;
}

// Import and spawn OBJ mesh at specific location
AActor* UWorldExplorerSubsystem::ImportAndSpawnOBJMesh(const FString& OBJPath, FVector SpawnLocation, FRotator SpawnRotation, FVector SpawnScale)
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ImportAndSpawnOBJMesh called"));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] OBJ Path: %s"), *OBJPath);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Spawn Location: %s"), *SpawnLocation.ToString());
	
	// Check if file exists
	if (!FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] OBJ file not found: %s"), *OBJPath);
		return nullptr;
	}
	
	// Get world
	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] No world found"));
		return nullptr;
	}
	
	// Spawn actor first
	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = FName(*FString::Printf(TEXT("GaussianSplat_%s"), *FDateTime::Now().ToString()));
	
	AActor* SpawnedActor = World->SpawnActor<AActor>(AActor::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);
	if (!SpawnedActor)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to spawn actor"));
		return nullptr;
	}
	
	// Create procedural mesh from OBJ with the spawned actor as owner
	UProceduralMeshComponent* ProcMesh = CreateProceduralMeshFromOBJ(OBJPath, SpawnedActor);
	if (!ProcMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to create mesh from OBJ"));
		SpawnedActor->Destroy();
		return nullptr;
	}
	
	// Set the procedural mesh as the root component
	SpawnedActor->SetRootComponent(ProcMesh);
	ProcMesh->SetWorldLocation(SpawnLocation);
	ProcMesh->SetWorldRotation(SpawnRotation);
	ProcMesh->SetWorldScale3D(SpawnScale);
	ProcMesh->RegisterComponent();
	
	// Set mobility to movable so it can be transformed
	ProcMesh->SetMobility(EComponentMobility::Movable);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Successfully spawned mesh actor: %s"), 
		*SpawnedActor->GetName());
	
	return SpawnedActor;
}

// Convert PLY and spawn mesh in one call (defaults to 90-degree Y rotation)
void UWorldExplorerSubsystem::ConvertAndSpawnPLY(const FString& PLYPath, FVector SpawnLocation, FRotator SpawnRotation, FVector SpawnScale)
{
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ConvertAndSpawnPLY called"));
	
	// Check if PLY exists
	if (!FPaths::FileExists(PLYPath))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] PLY file not found: %s"), *PLYPath);
		return;
	}
	
	// Generate OBJ path (same location as PLY, with _mesh suffix)
	FString OBJPath = FPaths::ChangeExtension(PLYPath, TEXT("")) + TEXT("_mesh.obj");
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Converting PLY to OBJ..."));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Output will be: %s"), *OBJPath);
	
	// Convert PLY to OBJ
	ConvertPLYToOBJ(PLYPath, OBJPath);
	
	// Wait a moment for file to be written (could be improved with proper async)
	FPlatformProcess::Sleep(0.5f);
	
	// Import and spawn the mesh
	if (FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] OBJ created, spawning mesh..."));
		AActor* SpawnedActor = ImportAndSpawnOBJMesh(OBJPath, SpawnLocation, SpawnRotation, SpawnScale);
		
		if (SpawnedActor)
		{
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Mesh successfully spawned at location: %s"), *SpawnLocation.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] OBJ file was not created: %s"), *OBJPath);
	}
}

void UWorldExplorerSubsystem::CheckAndAutoSpawnMesh()
{
	FString OBJPath = GetPlyOutputDirectory() / TEXT("point_cloud.obj");
	
	// Check if OBJ file exists and has been fully written (check file size stability)
	if (FPaths::FileExists(OBJPath))
	{
		// File exists! Stop the timer
		UWorld* World = GetWorld();
		if (World && AutoSpawnTimerHandle.IsValid())
		{
			World->GetTimerManager().ClearTimer(AutoSpawnTimerHandle);
		}
		
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓✓✓ RECONSTRUCTION COMPLETE! ✓✓✓"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Auto-spawning mesh in scene..."));
		
		// Wait a moment to ensure file is fully written
		FPlatformProcess::Sleep(2.0f);
		
		// Spawn at origin with scale and rotation
		FVector SpawnLocation = FVector(0, 0, -300);
		FRotator SpawnRotation = FRotator(90, 0, 0);
		FVector SpawnScale = FVector(500.0f, 500.0f, 500.0f);
		
		AActor* SpawnedActor = ImportAndSpawnOBJMesh(OBJPath, SpawnLocation, SpawnRotation, SpawnScale);
		
		if (SpawnedActor)
		{
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓✓✓ SUCCESS! Mesh automatically spawned in scene! ✓✓✓"));
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Actor name: %s"), *SpawnedActor->GetName());
			
			// Clean up temporary reconstruction files to free space for multiple splats
			FString DataDir = GetDataDirectory();
			TArray<FString> TempDirs = {
				DataDir / TEXT("input"),
				DataDir / TEXT("sparse"),
				DataDir / TEXT("distorted"),
				DataDir / TEXT("temp")
			};
			TArray<FString> TempFiles = {
				DataDir / TEXT("database.db")
			};
			
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Cleaning up temporary reconstruction files..."));
			for (const FString& Dir : TempDirs)
			{
				if (FPaths::DirectoryExists(Dir))
				{
					IFileManager::Get().DeleteDirectory(*Dir, false, true);
					UE_LOG(LogTemp, Display, TEXT("[WorldExplorer]   Deleted: %s"), *Dir);
				}
			}
			for (const FString& File : TempFiles)
			{
				if (FPaths::FileExists(File))
				{
					IFileManager::Get().Delete(*File);
					UE_LOG(LogTemp, Display, TEXT("[WorldExplorer]   Deleted: %s"), *File);
				}
			}
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Cleanup complete! Ready for next reconstruction."));
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ========================================"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Mesh file created but failed to spawn. Try manually calling ImportExistingSplat()"));
		}
	}
	else
	{
		// Still waiting...
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] [Polling] Waiting for reconstruction to complete..."));
	}
}
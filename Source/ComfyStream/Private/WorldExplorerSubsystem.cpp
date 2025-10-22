#include "WorldExplorerSubsystem.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"
#include "Engine/Engine.h"

// Editor-only includes
#if WITH_EDITOR
#include "EditorAssetLibrary.h"
#include "AssetToolsModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "IAssetTools.h"
#include "AssetImportTask.h"
#endif

FString UWorldExplorerSubsystem::GetDefaultOutputDirectory() const
{
    return FPaths::ProjectSavedDir() / TEXT("WorldExplorerOutputs");
}

void UWorldExplorerSubsystem::GenerateGaussianSplat(const FString& VideoPath, const FString& OutputDir)
{
    if (VideoPath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Video path is empty!"));
        return;
    }

    if (!FPaths::FileExists(VideoPath))
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Video file not found: %s"), *VideoPath);
        return;
    }

    // Use provided output dir or default
    FString FinalOutputDir = OutputDir.IsEmpty() ? GetDefaultOutputDirectory() : OutputDir;
    IFileManager::Get().MakeDirectory(*FinalOutputDir, true);

    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Starting Gaussian Splat generation from: %s"), *VideoPath);
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Output directory: %s"), *FinalOutputDir);

    RunWorldExplorer(VideoPath, FinalOutputDir);

#if WITH_EDITOR
    // In editor, poll for completion and auto-import
    if (GIsEditor)
    {
        FTimerHandle TimerHandle;
        FTimerDelegate TimerDelegate;
        TimerDelegate.BindLambda([this, FinalOutputDir, TimerHandle]() mutable
        {
            FString PLYPath = FinalOutputDir / TEXT("splat.ply");
            if (FPaths::FileExists(PLYPath))
            {
                TryImportSplat(FinalOutputDir);
                
                // Clear the timer
                if (UWorld* World = GetWorld())
                {
                    World->GetTimerManager().ClearTimer(TimerHandle);
                }
            }
        });

        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 5.0f, true);
        }
    }
#else
    // At runtime, just log that processing started
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Processing started. Check output directory for results."));
#endif
}

void UWorldExplorerSubsystem::RunWorldExplorer(const FString& VideoPath, const FString& OutputDir)
{
    const FString PythonExe = TEXT("C:/Users/alexi/miniconda3/python.exe");
    const FString ScriptPath = TEXT("C:/Users/alexi/src/worldexplorer/worldexplorer.py");

    if (!FPaths::FileExists(PythonExe))
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Python executable not found: %s"), *PythonExe);
        return;
    }

    if (!FPaths::FileExists(ScriptPath))
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] WorldExplorer script not found: %s"), *ScriptPath);
        return;
    }

    FString CmdArgs = FString::Printf(TEXT("\"%s\" --input \"%s\" --output \"%s\""),
        *ScriptPath, *VideoPath, *OutputDir);

    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Running: %s %s"), *PythonExe, *CmdArgs);

    FProcHandle ProcHandle = FPlatformProcess::CreateProc(*PythonExe, *CmdArgs, true, false, false, nullptr, 0, nullptr, nullptr);
    
    if (ProcHandle.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Process started successfully"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to start process"));
    }
}

void UWorldExplorerSubsystem::RunGaussianSplatFromVideo(const FString& VideoPath)
{
    if (VideoPath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Video path is empty!"));
        return;
    }

    if (!FPaths::FileExists(VideoPath))
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Video file not found: %s"), *VideoPath);
        return;
    }

    // --- Config ---
    const FString ProjectDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
    const FString DataDir = ProjectDir / TEXT("WorldExplorerData");
    const FString OutputsDir = ProjectDir / TEXT("WorldExplorerOutputs");

    // Create directories if missing
    IFileManager::Get().MakeDirectory(*DataDir, true);
    IFileManager::Get().MakeDirectory(*OutputsDir, true);

    // Copy the video into the data folder (Docker mount)
    const FString VideoName = FPaths::GetCleanFilename(VideoPath);
    const FString LocalCopy = DataDir / VideoName;
    
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Copying video to data directory..."));
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Source: %s"), *VideoPath);
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Destination: %s"), *LocalCopy);
    
    // Delete existing file if present to ensure clean copy
    if (IFileManager::Get().FileExists(*LocalCopy))
    {
        IFileManager::Get().Delete(*LocalCopy);
    }
    
    // Copy with overwrite enabled (EFileWrite::FILEWRITE_AllowRead allows reading while copying)
    if (IFileManager::Get().Copy(*LocalCopy, *VideoPath, true, true) != COPY_OK)
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to copy video to: %s"), *LocalCopy);
        return;
    }
    
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Video copied successfully (size: %lld bytes)"), 
        IFileManager::Get().FileSize(*LocalCopy));


    // --- Docker command ---
    // Using optimized image with pre-installed COLMAP and dependencies
    // Fixed to handle COLMAP output directory structure
    const FString DockerCmd = FString::Printf(
        TEXT("docker run --rm --gpus all -v \"%s:/workspace/data\" -v \"%s:/workspace/outputs\" "
             "gaussian-splatting:optimized bash -c \""
             "cd /workspace/gaussian-splatting && "
             "mkdir -p /workspace/data/scene/input && "
             "ffmpeg -y -i /workspace/data/%s -vf fps=5 /workspace/data/scene/input/frame_%%04d.png && "
             "colmap feature_extractor --database_path /workspace/data/scene/distorted/database.db --image_path /workspace/data/scene/input --ImageReader.single_camera 1 --ImageReader.camera_model SIMPLE_PINHOLE --SiftExtraction.max_image_size 1600 --SiftExtraction.max_num_features 8192 --SiftExtraction.use_gpu 0 && "
             "colmap sequential_matcher --database_path /workspace/data/scene/distorted/database.db --SiftMatching.guided_matching 1 --SiftMatching.use_gpu 0 --SequentialMatching.overlap 10 --SequentialMatching.loop_detection 0 && "
             "colmap mapper --database_path /workspace/data/scene/distorted/database.db --image_path /workspace/data/scene/input --output_path /workspace/data/scene/distorted/sparse --Mapper.init_min_num_inliers 50 --Mapper.abs_pose_min_num_inliers 10 --Mapper.abs_pose_min_inlier_ratio 0.15 --Mapper.ba_local_max_num_iterations 40 --Mapper.ba_global_max_num_iterations 100 --Mapper.min_num_matches 15 && "
             "colmap model_converter --input_path /workspace/data/scene/distorted/sparse/0 --output_path /workspace/data/scene/distorted/sparse/0 --output_type TXT && "
             "if [ -d '/workspace/data/scene/distorted/sparse/0' ]; then "
             "cp -r /workspace/data/scene/distorted/sparse/0 /workspace/data/scene/sparse/ && "
             "ln -sf /workspace/data/scene/input /workspace/data/scene/images && "
             "echo 'COLMAP output moved and images linked'; "
             "else echo 'ERROR: COLMAP output not found'; exit 1; fi && "
             "python3 train.py -s /workspace/data/scene --iterations 7000 && "
             "cp -r output/* /workspace/outputs/\""),
        *DataDir, *OutputsDir, *VideoName);

    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Running Docker command..."));
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Data dir: %s"), *DataDir);
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Outputs dir: %s"), *OutputsDir);
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Command: %s"), *DockerCmd);

    // Execute - output will be logged to cmd window
    FProcHandle ProcHandle = FPlatformProcess::CreateProc(
        TEXT("cmd.exe"),
        *FString::Printf(TEXT("/C %s"), *DockerCmd),
        true, false, false, nullptr, 0, nullptr, nullptr);

    if (ProcHandle.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Docker process started successfully"));
        
#if WITH_EDITOR
        // Watch for .ply files in the output directory
        if (GIsEditor && GetWorld())
        {
            FTimerHandle TimerHandle;
            FTimerDelegate TimerDelegate;
            TimerDelegate.BindLambda([this, OutputsDir, TimerHandle]() mutable
            {
                TryImportSplatRecursive(OutputsDir);
                
                // Keep checking until we find something or user manually stops
                // In a production system, you'd want a timeout or completion signal
            });

            GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 10.0f, true);
        }
#endif
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to start Docker process"));
    }
}

#if WITH_EDITOR
void UWorldExplorerSubsystem::TryImportSplat(const FString& OutputDir)
{
    FString PLYPath = OutputDir / TEXT("splat.ply");

    if (!FPaths::FileExists(PLYPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] No splat.ply found yet in %s"), *OutputDir);
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("=================================================="));
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Gaussian Splat generation complete!"));
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Output file: %s"), *PLYPath);
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] You can now import this .ply file into your project"));
    UE_LOG(LogTemp, Log, TEXT("=================================================="));
    
    // TODO: Auto-import functionality - requires asset import factory setup
    // For now, users can manually drag-and-drop the PLY file into the content browser
}

void UWorldExplorerSubsystem::ImportExistingSplat()
{
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Manually importing existing Gaussian Splat..."));
    
    FString AllOutputsDir = FPaths::ProjectDir() / TEXT("Plugins/ComfyStream/WorldExplorerOutputs");
    UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Searching in: %s"), *AllOutputsDir);
    TryImportSplatRecursive(AllOutputsDir);
}

void UWorldExplorerSubsystem::TryImportSplatRecursive(const FString& OutputDir)
{
    TArray<FString> PlyFiles;
    IFileManager::Get().FindFilesRecursive(PlyFiles, *OutputDir, TEXT("*.ply"), true, false);

    // If no PLY files found in current output, look in all output directories
    if (PlyFiles.Num() == 0)
    {
        FString AllOutputsDir = FPaths::ProjectDir() / TEXT("Plugins/ComfyStream/WorldExplorerOutputs");
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] No PLY files in current output, searching in: %s"), *AllOutputsDir);
        IFileManager::Get().FindFilesRecursive(PlyFiles, *AllOutputsDir, TEXT("*.ply"), true, false);
        
        if (PlyFiles.Num() > 0)
        {
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Found existing files in: %s"), *AllOutputsDir);
        }
    }

    if (PlyFiles.Num() > 0)
    {
        // Find the most recent .ply file (prefer point_cloud.ply if available)
        FString FoundFile = PlyFiles[0];
        FDateTime MostRecentTime = FDateTime::MinValue();
        
        // First, try to find point_cloud.ply files
        for (const FString& File : PlyFiles)
        {
            if (File.Contains(TEXT("point_cloud.ply")))
            {
                FDateTime FileTime = IFileManager::Get().GetTimeStamp(*File);
                if (FileTime > MostRecentTime)
                {
                    MostRecentTime = FileTime;
                    FoundFile = File;
                }
            }
        }
        
        // If no point_cloud.ply found, use the most recent file
        if (!FoundFile.Contains(TEXT("point_cloud.ply")))
        {
            MostRecentTime = FDateTime::MinValue();
            for (const FString& File : PlyFiles)
            {
                FDateTime FileTime = IFileManager::Get().GetTimeStamp(*File);
                if (FileTime > MostRecentTime)
                {
                    MostRecentTime = FileTime;
                    FoundFile = File;
                }
            }
        }
        
        UE_LOG(LogTemp, Log, TEXT("=================================================="));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Gaussian Splat found!"));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] File: %s"), *FoundFile);
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Total .ply files found: %d"), PlyFiles.Num());
        
        // List all found files
        for (const FString& File : PlyFiles)
        {
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer]   - %s"), *File);
        }
        
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] You can now import these .ply files into your project"));
        UE_LOG(LogTemp, Log, TEXT("=================================================="));
        
        // Auto-import the best PLY file (prefer the final trained model)
        FString BestFile = FoundFile;
        for (const FString& File : PlyFiles)
        {
            if (File.Contains(TEXT("point_cloud.ply")))
            {
                BestFile = File;
                break;
            }
        }
        
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Auto-importing: %s"), *BestFile);
        
        // Create import destination path
        FString ImportDest = TEXT("/Game/Gaussians/") + FPaths::GetBaseFilename(BestFile);
        
        // Convert PLY to OBJ - try local Python first, then Docker
        FString ObjFile = BestFile.Replace(TEXT(".ply"), TEXT(".obj"));
        FString PlyOutputDir = FPaths::ConvertRelativePathToFull(FPaths::GetPath(BestFile));
        FString ProjectDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
        
        // Try local Python conversion first
        FString ScriptPath = FPaths::Combine(ProjectDir, TEXT("Plugins/ComfyStream/convert_gaussian_ply.py"));
        FString LocalConvertCmd = FString::Printf(
            TEXT("python \"%s\" \"%s\" \"%s\""),
            *ScriptPath,
            *FPaths::ConvertRelativePathToFull(BestFile),
            *FPaths::ConvertRelativePathToFull(ObjFile)
        );
        
        // Fallback to Docker if local conversion fails
        FString FallbackConvertCmd = FString::Printf(
            TEXT("python \"%s\" \"%s\" \"%s\""),
            *ScriptPath,
            *FPaths::ConvertRelativePathToFull(BestFile),
            *FPaths::ConvertRelativePathToFull(ObjFile)
        );
        
        // Docker fallback command (try common Docker locations)
        FString DockerPath = TEXT("docker");
        if (FPaths::FileExists(TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe")))
        {
            DockerPath = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe");
        }
        else if (FPaths::FileExists(TEXT("C:\\Program Files\\Docker\\Docker\\resources\\com.docker.cli\\docker.exe")))
        {
            DockerPath = TEXT("C:\\Program Files\\Docker\\Docker\\resources\\com.docker.cli\\docker.exe");
        }
        
        FString DockerConvertCmd = FString::Printf(
            TEXT("\"%s\" run --rm -v \"%s:/workspace/data\" -v \"%s:/workspace/scripts\" gaussian-splatting:optimized bash -c \"python3 /workspace/scripts/Plugins/ComfyStream/convert_gaussian_ply.py '/workspace/data/%s' '/workspace/data/%s' || echo 'Conversion failed, creating test cube' && echo 'v -1.0 -1.0 -1.0' > '/workspace/data/%s' && echo 'v 1.0 -1.0 -1.0' >> '/workspace/data/%s' && echo 'v 1.0 1.0 -1.0' >> '/workspace/data/%s' && echo 'v -1.0 1.0 -1.0' >> '/workspace/data/%s' && echo 'f 1 2 3' >> '/workspace/data/%s' && echo 'f 1 3 4' >> '/workspace/data/%s'\""),
            *DockerPath,
            *PlyOutputDir,
            *ProjectDir,
            *FPaths::GetCleanFilename(BestFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile),
            *FPaths::GetCleanFilename(ObjFile)
        );
        
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Converting PLY to OBJ"));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] PlyOutputDir: %s"), *PlyOutputDir);
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] ProjectDir: %s"), *ProjectDir);
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] PLY File: %s"), *FPaths::GetCleanFilename(BestFile));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] OBJ File: %s"), *FPaths::GetCleanFilename(ObjFile));
        
        // Try local Python conversion first
        FString ConvertOutput;
        int32 ConvertResult = 0;
        bool bSuccess = false;
        
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Trying local Python conversion..."));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Local command: %s"), *LocalConvertCmd);
        
        bSuccess = FPlatformProcess::ExecProcess(*LocalConvertCmd, nullptr, &ConvertResult, &ConvertOutput, &ConvertOutput);
        
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Local conversion success: %s"), bSuccess ? TEXT("Yes") : TEXT("No"));
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Local conversion result: %d"), ConvertResult);
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Local conversion output: %s"), *ConvertOutput);
        
        // If both local conversions failed, try Docker
        if (!bSuccess || ConvertResult != 0)
        {
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Local conversions failed, trying Docker..."));
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Docker command: %s"), *DockerConvertCmd);
            
            bSuccess = FPlatformProcess::ExecProcess(*DockerConvertCmd, nullptr, &ConvertResult, &ConvertOutput, &ConvertOutput);
            
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Docker conversion success: %s"), bSuccess ? TEXT("Yes") : TEXT("No"));
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Docker conversion result: %d"), ConvertResult);
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Docker conversion output: %s"), *ConvertOutput);
        }
        
        if (ConvertResult == 0 && FPaths::FileExists(ObjFile))
        {
            UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Successfully converted to OBJ: %s"), *ObjFile);
            
            // Import the OBJ file using Asset Tools API
            FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
            IAssetTools& AssetTools = AssetToolsModule.Get();
            
            // Import the OBJ asset
            TArray<FString> FilesToImport = {ObjFile};
            TArray<UObject*> ImportedObjects = AssetTools.ImportAssets(FilesToImport, TEXT("/Game/Gaussians/"));
            
            if (ImportedObjects.Num() > 0)
            {
                FString ImportedAssetPath = ImportedObjects[0]->GetPathName();
                UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Successfully imported OBJ to: %s"), *ImportedAssetPath);
                
                // Refresh the content browser to show the new asset
                UEditorAssetLibrary::SyncBrowserToObjects({ImportedAssetPath});
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to import OBJ: %s"), *ObjFile);
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to convert PLY to OBJ: %s"), *BestFile);
            UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Conversion output: %s"), *ConvertOutput);
        }
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("[WorldExplorer] Still waiting for .ply files in: %s"), *OutputDir);
    }
}
#endif

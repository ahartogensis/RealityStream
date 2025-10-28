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
	FString VideoDestPath = DataDir / TEXT("input_video.mp4");
	
	// Create directories if they don't exist
	IFileManager::Get().MakeDirectory(*DataDir, true);
	IFileManager::Get().MakeDirectory(*OutputDir, true);
	
	// Copy video to data directory
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Copying video to: %s"), *VideoDestPath);
	if (!IFileManager::Get().Copy(*VideoDestPath, *VideoPath, true, true))
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to copy video file"));
		return;
	}
	
	// Run Docker reconstruction pipeline
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Starting reconstruction..."));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] This will take 5-10 minutes - extracting frames, running COLMAP, generating mesh..."));
	
	bool bSuccess = RunDockerReconstructionPipeline(VideoPath);
	
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Docker reconstruction failed"));
		return;
	}
	
	// Check if OBJ was created
	FString OBJPath = OutputDir / TEXT("point_cloud.obj");
	if (FPaths::FileExists(OBJPath))
	{
		UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓ Reconstruction complete! Spawning mesh..."));
		
		// Wait for file to be fully written
		FPlatformProcess::Sleep(1.0f);
		
		// Spawn at origin with scale and rotation
		FVector SpawnLocation = FVector(0, 0, -400);
		FRotator SpawnRotation = FRotator(90, 0, 0);
		FVector SpawnScale = FVector(500.0f, 500.0f, 500.0f);
		
		AActor* SpawnedActor = ImportAndSpawnOBJMesh(OBJPath, SpawnLocation, SpawnRotation, SpawnScale);
		
		if (SpawnedActor)
		{
			UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] ✓✓✓ SUCCESS! Mesh spawned in scene ✓✓✓"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] OBJ file not created: %s"), *OBJPath);
	}
}

bool UWorldExplorerSubsystem::RunDockerReconstructionPipeline(const FString& VideoPath)
{
	FString ProjectDir = GetProjectDirectory();
	FString DataDir = GetDataDirectory();
	FString OutputDir = GetPlyOutputDirectory();
	
	// Build Docker command to run the complete pipeline
	FString DockerCommand = FString::Printf(
		TEXT("\"C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe\" run --rm --gpus all ")
		TEXT("-v \"%s:/workspace/data\" ")
		TEXT("-v \"%s:/workspace/outputs\" ")
		TEXT("-v \"%s:/workspace/project\" ")
		TEXT("gaussian-splatting:optimized bash -c \"")
		// Step 1: Extract frames at 10 fps for optimal quality
		TEXT("echo '=== Extracting frames at 10 fps for maximum quality ===' && ")
		TEXT("rm -rf /workspace/data/input /workspace/data/sparse /workspace/data/distorted /workspace/data/temp /workspace/data/database.db || true && ")
		TEXT("mkdir -p /workspace/data/input && ")
		TEXT("ffmpeg -i /workspace/data/input_video.mp4 -qscale:v 1 -qmin 1 -vf fps=10 /workspace/data/input/frame_%%04d.jpg && ")
		// Step 2: Run COLMAP reconstruction
		TEXT("echo '=== Running COLMAP sparse reconstruction ===' && ")
		TEXT("python3 /workspace/gaussian-splatting/convert.py -s /workspace/data && ")
		// Step 3: Export to PLY
		TEXT("echo '=== Exporting point cloud to PLY ===' && ")
		TEXT("colmap model_converter --input_path /workspace/data/sparse/0 --output_path /workspace/outputs/point_cloud.ply --output_type PLY && ")
		// Step 4: Convert PLY to OBJ with maximum quality remeshing
		TEXT("echo '=== Converting to OBJ with MAXIMUM quality remeshing ===' && ")
		TEXT("python3 /workspace/project/Plugins/ComfyStream/convert_gaussian_ply.py /workspace/outputs/point_cloud.ply /workspace/outputs/point_cloud.obj && ")
		TEXT("echo '=== ✓ Pipeline complete! ===' && ")
		TEXT("ls -lh /workspace/outputs/point_cloud.obj\""),
		*DataDir,
		*OutputDir,
		*ProjectDir
	);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Executing Docker reconstruction pipeline..."));
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Command: %s"), *DockerCommand);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	
	bool bSuccess = FPlatformProcess::ExecProcess(
		*DockerCommand,
		TEXT(""),
		&ReturnCode,
		&Output,
		&Errors,
		*ProjectDir
	);
	
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker execution result: %d"), ReturnCode);
	UE_LOG(LogTemp, Display, TEXT("[WorldExplorer] Docker output: %s"), *Output);
	
	if (!Errors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[WorldExplorer] Docker errors: %s"), *Errors);
	}
	
	return bSuccess && ReturnCode == 0;
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
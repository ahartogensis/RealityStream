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

//reconstruction to mesh importer from World Explorer to Unreal Engine 5.6 

void USplatCreatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Subsystem initialized"));
}

void USplatCreatorSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Subsystem deinitialized"));
}

// =====================================================
//  MAIN ENTRY
// =====================================================

void USplatCreatorSubsystem::CheckAndImportSplat(const FString& VideoPath)
{
	const FString OutputDir = GetOutputDirectory();
	const FString PlyFile = OutputDir / TEXT("point_cloud.ply");
	const FString ObjFile = OutputDir / TEXT("point_cloud.obj");

	if (FPaths::FileExists(PlyFile))
	{
		UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Found existing PLY, converting..."));
		ConvertPLYToOBJ(PlyFile, ObjFile);
		return;
	}

	if (!VideoPath.IsEmpty() && FPaths::FileExists(VideoPath))
	{
		ProcessVideoToMesh(VideoPath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[SplatCreator] No PLY or valid video file found."));
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
	FString PlyOutputDir = FPaths::GetPath(PLYPath);
	FString ProjectDir = GetProjectDirectory();
	
	FString Command = FString::Printf(
		TEXT("\"C:\\Program Files\\Docker\\Docker\\resources\\bin\\docker.exe\" run --rm -v \"%s:/workspace/data\" -v \"%s:/workspace/scripts\" gaussian-splatting:optimized bash -c \"python3 /workspace/scripts/Plugins/RealityStream/convert_gaussian_ply.py '/workspace/data/point_cloud.ply' '/workspace/data/point_cloud.obj'\""),
		*PlyOutputDir,
		*ProjectDir
	);
	
	int32 ReturnCode = 0;
	FString Output;
	FString Errors;
	
	bool bSuccess = FPlatformProcess::ExecProcess(*Command, TEXT(""), &ReturnCode, &Output, &Errors);
	
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Docker execution result: %d"), ReturnCode);
	UE_LOG(LogTemp, Display, TEXT("[SplatCreator] Docker output: %s"), *Output);
	if (!Errors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[SplatCreator] Docker errors: %s"), *Errors);
	}
	
	if (bSuccess && ReturnCode == 0 && FPaths::FileExists(OBJPath))
	{
		ImportAndSpawnOBJMesh(OBJPath, FVector(0,0,-300), FRotator(90,0,0), FVector(500));
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("[SplatCreator] OBJ not found after conversion"));
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

	MeshActor->SetActorLocation(Location);
	MeshActor->SetActorRotation(Rotation);
	MeshActor->SetActorScale3D(Scale);

	UProceduralMeshComponent* MeshComp = CreateProceduralMeshFromOBJ(ObjPath, MeshActor);
	if (MeshComp)
	{
		MeshComp->SetMobility(EComponentMobility::Movable);
		MeshActor->SetRootComponent(MeshComp);
		
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
			UE_LOG(LogTemp, Display, TEXT("  Color[%d]: R=%d G=%d B=%d"), i, Color.R, Color.G, Color.B);
		}
	}

	return true;
}


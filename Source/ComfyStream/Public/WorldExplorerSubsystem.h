#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/World.h"
#include "WorldExplorerSubsystem.generated.h"

/**
 * WorldExplorer subsystem for handling Gaussian splat conversions
 */
UCLASS(BlueprintType)
class COMFYSTREAM_API UWorldExplorerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// USubsystem interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// WorldExplorer functionality - Blueprint callable for runtime use
	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void ImportExistingSplat();

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void RunGaussianSplat();

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void CheckAndImportSplat(const FString& VideoPath = TEXT(""));

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void ConvertPLYToOBJ(const FString& PLYPath, const FString& OBJPath);

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	AActor* ImportAndSpawnOBJMesh(const FString& OBJPath, FVector SpawnLocation = FVector::ZeroVector, FRotator SpawnRotation = FRotator(90, 0, 0), FVector SpawnScale = FVector(400.0f, 400.0f, 400.0f));

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void ConvertAndSpawnPLY(const FString& PLYPath, FVector SpawnLocation = FVector::ZeroVector, FRotator SpawnRotation = FRotator(90, 0, 0), FVector SpawnScale = FVector(400.0f, 400.0f, 400.0f));

	UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
	void ProcessVideoToMesh(const FString& VideoPath);

private:
	// Helper functions
	FString GetProjectDirectory();
	FString GetPlyOutputDirectory();
	FString GetDataDirectory();
	bool ExecutePythonScript(const FString& ScriptPath, const FString& InputPath, const FString& OutputPath);
	bool ExecuteDockerScript(const FString& InputPath, const FString& OutputPath);
	bool RunDockerReconstructionPipeline(const FString& VideoPath);
	
	// Runtime mesh import helpers
	class UProceduralMeshComponent* CreateProceduralMeshFromOBJ(const FString& OBJPath, AActor* Owner);
	bool ParseOBJFile(const FString& OBJPath, TArray<FVector>& OutVertices, TArray<int32>& OutTriangles, TArray<FVector>& OutNormals, TArray<FColor>& OutVertexColors);
};

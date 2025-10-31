#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SplatCreatorSubsystem.generated.h"

class UProceduralMeshComponent;

UCLASS(BlueprintType)
class REALITYSTREAM_API USplatCreatorSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	//Entry point: Reconstruct video → spawn Gaussian mesh or import existing PLY 
	UFUNCTION(BlueprintCallable, Category = "SplatCreator")
	void CheckAndImportSplat(const FString& VideoPath = TEXT(""));

private:
	// Core pipeline
	void ImportExistingSplat();
	void ProcessVideoToMesh(const FString& VideoPath);
	bool RunDockerReconstructionPipeline(const FString& VideoPath);

	// File operations
	bool ConvertPLYToOBJ(const FString& PLYPath, const FString& OBJPath);
	FString GetProjectDirectory() const;
	FString GetOutputDirectory() const;
	FString GetDataDirectory() const;

	// Runtime import
	AActor* ImportAndSpawnOBJMesh(const FString& OBJPath, FVector Location, FRotator Rotation, FVector Scale);
	UProceduralMeshComponent* CreateProceduralMeshFromOBJ(const FString& OBJPath, AActor* Owner);
	bool ParseOBJFile(const FString& OBJPath, TArray<FVector>& OutVertices, TArray<int32>& OutTriangles, TArray<FVector>& OutNormals, TArray<FColor>& OutColors);

	// Async auto-spawn polling
	FTimerHandle AutoSpawnTimer;
	void CheckAndAutoSpawnMesh();
};

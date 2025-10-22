#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WorldExplorerSubsystem.generated.h"

/**
 * Handles launching WorldExplorer and auto-importing Gaussian splats
 * Works at both runtime and in editor
 */
UCLASS()
class COMFYSTREAM_API UWorldExplorerSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    /**
     * Generate a Gaussian Splat from a video file using WorldExplorer
     * @param VideoPath - Full path to the video file to process
     * @param OutputDir - Optional custom output directory. If empty, uses default location
     */
    UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
    void GenerateGaussianSplat(const FString& VideoPath, const FString& OutputDir = "");

    /**
     * Get the default output directory for WorldExplorer results
     */
    UFUNCTION(BlueprintPure, Category = "WorldExplorer")
    FString GetDefaultOutputDirectory() const;

    /**
     * Run Gaussian Splatting from video using Docker container
     * @param VideoPath - Full path to the video file to process
     */
    UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
    void RunGaussianSplatFromVideo(const FString& VideoPath);

    /**
     * Import an existing Gaussian Splat from the outputs directory
     * Useful for testing or importing previously generated splats
     */
    UFUNCTION(BlueprintCallable, Category = "WorldExplorer")
    void ImportExistingSplat();

private:
    void RunWorldExplorer(const FString& VideoPath, const FString& OutputDir);
    
#if WITH_EDITOR
    void TryImportSplat(const FString& OutputDir);
    void TryImportSplatRecursive(const FString& OutputDir);
#endif
};


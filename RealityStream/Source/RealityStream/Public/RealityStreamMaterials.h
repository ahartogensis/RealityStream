#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"

class UMaterialInterface;

namespace RealityStreamMaterials
{
	/** Loads first valid material from GamePaths, then engine fallbacks safe for packaged builds. */
	UMaterialInterface* LoadMaterialWithFallbacks(const TArray<FString>& GamePaths);

	UMaterialInterface* GetSplatMorphMaterial();
	UMaterialInterface* GetProceduralMeshBaseMaterial();
}

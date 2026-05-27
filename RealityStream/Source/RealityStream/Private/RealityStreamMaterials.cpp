#include "RealityStreamMaterials.h"

#include "Materials/MaterialInterface.h"
#include "UObject/UObjectGlobals.h"

namespace RealityStreamMaterials
{
	static UMaterialInterface* LoadFirstValid(const TArray<FString>& Paths)
	{
		for (const FString& Path : Paths)
		{
			if (Path.IsEmpty())
			{
				continue;
			}

			if (UMaterialInterface* Mat = Cast<UMaterialInterface>(FSoftObjectPath(Path).TryLoad()))
			{
				return Mat;
			}

			if (UMaterialInterface* Mat = LoadObject<UMaterialInterface>(nullptr, *Path))
			{
				return Mat;
			}
		}

		return nullptr;
	}

	UMaterialInterface* LoadMaterialWithFallbacks(const TArray<FString>& GamePaths)
	{
		if (UMaterialInterface* Mat = LoadFirstValid(GamePaths))
		{
			return Mat;
		}

		static const TArray<FString> EngineFallbacks = {
			TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"),
			TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"),
		};

		return LoadFirstValid(EngineFallbacks);
	}

	UMaterialInterface* GetSplatMorphMaterial()
	{
		static TWeakObjectPtr<UMaterialInterface> Cached;
		if (Cached.IsValid())
		{
			return Cached.Get();
		}

		static const TArray<FString> Paths = {
			TEXT("/Game/_GENERATED/Materials/M_SplatMorph.M_SplatMorph"),
			TEXT("/Game/_GENERATED/Materials/M_VertexColor.M_VertexColor"),
		};

		UMaterialInterface* Mat = LoadMaterialWithFallbacks(Paths);
		Cached = Mat;
		if (!Mat)
		{
			UE_LOG(LogTemp, Warning,
				TEXT("[RealityStream] Splat morph material not found. Add /Game/_GENERATED/Materials to cook list or assign M_SplatMorph on the map."));
		}
		return Mat;
	}

	UMaterialInterface* GetProceduralMeshBaseMaterial()
	{
		static TWeakObjectPtr<UMaterialInterface> Cached;
		if (Cached.IsValid())
		{
			return Cached.Get();
		}

		static const TArray<FString> Paths = {
			TEXT("/Game/_GENERATED/Materials/M_ProceduralMeshTexture.M_ProceduralMeshTexture"),
			TEXT("/Game/M_ProceduralMeshTexture.M_ProceduralMeshTexture"),
			TEXT("/Game/ImportedTextures/M_ProceduralMeshTexture.M_ProceduralMeshTexture"),
			TEXT("/Game/_GENERATED/Materials/M_VertexColor.M_VertexColor"),
			TEXT("/Game/M_VertexColor.M_VertexColor"),
		};

		UMaterialInterface* Mat = LoadMaterialWithFallbacks(Paths);
		Cached = Mat;
		if (!Mat)
		{
			UE_LOG(LogTemp, Warning,
				TEXT("[RealityStream] Procedural mesh base material not found. Cook /Game/_GENERATED/Materials (M_ProceduralMeshTexture)."));
		}
		return Mat;
	}
}

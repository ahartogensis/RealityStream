#include "RealityStreamPaths.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"

namespace RealityStreamPaths
{
	static FString CachedPluginBaseDir;

	FString GetPluginBaseDir()
	{
		if (!CachedPluginBaseDir.IsEmpty() && FPaths::DirectoryExists(CachedPluginBaseDir))
		{
			return CachedPluginBaseDir;
		}

		if (TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("RealityStream"));
			Plugin.IsValid())
		{
			const FString BaseDir = FPaths::ConvertRelativePathToFull(Plugin->GetBaseDir());
			if (FPaths::DirectoryExists(BaseDir))
			{
				CachedPluginBaseDir = BaseDir;
				return CachedPluginBaseDir;
			}
		}

		const TArray<FString> Candidates = {
			FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/RealityStream")),
			FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("RealityStream")),
			FPaths::Combine(FPaths::LaunchDir(), TEXT("Plugins/RealityStream")),
		};

		for (const FString& Candidate : Candidates)
		{
			const FString Full = FPaths::ConvertRelativePathToFull(Candidate);
			if (FPaths::DirectoryExists(Full))
			{
				CachedPluginBaseDir = Full;
				return CachedPluginBaseDir;
			}
		}

		UE_LOG(LogTemp, Error,
			TEXT("[RealityStream] Could not find plugin data folder. Expected Plugins/RealityStream next to the project or executable (with SplatCreatorOutputs and MeshImport)."));

		CachedPluginBaseDir = FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/RealityStream"));
		return CachedPluginBaseDir;
	}

	FString GetSplatCreatorOutputsDir()
	{
		return GetPluginBaseDir() / TEXT("SplatCreatorOutputs");
	}

	FString GetMeshImportDir()
	{
		return GetPluginBaseDir() / TEXT("MeshImport");
	}
}

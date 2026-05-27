using System.IO;
using UnrealBuildTool;

public class RealityStream : ModuleRules
{
    public RealityStream(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {});
        PrivateIncludePaths.AddRange(new string[] {});

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "ImageWrapper",
                "WebSockets",
                "ProceduralMeshComponent",
                "Json",
                "JsonUtilities"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
                "RenderCore",
                "RHI",
                "Projects"
            }
        );

        StagePluginRuntimeDataDirectories();

        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "UnrealEd",
                    "InputCore",
                    "EditorStyle",
                    "LevelEditor",
                    "AssetTools",
                    "AssetRegistry"
                }
            );
        }
    }

    /** Copies SplatCreatorOutputs + MeshImport next to the staged plugin (required for packaged splats/OBJ import). */
    void StagePluginRuntimeDataDirectories()
    {
        if (Target.Type != TargetRules.TargetType.Game)
        {
            return;
        }

        string[] DataDirNames = { "SplatCreatorOutputs", "MeshImport" };
        foreach (string DirName in DataDirNames)
        {
            string FullDir = Path.Combine(PluginDirectory, DirName);
            if (!Directory.Exists(FullDir))
            {
                continue;
            }

            foreach (string FilePath in Directory.EnumerateFiles(FullDir, "*", SearchOption.AllDirectories))
            {
                string FileName = Path.GetFileName(FilePath);
                if (FileName.Equals("desktop.ini", System.StringComparison.OrdinalIgnoreCase)
                    || FileName.StartsWith(".", System.StringComparison.Ordinal))
                {
                    continue;
                }

                RuntimeDependencies.Add(FilePath, StagedFileType.NonUFS);
            }
        }
    }
}

using UnrealBuildTool;

public class ComfyStream : ModuleRules
{
	public ComfyStream(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {"ComfyStream/Public"
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[] {"ComfyStream/Private"
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ImageWrapper",
				"WebSockets",
				"ProceduralMeshComponent"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				"RenderCore",
				"RHI"
			}
		);
		
		// Editor-only dependencies for WorldExplorer functionality
		if (Target.Type == TargetRules.TargetType.Editor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd",
					"InputCore",
					"Projects",
					"EditorStyle",
					"LevelEditor"
				}
			);
		}
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}

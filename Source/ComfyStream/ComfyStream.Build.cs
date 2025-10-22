using UnrealBuildTool;

public class ComfyStream : ModuleRules
{
	public ComfyStream(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[] {
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ImageWrapper",
				"HTTP",
				"Json",
				"WebSockets"
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
					"EditorSubsystem",
					"InputCore",
					"Projects",
					"EditorStyle",
					"LevelEditor",
					"AssetTools",
					"DesktopPlatform",
					"EditorScriptingUtilities"  // For EditorAssetLibrary
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

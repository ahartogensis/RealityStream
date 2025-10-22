#include "ComfyStream.h"

#define LOCTEXT_NAMESPACE "FComfyStreamModule"

void FComfyStreamModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file
#if WITH_EDITOR
	// Delay-load WorldExplorer functionality to avoid including editor headers in runtime module
	if (GIsEditor)
	{
		// This will be compiled only in editor builds
		extern void RegisterWorldExplorerMenus();
		RegisterWorldExplorerMenus();
	}
#endif
}

void FComfyStreamModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FComfyStreamModule, ComfyStream)

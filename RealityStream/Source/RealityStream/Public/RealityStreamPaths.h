#pragma once

#include "CoreMinimal.h"

namespace RealityStreamPaths
{
	/** Plugin root (editor, PIE, and packaged when data is staged). */
	FString GetPluginBaseDir();

	FString GetSplatCreatorOutputsDir();
	FString GetMeshImportDir();
}

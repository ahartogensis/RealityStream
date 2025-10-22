#if WITH_EDITOR

#include "WorldExplorerCommand.h"
#include "WorldExplorerSubsystem.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "LevelEditor.h"
#include "DesktopPlatformModule.h"
#include "Editor.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

void FWorldExplorerCommand::RegisterMenus()
{
    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

    TSharedPtr<FExtender> Extender = MakeShareable(new FExtender());
    Extender->AddMenuExtension("FileLoadAndSave", EExtensionHook::After, nullptr,
        FMenuExtensionDelegate::CreateLambda([](FMenuBuilder& MenuBuilder)
        {
            MenuBuilder.AddMenuEntry(
                FText::FromString("Generate Gaussian Splat from Video"),
                FText::FromString("Process a video file with WorldExplorer to generate a Gaussian Splat"),
                FSlateIcon(),
                FUIAction(FExecuteAction::CreateStatic(&FWorldExplorerCommand::ExecuteGenerateSplat))
            );
        })
    );

    LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(Extender);
}

void FWorldExplorerCommand::ExecuteGenerateSplat()
{
    FString VideoPath = OpenFileDialog();
    if (VideoPath.IsEmpty())
        return;

    // Get the subsystem from the current game instance
    if (GEditor && GEditor->GetEditorWorldContext().World())
    {
        UWorld* World = GEditor->GetEditorWorldContext().World();
        if (UGameInstance* GameInstance = World->GetGameInstance())
        {
            if (UWorldExplorerSubsystem* Subsystem = GameInstance->GetSubsystem<UWorldExplorerSubsystem>())
            {
                Subsystem->GenerateGaussianSplat(VideoPath);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("[WorldExplorer] Failed to get WorldExplorerSubsystem"));
            }
        }
    }
}

FString FWorldExplorerCommand::OpenFileDialog()
{
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (!DesktopPlatform)
        return FString();

    TArray<FString> OutFiles;
    bool bOpened = DesktopPlatform->OpenFileDialog(
        nullptr,
        TEXT("Select Video File"),
        TEXT(""),
        TEXT(""),
        TEXT("Video Files (*.mp4;*.mov)|*.mp4;*.mov"),
        EFileDialogFlags::None,
        OutFiles
    );

    return bOpened && OutFiles.Num() > 0 ? OutFiles[0] : FString();
}

// Export function so the main module can call this without including the header
void RegisterWorldExplorerMenus()
{
    FWorldExplorerCommand::RegisterMenus();
}

#endif // WITH_EDITOR


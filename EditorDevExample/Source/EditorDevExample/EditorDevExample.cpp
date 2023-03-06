// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorDevExample.h"

#include "ContentBrowserModule.h"
#include "LevelEditor.h"
#include "Commands/FMenuBarOption0Commands.h"
#include "Helper/FEditorExtensionHelper.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FEditorDevExample, EditorDevExample, "EditorDevExample");

#define LOCTEXT_NAMESPACE "FEditorDevExample"

void FEditorDevExample::StartupModule()
{
	static FName LevelEditorName = FName("LevelEditor");
	static FName HelpName = FName("Help");
	FMenuBarOption0Commands::Register();
	BindCommandsForMyMenuBarOption();
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(LevelEditorName);
	const TSharedPtr<FExtender> EditorExtender = MakeShareable(new FExtender());
	EditorExtender->AddMenuBarExtension(HelpName, EExtensionHook::After, nullptr,
	                                    FMenuBarExtensionDelegate::CreateRaw(
		                                    this, &FEditorDevExample::AddMyMenuBarOption));

	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(EditorExtender);
	IModuleInterface::StartupModule();
}

void FEditorDevExample::ShutdownModule()
{
	FMenuBarOption0Commands::Unregister();
	IModuleInterface::ShutdownModule();
}

void FEditorDevExample::BindCommandsForMyMenuBarOption()
{
	static FName LevelEditorName = FName("LevelEditor");
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(LevelEditorName);
	TSharedRef<FUICommandList> LevelEditorCommandList = LevelEditorModule.GetGlobalLevelEditorActions();
	LevelEditorCommandList->MapAction(
		FMenuBarOption0Commands::Get().HelloWorldCommand,
		FExecuteAction::CreateRaw(&Helper, &FEditorExtensionHelper::PrintHelloWorld)
	);
	LevelEditorCommandList->MapAction(
			FMenuBarOption0Commands::Get().ShowNotifyWindowCommand,
			FExecuteAction::CreateRaw(&Helper, &FEditorExtensionHelper::ShowNotifyWindow)
		);
	LevelEditorCommandList->MapAction(
				FMenuBarOption0Commands::Get().ShowMessageDialogCommand,
				FExecuteAction::CreateRaw(&Helper, &FEditorExtensionHelper::ShowMessageDialog)
			);
	LevelEditorCommandList->MapAction(
				FMenuBarOption0Commands::Get().CountNumberCommand,
				FExecuteAction::CreateRaw(&Helper, &FEditorExtensionHelper::CountNumber)
			);
}
	


void FEditorDevExample::AddMyMenuBarOption(FMenuBarBuilder& Builder)
{
	static FName MyMenubarOption0Name = FName("MyMenubarOption0");
	Builder.AddPullDownMenu(
		LOCTEXT("MyMenubarOption0", "MyMenubarOption0"),
		LOCTEXT("MyMenubarOption0ToolTip", "MyMenubarOption0 we added by Code"),
		FNewMenuDelegate::CreateRaw(this, &FEditorDevExample::AddOptionsUnderMyMenuBarOption),
		MyMenubarOption0Name
	);
}

void FEditorDevExample::AddOptionsUnderMyMenuBarOption(FMenuBuilder& Builder)
{
	static FName HelloWorldName = FName("Hello World");
	Builder.BeginSection(HelloWorldName,LOCTEXT("Hello World", "Hello World"));
	Builder.AddMenuEntry(FMenuBarOption0Commands::Get().HelloWorldCommand, HelloWorldName
	);
	Builder.EndSection();
	Builder.AddSeparator();
	
	static FName ShowNotifyWindowName = FName("ShowNotifyWindow");

	Builder.BeginSection(HelloWorldName,LOCTEXT("Pop Window", "Pop Window"));
	Builder.AddMenuEntry(FMenuBarOption0Commands::Get().ShowNotifyWindowCommand, ShowNotifyWindowName
	);

	static FName ShowMessageDialogName = FName("ShowMessageDialog");
	Builder.AddMenuEntry(FMenuBarOption0Commands::Get().ShowMessageDialogCommand, ShowMessageDialogName
	);

	static FName CountNumberName = FName("CountNumber");
	Builder.AddMenuEntry(FMenuBarOption0Commands::Get().CountNumberCommand, CountNumberName
	);
	Builder.EndSection();
}

#undef LOCTEXT_NAMESPACE

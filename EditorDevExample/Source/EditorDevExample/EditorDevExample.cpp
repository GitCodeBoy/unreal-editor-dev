// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorDevExample.h"

#include "ContentBrowserModule.h"
#include "LevelEditor.h"
#include "Commands/FMenuBarOption0Commands.h"
#include "Helper/FEditorExtensionHelper.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FEditorDevExample, EditorDevExample, "EditorDevExample");


void FEditorDevExample::StartupModule()
{
	FMenuBarOption0Commands::Register();
	BindCommandsForMyMenuBarOption();
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedPtr<FExtender> EditorExtender = MakeShareable(new FExtender());
	EditorExtender->AddMenuBarExtension(FName("Help"), EExtensionHook::After, nullptr,
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
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedRef<FUICommandList> LevelEditorCommandList = LevelEditorModule.GetGlobalLevelEditorActions();
	LevelEditorCommandList->MapAction(
		FMenuBarOption0Commands::Get().HelloWorldCommand,
		FExecuteAction::CreateRaw(&Helper,&FEditorExtensionHelper::PrintHelloWorld)
		);
	
}

void FEditorDevExample::AddMyMenuBarOption(FMenuBarBuilder& Builder) 
{
	Builder.AddPullDownMenu(FText::FromString(FString("MyMenubarOption0")),
	                        FText::FromString(FString("MyMenubarOption0 add by Code")),
	                        FNewMenuDelegate::CreateRaw(this, &FEditorDevExample::AddOptionsUnderMyMenuBarOption),
	                        "MyMenubarOption0");
}

void FEditorDevExample::AddOptionsUnderMyMenuBarOption(FMenuBuilder& Builder) 
{
	// FText::FromString("HelloWorld"), FText::FromString("print HelloWorld")
	Builder.BeginSection("Section0",FText::FromString("Section0"));
	Builder.AddMenuEntry(FMenuBarOption0Commands::Get().HelloWorldCommand, "HelloWorldMenu"
	);
	Builder.EndSection();
	Builder.AddSeparator();
}



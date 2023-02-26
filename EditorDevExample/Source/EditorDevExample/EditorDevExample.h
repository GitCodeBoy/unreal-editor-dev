// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Helper/FEditorExtensionHelper.h"
class FUICommandList;
class FEditorDevExample:public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void BindCommandsForMyMenuBarOption() ;
	void AddMyMenuBarOption(FMenuBarBuilder& Builder) ;
	void AddOptionsUnderMyMenuBarOption(FMenuBuilder& Builder) ;
public:
	TSharedPtr< FUICommandList> CommandList;
	FEditorExtensionHelper Helper;
};

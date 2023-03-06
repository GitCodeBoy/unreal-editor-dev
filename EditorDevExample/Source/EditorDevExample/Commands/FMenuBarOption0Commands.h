#pragma once

#define LOCTEXT_NAMESPACE "FMenuBarOption0Commands"
class FMenuBarOption0Commands : public TCommands<FMenuBarOption0Commands>
{
public:
	FMenuBarOption0Commands()
		: TCommands<FMenuBarOption0Commands>(TEXT("MenuBarOption0Commands"),
		                                     LOCTEXT("FMenuBarOption0CommandsDescribe","Commands for MenuBarOption0"),
		                                     NAME_None, FName("Todo"))
	{
	}

	virtual void RegisterCommands() override;
public:
	TSharedPtr<class FUICommandInfo> HelloWorldCommand;
	TSharedPtr<class FUICommandInfo> ShowNotifyWindowCommand;
	TSharedPtr<class FUICommandInfo> ShowMessageDialogCommand;
	TSharedPtr<class FUICommandInfo> CountNumberCommand;
	
};
#undef LOCTEXT_NAMESPACE
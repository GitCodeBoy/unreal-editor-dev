#pragma once


class FMenuBarOption0Commands : public TCommands<FMenuBarOption0Commands>
{
public:
	FMenuBarOption0Commands()
		: TCommands<FMenuBarOption0Commands>(TEXT("MenuBarOption0Commands"),
		                                     FText::FromString("Example Menu tool"), 
		                                     NAME_None, FName("Todo"))
	{
	}
	
	virtual void RegisterCommands() override;
public:
	TSharedPtr<class FUICommandInfo> HelloWorldCommand;
};

#include "FMenuBarOption0Commands.h"

#define LOCTEXT_NAMESPACE "FMenuBarOption0Commands"
void FMenuBarOption0Commands::RegisterCommands()
{
	UI_COMMAND(HelloWorldCommand,"HelloWorld","Print hello world string in console",EUserInterfaceActionType::Button,FInputChord());
	UI_COMMAND(ShowNotifyWindowCommand,"ShowNotifyWindow","Show Notify Window",EUserInterfaceActionType::Button,FInputChord());
	UI_COMMAND(ShowMessageDialogCommand,"ShowMessageDialog","Show Message Dialog",EUserInterfaceActionType::Button,FInputChord());
	UI_COMMAND(CountNumberCommand,"CountNumber","Count Number From 0 To 1000 ",EUserInterfaceActionType::Button,FInputChord());
}
#undef LOCTEXT_NAMESPACE


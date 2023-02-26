#include "FMenuBarOption0Commands.h"

#define LOCTEXT_NAMESPACE "FMenuBarOption0Commands"
void FMenuBarOption0Commands::RegisterCommands()
{
	UI_COMMAND(HelloWorldCommand,"HelloWorld","Print hello world string in console",EUserInterfaceActionType::Button,FInputChord());
}
#undef LOCTEXT_NAMESPACE


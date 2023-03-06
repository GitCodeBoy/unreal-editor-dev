#include "FEditorExtensionHelper.h"

#include "Framework/Notifications/NotificationManager.h"
#include "Misc/MessageDialog.h"
#include "Widgets/Notifications/SNotificationList.h"
#define LOCTEXT_NAMESPACE "FEditorExtensionHelper"

void FEditorExtensionHelper::PrintHelloWorld()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
}

void FEditorExtensionHelper::ShowNotifyWindow()
{
	FSlateNotificationManager& Manager = FSlateNotificationManager::Get();
	FNotificationInfo Info(LOCTEXT("Notifycation Text", "Notifycation Text"));
	Manager.AddNotification(Info);
}

void FEditorExtensionHelper::ShowMessageDialog()
{
	const FText MessageDialogContent = LOCTEXT("MessageDialogContent", "MessageDialogContent");
	const FText MessageDialogTitle = LOCTEXT("MessageDialogTitle", "MessageDialogTitle");
	EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNoYesAllNoAllCancel, MessageDialogContent,
	                                                   &MessageDialogTitle);
	if (Result == EAppReturnType::YesAll)
	{
		UE_LOG(LogTemp, Warning, TEXT("YesAll"));
	}
}

void FEditorExtensionHelper::CountNumber()
{
	GWarn->BeginSlowTask(LOCTEXT("Count Number", "Count Number from 0 to 9"), true, false);
	for (int i = 0; i < 10; i++)
	{
		GWarn->UpdateProgress(i + 1, 10);
		FPlatformProcess::Sleep(1);
	}
	GWarn->EndSlowTask();
}
#undef LOCTEXT_NAMESPACE

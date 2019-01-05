// Fill out your copyright notice in the Description page of Project Settings.

#include "MainLoginWidget.h"

#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/Border.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "PFGameInstance.h"


void UMainLoginWidget::NativeConstruct()
{
	// Call the Blueprint "Event Construct" node
	Super::NativeConstruct();

	if (CheckWidgets())
	{
		LoginWidgetsShow();
	} 
	else
	{
		return;
	};
}

// Items can be nullptr if we haven't created it in the
// Blueprint subclass
bool UMainLoginWidget::CheckWidgets()
{
	if (!HeaderEmail)
	{
		UE_LOG(LogTemp, Error, TEXT("HeaderEmail is lost"))
		return false;
	}
	if (!HeaderPassword)
	{
		UE_LOG(LogTemp, Error, TEXT("HeaderPassword is lost"))
		return false;
	}
	if (!BorderEmail)
	{
		UE_LOG(LogTemp, Error, TEXT("BorderEmail is lost"))
		return false;
	}
	if (!BorderPassword)
	{
		UE_LOG(LogTemp, Error, TEXT("BorderPassword is lost"))
		return false;
	}
	if (!InputEmail)
	{
		UE_LOG(LogTemp, Error, TEXT("InputEmail is lost"))
		return false;
	}
	if (!InputPassword)
	{
		UE_LOG(LogTemp, Error, TEXT("InputPassword is lost"))
		return false;
	}
	if (!ButtonLogin)
	{
		UE_LOG(LogTemp, Error, TEXT("ButtonLogin is lost"))
		return false;
	}
	if (!ButtonLoginText)
	{
		UE_LOG(LogTemp, Error, TEXT("ButtonLoginText is lost"))
		return false;
	}
	return true;
}

void UMainLoginWidget::LoginWidgetsShow()
{
	HeaderEmail->SetText(FText::FromString(TextLogin));
	HeaderEmail->SetVisibility(ESlateVisibility::Visible);

	HeaderPassword->SetText(FText::FromString(TextPassword));
	HeaderPassword->SetVisibility(ESlateVisibility::Visible);

	BorderEmail->SetVisibility(ESlateVisibility::Visible);

	BorderPassword->SetVisibility(ESlateVisibility::Visible);

	ButtonLogin->OnClicked.AddDynamic(this, &UMainLoginWidget::ButtonLoginClicked);
	ButtonLogin->SetVisibility(ESlateVisibility::Visible);

	ButtonLoginText->SetText(FText::FromString(TextButton));
}

void UMainLoginWidget::LoginWidgetsHide()
{
	HeaderEmail->SetVisibility(ESlateVisibility::Hidden);
	HeaderPassword->SetVisibility(ESlateVisibility::Hidden);
	BorderEmail->SetVisibility(ESlateVisibility::Hidden);
	BorderPassword->SetVisibility(ESlateVisibility::Hidden);
	ButtonLogin->SetVisibility(ESlateVisibility::Hidden);
}

void UMainLoginWidget::ButtonLoginClicked()
{
	// Clearify Error Message
	Message->SetText(FText::FromString(""));

	UPFGameInstance* PFGI = Cast<UPFGameInstance>(GetWorld()->GetGameInstance());
	if (IsValid(PFGI))
	{
		PFGI->Login(InputEmail->GetText(), InputPassword->GetText(), this);
	}
}

void UMainLoginWidget::LoginSuccess()
{
	Message->SetText(FText::FromString(TextLoginSuccess));
	LoginWidgetsHide();
}

void UMainLoginWidget::LoginFail(FString ErrorText)
{
	Message->SetText(FText::FromString(ErrorText));
}

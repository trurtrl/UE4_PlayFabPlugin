// Fill out your copyright notice in the Description page of Project Settings.

#include "PFGameInstance.h"



UPFGameInstance::UPFGameInstance()
{
	/*
	clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	clientAPI->SetTitleId(TEXT("9D95"));

	PlayFab::ClientModels::FLoginWithCustomIDRequest request;
	request.CustomId = TEXT("GettingStartedGuide");
	request.CreateAccount = true;*/

/*	clientAPI->LoginWithCustomID(request,
		PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &UPFGameInstance::OnSuccess),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UPFGameInstance::OnError)
	);*/
}

//	 void (UMainLoginWidget::*OnSuccess)(), void (UMainLoginWidget::*OnError)()

void UPFGameInstance::Login(FText Email, FText Password, UMainLoginWidget* LoginWidget)
{
	clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	clientAPI->SetTitleId(TitleId);	
	
	MainLoginWidget = LoginWidget;
	PlayFab::ClientModels::FLoginWithEmailAddressRequest request;
	request.Email = Email.ToString();
	request.Password = Password.ToString();

	clientAPI->LoginWithEmailAddress(request,
		PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateUObject(this, &UPFGameInstance::OnSuccess),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UPFGameInstance::OnError)
	);
}

void UPFGameInstance::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
{
//	UE_LOG(LogTemp, Warning, TEXT("Congratulations, you've logged in PlayFab!"));
	MainLoginWidget->LoginSuccess();
}

void UPFGameInstance::OnError(const PlayFab::FPlayFabError& ErrorResult) const
{
//	UE_LOG(LogTemp, Error, TEXT("Something went wrong with call.\nHere's some debug information:\n%s"), *ErrorResult.GenerateErrorReport());
	MainLoginWidget->LoginFail(ErrorResult.GenerateErrorReport());
}




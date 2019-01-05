// Fill out your copyright notice in the Description page of Project Settings.

#include "PFGameInstance.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


UPFGameInstance::UPFGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuClassFinder(TEXT("/Game/Menu"));
	MenuClass = MenuClassFinder.Class;

	clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	clientAPI->SetTitleId(TEXT("9D95"));

	PlayFab::ClientModels::FLoginWithCustomIDRequest request;
	request.CustomId = TEXT("GettingStartedGuide");
	request.CreateAccount = true;

/*	clientAPI->LoginWithCustomID(request,
		PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &UPFGameInstance::OnSuccess),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UPFGameInstance::OnError)
	);*/
}

void UPFGameInstance::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
{
	UE_LOG(LogTemp, Warning, TEXT("Congratulations, you've logged in PlayFab!"));
}

void UPFGameInstance::OnError(const PlayFab::FPlayFabError& ErrorResult) const
{
	UE_LOG(LogTemp, Error, TEXT("Something went wrong with call.\nHere's some debug information:\n%s"), *ErrorResult.GenerateErrorReport());
}




// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "PlayFab.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientAPI.h"

#include "PFGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UPFGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPFGameInstance();
	void OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const;
	void OnError(const PlayFab::FPlayFabError& ErrorResult) const;

private:
	PlayFabClientPtr clientAPI = nullptr;	
	
};

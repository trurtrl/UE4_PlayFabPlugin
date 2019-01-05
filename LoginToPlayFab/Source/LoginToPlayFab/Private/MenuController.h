// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuController.generated.h"

class UMenuWidget;

/**
 * 
 */
UCLASS()
class AMenuController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UMenuWidget * MenuWidget;
	
	void BeginPlay();
};

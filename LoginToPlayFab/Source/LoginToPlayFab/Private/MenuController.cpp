// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuController.h"
#include "MenuWidget.h"
#include "PFGameInstance.h"

//class MenuClass;


void AMenuController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	//Mode.SetLockMouseToViewport(true);
	Mode.SetHideCursorDuringCapture(false);
	SetInputMode(Mode);

	MenuWidget = CreateWidget<UMenuWidget>(this, (Cast<UPFGameInstance>(GetWorld()->GetGameInstance()))->MenuClass );
	UE_LOG(LogTemp, Warning, TEXT("MenuWidget is created"))

	MenuWidget->AddToViewport(100);
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay is done"))
}


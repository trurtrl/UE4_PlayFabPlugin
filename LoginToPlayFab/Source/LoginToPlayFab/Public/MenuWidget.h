// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UVerticalBox;
class UTextBlock;
class UButton;


/**
 * 
 */
UCLASS()
class LOGINTOPLAYFAB_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UVerticalBox * MyRootWidget;

	UTextBlock * HeaderText;

	UButton* Start;
	
	virtual TSharedRef<SWidget> RebuildWidget();
};

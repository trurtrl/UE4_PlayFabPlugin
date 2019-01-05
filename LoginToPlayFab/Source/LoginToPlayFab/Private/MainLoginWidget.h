// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainLoginWidget.generated.h"

class UTextBlock;
class UBorder;
class UEditableTextBox;
class UButton;
class FText;

/**
 * 
 */
UCLASS()
class UMainLoginWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void ButtonLoginClicked();

	void ShowMessageLogin();
	void ShowMessageFail();

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeaderEmail;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeaderPassword;

	UPROPERTY(meta = (BindWidget))
	UBorder* BorderEmail;

	UPROPERTY(meta = (BindWidget))
	UBorder* BorderPassword;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* InputEmail;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* InputPassword;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonLogin;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonLoginText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Message;

	void LoginWidgetsHide();
	void LoginWidgetsShow();
	bool CheckWidgets();
};

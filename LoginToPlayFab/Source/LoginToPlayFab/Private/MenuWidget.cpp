// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/EditableText.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"


TSharedRef<SWidget> UMenuWidget::RebuildWidget()
{


	//	RootWidget = Cast<UVerticalBox>(GetRootWidget());

	MyRootWidget = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("RootWidget"));
	WidgetTree->RootWidget = MyRootWidget;

	//	!!!	Super::RebuildWidget() should be called after setting RootWidget	!!!
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	if (MyRootWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyRootWidget is here!!!"))
	}

	Start = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	HeaderText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HeaderT"));
	HeaderText->SetText(FText::FromString(TEXT("Test Text")));
	UE_LOG(LogTemp, Warning, TEXT("HD is done - %s"), *(HeaderText->Text.ToString()))
		MyRootWidget->AddChildToVerticalBox(Start);
	UE_LOG(LogTemp, Warning, TEXT("RootWidget added Child"))
		Start->AddChild(HeaderText);
	UE_LOG(LogTemp, Warning, TEXT("RootWidget added Child"))
		return Widget;
}





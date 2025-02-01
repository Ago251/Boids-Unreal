// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsHUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"

void ABoidsHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (SteeringControlWidgetClass)
	{
		SteeringControlWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), SteeringControlWidgetClass);
		
		if (SteeringControlWidgetInstance)
		{
			SteeringControlWidgetInstance->AddToViewport();
			
			UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(SteeringControlWidgetInstance->Slot);
			if (CanvasSlot)
			{
				CanvasSlot->SetPosition(FVector2D(100.f, 100.f));
				CanvasSlot->SetSize(FVector2D(300.f, 50.f));    
			}
		}
	}
}

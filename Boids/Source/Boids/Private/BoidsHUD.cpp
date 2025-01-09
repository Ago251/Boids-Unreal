// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsHUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"

void ABoidsHUD::BeginPlay()
{
	Super::BeginPlay();

	// Aggiungi il widget al viewport
	if (SteeringControlWidgetClass)
	{
		// Crea l'istanza del widget
		SteeringControlWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), SteeringControlWidgetClass);
		
		if (SteeringControlWidgetInstance)
		{
			// Aggiungi il widget al viewport
			SteeringControlWidgetInstance->AddToViewport();

			// Imposta il layout del widget, ad esempio posizionandolo nella parte superiore a sinistra
			UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(SteeringControlWidgetInstance->Slot);
			if (CanvasSlot)
			{
				// Posiziona il widget nella posizione desiderata
				CanvasSlot->SetPosition(FVector2D(100.f, 100.f));  // Imposta la posizione X e Y
				CanvasSlot->SetSize(FVector2D(300.f, 50.f));      // Imposta la larghezza e altezza
			}
		}
	}
}

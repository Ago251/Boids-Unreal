// Fill out your copyright notice in the Description page of Project Settings.

#include "SteeringControlWidget.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"

void USteeringControlWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Associa l'evento di cambiamento del valore dello Slider alla funzione
	if (StrengthSlider)
	{
		StrengthSlider->OnValueChanged.AddDynamic(this, &USteeringControlWidget::OnStrengthValueChanged);
	}
}

void USteeringControlWidget::OnStrengthValueChanged(float Value)
{
	// Aggiorna il testo con il valore attuale dello Slider
	OnValueChangedDelegate.Broadcast(Value);
}

void USteeringControlWidget::SetTextLabel(FText Text)
{
	StrengthText->SetText(Text);
}

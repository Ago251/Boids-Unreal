// Fill out your copyright notice in the Description page of Project Settings.


#include "SteeringBehaviour.h"

#include "SteeringControlWidget.h"
#include "Components/Slider.h"

FVector USteeringBehaviour::CalculateSteeringForce_Implementation(class AActor* Owner)
{
    return FVector::ZeroVector; 
}

void USteeringBehaviour::SetStrength_Implementation(float value)
{
    Strength = value;
}

void USteeringBehaviour::SetWidget(USteeringControlWidget* Widget)
{
    if (Widget != nullptr)
    {
        if (AssociatedWidget != nullptr)
        {
            AssociatedWidget->OnValueChangedDelegate.RemoveDynamic(this, &USteeringBehaviour::SetStrength);
        }
        AssociatedWidget = Widget;
        Strength = AssociatedWidget->StrengthSlider->GetValue();
        AssociatedWidget->OnValueChangedDelegate.AddDynamic(this, &USteeringBehaviour::SetStrength);
    }
}

void USteeringBehaviour::RemoveWidget(USteeringControlWidget* Widget)
{
    if (AssociatedWidget != nullptr)
    {
        AssociatedWidget->OnValueChangedDelegate.RemoveDynamic(this, &USteeringBehaviour::SetStrength);
        AssociatedWidget = Widget;
    }
}



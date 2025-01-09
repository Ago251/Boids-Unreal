// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BoidsHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API ABoidsHUD : public AHUD
{
	GENERATED_BODY()

public:
	// Classe del widget
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UUserWidget> SteeringControlWidgetClass;

private:
	// Istanza del widget
	UUserWidget* SteeringControlWidgetInstance;

protected:
	virtual void BeginPlay() override;
	
};

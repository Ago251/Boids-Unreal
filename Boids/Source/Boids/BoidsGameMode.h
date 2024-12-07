// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/GameModeBase.h"
#include "BoidsGameMode.generated.h"

UCLASS(minimalapi)
class ABoidsGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Boids")
	int32 NumBoids = 50;
	
	UPROPERTY(EditDefaultsOnly, Category = "Boids")
	TSubclassOf<AActor> BoidClass;

public:
	ABoidsGameMode();

	virtual void BeginPlay() override;
};




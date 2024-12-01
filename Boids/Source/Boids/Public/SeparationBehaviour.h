// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.h"
#include "SeparationBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API USeparationBehaviour : public USteeringBehaviour
{
	GENERATED_BODY()

public:
	float DesiredSeparation;
	
	virtual FVector CalculateSteeringForce_Implementation(class AActor* Owner) override;
};

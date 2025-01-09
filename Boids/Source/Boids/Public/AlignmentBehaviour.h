// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.h"
#include "AlignmentBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API UAlignmentBehaviour : public USteeringBehaviour
{
	GENERATED_BODY()

public:
	virtual FVector CalculateSteeringForce_Implementation(AActor* Owner) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.h"
#include "CohesionBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API UCohesionBehaviour : public USteeringBehaviour
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SteeringBehaviour")
	float CohesionStrength = 1.0f;
	
	virtual FVector CalculateSteeringForce_Implementation(AActor* Owner) override;
};

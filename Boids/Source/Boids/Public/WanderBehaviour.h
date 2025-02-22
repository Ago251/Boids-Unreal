// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.h"
#include "WanderBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API UWanderBehaviour : public USteeringBehaviour
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wander")
	float WanderCircleDistance = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wander")
	float WanderCircleRadius = 200.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wander")
	float WanderJitter = 50.f;

private:
	FVector WanderTarget;

public:
	virtual FVector CalculateSteeringForce_Implementation(AActor* Owner) override;
};

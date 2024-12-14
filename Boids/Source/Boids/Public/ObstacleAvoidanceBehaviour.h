// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.h"
#include "ObstacleAvoidanceBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class BOIDS_API UObstacleAvoidanceBehaviour : public USteeringBehaviour
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle Avoidance")
	int NumFeelers = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle Avoidance")
	float FeelerLength = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle Avoidance")
	float MaxAngle = 30.f;
	
public:
	virtual FVector CalculateSteeringForce_Implementation(AActor* Owner) override;
};

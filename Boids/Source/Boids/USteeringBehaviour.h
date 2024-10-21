// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "USteeringBehaviour.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class BOIDS_API USteeringBehaviour : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
	FVector CalculateSteeringForce(const FVector& TargetLocation, class AActor* Owner);
};

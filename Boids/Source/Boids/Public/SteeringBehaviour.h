// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SteeringBehaviour.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class BOIDS_API USteeringBehaviour : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
	FVector CalculateSteeringForce(class AActor* Owner);
};

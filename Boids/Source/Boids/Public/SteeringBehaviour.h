// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviour.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class BOIDS_API USteeringBehaviour : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SteeringBehaviour")
	float Strength = 1.0f;
	
	UPROPERTY()
	class USteeringControlWidget* AssociatedWidget;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
	FVector CalculateSteeringForce(class AActor* Owner);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
	void SetStrength(float value);

	UFUNCTION(BlueprintCallable, Category = "Steering")
	void SetWidget(USteeringControlWidget* Widget);

	UFUNCTION(BlueprintCallable, Category = "Steering")
	void RemoveWidget(USteeringControlWidget* Widget);
};

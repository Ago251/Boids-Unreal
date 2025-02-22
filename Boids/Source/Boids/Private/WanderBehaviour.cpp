// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderBehaviour.h"

FVector UWanderBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
	 if (!Owner) return FVector::ZeroVector;
	
    FVector BoidLocation = Owner->GetActorLocation();
    FVector Forward = Owner->GetActorForwardVector();

	FVector WanderCircleCenter = BoidLocation + Forward * WanderCircleDistance;
	
    WanderTarget += FVector(FMath::FRandRange(-WanderJitter, WanderJitter),
    						FMath::FRandRange(-WanderJitter, WanderJitter),
    						FMath::FRandRange(-WanderJitter, WanderJitter));
	
    WanderTarget = WanderTarget.GetClampedToSize(-WanderCircleRadius, WanderCircleRadius);
	
    FVector WanderTargetWorld = WanderCircleCenter + WanderTarget;
    FVector WanderForce = WanderTargetWorld - BoidLocation;
	
    return WanderForce.GetSafeNormal() * Strength;
}
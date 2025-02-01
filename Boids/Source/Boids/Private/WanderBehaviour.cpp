// Fill out your copyright notice in the Description page of Project Settings.


#include "WanderBehaviour.h"

UWanderBehaviour::UWanderBehaviour()
{
	WanderTarget = FVector(FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f), 0).GetSafeNormal() * WanderCircleRadius;
}

FVector UWanderBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
	 if (!Owner) return FVector::ZeroVector;
	
    FVector BoidLocation = Owner->GetActorLocation();
    FVector Forward = Owner->GetActorForwardVector();
	
	float ActorRadius = 0.f;
	if (Owner) {
		FVector Origin, BoxExtent;
		Owner->GetActorBounds(true, Origin, BoxExtent); // Ottieni le dimensioni del bounding box dell'attore
		ActorRadius = BoxExtent.Size() * 0.2f;          // Calcola il raggio approssimativo
	}

	FVector WanderCircleCenter = BoidLocation + Forward * (WanderCircleRadius + ActorRadius);

	
    WanderTarget += FVector(FMath::FRandRange(-WanderJitter, WanderJitter), FMath::FRandRange(-WanderJitter, WanderJitter), FMath::FRandRange(-WanderJitter, WanderJitter));
	
    WanderTarget = WanderTarget.GetClampedToSize(-WanderCircleRadius, WanderCircleRadius);
	
    FVector WanderTargetWorld = WanderCircleCenter + WanderTarget;
	
    FVector WanderForce = WanderTargetWorld - BoidLocation;
	
    DrawDebugSphere(GetWorld(), WanderCircleCenter, 10.f, 12, FColor::Blue, false, 0.0f);
    DrawDebugSphere(GetWorld(), WanderTargetWorld, 10.f, 12, FColor::Red, false, 0.0f);
    DrawDebugLine(GetWorld(), BoidLocation, WanderTargetWorld, FColor::Green, false, 0.0f, 0, 1.f);
	
    return (WanderForce.GetSafeNormal() * WanderCircleRadius) * Strength;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "SeparationBehaviour.h"
#include "Boid.h"


FVector USeparationBehaviour::CalculateSteeringForce_Implementation(class AActor* Owner)
{
	const ABoid* Boid = Cast<ABoid>(Owner);
	if (!Boid) return FVector::ZeroVector;

	FVector SteeringForce = FVector::ZeroVector;
	TArray<ABoid*> Neighbors = Boid->GetNeighbors();

	for (ABoid* Neighbor : Neighbors)
	{
		float Distance = FVector::Dist(Boid->GetActorLocation(), Neighbor->GetActorLocation());
		FVector Direction = Boid->GetActorLocation() - Neighbor->GetActorLocation();
		SteeringForce += Direction / Distance;
	}

	if (Neighbors.Num() > 0)
		SteeringForce /= Neighbors.Num();


	return SteeringForce.GetSafeNormal() * Strength;
}

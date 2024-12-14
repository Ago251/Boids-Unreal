// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "CohesionBehaviour.h"

FVector UCohesionBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
	const ABoid* Boid = Cast<ABoid>(Owner);
	if (!Boid) return FVector::ZeroVector;

	FVector CenterOfMass = FVector::ZeroVector;
	int NeighborCount = 0;
	
	FVector OwnerLocation = Owner->GetActorLocation();

	TArray<ABoid*> Neighbors = Boid->GetNeighbors();
	
	for (ABoid* Neighbor : Neighbors)
	{
		CenterOfMass += Neighbor->GetActorLocation();
		NeighborCount++;
	}
	
	if (NeighborCount > 0)
	{
		CenterOfMass /= NeighborCount;
		FVector DesiredDirection = (CenterOfMass - OwnerLocation).GetSafeNormal();
		return DesiredDirection * CohesionStrength;
	}

	return FVector::ZeroVector;
}

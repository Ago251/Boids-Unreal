// Fill out your copyright notice in the Description page of Project Settings.


#include "AlignmentBehaviour.h"
#include "Boid.h"

FVector UAlignmentBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
	const ABoid* Boid = Cast<ABoid>(Owner);
	if (!Boid) return FVector::ZeroVector;
	
	FVector AverageDirection = FVector::ZeroVector;
	int NeighborCount = 0;
	
	TArray<ABoid*> Neighbors = Boid->GetNeighbors();

	for (ABoid* Neighbor : Neighbors)
	{
		AverageDirection += Neighbor->GetActorForwardVector();
		NeighborCount++;
	}

	if (NeighborCount > 0)
	{
		AverageDirection /= NeighborCount;
		FVector DesiredDirection = AverageDirection.GetSafeNormal();
		return DesiredDirection * Strength;
	}

	return FVector::ZeroVector;
}

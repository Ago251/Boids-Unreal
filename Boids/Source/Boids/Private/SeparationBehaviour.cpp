// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "SeparationBehaviour.h"


FVector USeparationBehaviour::CalculateSteeringForce_Implementation(class AActor* Owner)
{
	const ABoid* Boid = Cast<ABoid>(Owner);
	if (!Boid) return FVector::ZeroVector;

	FVector SteeringForce = FVector::ZeroVector;
	TArray<ABoid*> Neighbors = Boid->GetNeighbors();
	
	for (ABoid* Neighbor : Neighbors)
	{
		float Distance = FVector::Dist(Boid->GetActorLocation(), Neighbor->GetActorLocation());
		if (Distance > 0 && Distance < DesiredSeparation)
		{
			FVector Diff = Boid->GetActorLocation() - Neighbor->GetActorLocation();
			Diff = Diff.GetSafeNormal() / Distance;
			SteeringForce += Diff;
		}
	}
	
	if (Neighbors.Num() > 0)
		SteeringForce /= Neighbors.Num();

	return SteeringForce;
}

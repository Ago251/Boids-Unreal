// Fill out your copyright notice in the Description page of Project Settings.


#include "SteeringComponent.h"

#include "AlignmentBehaviour.h"
#include "Boid.h"
#include "CohesionBehaviour.h"
#include "SeparationBehaviour.h"

// Sets default values for this component's properties
USteeringComponent::USteeringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USteeringComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USteeringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Owner = GetOwner();
	if (!Owner)
		return;
	
	FVector TotalSteeringForce = CalculateSteeringForce(Owner);
	
	FVector MovementDirection = TotalSteeringForce.GetClampedToMaxSize(1.0f);
	FVector MovementOffset = MovementDirection * Speed * DeltaTime;
	
	FVector NewLocation = Owner->GetActorLocation() + MovementOffset;
	Owner->SetActorLocation(NewLocation);

	if (!MovementDirection.IsNearlyZero())
	{
		FRotator NewRotation = MovementDirection.Rotation();
		Owner->SetActorRotation(NewRotation);
	}
}

FVector USteeringComponent::CalculateSteeringForce(AActor* Owner)
{
	FVector TotalSteeringForce = FVector::ZeroVector;

	for (USteeringBehaviour* BehaviourInstance : SteeringBehaviours)
	{
			if (BehaviourInstance)
				TotalSteeringForce += BehaviourInstance->CalculateSteeringForce(Owner);
	}

	return TotalSteeringForce;
}

void USteeringComponent::SetAlignmentWidget(USteeringControlWidget* Widget)
{
	for (USteeringBehaviour* behaviour : SteeringBehaviours)
	{
		if (behaviour && behaviour->IsA<UAlignmentBehaviour>())
		{
			behaviour->SetWidget(Widget); 
		}
	}
}

void USteeringComponent::SetCohesionWidget(USteeringControlWidget* Widget)
{
	for (USteeringBehaviour* behaviour : SteeringBehaviours)
	{
		if (behaviour && behaviour->IsA<UCohesionBehaviour>())
		{
			behaviour->SetWidget(Widget); 
		}
	}
}

void USteeringComponent::SetSeparationWidget(USteeringControlWidget* Widget)
{
	for (USteeringBehaviour* behaviour : SteeringBehaviours)
	{
		if (behaviour && behaviour->IsA<USeparationBehaviour>())
		{
			behaviour->SetWidget(Widget); 
		}
	}
}





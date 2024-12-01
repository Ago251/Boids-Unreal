// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	NeighborDetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	NeighborDetectionSphere->SetupAttachment(StaticMesh); 
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<ABoid*> ABoid::GetNeighbors() const
{
	TArray<AActor*> OverlappingActors;
	NeighborDetectionSphere->GetOverlappingActors(OverlappingActors, ABoid::StaticClass());
	
	TArray<ABoid*> Neighbors;
	for (AActor* Actor : OverlappingActors)
	{
		if (Actor != this)
		{
			Neighbors.Add(Cast<ABoid>(Actor));
		}
	}

	return Neighbors;
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class BOIDS_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Boid")
	class USphereComponent* NeighborDetectionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid")
	float NeighborRange = 500.0f; 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	TArray<ABoid*> GetNeighbors() const;
};
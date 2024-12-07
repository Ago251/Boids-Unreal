// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteeringBehaviour.h"
#include "SteeringComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOIDS_API USteeringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USteeringComponent();

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = "Steering")
	TArray<USteeringBehaviour*> SteeringBehaviours;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Steering")
	float Speed = 1000.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	FVector CalculateSteeringForce(AActor* Owner);
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

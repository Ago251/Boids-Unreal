// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoidsGameMode.h"


#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABoidsGameMode::ABoidsGameMode() {}

void ABoidsGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (BoidClass)
	{
		TArray<AActor*> TriggerBoxes;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox::StaticClass(), TriggerBoxes);

		if (TriggerBoxes.Num() > 0)
		{
			ATriggerBox* SpawnAreaTriggerBox = Cast<ATriggerBox>(TriggerBoxes[0]);
			
			if (SpawnAreaTriggerBox)
			{
				UBoxComponent* BoxComponent = Cast<UBoxComponent>(SpawnAreaTriggerBox->GetCollisionComponent());
		
				for (int32 i = 0; i < NumBoids; i++)
				{
					FVector SpawnLocation = FMath::RandPointInBox(BoxComponent->Bounds.GetBox());
					FRotator SpawnRotation = FRotator::ZeroRotator;
			
					GetWorld()->SpawnActor<AActor>(BoidClass, SpawnLocation, SpawnRotation);
				}
			}
		}
	}
}

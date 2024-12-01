// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoidsGameMode.h"
#include "BoidsPlayerController.h"
#include "BoidsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABoidsGameMode::ABoidsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABoidsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(
		TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ABoidsGameMode::BeginPlay()
{
	Super::BeginPlay();

	Super::BeginPlay();

	if (BoidClass)
	{
		for (int32 i = 0; i < NumBoids; i++)
		{
			FVector SpawnLocation = FMath::RandPointInBox(SpawnArea);
			FRotator SpawnRotation = FRotator::ZeroRotator;
			
			GetWorld()->SpawnActor<AActor>(BoidClass, SpawnLocation, SpawnRotation);
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleAvoidanceBehaviour.h"

FVector UObstacleAvoidanceBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
    if (!Owner)
        return FVector::ZeroVector;

    FVector BoidLocation = Owner->GetActorLocation();
    FVector Forward = Owner->GetActorForwardVector();
    
    FVector TotalAvoidanceForce = FVector::ZeroVector;

    for (int VerticalIndex = 0; VerticalIndex < NumVerticalFeelers; VerticalIndex++)
    {
        float VerticalStep = (NumVerticalFeelers > 1) ? (float)VerticalIndex / (NumVerticalFeelers - 1) : 0.5f;
        float VerticalAngle = FMath::Lerp(-VerticalMaxAngle, VerticalMaxAngle, VerticalStep);
        
        FQuat VerticalRotation = FQuat(Owner->GetActorRightVector(), FMath::DegreesToRadians(VerticalAngle));
        FVector RotatedForward = VerticalRotation.RotateVector(Forward);

        for (int HorizontalIndex = 0; HorizontalIndex < NumHorizontalFeelers; HorizontalIndex++)
        {
            float HorizontalStep = (NumHorizontalFeelers > 1) ? (float)HorizontalIndex / (NumHorizontalFeelers - 1) : 0.5f;
            float HorizontalAngle = FMath::Lerp(-HorizontalMaxAngle, HorizontalMaxAngle, HorizontalStep);
            
            FQuat HorizontalRotation = FQuat(Owner->GetActorUpVector(), FMath::DegreesToRadians(HorizontalAngle));
            FVector Direction = HorizontalRotation.RotateVector(RotatedForward);

            FVector TraceStart = BoidLocation;
            FVector TraceEnd = BoidLocation + Direction * FeelerLength;

            FHitResult HitResult;
            FCollisionQueryParams QueryParams;
            QueryParams.AddIgnoredActor(Owner);

            bool bHit = GetWorld()->LineTraceSingleByChannel(
                HitResult,
                TraceStart,
                TraceEnd,
                ECC_Visibility,
                QueryParams
            );

            if (bHit)
            {
                FVector AvoidanceForce = (HitResult.Normal + Forward).GetSafeNormal();
                float DistanceToObstacle = FVector::Dist(HitResult.Location, BoidLocation);
                float Weight = 1.0f - (DistanceToObstacle / FeelerLength);
                TotalAvoidanceForce += AvoidanceForce * Weight;
            }
        }
    }

    return (TotalAvoidanceForce * FeelerLength) * Strength;
}


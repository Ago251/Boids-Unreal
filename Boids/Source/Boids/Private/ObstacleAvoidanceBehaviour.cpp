// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleAvoidanceBehaviour.h"

FVector UObstacleAvoidanceBehaviour::CalculateSteeringForce_Implementation(AActor* Owner)
{
    if (!Owner)
    {
        return FVector::ZeroVector;
    }

    FVector BoidLocation = Owner->GetActorLocation();
    FVector Forward = Owner->GetActorForwardVector();

    FVector BestAvoidanceForce = FVector::ZeroVector;
    float BestDistance = 0.f;
    
    int TotalFeelers = NumHorizontalFeelers * NumVerticalFeelers;

    for (int VerticalIndex = 0; VerticalIndex < NumVerticalFeelers; VerticalIndex++)
    {
        float VerticalAngle = FMath::Lerp(-VerticalMaxAngle, VerticalMaxAngle, (float)VerticalIndex / (NumVerticalFeelers - 1));
        FVector VerticalDirection = Forward.RotateAngleAxis(VerticalAngle, FVector::RightVector);

        for (int HorizontalIndex = 0; HorizontalIndex < NumHorizontalFeelers; HorizontalIndex++)
        {
            float HorizontalAngle = FMath::Lerp(-HorizontalMaxAngle, HorizontalMaxAngle, (float)HorizontalIndex / (NumHorizontalFeelers - 1));
            FVector Direction = VerticalDirection.RotateAngleAxis(HorizontalAngle, FVector::UpVector);

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

            FColor DebugColor = bHit ? FColor::Red : FColor::Green;
            DrawDebugLine(GetWorld(), TraceStart, TraceEnd, DebugColor, false, 0.0f);

            if (bHit)
            {
                FVector AvoidanceForce = (HitResult.Normal + Forward).GetSafeNormal();
                float DistanceToObstacle = FVector::Dist(HitResult.Location, BoidLocation);

                if (DistanceToObstacle > BestDistance)
                {
                    BestDistance = DistanceToObstacle;
                    BestAvoidanceForce = AvoidanceForce;
                }
            }
        }
    }

    return (BestAvoidanceForce * FeelerLength) * Strength;
}
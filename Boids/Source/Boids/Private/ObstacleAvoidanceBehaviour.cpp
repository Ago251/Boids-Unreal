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
    
    for (int i = 0; i < NumFeelers; i++)
    {
        float AngleOffset = FMath::Lerp(-MaxAngle, MaxAngle, (float)i / (NumFeelers - 1));
        FVector Direction = Forward.RotateAngleAxis(AngleOffset, FVector::UpVector);

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
        DrawDebugLine(GetWorld(), TraceStart, TraceEnd, DebugColor, false, 0.1f);
        
        if (bHit)
        {
            FVector AvoidanceForce = (HitResult.Normal + Direction).GetSafeNormal();
            float DistanceToObstacle = FVector::Dist(HitResult.Location, BoidLocation);
            
            if (DistanceToObstacle > BestDistance)
            {
                BestDistance = DistanceToObstacle;
                BestAvoidanceForce = AvoidanceForce;
            }
        }
        else
        {
            return Direction * FeelerLength;
        }
    }
    
    return BestAvoidanceForce * FeelerLength;
}
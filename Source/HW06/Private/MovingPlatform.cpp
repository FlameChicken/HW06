

#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

  
    MoveSpeed = 200.f;             
    MaxRange = 500.f;             
    MoveDirection = FVector(1.f, 0.f, 0.f); 

    MovementSign = 1.f;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();


    StartLocation = GetActorLocation();


    if (MoveDirection.IsNearlyZero())
    {
        MoveDirection = FVector(1.f, 0.f, 0.f);
    }
    else
    {
        MoveDirection.Normalize();
    }
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    FVector CurrentLocation = GetActorLocation();
    float   TraveledDistance = FVector::DotProduct(
        CurrentLocation - StartLocation,
        MoveDirection);

 
    if (TraveledDistance >= MaxRange)
    {
        MovementSign = -1.f;  
    }
    else if (TraveledDistance <= 0.f)
    {
        MovementSign = 1.f;   
    }


    FVector NewLocation = CurrentLocation
        + MoveDirection * MoveSpeed * MovementSign * DeltaTime;

    SetActorLocation(NewLocation);
}
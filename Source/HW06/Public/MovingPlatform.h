

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class HW06_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

   
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;

 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings",
        meta = (ClampMin = "0.0", ToolTip = "플랫폼 이동 속도 (cm/s). 플레이 중 즉시 반영."))
    float MoveSpeed;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings",
        meta = (ClampMin = "0.0", ToolTip = "시작 위치 기준 최대 이동 거리 (cm)."))
    float MaxRange;

   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector MoveDirection;


    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Platform Settings|Runtime")
    FVector StartLocation;

private:

    float MovementSign;
};
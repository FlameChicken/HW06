

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class HW06_API ARotatingActor : public AActor
{
    GENERATED_BODY()

public:
    ARotatingActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;



    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Settings",
        meta = (ToolTip = "초당 회전량(도). 플레이 중에도 실시간 반영됩니다."))
    FRotator RotationSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation Settings")
    bool bRotateOnlyInPlay;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX",
        meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float EffectIntensity;
};
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

UCLASS()
class THIRDPERSONACTION_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
    virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
    float Amplitude = 0.25f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
    float TimeConstant = 0.25f;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UStaticMeshComponent* ItemMesh;
    
    UFUNCTION(BlueprintPure)
    float TransformedSin();
    
    UFUNCTION(BlueprintPure)
    float TransformedCos();
    
    UFUNCTION()
    virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    float RunningTime;
    
    UPROPERTY(VisibleAnywhere)
    USphereComponent* Sphere;

};

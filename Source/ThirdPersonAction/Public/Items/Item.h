#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

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
    
    UFUNCTION(BlueprintPure)
    float TransformedSin();
    
    UFUNCTION(BlueprintPure)
    float TransformedCos();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    float RunningTime;
    
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ItemMesh;

};

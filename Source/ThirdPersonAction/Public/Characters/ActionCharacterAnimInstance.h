// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ActionCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONACTION_API UActionCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
    
public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaTime) override;
	
    UPROPERTY(BlueprintReadOnly)
    class AActionCharacter* ActionCharacter;
    
    UPROPERTY(BlueprintReadOnly, Category = Movement)
    class UCharacterMovementComponent* ActionCharacterMovement;
    
    UPROPERTY(BlueprintReadOnly, Category = Movement)
    float GroundSpeed;
    
    UPROPERTY(BlueprintReadOnly, Category = Movement)
    bool isFalling;
};

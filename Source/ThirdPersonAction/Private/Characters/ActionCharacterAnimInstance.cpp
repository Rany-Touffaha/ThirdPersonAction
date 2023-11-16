// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionCharacterAnimInstance.h"
#include "Characters/ActionCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UActionCharacterAnimInstance::NativeInitializeAnimation() 
{
    Super::NativeInitializeAnimation();

    ActionCharacter = Cast<AActionCharacter>(TryGetPawnOwner());
    if (ActionCharacter)
    {
        ActionCharacterMovement = ActionCharacter->GetCharacterMovement();
    }
    
}

void UActionCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);
    
    if(ActionCharacterMovement)
    {
        
        GroundSpeed = UKismetMathLibrary::VSizeXY(ActionCharacterMovement->Velocity);
        isFalling = ActionCharacterMovement->IsFalling();
    }
}

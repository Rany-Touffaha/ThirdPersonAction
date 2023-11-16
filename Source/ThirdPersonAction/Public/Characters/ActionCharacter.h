#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ActionCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THIRDPERSONACTION_API AActionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
    
	AActionCharacter();
    
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void Jump() override;

protected:
    
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = Input)
    UInputMappingContext* CharacterMappingContext;
    
    UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* MovementAction;
    
    UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* LookAction;
    
    UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* JumpAction;
    
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    
private:
    
    UPROPERTY(EditAnywhere)
    USpringArmComponent* SpringArm;
    
    UPROPERTY(EditAnywhere)
    UCameraComponent* ViewCamera;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ActionCharacter.generated.h"

UCLASS()
class THIRDPERSONACTION_API AActionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AActionCharacter();
    
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

};

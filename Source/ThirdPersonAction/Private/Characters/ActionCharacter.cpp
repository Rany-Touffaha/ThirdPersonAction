#include "Characters/ActionCharacter.h"


AActionCharacter::AActionCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AActionCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AActionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



#include "Items/Item.h"
#include "ThirdPersonAction/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/ActionCharacter.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
    
    ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
    RootComponent = ItemMesh;
    
    Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    Sphere->SetupAttachment(GetRootComponent());

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
    
    Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
    Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
    
}

float AItem::TransformedSin()
{
    return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
    return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AActionCharacter* ActionActor = Cast<AActionCharacter>(OtherActor);
    if (ActionActor)
    {
        ActionActor->SetOverlappingItem(this);
    }
    
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AActionCharacter* ActionActor = Cast<AActionCharacter>(OtherActor);
    if (ActionActor)
    {
        ActionActor->SetOverlappingItem(nullptr);
    }
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    RunningTime += DeltaTime;
    
}


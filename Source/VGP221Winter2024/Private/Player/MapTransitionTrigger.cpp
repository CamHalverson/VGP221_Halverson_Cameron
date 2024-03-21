// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MapTransitionTrigger.h"
#include "Player/FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMapTransitionTrigger::AMapTransitionTrigger()
{
    PrimaryActorTick.bCanEverTick = true;

    UBoxComponent* BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent")); // Adjusted name here
    RootComponent = BoxComponent;

    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMapTransitionTrigger::OnOverlapBegin);
}
void AMapTransitionTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void AMapTransitionTrigger::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMapTransitionTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(OtherActor);
        if (PlayerCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("Player character overlapped with trigger box"));
            UGameplayStatics::OpenLevel(this, FName("FPSMap"), true);
        }
    }
}


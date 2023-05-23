// Fill out your copyright notice in the Description page of Project Settings.


#include "BossFightTrigger.h"
#include "Components/PrimitiveComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABossFightTrigger::ABossFightTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent, FName("TriggerBox"));
}

// Called when the game starts or when spawned
void ABossFightTrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABossFightTrigger::OnOverlapBegin);
}

void ABossFightTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player entered boss room")));
		boss->StartStateSelection();
		boss->BattleStarted = true;
		boss->Player->GameHUD->SetBossHUDVisibility(true);
	}
}

// Called every frame
void ABossFightTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


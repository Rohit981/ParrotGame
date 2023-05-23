// Fill out your copyright notice in the Description page of Project Settings.


#include "BossSpikeSpawner.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABossSpikeSpawner::ABossSpikeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABossSpikeSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABossSpikeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABossSpikeSpawner::SpawnSpike()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AFallingSpike>(SpikeClass, GetActorLocation()+FVector(FMath::RandRange(-100.f,100.f),0, FMath::RandRange(0.f, 400.f)), FRotator(0, 0, 0));
	}
}


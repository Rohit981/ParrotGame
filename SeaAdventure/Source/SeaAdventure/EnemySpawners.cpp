// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawners.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEnemySpawners::AEnemySpawners()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawners::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AFishCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
}

// Called every frame
void AEnemySpawners::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player->Learned_Shoot == true && spawnCount == 0)
	{
		if (EnemyClass != nullptr)
		{
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				FVector Location = GetActorLocation();
				FRotator OldRotation = GetActorRotation();

				World->SpawnActor<AEnemy>(EnemyClass, Location, OldRotation);

				spawnCount += 1;

			}
		}
	}

}


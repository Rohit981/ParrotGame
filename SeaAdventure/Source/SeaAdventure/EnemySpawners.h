// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishCharacter.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawners.generated.h"

UCLASS()
class SEAADVENTURE_API AEnemySpawners : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawners();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AFishCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
		TSubclassOf<class AEnemy> EnemyClass;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	int spawnCount = 0;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingSpike.h"
#include "BossSpikeSpawner.generated.h"

UCLASS()
class SEAADVENTURE_API ABossSpikeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossSpikeSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AFallingSpike> SpikeClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnSpike();

};

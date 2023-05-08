// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpikeActor.generated.h"

UCLASS()
class SEAADVENTURE_API ASpikeActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpikeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Collider (overlap)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* colliderOverlap;

	// Collider (block)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* colliderBlock;

	// Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* staticMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

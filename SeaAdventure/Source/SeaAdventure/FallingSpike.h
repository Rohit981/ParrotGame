// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingSpike.generated.h"

UCLASS()
class SEAADVENTURE_API AFallingSpike : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFallingSpike();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Collider (overlap)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* colliderOverlap;

	// Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spike", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* staticMesh;
	
	// Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = speed, meta = (AllowPrivateAccess = "true"))
		float interpSpeed = 200;

	FVector targetLocation;

	FTimerHandle tHandlerSelfDestroy;

	void SelfDestroy();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};

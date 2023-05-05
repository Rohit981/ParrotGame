// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Garbage.generated.h"

class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class SEAADVENTURE_API AGarbage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGarbage();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		USphereComponent* Collider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

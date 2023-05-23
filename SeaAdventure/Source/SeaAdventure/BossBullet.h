// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBullet.h"
#include "BossBullet.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API ABossBullet : public AEnemyBullet
{
	GENERATED_BODY()
public:
	ABossBullet();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Collision
		virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = speed, meta = (AllowPrivateAccess = "true"))
		float interpSpeed = 200;

	FVector targetLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void DestroyMesh(float DeltaTime);
	float LifeTime;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "GameFramework/Character.h"
#include "RangeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API ARangeEnemy : public AEnemy
{
	GENERATED_BODY()

public:
	ARangeEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UAnimMontage* Attack_Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		USceneComponent* MuzzlePoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
		float countingTimerDown;

	UPROPERTY(VisibleAnywhere, Category = Character)
		float StopstrafeTimer = 0;


	FTimerHandle Time_Handle_Manager;

	void FireGun();

	void StartFiringTimer(float DeltaTime);

	void Dead();

	UFUNCTION(BlueprintCallable)
		void CanSpawnBullet();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
		TSubclassOf<class AEnemyBullet> BulletClass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Strafe();

	UPROPERTY(BlueprintReadWrite)
		bool IsAttacked = false;

	UPROPERTY(BlueprintReadWrite)
		bool CanFire = false;

	UPROPERTY(BlueprintReadWrite)
		bool CanStrafe = false;

private:
	bool Is_SpawningBullet = false;

};

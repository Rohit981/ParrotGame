// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "BossSpikeSpawner.h"
#include "Boss.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API ABoss : public AEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoss();
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* PunchHitBox;
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool canMove = true;

	void Dead();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
	//	class USphereComponent* BossHitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UAnimMontage* Attack_Montage_Atk1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UAnimMontage* Attack_Montage_Atk2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UAnimMontage* Attack_Montage_Atk3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		USceneComponent* MuzzlePoint;

	UPROPERTY(VisibleAnywhere, Category = Character)
		float StopstrafeTimer = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = timer, meta = (AllowPrivateAccess = "true"))
		float StateSwitchInterval = 8.f;

	// Timer Handler
	//FTimerHandle tHandlerState;
	FTimerHandle tHandlerMeleeStart;
	FTimerHandle tHandlerMeleeReset;
	FTimerHandle tHandlerChangeMoveTarget;
	FTimerHandle tHandlerAttackTimer;
	FTimerHandle tHandlerAttackManualState;
	FTimerHandle tHandlerShootDelay;

	void FireGun();
	void ShuffleBossState();
	void ShootProjectile();

	UFUNCTION(BlueprintCallable)
		void CanSpawnBullet();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
		TSubclassOf<class AEnemyBullet> BulletClass;

	// Spike Spawners
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawner)
		TArray<ABossSpikeSpawner*> spawners;

	// Target Positions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BossPositions, meta = (AllowPrivateAccess = "true"))
		TArray<AActor*> Positions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BossPositions, meta = (AllowPrivateAccess = "true"))
		AActor* MiddlePosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float movementSpeed = 100.f;

	void ResetAttacking();
	void ChangeMoveLoation();

	void Attack_Spike();
	void Attack_Melee();
	void Attack_Shoot();

	bool timerTicking = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Attacking();

	UFUNCTION(BlueprintCallable)
		void StopAttacking();

	void Strafe();

	UPROPERTY(BlueprintReadWrite)
		bool IsAttacked = false;

	UPROPERTY(BlueprintReadWrite)
		bool CanFire = false;

	UPROPERTY(BlueprintReadWrite)
		bool CanStrafe = false;

	UPROPERTY(BlueprintReadWrite)
		bool isMoving = false;

	void StartStateSelection();

	bool BattleStarted = false;

	virtual void PlayerRespawn(AFishCharacter* player);

private:
	void HitCheck();

	void Move(float DeltaTime);

	void AttackStateShift();

	bool playerHit = false;

	bool Is_SpawningBullet = false;

	bool isAttacking = false;

	float stateTimer = 4.f;

	int attackState = 1;

	FVector currentTargetPosition;
	
};

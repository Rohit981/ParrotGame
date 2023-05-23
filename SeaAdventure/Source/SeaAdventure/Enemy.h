// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishCharacter.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class SEAADVENTURE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UAnimInstance* AnimInstance;

	void BulletHit(float DeltaTime);

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Enemy)
		int DetectionLength = 0;

	float attackWaitTime = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Player)
		int EnemyDamageTaken = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Player)
		FVector HitPosition;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = Enemy)
		AFishCharacter* Player;

	bool ISDamageTaken = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		bool Is_Dead = false;

	float HitReactionTime = 0;

	bool Bullet_Hit = false;

	int hitCounter = 0;

	virtual void PlayerRespawn(AFishCharacter* player);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		bool Is_Punching = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
		int Enemy_Health = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
		int Enemy_Max_Health = 2;

	UFUNCTION(BlueprintCallable)
		void DamageTaken();

	UPROPERTY(BlueprintReadWrite)
		bool Enemy_IsLookOn = false;

	bool EnemyAgro = false;

	bool IsHit;


};

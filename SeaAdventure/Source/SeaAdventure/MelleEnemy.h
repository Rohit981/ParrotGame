// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.h"
#include "MelleEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API AMelleEnemy : public AEnemy
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* PunchHitBox;



public:
	// Sets default values for this character's properties
	AMelleEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool canMove = true;

	void Dead();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UAnimMontage* Attack_Montage;

	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Attacking();

	UFUNCTION(BlueprintCallable)
		void StopAttacking();



private:
	void HitCheck();

	bool playerHit = false;

	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Player = Cast<AFishCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	AnimInstance = GetMesh()->GetAnimInstance();

}

void AEnemy::BulletHit(float DeltaTime)
{
	if (Bullet_Hit == true)
	{
		HitReactionTime += DeltaTime;

	}

	if (HitReactionTime >= 2.f)
	{
		HitReactionTime = 0;

		hitCounter = 2;

		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_NavWalking);

	}
}

void AEnemy::DamageTaken()
{
	Bullet_Hit = true;

	EnemyAgro = true;
}




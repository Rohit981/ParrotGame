// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Components/CapsuleComponent.h"
#include "Components/TimelineComponent.h"

ARangeEnemy::ARangeEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(RootComponent, FName("RightHand"));
}

void ARangeEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ARangeEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	if (IsAttacked == true && Enemy_Health > 0 && CanStrafe == false)
	{

		FireGun();

		StartFiringTimer(DeltaTime);



	}

	if (CanStrafe == true)
	{
		Strafe();

		StopstrafeTimer += DeltaTime;


	}

	if (StopstrafeTimer >= 1.f)
	{
		CanStrafe = false;

		StopstrafeTimer = 0;
	}

	Dead();
}

void ARangeEnemy::FireGun()
{
	if (CanFire)
	{
		AnimInstance->Montage_Play(Attack_Montage, 1.f, EMontagePlayReturnType::Duration, 0.f);

	}
	if (BulletClass != nullptr && Is_SpawningBullet)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			FVector Location = MuzzlePoint->GetComponentLocation();
			FRotator OldRotation = MuzzlePoint->GetComponentRotation();

			World->SpawnActor<AEnemyBullet>(BulletClass, Location, OldRotation);

			Is_SpawningBullet = false;

		}
	}
}

void ARangeEnemy::StartFiringTimer(float DeltaTime)
{
	countingTimerDown -= DeltaTime;

	if (countingTimerDown <= 0)
	{
		CanFire = true;

		countingTimerDown = 3.0f;

	}
	else
	{
		CanFire = false;
	}
}


void ARangeEnemy::Dead()
{
	if (Enemy_Health <= 0)
	{
		UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
		CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
		//SetActorEnableCollision(true);
	}
}

void ARangeEnemy::CanSpawnBullet()
{
	Is_SpawningBullet = true;
}





void ARangeEnemy::Strafe()
{
	if (GetCharacterMovement()->bOrientRotationToMovement == true)
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}

	AddMovementInput(GetActorForwardVector(), 1);
}

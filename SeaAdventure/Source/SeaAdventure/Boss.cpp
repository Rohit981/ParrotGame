// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/CapsuleComponent.h"

ABoss::ABoss() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PunchHitBox = CreateDefaultSubobject<USphereComponent>(TEXT("PunchCollider"));
	PunchHitBox->SetupAttachment(RootComponent, FName("AttackCollider"));
	//BossHitBox = CreateDefaultSubobject<USphereComponent>(TEXT("PassiveHitCollider"));
	//BossHitBox->SetupAttachment(RootComponent, FName("BodyAttackCollider"));
}

void ABoss::BeginPlay()
{
	Super::BeginPlay();

	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//BossHitBox->OnComponentBeginOverlap.AddDynamic(this, &ABoss::OnOverlapBegin);
	PunchHitBox->OnComponentBeginOverlap.AddDynamic(this, &ABoss::OnOverlapBegin);

	stateTimer = StateSwitchInterval - 2.f;
}

void ABoss::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player in boss damage zone")));
		if (!(Cast<AFishCharacter>(OtherActor)->IsInvincible())) {
			Cast<AFishCharacter>(OtherActor)->DamageBounce();
		}
	}
}

void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timerTicking) {
		stateTimer += DeltaTime;
		if (stateTimer >= StateSwitchInterval) {
			stateTimer = 0;
			ShuffleBossState();
		}
	}

	if (Is_Punching == true)
	{
		attackWaitTime += DeltaTime;
	}

	if (canMove == false)
	{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	}

	if (Enemy_Health > 0)
		HitCheck();

	BulletHit(DeltaTime);

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

void ABoss::Attacking()
{
	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void ABoss::StopAttacking()
{
	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	canMove = true;
}

void ABoss::Strafe()
{
	if (GetCharacterMovement()->bOrientRotationToMovement == true)
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}

	AddMovementInput(GetActorForwardVector(), 1);
}

void ABoss::StartStateSelection()
{
	// Set Timer
	//GetWorldTimerManager().SetTimer(tHandlerState, this, &ABoss::ShuffleBossState , 8, false);
	timerTicking = true;
}

void ABoss::HitCheck()
{
	FVector Start = GetActorLocation();

	FVector End = (GetActorForwardVector() * DetectionLength) + Start;


	FHitResult OutHit;

	TArray<AActor*> ActorsToIgnore;

	ActorsToIgnore.Add(this);

	IsHit = false;

	IsHit = UKismetSystemLibrary::SphereTraceSingle(this->GetWorld(), Start, End, 40, ETraceTypeQuery::TraceTypeQuery2, false, ActorsToIgnore,
		EDrawDebugTrace::None, OutHit, true, FLinearColor::Red, FLinearColor::Green, 0.f);

	if (IsHit == true && attackWaitTime == 0)
	{
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Got Hit")));

		AnimInstance->Montage_Play(Attack_Montage_Atk1, 1.f, EMontagePlayReturnType::Duration, 0.f);

		Is_Punching = true;

		canMove = false;

	}
	else
	{
		if (attackWaitTime >= 3.f)
		{
			Is_Punching = false;

			attackWaitTime = 0;

			GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_NavWalking);
		}
	}
}

void ABoss::Dead()
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

void ABoss::FireGun()
{
	if (CanFire)
	{
		AnimInstance->Montage_Play(Attack_Montage_Atk2, 1.f, EMontagePlayReturnType::Duration, 0.f);

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

void ABoss::ShuffleBossState()
{
	// For testing purpose we just do a rotate now
	// Drop spikes
	if (attackState == 1) {
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Boss Attack1")));
		AnimInstance->Montage_Play(Attack_Montage_Atk1, 1.f, EMontagePlayReturnType::Duration, 0.f);
		// Random choose spawners and activate them
		for(auto spawner : spawners)
		{
			spawner->SpawnSpike();
		}
	}

	// Dash melee
	if (attackState == 2) {
		AnimInstance->Montage_Play(Attack_Montage_Atk2, 1.f, EMontagePlayReturnType::Duration, 0.f);
		GetWorldTimerManager().SetTimer(tHandlerMeleeStart, this, &ABoss::Attacking, 0.85f, false);
		// TODO: Movement
		GetWorldTimerManager().SetTimer(tHandlerMeleeReset, this, &ABoss::StopAttacking, 2.f, false);
	}

	// Shoot projectiles
	if (attackState == 3) {
		AnimInstance->Montage_Play(Attack_Montage_Atk3, 1.f, EMontagePlayReturnType::Duration, 0.f);
	}

	if (attackState < 3) attackState++;
	else attackState = 1;
}

void ABoss::CanSpawnBullet()
{
	Is_SpawningBullet = true;
}

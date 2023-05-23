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
	if (OtherActor != this && OtherComp->ComponentHasTag(FName("Player")))
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player in boss damage zone")));
		if (!(Cast<AFishCharacter>(OtherActor)->IsInvincible())) {
			Cast<AFishCharacter>(OtherActor)->DamageBounce();
		}
	}
}

void ABoss::ResetAttacking()
{
	isAttacking = false;
	timerTicking = true;
}

void ABoss::ChangeMoveLoation()
{
	currentTargetPosition = Positions[FMath::RandRange(0, Positions.Num() - 1)]->GetActorLocation();
}

void ABoss::Attack_Spike()
{
	AnimInstance->Montage_Play(Attack_Montage_Atk1, 1.f, EMontagePlayReturnType::Duration, 0.f);
	// Random choose spawners and activate them
	for (auto spawner : spawners)
	{
		spawner->SpawnSpike();
	}
	GetWorldTimerManager().SetTimer(tHandlerAttackManualState, this, &ABoss::AttackStateShift, 4, false);
	// Set isAttacking to false after the attack
	GetWorldTimerManager().SetTimer(tHandlerAttackTimer, this, &ABoss::ResetAttacking, 4, false);
}

void ABoss::Attack_Melee()
{
	AnimInstance->Montage_Play(Attack_Montage_Atk2, 1.f, EMontagePlayReturnType::Duration, 0.f);
	GetWorldTimerManager().SetTimer(tHandlerMeleeStart, this, &ABoss::Attacking, 0.85f, false);
	GetWorldTimerManager().SetTimer(tHandlerMeleeReset, this, &ABoss::StopAttacking, 2.f, false);
	AttackStateShift();
	// Set isAttacking to false after the attack
	GetWorldTimerManager().SetTimer(tHandlerAttackTimer, this, &ABoss::ResetAttacking, 3, false);
}

void ABoss::Attack_Shoot()
{
	AnimInstance->Montage_Play(Attack_Montage_Atk3, 1.f, EMontagePlayReturnType::Duration, 0.f);
	
	GetWorldTimerManager().SetTimer(tHandlerShootDelay, this, &ABoss::ShootProjectile, 1, false);

	GetWorldTimerManager().SetTimer(tHandlerAttackManualState, this, &ABoss::AttackStateShift, 3, false);
	// Set isAttacking to false after the attack
	GetWorldTimerManager().SetTimer(tHandlerAttackTimer, this, &ABoss::ResetAttacking, 3, false);
}

void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timerTicking) {
		stateTimer += DeltaTime;
		if (stateTimer >= StateSwitchInterval) {
			//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("TimerDone")));
			stateTimer = 0;
			ShuffleBossState();
			timerTicking = false;
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

	if(BattleStarted && !Is_Dead)
		Move(DeltaTime);

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
	ChangeMoveLoation();
}

void ABoss::PlayerRespawn(AFishCharacter* player)
{
	AEnemy::PlayerRespawn(player);
	BattleStarted = false;
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

void ABoss::Move(float DeltaTime)
{
	// This move target only happening at random
	if (!isAttacking) {
		// Stop moving at destination
		if (isMoving && abs(GetActorLocation().X - currentTargetPosition.X) <= 50) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Move Not attacking done")));
			isMoving = false;
			// TODO: Animation state set to idle

			// Choose another move target
			GetWorldTimerManager().SetTimer(tHandlerChangeMoveTarget, this, &ABoss::ChangeMoveLoation, 2.f, false);
		}
		else if(abs(GetActorLocation().X - currentTargetPosition.X) >= 50){
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Trying to move for position")));
			if (!isMoving) {
				isMoving = true;
				// TODO: Animation state set to walking
			}
			SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(),FVector(currentTargetPosition.X, 0, GetActorLocation().Z), DeltaTime, movementSpeed));
		}
	}
	// This is attack specific moving (Attack 2 dash)
	else {
		if (attackState == 2) {
			// Stop moving at destination
			if (isMoving && abs(GetActorLocation().X - Player->GetActorLocation().X)  <= 400) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Move State 2 done")));
				// TODO: Animation state set to idle
				isMoving = false;
				// Begin Attack
				Attack_Melee();
			}
			else if(abs(GetActorLocation().X - Player->GetActorLocation().X) > 400){
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Trying to move for melee")));
				// Dash
				if (!isMoving) {
					// TODO: Animation state set to walking
					isMoving = true;
				}
				SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), FVector(Player->GetActorLocation().X + 150.f, 0, GetActorLocation().Z), DeltaTime, movementSpeed*2.5f));
			}
		}
	}
}

void ABoss::AttackStateShift()
{
	if (attackState < 3) attackState++;
	else attackState = 1;

	if (attackState == 2) isMoving = true;
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
		Is_Dead = true;
		timerTicking = false;
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
	if (!Is_Dead) {
		isAttacking = true;
		// For testing purpose we just do a rotate now
		// Drop spikes
		if (attackState == 1) {
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Boss Attack1")));
			Attack_Spike();
		}

		// Dash melee
		else if (attackState == 2) {
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Boss Attack2")));
			// Handled after movement in Move()
		}

		// Shoot projectiles
		else if (attackState == 3) {
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Boss Attack3")));
			Attack_Shoot();
		}
	}
}

void ABoss::ShootProjectile()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		World->SpawnActor<AEnemyBullet>(BulletClass, GetActorLocation() + FVector(-150, 0, 0), FRotator(0, 0, 0));
	}
}

void ABoss::CanSpawnBullet()
{
	Is_SpawningBullet = true;
}

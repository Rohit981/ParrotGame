// Fill out your copyright notice in the Description page of Project Settings.


#include "MelleEnemy.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/CapsuleComponent.h"

AMelleEnemy::AMelleEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PunchHitBox = CreateDefaultSubobject<USphereComponent>(TEXT("PunchCollider"));
	PunchHitBox->SetupAttachment(RootComponent, FName("RightHand"));
}

void AMelleEnemy::BeginPlay()
{
	Super::BeginPlay();

	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PunchHitBox->OnComponentBeginOverlap.AddDynamic(this, &AMelleEnemy::OnOverlapBegin);
}

void AMelleEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor != this)
	{

		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT(" Hit Player")));
		Player->playerLives -= 1;

		
	}
}



void AMelleEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	if (Is_Punching == true)
	{
		attackWaitTime += DeltaTime;


	}

	if (canMove == false )
	{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);

	}


	if (Enemy_Health > 0)
		HitCheck();


	BulletHit(DeltaTime);

	Dead();
}

void AMelleEnemy::Attacking()
{
	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	
}

void AMelleEnemy::StopAttacking()
{
	PunchHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	

	canMove = true;
}

void AMelleEnemy::HitCheck()
{
	FVector Start = GetActorLocation();

	FVector End = (GetActorForwardVector() * DetectionLength) + Start;


	FHitResult OutHit;

	TArray<AActor*> ActorsToIgnore;

	ActorsToIgnore.Add(this);

	IsHit = false;

	IsHit = UKismetSystemLibrary::SphereTraceSingle(this->GetWorld(), Start, End, 40, ETraceTypeQuery::TraceTypeQuery2, false, ActorsToIgnore,
		EDrawDebugTrace::ForDuration, OutHit, true, FLinearColor::Red, FLinearColor::Green, 0.f);

	if (IsHit == true && attackWaitTime == 0)
	{
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Got Hit")));

		AnimInstance->Montage_Play(Attack_Montage, 1.f, EMontagePlayReturnType::Duration, 0.f);

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

void AMelleEnemy::Dead()
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



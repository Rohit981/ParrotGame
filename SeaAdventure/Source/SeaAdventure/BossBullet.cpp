// Fill out your copyright notice in the Description page of Project Settings.


#include "BossBullet.h"
#include "Components/SphereComponent.h"
#include "FishCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABossBullet::ABossBullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	//Collider->SetupAttachment(RootComponent);

	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//Mesh->SetupAttachment(Collider);

	//ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
}

void ABossBullet::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABossBullet::OnOverlapBegin);
}

void ABossBullet::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if (OtherActor != this)
	{
		if (OtherComp->ComponentHasTag(FName("Player")))
		{
			AFishCharacter* Player = Cast<AFishCharacter>(OtherActor);

			Player->playerLives -= 1;


			Destroy();

		}
		// Blocks player bullets
		else if (OtherComp->ComponentHasTag(FName("Bullet")))
		{
			OtherComp->GetOwner()->Destroy();
		}
	}
}

void ABossBullet::Tick(float DeltaTime)
{
	
}

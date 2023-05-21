// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBullet.h"
#include "Components/SphereComponent.h"
#include "FishCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AEnemyBullet::AEnemyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBullet::OnOverlapBegin);
	
}

void AEnemyBullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		if (OtherComp->ComponentHasTag(FName("Player")))
		{
			AFishCharacter* Player = Cast<AFishCharacter>(OtherActor);

			Player->playerLives -= 1;
			
			
			Destroy();

		}
	}
}

// Called every frame
void AEnemyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DestroyMesh(DeltaTime);

}

void AEnemyBullet::DestroyMesh(float DeltaTime)
{
	LifeTime += DeltaTime;


	if (LifeTime >= TimeElapsed)
	{
		Destroy();
	}
}


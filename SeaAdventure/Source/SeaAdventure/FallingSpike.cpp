// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingSpike.h"
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"

AFallingSpike::AFallingSpike()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Decalre mesh
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	staticMesh->SetupAttachment(RootComponent);

	// Declare collider
	colliderOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider Overlap"));
	colliderOverlap->SetupAttachment(staticMesh);
}

void AFallingSpike::BeginPlay()
{
	Super::BeginPlay();

	targetLocation = GetActorLocation() - FVector(0, 0, 3000);
}

void AFallingSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), targetLocation, DeltaTime, interpSpeed));
}

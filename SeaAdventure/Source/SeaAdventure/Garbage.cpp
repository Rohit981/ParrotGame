// Fill out your copyright notice in the Description page of Project Settings.


#include "Garbage.h"
#include "Components/SphereComponent.h"

// Sets default values
AGarbage::AGarbage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

}

// Called when the game starts or when spawned
void AGarbage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGarbage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


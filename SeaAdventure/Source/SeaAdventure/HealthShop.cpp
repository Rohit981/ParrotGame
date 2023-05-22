// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthShop.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"


// Sets default values
AHealthShop::AHealthShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	Interaction_UI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction UI"));
	Interaction_UI->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AHealthShop::BeginPlay()
{
	Super::BeginPlay();

	Interaction_UI->SetVisibility(false);

	
}

// Called every frame
void AHealthShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


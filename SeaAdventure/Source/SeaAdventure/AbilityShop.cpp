// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityShop.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"


// Sets default values
AAbilityShop::AAbilityShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	AbilityInteraction_UI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Ability UI"));
	AbilityInteraction_UI->SetupAttachment(Mesh);


	Interaction_UI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction UI"));
	Interaction_UI->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AAbilityShop::BeginPlay()
{
	Super::BeginPlay();

	AbilityInteraction_UI->SetVisibility(false);
	Interaction_UI->SetVisibility(false);
	
}

// Called every frame
void AAbilityShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


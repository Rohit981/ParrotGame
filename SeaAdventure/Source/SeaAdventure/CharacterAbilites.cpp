// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAbilites.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"

// Sets default values
ACharacterAbilites::ACharacterAbilites()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void ACharacterAbilites::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}

	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharacterAbilites::OnOverlapBegin);
	
}



// Called every frame
void ACharacterAbilites::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterAbilites::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ACharacterAbilites::Shoot);


		//Dash
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &ACharacterAbilites::Dash);
	}

}



void ACharacterAbilites::Shoot()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ShootPressed"));

	if (BulletClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			FVector Location = MuzzlePoint->GetComponentLocation();
			FRotator OldRotation = MuzzlePoint->GetComponentRotation();

			World->SpawnActor<ABullet>(BulletClass, Location, OldRotation);

		}
	}
}

void ACharacterAbilites::Dash()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("DashPressed"));

}

void ACharacterAbilites::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}


// Fill out your copyright notice in the Description page of Project Settings.

#include "FishCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AFishCharacter::AFishCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 1000.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->GravityScale = 1.8f;
	GetCharacterMovement()->JumpZVelocity = 750.f;
	GetCharacterMovement()->AirControl = 0.85f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = false; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(GetMesh());

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

}

// Called when the game starts or when spawned
void AFishCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FishCharacter deployed"));

	// Input Action Mapping
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FishMappingContext, 0);
		}
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFishCharacter::OnOverlapBegin);

	// Ability initializing
	if (Learned_Shoot) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Shoot Activated"));
	}else 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Shoot Not Learned"));
	if (Learned_DoubleJump) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Double Jump Activated"));
		JumpMaxCount = 2;
	}else
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Double Jump Not Learned"));
	if (Learned_Glide) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Glide Activated"));
	}else
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Glide Not Learned"));
	gliding = false;

}

// Called to bind functionality to input
void AFishCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFishCharacter::Move);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &AFishCharacter::Shoot);

		// Shooting

		// Gliding
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AFishCharacter::Glide);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AFishCharacter::StopGliding);

		// Looking
		//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFishCharacter::Look);

	}
}

// Called every frame
void AFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (gliding) GlideTick();
}


void AFishCharacter::Move(const FInputActionValue& Value)
{
	// input is a float
	float MovementInput = Value.Get<float>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		//const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementInput);
		//AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AFishCharacter::Glide()
{
	if (Learned_Glide) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Glide"));
		gliding = true;
	}

}
void AFishCharacter::StopGliding()
{
	if (Learned_Glide) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Glide Stopped"));
		gliding = false;
	}
}

void AFishCharacter::GlideTick() {
	//GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Velocity.Z: %f"), GetCharacterMovement()->Velocity.Z));
	if (GetCharacterMovement()->Velocity.Z <= -100) {
		GetCharacterMovement()->Velocity.Z = -100;
	}
}


void AFishCharacter::Shoot()
{
	// TODO: There is a BUG the bullets pushes players to the side! Found on May 7th

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ShootPressed"));
	if (Learned_Shoot) {
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
}

void AFishCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		if (OtherComp->ComponentHasTag(FName("garbage"))) {
			OtherActor->Destroy();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Garbage destroyed"));
		}
		else if (OtherComp->ComponentHasTag(FName("spike"))) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Stepped on Spikes"));
		}
	}

}



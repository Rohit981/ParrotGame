// Fill out your copyright notice in the Description page of Project Settings.

#include "FishCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


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
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 2000.0f, 0.0f); // ...at this rotation rate

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

	//Intialized garbage and PlayerLives Variable
	garbageValue = 0;
	playerLives = 3;
	
	invincible = false;
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
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AFishCharacter::OnOverlapEnd);

	//Initializing the HUD
	GameHUD = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	GameHUD->InteractionUI_Ref->SetVisibility(ESlateVisibility::Hidden);


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
	enableMove = true;

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

		// Gliding
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AFishCharacter::Interact);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &AFishCharacter::Interact_End);

		// Looking
		//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFishCharacter::Look);

	}
}

// Called every frame
void AFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (gliding) GlideTick();

	SetActorLocation(FVector(GetActorLocation().X, 0, GetActorLocation().Z));

	Dead();

	LearnAbilites();

	
}


void AFishCharacter::Move(const FInputActionValue& Value)
{
	// input is a float
	float MovementInput = Value.Get<float>();

	if (Controller != nullptr && enableMove)
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

void AFishCharacter::OnStepSpike()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Stepped on Spikes"));
	//UBoxComponent* collider = Cast<UBoxComponent>(OtherComp);

	// Bounce off
	double direction = 0;
	enableMove = false;
	direction = GetActorForwardVector().X >= 0 ? 1 : -1;
	LaunchCharacter(FVector(direction * -500, 0, 500), true, true);
	invincible = true;

	// Disable input for some time
	GetWorldTimerManager().SetTimer(tHandlerInput, this, &AFishCharacter::RestoreBounce, 0.3, false);
	// Disable damage for some time
	GetWorldTimerManager().SetTimer(tHandlerInvincible, this, &AFishCharacter::RestoreInvincible, invincibleTime, false);
	// Health decuction
	playerLives -= 1;
}

void AFishCharacter::Dead()
{
	if (playerLives <= 0)
	{
		UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
		CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));

		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);

		DisableInput(GetWorld()->GetFirstPlayerController());

		//CameraBoom->
	}
}

void AFishCharacter::Interact()
{
	if (Is_OverlappedAbility == true)
	{
		
		Can_Interact = true;
		
	}
}

void AFishCharacter::Interact_End()
{
	Can_Interact = false;

}

void AFishCharacter::LearnAbilites()
{
	if (Can_Interact == true)
	{
		if (garbageValue >= 5)
		{
			Learned_Glide = true;
		}

		if (garbageValue >= 10)
		{
			Learned_Shoot = true;

		}

		if (garbageValue >= 15)
		{
			Learned_DoubleJump = true;

		}

	}
}


void AFishCharacter::Shoot()
{
	// TODO: There is a BUG the bullets pushes players to the side! Found on May 7th

	if (Learned_Shoot) 
	{
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

void AFishCharacter::SetupStimuls()
{
	stimulSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimul"));

	stimulSource->RegisterForSense(TSubclassOf<UAISense>());
	stimulSource->RegisterWithPerceptionSystem();
}

void AFishCharacter::RestoreBounce()
{
	enableMove = true;
}

void AFishCharacter::RestoreInvincible()
{
	invincible = false;
	// Temp check for spike collisions
	TArray< UPrimitiveComponent* > OverlappingComponents;
	GetOverlappingComponents(OverlappingComponents);
	if (!OverlappingComponents.IsEmpty()) {
		for (UPrimitiveComponent* OtherComp : OverlappingComponents)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Colliding with %s"), *OtherComp->GetName()));
			if (OtherComp->ComponentHasTag(FName("spike"))) {
				OnStepSpike();
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
			garbageValue += 1;
		}
		else if (OtherComp->ComponentHasTag(FName("spike"))) {
			if (!invincible) {
				OnStepSpike();
			}
		}

		else if (OtherComp->ComponentHasTag(FName("AbilityShop")))
		{
			GameHUD->InteractionUI_Ref->SetVisibility(ESlateVisibility::Visible);

			Is_OverlappedAbility = true;
		}

	}

}

void AFishCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != this)
	{
		if (OtherComp->ComponentHasTag(FName("AbilityShop")))
		{
			GameHUD->InteractionUI_Ref->SetVisibility(ESlateVisibility::Hidden);

			Is_OverlappedAbility = false;

		}
		
	}
}



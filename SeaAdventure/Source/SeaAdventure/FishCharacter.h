// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameHUD.h"
#include "Bullet.h"
#include "HealthShop.h"
#include "AbilityShop.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerStart.h"
#include "FishCharacter.generated.h"

UCLASS()
class SEAADVENTURE_API AFishCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFishCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	// Follow camera 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	// Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* FishMappingContext;

	// Move Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	// Jump Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* JumpAction;

	// Move Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* ShootAction;

	// Move Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		USceneComponent* MuzzlePoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
		TSubclassOf<class ABullet> BulletClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
		TSubclassOf<class AFishCharacter> CharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
		TSubclassOf<class ABoss> BossClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
		TSubclassOf<class ABossFightTrigger> BossFightTriggerClass;

	// Player Start Location
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
		class APlayerStart* playerStart;*/

	// Collision
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Move function
	void Move(const FInputActionValue& Value);

	// Shoot function
	void Shoot();
	void ShootCompleted();

	void CanShoot();

	// Glide functions to turn on/off boolean
	void Glide();
	void StopGliding();
	
	// Glide function
	void GlideTick();

	// Step on Spikes
	void OnStepSpike();

	// PlayerDeath Function
	void Dead();

	// PlayerRespawn Function
	void Respawn();

	//Player Interact
	void Interact();

	void Interact_End();

	void LearnAbilites();

	void SpawnBullet();



	// Abilities
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
		bool Learned_DoubleJump = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
		bool Learned_Glide = false;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		int garbageValue;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		float invincibleTime = 2.f;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		FString abilityText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		float bulletRateofFire;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		bool has_changed_level = false;


	bool gliding = false;

	bool enableMove = true;

	bool invincible = false;

	bool isAlive = true;

	//AI
	class UAIPerceptionStimuliSourceComponent* stimulSource;

	void SetupStimuls();

	

	
	// Timer Handler
	FTimerHandle tHandlerInput;
	FTimerHandle tHandlerInvincible;
	FTimerHandle tHandlerRespawn;

	// Timer controlled function
	void RestoreBounce();
	void RestoreInvincible();

public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gun)
		AGameHUD* GameHUD;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess = "true"))
		int playerLives;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
		bool Learned_Shoot = false;

	void DamageBounce();

	bool IsInvincible();

	// Access Functions
	void SetGarbageAmount(int amount);
	void SetSkillsLearned(bool glide, bool shoot, bool dblJmp);


private:
	bool Is_OverlappedAbility = false;
	bool Is_OverlappedHealth = false;
	bool Can_Interact = false;
	bool bdestroy_HealthShop = false;
	bool CanFire = true;

	AHealthShop* healthShop_ref;
	AAbilityShop* abilityShop_ref;
};

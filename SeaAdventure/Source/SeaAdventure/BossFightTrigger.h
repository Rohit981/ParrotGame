// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boss.h"
#include "GameFramework/Actor.h"
#include "BossFightTrigger.generated.h"

UCLASS()
class SEAADVENTURE_API ABossFightTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossFightTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Trigger, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference, meta = (AllowPrivateAccess = "true"))
		class ABoss* boss;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

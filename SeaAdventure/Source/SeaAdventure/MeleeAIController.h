// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.h"
#include "MeleeAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API AMeleeAIController : public AEnemyController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* const InPawn) override;

private:
	AMeleeAIController();
	
};

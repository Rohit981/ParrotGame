// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyController.h"
#include "RangeAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API ARangeAIController : public AEnemyController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* const InPawn) override;

private:
	ARangeAIController();
	
};

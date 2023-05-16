// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnemyFindRandomLoc.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API UEnemyFindRandomLoc : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

private:

	UEnemyFindRandomLoc();

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
		float SearchRadius = 500;
	
};

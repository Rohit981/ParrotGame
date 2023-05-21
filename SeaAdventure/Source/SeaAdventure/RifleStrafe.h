// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RifleStrafe.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API URifleStrafe : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

private:
	URifleStrafe();

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};

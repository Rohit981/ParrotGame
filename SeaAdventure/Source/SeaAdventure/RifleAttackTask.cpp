// Fill out your copyright notice in the Description page of Project Settings.


#include "RifleAttackTask.h"
#include "RangeAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RangeEnemy.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


URifleAttackTask::URifleAttackTask()
{
	NodeName = TEXT("Long Range Attack");
}

EBTNodeResult::Type URifleAttackTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ARangeAIController* AIController = Cast<ARangeAIController>(OwnerComp.GetAIOwner());

	ARangeEnemy* LongRangeChar = Cast<ARangeEnemy>(AIController->GetPawn());

	LongRangeChar->IsAttacked = true;

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);


	return EBTNodeResult::Succeeded;
}

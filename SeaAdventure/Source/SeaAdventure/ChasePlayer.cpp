// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasePlayer.h"
#include "EnemyController.h"
#include "MeleeAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MelleEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UChasePlayer::UChasePlayer()
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AMeleeAIController* AIController = Cast<AMeleeAIController>(OwnerComp.GetAIOwner());
	FVector playerLoc = AIController->GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

	AMelleEnemy* MeleeEnemy = Cast<AMelleEnemy>(AIController->GetPawn());

	MeleeEnemy->GetCharacterMovement()->MaxWalkSpeed = 200;


	UAIBlueprintHelperLibrary::SimpleMoveToLocation(AIController, playerLoc);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}

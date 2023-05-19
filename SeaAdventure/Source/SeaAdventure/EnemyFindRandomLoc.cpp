// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFindRandomLoc.h"
#include "AIController.h"
#include "EnemyController.h"
#include "NavigationSystem.h"
#include "MelleEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UEnemyFindRandomLoc::UEnemyFindRandomLoc()
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UEnemyFindRandomLoc::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    FNavLocation Location;

    AEnemyController* AIController = Cast<AEnemyController>(OwnerComp.GetAIOwner());

    APawn* AIPawn = AIController->GetPawn();


    FVector Origin = AIPawn->GetActorLocation();

    UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

    if (NavSystem != nullptr && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location))
    {
        AIController->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Location.Location);

        AMelleEnemy* MeleeEnemy = Cast<AMelleEnemy>(AIController->GetPawn());

        MeleeEnemy->GetCharacterMovement()->MaxWalkSpeed = 100;


    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

    return EBTNodeResult::Succeeded;
}

FString UEnemyFindRandomLoc::GetStaticDescription() const
{
    return FString::Printf(TEXT("Vector : %s"), *BlackboardKey.SelectedKeyName.ToString());
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RifleStrafe.h"
#include "RangeAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RangeEnemy.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


URifleStrafe::URifleStrafe()
{
	NodeName = TEXT("Long Range Strafe");
}

EBTNodeResult::Type URifleStrafe::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ARangeAIController* AIController = Cast<ARangeAIController>(OwnerComp.GetAIOwner());

	ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);


	ARangeEnemy* LongRangeChar = Cast<ARangeEnemy>(AIController->GetPawn());

	AIController->SetFocus(player, EAIFocusPriority::Gameplay);

	if (LongRangeChar->CanFire == false)
	{
		LongRangeChar->CanStrafe = true;

	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindPlayerLoc.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API UFindPlayerLoc : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UFindPlayerLoc();

private:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ALlowPrivateAccess = true))
		bool IsSearching = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ALlowPrivateAccess = true))
		float Search_Radius = 150.f;
	
};

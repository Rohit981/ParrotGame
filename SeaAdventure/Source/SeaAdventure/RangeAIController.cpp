// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeAIController.h"

ARangeAIController::ARangeAIController()
{

}

void ARangeAIController::BeginPlay()
{
	Super::BeginPlay();

	InitializeBehaviourTree();
}

void ARangeAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OnHit();

	Dead();
}

void ARangeAIController::OnPossess(APawn* const InPawn)
{
	Super::OnPossess(InPawn);

	AIPossess(InPawn);
}

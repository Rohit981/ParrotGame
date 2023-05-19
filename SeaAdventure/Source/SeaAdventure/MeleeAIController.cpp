// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

AMeleeAIController::AMeleeAIController()
{

}

void AMeleeAIController::BeginPlay()
{
	Super::BeginPlay();

	InitializeBehaviourTree();

}

void AMeleeAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OnHit();

	Dead();

	
}

void AMeleeAIController::OnPossess(APawn* const InPawn)
{
	Super::OnPossess(InPawn);

	AIPossess(InPawn);
}

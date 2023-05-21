// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeEnemy.h"

ARangeEnemy::ARangeEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARangeEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ARangeEnemy::FireGun()
{
}

void ARangeEnemy::StartFiringTimer(float DeltaTime)
{
}


void ARangeEnemy::Dead()
{
}

void ARangeEnemy::Tick(float DeltaTime)
{
}

void ARangeEnemy::Strafe()
{
}

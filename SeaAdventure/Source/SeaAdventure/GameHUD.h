// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SEAADVENTURE_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> GarbageAndHealth_HUD;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> InteractionUI_HUD;


	// Variable to hold the widget After Creating it.
	UUserWidget* GarbageAndHealth_Ref;
	UUserWidget* InteractionUI_Ref;

	

	// Override BeginPlay()
	virtual void BeginPlay() override;
	
};

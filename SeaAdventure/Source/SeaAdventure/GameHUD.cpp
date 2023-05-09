// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

void AGameHUD::BeginPlay()
{
	if (GarbageAndHealth_HUD && InteractionUI_HUD) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		GarbageAndHealth_Ref = CreateWidget<UUserWidget>(GetWorld(), GarbageAndHealth_HUD);
		InteractionUI_Ref = CreateWidget<UUserWidget>(GetWorld(), InteractionUI_HUD);


		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (GarbageAndHealth_Ref && InteractionUI_Ref)
		{
			//let add it to the view port
			GarbageAndHealth_Ref->AddToViewport();
			InteractionUI_Ref->AddToViewport();
			
		}

	}
}

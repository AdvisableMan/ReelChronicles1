// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AnimationsGameMode.h"
#include "AnimationsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAnimationsGameMode::AAnimationsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT(" /Game/Content/AZRI/Blueprints/ThirdPersonCharacter"));
	//(TEXT(" /Game/Content/AZRI/Blueprints/ThirdPersonCharacter"));
	//(TEXT(" /Game/Content/AZRI/AZRI_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

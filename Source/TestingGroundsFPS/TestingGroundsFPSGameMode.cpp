// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TestingGroundsFPSGameMode.h"
#include "TestingGroundsFPSHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundsFPSGameMode::ATestingGroundsFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviors/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsFPSHUD::StaticClass();
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class AbilityInputKeysID : uint8
{
	
	None		UMETA(DisplayName = "None"),
	
	Jump		UMETA(DisplayName = "Jump"),
	
	Heal		UMETA(DisplayName = "Heal"),

	Attack		UMETA(DisplayName = "Attack"),
	
};

class DEMO_API PlayerInputKeys
{
public:
	PlayerInputKeys();
	~PlayerInputKeys();
};

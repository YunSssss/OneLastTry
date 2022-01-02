// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Demo/Characters/BaseCharacter.h"
#include "EnemyCharacter1.generated.h"

/**
 * 
 */
class UPawnSensingComponent;
UCLASS()
class DEMO_API AEnemyCharacter1 : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter1();


	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPawnSensingComponent* PawnSensingComp;
	
	UFUNCTION()
	void OnSeenPawn(APawn* Pawn);
};

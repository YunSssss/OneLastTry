// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Demo/Characters/BaseCharacter.h"
#include "EnemyCharacter2.generated.h"

class UPawnSensingComponent;
class UBlackboardComponent;

/**
 * 
 */
UCLASS()
class DEMO_API AEnemyCharacter2 : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter2();

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPawnSensingComponent* PawnSensingComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBlackboardComponent* BlackboardComp;
	bool bSeenPlayer;

	UFUNCTION()
	void HadSeenPlayer(APawn* Pawn);

	


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_Enemy2.generated.h"

/**
 * 
 */
class UBlackboardComponent;
class UBehaviorTree;
class UBehaviorTreeComponent;

UCLASS()
class DEMO_API AAIController_Enemy2 : public AAIController
{
	GENERATED_BODY()

public:
	AAIController_Enemy2();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	UBehaviorTreeComponent* BehaviorTreeCompo;
	UBehaviorTree* BehaviorTree;
	UBlackboardComponent* BlackBoardCompo;
	
};

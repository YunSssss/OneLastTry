// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */

class UBlackboardComponent;
class UBehaviorTreeComponent;

class UBaseBlackboardData;
class UEnemyBehaviorTree;

UCLASS()
class DEMO_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	
	UBlackboardComponent* BlackboardComp;
	UBehaviorTreeComponent* BehaviorTreeComp;
	UBaseBlackboardData* OwnBlackboard;
	UEnemyBehaviorTree* OwnBehaviorTree;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

};

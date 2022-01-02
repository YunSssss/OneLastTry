// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EnemyBehaviorTree.generated.h"

/**
 * 
 */
class UBaseBlackboardData;
UCLASS()
class DEMO_API UEnemyBehaviorTree : public UBehaviorTree
{
	GENERATED_BODY()

public:
	UEnemyBehaviorTree();

protected:
	UBaseBlackboardData* OwnBlackBoard;
	
};

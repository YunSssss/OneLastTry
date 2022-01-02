// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "BaseBlackboardData.generated.h"

/**
 * 
 */

	class UBlackboardKeyType_Object;
	class UBlackboardKeyType_Vector;
	class UBlackboardKeyType_Bool;

UCLASS()
class DEMO_API UBaseBlackboardData : public UBlackboardData
{
	GENERATED_BODY()
	
public:
	UBaseBlackboardData();

protected:
	
	UBlackboardKeyType_Vector* PlayerLocation;
	UBlackboardKeyType_Bool* CanSeenPlayer;
};

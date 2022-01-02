// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBlackboardData.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"


UBaseBlackboardData::UBaseBlackboardData() 
{
	Keys.SetNum(2);
    CanSeenPlayer = NewObject<UBlackboardKeyType_Bool>();
	if (CanSeenPlayer !=nullptr)
	{
		Keys[0].EntryName = "CanSeenPlayer";
		Keys[0].KeyType = CanSeenPlayer;
		Keys[0].bInstanceSynced = false;
	}

	PlayerLocation = NewObject<UBlackboardKeyType_Vector>();
	if (PlayerLocation!=nullptr)
	{
		Keys[1].EntryName = "PlayerLocation";
		Keys[1].KeyType = PlayerLocation;
		Keys[1].bInstanceSynced = false;
	}
}

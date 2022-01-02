// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBehaviorTree.h"
#include "Demo/AI/BaseBlackboardData.h"

UEnemyBehaviorTree::UEnemyBehaviorTree()
{
    OwnBlackBoard = NewObject<UBaseBlackboardData>();
    if(OwnBlackBoard && (!BlackboardAsset))
    {
        BlackboardAsset = OwnBlackBoard;
    }
}


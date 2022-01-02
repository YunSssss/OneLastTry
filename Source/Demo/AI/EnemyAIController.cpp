// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Demo/AI/BaseBlackboardData.h"
#include "Demo/AI/EnemyBehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Demo/Characters/EnemyCharacter1.h"


AEnemyAIController::AEnemyAIController() 
{
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
    BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponennt"));
}

void AEnemyAIController::OnPossess(APawn* InPawn) 
{
    Super::OnPossess(InPawn);

    AEnemyCharacter1* EnemyChar = Cast<AEnemyCharacter1>(InPawn);
    if(!EnemyChar)
    {
        return;
    }
    
    OwnBlackboard = NewObject<UBaseBlackboardData>();
    if(OwnBlackboard)
    {
        UseBlackboard(OwnBlackboard,BlackboardComp);
    }
        
    OwnBehaviorTree = NewObject<UEnemyBehaviorTree>();
    if(OwnBehaviorTree)
    {
        BehaviorTreeComp->StartTree(*OwnBehaviorTree);
    }
        
}

void AEnemyAIController::OnUnPossess() 
{
    Super::OnUnPossess();
    if(BehaviorTreeComp)
    {
        BehaviorTreeComp->StopTree(EBTStopMode::Safe);
    }
    
}

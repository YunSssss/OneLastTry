// Fill out your copyright notice in the Description page of Project Settings.


#include "Demo/AI/AIController_Enemy2.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "UObject/ConstructorHelpers.h"
#include "Demo/Characters/EnemyCharacter2.h"


AAIController_Enemy2::AAIController_Enemy2() 
{
    BehaviorTreeCompo = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Enemy2BeahvoirTreeComp"));
    BlackBoardCompo = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Enemy2BalckboardComp"));

    static ConstructorHelpers::FObjectFinder<UBehaviorTree>BehaviorTreeObj(TEXT("BehaviorTree'/Game/Blueprints/Ai/AI_Enemy2BT.AI_Enemy2BT'"));
    if(BehaviorTreeObj.Succeeded())
    {
        BehaviorTree = BehaviorTreeObj.Object;
    }

}

void AAIController_Enemy2::OnPossess(APawn* InPawn) 
{
    AEnemyCharacter2* AIPawn = Cast<AEnemyCharacter2>(InPawn);
	if (AIPawn == nullptr)
	{
		return;
	}
    Super::OnPossess(InPawn);

    if(AIPawn !=nullptr && BehaviorTree!=nullptr)
    {
        
        UseBlackboard(BehaviorTree->BlackboardAsset,BlackBoardCompo);
        AIPawn->BlackboardComp->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
    }
      
    if(BehaviorTreeCompo)
    {
        BehaviorTreeCompo->StartTree(*BehaviorTree);
    }

}

void AAIController_Enemy2::OnUnPossess() 
{
    Super::OnUnPossess();
    if(BehaviorTreeCompo!=nullptr)
    {
        BehaviorTreeCompo->StopTree(EBTStopMode::Safe);
    }
   
}


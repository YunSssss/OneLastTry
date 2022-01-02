// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GoToPlayer.h"
#include "Demo/AI/AIController_Enemy2.h"
#include "Demo/Characters/EnemyCharacter2.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Demo/Characters/MyPlayerCharacter.h"


EBTNodeResult::Type UBTT_GoToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    AAIController_Enemy2* AIController = Cast<AAIController_Enemy2>(OwnerComp.GetAIOwner()); 
	if (AIController != nullptr)
	{
		
		FVector TargetLocation;
		UBlackboardComponent* BlackboardCompo = OwnerComp.GetBlackboardComponent();
		if (BlackboardCompo != nullptr)
		{
			TargetLocation = BlackboardCompo->GetValueAsVector(TEXT("TargetLocation"));
		}

		AEnemyCharacter2* AIPawn = Cast<AEnemyCharacter2>(AIController->GetPawn()); 
		if (AIPawn != nullptr && AIPawn->bSeenPlayer) 
		{
            AMyPlayerCharacter* Player = Cast<AMyPlayerCharacter>(OwnerComp.GetOwner()->GetOwner());
			if(Player!=nullptr)
			{
				AIController->SetFocus(Player,EAIFocusPriority::Move);
			}
			AIController->MoveToLocation(TargetLocation);
			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Failed;
		}
	}
	else
	{
		return EBTNodeResult::Failed; // 失败
	}
}

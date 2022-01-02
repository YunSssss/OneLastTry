// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter1.h"
#include "Demo/AI/EnemyAIController.h"
#include "Perception/PawnSensingComponent.h"
#include "Demo/Characters/MyPlayerCharacter.h"
#include "Demo/AI/BaseBlackboardData.h"
#include "Demo/AI/EnemyBehaviorTree.h"
#include "Demo/AI/EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

AEnemyCharacter1::AEnemyCharacter1() 
{
    AIControllerClass = AEnemyAIController::StaticClass();

    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
    PawnSensingComp->OnSeePawn.AddDynamic(this,&AEnemyCharacter1::OnSeenPawn);
    GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

} 

void AEnemyCharacter1::OnSeenPawn(APawn* Pawn) 
{
    AMyPlayerCharacter* PlayerChar  = Cast<AMyPlayerCharacter>(Pawn);
    AEnemyAIController* ThisAIControl =Cast<AEnemyAIController>(this->GetController());

    if(PlayerChar && ThisAIControl)
    {
        FVector PlayerLocaton = PlayerChar->GetActorLocation();
        ThisAIControl->BlackboardComp->SetValueAsVector("PlayerLocation",PlayerLocaton);
        ThisAIControl->SetFocus(PlayerChar,EAIFocusPriority::Move);
        FVector MoveToLocation =ThisAIControl->BlackboardComp->GetValueAsVector("PlayerLocation");
        ThisAIControl->MoveTo(FVector(MoveToLocation.X,MoveToLocation.Y,0.0f));
    }
}

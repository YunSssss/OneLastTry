// Fill out your copyright notice in the Description page of Project Settings.

#include "Demo/Characters/EnemyCharacter2.h"
#include "Demo/AI/AIController_Enemy2.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "UObject/ConstructorHelpers.h"
#include "Demo/Characters/MyPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"


AEnemyCharacter2::AEnemyCharacter2() 
{
    AIControllerClass = AAIController_Enemy2::StaticClass();

    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Enemy2PawnSensingComp"));
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Enemy2BlackboardComp"));
    GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
 
    bSeenPlayer = false;


}

void AEnemyCharacter2::BeginPlay() 
{
    Super::BeginPlay();
    if(PawnSensingComp != nullptr)
    {
        PawnSensingComp->OnSeePawn.AddDynamic(this,&AEnemyCharacter2::HadSeenPlayer);
    }
}

void AEnemyCharacter2::HadSeenPlayer(APawn* Pawn) 
{
    UE_LOG(LogTemp, Warning, TEXT("SeePlayer"));
    AMyPlayerCharacter* Player = Cast<AMyPlayerCharacter>(Pawn);
    AAIController_Enemy2* AIController = Cast<AAIController_Enemy2>(GetController());
    if(Player && AIController)
    {
        
        FVector PlayerLocation = Player->GetActorLocation();
        
        AIController->BlackBoardCompo->SetValueAsVector(TEXT("TargetLocation"), PlayerLocation);
		bSeenPlayer = true;

    }

}


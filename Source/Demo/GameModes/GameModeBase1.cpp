// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase1.h"
#include "Uobject/ConstructorHelpers.h"
#include "Demo/Characters/BaseCharacter.h"

AGameModeBase1::AGameModeBase1()
{
    static ConstructorHelpers::FClassFinder<APawn>PlayerPawn(TEXT("Blueprint'/Game/Blueprints/Characters/Player_BP.Player_BP_C'"));

    if(PlayerPawn.Succeeded())
    {
        DefaultPawnClass = PlayerPawn.Class;
    }

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstanceBase.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds) 
{
    CharacterPawn = Cast<ABaseCharacter>(TryGetPawnOwner());

    if(CharacterPawn != nullptr)
    {
        MoveSpeed = CharacterPawn->GetVelocity().Size();
        InAir = CharacterPawn->GetCharacterMovement()->IsFalling();
    }
}

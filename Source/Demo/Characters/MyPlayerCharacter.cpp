// Fill out your copyright notice in the Description page of Project Settings.


#include "Demo/Characters/MyPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Abilities/GameplayAbility_CharacterJump.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"


AMyPlayerCharacter::AMyPlayerCharacter()
{
    

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->SetupAttachment(RootComponent);

    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
    PlayerCamera->bUsePawnControlRotation = false;
    PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

    
}

void AMyPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) 
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

   
    PlayerInputComponent->BindAxis("MoveForward",this,&AMyPlayerCharacter::MoveFW);
    PlayerInputComponent->BindAxis("MoveRight",this,&AMyPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn",this,&ACharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp",this,&ACharacter::AddControllerPitchInput);
    //PlayerInputComponent->BindAction("Jump" ,IE_Pressed,this,&ACharacter::Jump);
    // PlayerInputComponent->BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);

    if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent,
			FGameplayAbilityInputBinds(
				FString(),
				FString(),
				FString(TEXT("AbilityInputKeysID")),
				static_cast<int32>(AbilityInputKeysID::None),
				static_cast<int32>(AbilityInputKeysID::None)
			)
		);
	}


}

void AMyPlayerCharacter::PossessedBy(AController* NewController) 
{
    if(!AbilitySystemComponent)
    {
        return;
    }

    for (TPair<AbilityInputKeysID, TSubclassOf<UGameplayAbility>> GA : Abilitys)
	{
		if (GA.Key != AbilityInputKeysID::None)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(GA.Value, 1, static_cast<int32>(GA.Key), this));

		}
	}
}


void AMyPlayerCharacter::MoveFW(float Value) 
{
    if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);
	}
}

void AMyPlayerCharacter::MoveRight(float Value) 
{
    if ( (Controller != NULL) && (Value != 0.0f) )
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Value);
	}
}

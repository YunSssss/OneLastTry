// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "AbilitySystemComponent.h"
#include "Demo/Gas/AttributeSetBase.h"
#include "GameplayEffect.h"
#include "Abilities/GameplayAbility.h"


ABaseCharacter::ABaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	GetCapsuleComponent()->InitCapsuleSize(42.0f,96.0f);


	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSetBase = CreateDefaultSubobject<UAttributeSetBase>(TEXT("AttributeSetBase"));

	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}


void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if(!IsValid(AbilitySystemComponent))
	{
		return;
	}
	else
	{
	 	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	 	EffectContext.AddSourceObject(this);

		for(TSubclassOf<UGameplayEffect>GEClass :SetEffectsBeforePlay)
	 	{
			GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(GEClass->GetDefaultObject<UGameplayEffect>(), 1, EffectContext);
		}
			
	 }
}


void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const 
{
	return AbilitySystemComponent;
}

void ABaseCharacter::PossessedBy(AController* NewController) 
{
	Super::PossessedBy(NewController);


	
}

void ABaseCharacter::ReceiveDamage(UAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
	DamageReceived.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}


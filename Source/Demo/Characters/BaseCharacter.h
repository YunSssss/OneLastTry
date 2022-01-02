// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UAbilitySystemComponent;
class UAttributeSetBase;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

UCLASS()
class DEMO_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

protected:
	
	virtual void BeginPlay() override;
	
public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UAttributeSetBase* AttributeSetBase;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TSubclassOf<UGameplayAbility>> SetAbilityBeforePlay;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TSubclassOf<UGameplayEffect>> SetEffectsBeforePlay;

	FReceivedDamageDelegate DamageReceived;

	virtual void ReceiveDamage(UAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);

};

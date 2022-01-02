// Fill out your copyright notice in the Description page of Project Settings.


#include "Demo/Gas/DamageExecutionCalculation.h"
#include "Demo/Gas/AttributeSetBase.h"
#include "Abilities/GameplayAbility.h"
#include "Demo/Characters/MyPlayerCharacter.h"

struct MDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(ArmorPoint);

	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	MDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, ArmorPoint, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, Damage, Target, false);
	}
};

static const MDamageStatics& DamageStatics()
{
	static MDamageStatics DamageStatics;
	return DamageStatics;
}

void UDamageExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent* SourceAbilityComp = ExecutionParams.GetSourceAbilitySystemComponent();
	UAbilitySystemComponent* TargetAbilityComp = ExecutionParams.GetTargetAbilitySystemComponent();

	AActor* SourceActor = SourceAbilityComp ? SourceAbilityComp->AvatarActor : nullptr;
	AActor* TargetActor = TargetAbilityComp ? TargetAbilityComp->AvatarActor : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	// Gather the tags from the source and target as that can affect which buffs should be used
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float ArmorPoint = 1.0f;

	FMath::Max<float>(ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorPointDef, EvaluationParameters, ArmorPoint), 0.0f);

	float Damage = FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Gas.Damages")), false, -1.0f), 0.0f);
	float UnmitigatedDamage = Damage;
	float MitigatedDamage = (Damage) * (100 / (100 + ArmorPoint));

	if (MitigatedDamage > 0.f)
	{

		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, MitigatedDamage));
	}


	UAbilitySystemComponent* TargetASC = Cast<UAbilitySystemComponent>(TargetAbilityComp);
	if (TargetASC)
	{
		UAbilitySystemComponent* SourceASC = Cast<UAbilitySystemComponent>(SourceAbilityComp);
		AMyPlayerCharacter* Target = Cast<AMyPlayerCharacter>(TargetASC->GetOwner());
		Target->ReceiveDamage(SourceASC, UnmitigatedDamage, MitigatedDamage);
	}
}


#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class DEMO_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
	
public:
	UAttributeSetBase();

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Health)

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxHealth)

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxMana)

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Mana)

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxSpeed)

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameplayAttributeData ArmorPoint;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, ArmorPoint)


		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Damage)


	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

protected:
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

};

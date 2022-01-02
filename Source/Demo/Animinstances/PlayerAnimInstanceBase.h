// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Demo/Characters/BaseCharacter.h"
#include "PlayerAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UPlayerAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MoveSpeed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool InAir;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ABaseCharacter* CharacterPawn;
	virtual void NativeUpdateAnimation(float DeltaSeconds);
	
};

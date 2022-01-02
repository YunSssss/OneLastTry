// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Demo/Characters/BaseCharacter.h"
#include "Demo/Gas/PlayerInputKeys.h"
#include "MyPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class DEMO_API AMyPlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMyPlayerCharacter();
	
	UPROPERTY(BlueprintReadWrite)
	UCameraComponent* PlayerCamera;

	UPROPERTY(BlueprintReadWrite)
	USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TMap<AbilityInputKeysID, TSubclassOf<class UGameplayAbility>> Abilitys;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

private:
	void MoveFW(float Value);
	void MoveRight(float Value);
};

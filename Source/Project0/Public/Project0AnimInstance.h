// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Project0AnimInstance.generated.h"

class UCharacterMovementComponent;
class AProject0Character;
/**
 * 
 */
UCLASS()
class PROJECT0_API UProject0AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly)
	AProject0Character* Project0Character;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UCharacterMovementComponent* Project0CharacterMovement;
	
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;
	
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool IsFalling;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "Project0Character.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UMotionWarpingComponent;

UCLASS()
class PROJECT0_API AProject0Character : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	UMotionWarpingComponent* MotionWarpingComponent;

public:
	AProject0Character();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump() override;
	

public:
	FORCEINLINE UMotionWarpingComponent* GetMotionWarpingComponent() const { return MotionWarpingComponent; }
};

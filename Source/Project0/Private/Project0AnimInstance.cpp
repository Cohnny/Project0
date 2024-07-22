// Fill out your copyright notice in the Description page of Project Settings.


#include "Project0AnimInstance.h"
#include "Project0Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UProject0AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Project0Character = Cast<AProject0Character>(TryGetPawnOwner());
	if(Project0Character)
	{
		Project0CharacterMovement = Project0Character->GetCharacterMovement();
	}
}

void UProject0AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(Project0CharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(Project0CharacterMovement->Velocity);
		IsFalling = Project0CharacterMovement->IsFalling();
	}
}

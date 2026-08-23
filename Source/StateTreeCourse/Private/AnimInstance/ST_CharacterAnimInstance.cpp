// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/ST_CharacterAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "Character/ST_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UST_CharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AST_CharacterBase>(TryGetPawnOwner());
	
	if (OwningCharacter != nullptr)
	{
		OwningCharacterMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UST_CharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (OwningCharacter == nullptr || OwningCharacterMovementComponent == nullptr) return;
	
	GroundSpeed = OwningCharacter->GetVelocity().Size();
	
	OwningCharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f ? bHasAcceleration = true : bHasAcceleration = false;
	
	OwningCharacterMovementComponent->IsFalling() ? bIsInAir = true : bIsInAir = false;
	
	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ST_CharacterAnimInstance.generated.h"

class UBlendSpace1D;
class UCharacterMovementComponent;
class AST_CharacterBase;
/**
 * 
 */
UCLASS()
class STATETREECOURSE_API UST_CharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	
	virtual void NativeInitializeAnimation() override;
	
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
	void SetHeadLookAngle(const float InAngle) { HeadLookAngle = InAngle; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Owner", meta=(AllowPrivateAccess=true))
	AST_CharacterBase* OwningCharacter;
	
	UPROPERTY()
	UCharacterMovementComponent* OwningCharacterMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|Locomotion")
	float GroundSpeed;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|Locomotion")
	bool bHasAcceleration;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|Locomotion")
	bool bIsInAir;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|Locomotion")
	float LocomotionDirection;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|Locomotion")
	float HeadLookAngle = 0.0f;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Blendspace",meta=(AllowPrivateAccess="true"))
	UBlendSpace1D* ForwardBlendSpace;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Blendspace",meta=(AllowPrivateAccess="true"))
	UBlendSpace1D* ForwardArmedBlendSpace;
};


















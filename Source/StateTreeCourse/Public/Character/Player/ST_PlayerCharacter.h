// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Character/ST_CharacterBase.h"
#include "ST_PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class STATETREECOURSE_API AST_PlayerCharacter : public AST_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AST_PlayerCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void PawnClientRestart() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	UCameraComponent* FollowCamera;
	
#pragma region Input
	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AllowPrivateAccess="true"))
	UInputMappingContext* MinimalInputMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* MoveInputAction;
	
	void Move(const FInputActionValue& Value);
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* LookInputAction;
	
	void Look(const FInputActionValue& Value);
#pragma endregion 
};

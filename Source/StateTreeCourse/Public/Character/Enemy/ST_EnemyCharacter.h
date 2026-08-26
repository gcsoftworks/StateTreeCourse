// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ST_CharacterBase.h"
#include "ST_EnemyCharacter.generated.h"

UCLASS()
class STATETREECOURSE_API AST_EnemyCharacter : public AST_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AST_EnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

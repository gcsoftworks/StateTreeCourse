// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ST_CharacterBaseInterface.h"
#include "Interface/ST_CharacterCombatInterface.h"
#include "ST_CharacterBase.generated.h"

class UST_CharacterCombatComponent;

UCLASS()
class STATETREECOURSE_API AST_CharacterBase : public ACharacter, public IST_CharacterBaseInterface, public IST_CharacterCombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AST_CharacterBase();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual USkeletalMeshComponent* GetSkeletalMeshComponent() const override;
	
	virtual UStaticMeshComponent* GetWeaponStaticMeshComponent() const override;
	
	virtual UST_CharacterCombatComponent* GetCharacterCombatComponent() const override;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* WeaponStaticMeshComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	UST_CharacterCombatComponent* CharacterCombatComponent;

};
















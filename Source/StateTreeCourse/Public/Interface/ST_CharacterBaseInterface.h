// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ST_CharacterBaseInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UST_CharacterBaseInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STATETREECOURSE_API IST_CharacterBaseInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual USkeletalMeshComponent* GetSkeletalMeshComponent() const;
	virtual UStaticMeshComponent* GetWeaponStaticMeshComponent() const;
};

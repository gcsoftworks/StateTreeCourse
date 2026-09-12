// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/ST_CharacterBaseInterface.h"


// Add default functionality here for any IST_CharacterBaseInterface functions that are not pure virtual.
USkeletalMeshComponent* IST_CharacterBaseInterface::GetSkeletalMeshComponent() const
{
	return nullptr;
}

UStaticMeshComponent* IST_CharacterBaseInterface::GetWeaponStaticMeshComponent() const
{
	return nullptr;
}

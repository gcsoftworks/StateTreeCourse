// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ST_ActorGameplayTagsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UST_ActorGameplayTagsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STATETREECOURSE_API IST_ActorGameplayTagsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual FGameplayTagContainer& GetOwnedGameplayTags() = 0;
};

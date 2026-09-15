// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_BlueprintFunctionLibrary.h"

#include "GameplayTagContainer.h"
#include "Interface/ST_ActorGameplayTagsInterface.h"

bool UST_BlueprintFunctionLibrary::BP_DoesActorHasTag(AActor* Actor, const FGameplayTag TagToCheck,
	const bool bIsExactTag)
{
	return NativeDoesActorHasTag(Actor, TagToCheck, bIsExactTag);
}

bool UST_BlueprintFunctionLibrary::NativeDoesActorHasTag(AActor* Actor, const FGameplayTag TagToCheck, const bool bIsExactTag)
{
	if (Actor == nullptr || TagToCheck.IsValid() == false)
	{
		return false;
	}
	
	IST_ActorGameplayTagsInterface* ActorGameplayTagsInterface = Cast<IST_ActorGameplayTagsInterface>(Actor);
	
	if (ActorGameplayTagsInterface == nullptr)
	{
		return false;
	}
	
	if (bIsExactTag)
	{
		return ActorGameplayTagsInterface->GetOwnedGameplayTags().HasTagExact(TagToCheck);
	}
	
	return ActorGameplayTagsInterface->GetOwnedGameplayTags().HasTag(TagToCheck);
}

void UST_BlueprintFunctionLibrary::NativeAddGameplayTagToActor(AActor* Actor, const FGameplayTag TagToAdd)
{
	if (Actor == nullptr || TagToAdd.IsValid() == false)
	{
		return;
	}
	
	IST_ActorGameplayTagsInterface* ActorGameplayTagsInterface = Cast<IST_ActorGameplayTagsInterface>(Actor);
	
	if (ActorGameplayTagsInterface == nullptr)
	{
		return;
	}
	
	ActorGameplayTagsInterface->GetOwnedGameplayTags().AddTag(TagToAdd);
}

void UST_BlueprintFunctionLibrary::NativeRemoveGameplayTagFromActor(AActor* Actor, const FGameplayTag TagToRemove)
{
	if (Actor == nullptr || TagToRemove.IsValid() == false)
	{
		return;
	}
	
	IST_ActorGameplayTagsInterface* ActorGameplayTagsInterface = Cast<IST_ActorGameplayTagsInterface>(Actor);
	
	if (ActorGameplayTagsInterface == nullptr)
	{
		return;
	}
	
	ActorGameplayTagsInterface->GetOwnedGameplayTags().RemoveTag(TagToRemove);
}












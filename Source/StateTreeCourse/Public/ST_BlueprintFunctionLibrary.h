// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ST_BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class STATETREECOURSE_API UST_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure, Category="BlueprintFunctionLibrary|ActorGameplayTag", meta=(DisplayName="Does Actor Has Tag", BlueprintThreadSafe))
	static bool BP_DoesActorHasTag(AActor* Actor, const FGameplayTag TagToCheck, const bool bIsExactTag = true);
	static bool NativeDoesActorHasTag(AActor* Actor, const FGameplayTag TagToCheck, const bool bIsExactTag = true);
	
	static void NativeAddGameplayTagToActor(AActor* Actor, const FGameplayTag TagToAdd);
	
	static void NativeRemoveGameplayTagFromActor(AActor* Actor, const FGameplayTag TagToRemove);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "ST_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STATETREECOURSE_API AST_PlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:
	AST_PlayerController();
	
	virtual FGenericTeamId GetGenericTeamId() const override;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Controller", meta=(AllowPrivateAccess="true"))
	FGenericTeamId TeamID;
};

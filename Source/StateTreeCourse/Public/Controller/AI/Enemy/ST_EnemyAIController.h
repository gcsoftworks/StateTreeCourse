// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controller/AI/ST_AIController.h"
#include "ST_EnemyAIController.generated.h"

UCLASS()
class STATETREECOURSE_API AST_EnemyAIController : public AST_AIController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

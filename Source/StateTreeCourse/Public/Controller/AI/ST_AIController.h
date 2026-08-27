// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ST_AIController.generated.h"

UCLASS()
class STATETREECOURSE_API AST_AIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AST_AIController();
	
	explicit AST_AIController(const FObjectInitializer& ObjectInitializer);
	
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	int32 TeamID;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ST_AIController.generated.h"

class UAISenseConfig_Sight;

UCLASS(BlueprintType, Abstract, meta=(DisplayName="AI Controller"))
class STATETREECOURSE_API AST_AIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit AST_AIController(const FObjectInitializer& ObjectInitializer);
	
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	int32 TeamID;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Component", meta=(AllowPrivateAccess="true"))
	UAIPerceptionComponent* AIPerceptionComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Component", meta=(AllowPrivateAccess="true"))
	bool bUseSightSense = true;
	
	UPROPERTY()
	UAISenseConfig_Sight* AISenseConfig_Sight;
};

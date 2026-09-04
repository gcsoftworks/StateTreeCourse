// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StateTreeAIComponent.h"

#include "ST_StateTreeAIComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STATETREECOURSE_API UST_StateTreeAIComponent : public UStateTreeAIComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UST_StateTreeAIComponent();
	
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/AI/ST_AIController.h"


// Sets default values
AST_AIController::AST_AIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AST_AIController::AST_AIController(const FObjectInitializer& ObjectInitializer)
{
	AAIController::SetGenericTeamId(FGenericTeamId(TeamID));
}

ETeamAttitude::Type AST_AIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* OtherPawn = Cast<APawn>(&Other);
	
	IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());
	
	if (OtherTeamAgent == nullptr)
	{
		return ETeamAttitude::Neutral;
	}
	
	const int32 OtherTeamId = OtherTeamAgent->GetGenericTeamId();
	
	if (OtherTeamId != GetGenericTeamId() && OtherTeamId != -1)
	{
		return ETeamAttitude::Hostile;
	}
	
	if (OtherTeamId == GetGenericTeamId())
	{
		return ETeamAttitude::Friendly;
	}
	
	return ETeamAttitude::Neutral;
}

// Called when the game starts or when spawned
void AST_AIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AST_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


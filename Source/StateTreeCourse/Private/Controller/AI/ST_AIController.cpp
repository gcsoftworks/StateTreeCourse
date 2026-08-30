// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/AI/ST_AIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"


// Sets default values
AST_AIController::AST_AIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AST_AIController::AST_AIController(const FObjectInitializer& ObjectInitializer)
{
	AAIController::SetGenericTeamId(FGenericTeamId(TeamID));
	
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISenseConfig_Sight"));
	AISenseConfig_Sight->SightRadius = 1000.0f;
	AISenseConfig_Sight->LoseSightRadius = 1500.0f;
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 180.0f;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->SetMaxAge(6.0f);
	AIPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	AIPerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
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

#if WITH_EDITOR
void AST_AIController::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = PropertyChangedEvent.Property != nullptr ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AST_AIController, bUseSightSense))
	{
		if (AIPerceptionComponent && AISenseConfig_Sight)
		{
			AIPerceptionComponent->SetSenseEnabled(UAISense_Sight::StaticClass(), bUseSightSense);
		}
		return;
	}
}
#endif


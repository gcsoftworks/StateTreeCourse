// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/AI/ST_AIController.h"

#include "Component/StateTree/ST_StateTreeAIComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AST_AIController::AST_AIController(const FObjectInitializer& ObjectInitializer)
{
	AAIController::SetGenericTeamId(FGenericTeamId(TeamID));
	
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISenseConfig_Sight"));
	AISenseConfig_Sight->SightRadius = 1000.0f;
	AISenseConfig_Sight->LoseSightRadius = 1500.0f;
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 90.0f;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->SetMaxAge(6.0f);
	AIPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	AIPerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
	
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AST_AIController::OnTargetPerceptionUpdated);
	
	StateTreeAIComponent = CreateDefaultSubobject<UST_StateTreeAIComponent>(TEXT("StateTreeAIComponent"));
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
	
	AST_AIController::SetGenericTeamId(FGenericTeamId(TeamID));
}

void AST_AIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Actor == nullptr)
	{
		return;
	}
	
	static const FAISenseID SightID = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	
	if (Stimulus.Type == SightID)
	{
		if (Stimulus.WasSuccessfullySensed() == true)
		{
			if (GetTeamAttitudeTowards(*Actor) == ETeamAttitude::Hostile)
			{
				HostileActor = Actor;
				//TODO: Send StateTree event
			}
		}
		else
		{
			HostileActor = nullptr;
			//TODO: Send StateTree event
		}
	}
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


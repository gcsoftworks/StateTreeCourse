#include "StateTree/Task/ST_LookAroundStateTreeTask.h"

#include "StateTreeExecutionContext.h"
#include "AnimInstance/ST_CharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "Interface/ST_CharacterBaseInterface.h"

void FST_LookAroundInstanceData::ResetData()
{
	ElapsedTime = 0.0f;
	CharacterAnimInstance = nullptr;
}

const UStruct* FST_LookAroundStateTreeTask::GetInstanceDataType() const
{
	return FST_LookAroundInstanceData::StaticStruct();
}

EStateTreeRunStatus FST_LookAroundStateTreeTask::EnterState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	InstanceData.ElapsedTime = 0.0f;
	ACharacter* Character = Cast<ACharacter>(InstanceData.ContextActor);
	
	InstanceData.CharacterAnimInstance = Cast<UST_CharacterAnimInstance>(Character->GetMesh()->GetAnimInstance());
	
	if (InstanceData.CharacterAnimInstance == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	Cast<IST_CharacterBaseInterface>(InstanceData.ContextActor)->SetHeadLookAroundActive(true);
	
	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FST_LookAroundStateTreeTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor)
	{
		InstanceData.ElapsedTime += DeltaTime;
		
		float CalculateAngle = FMath::Sin(InstanceData.ElapsedTime * InstanceData.LookSpeed) * InstanceData.MaxLookAngle;
		
		InstanceData.CharacterAnimInstance->SetHeadLookAngle(CalculateAngle);
	}
	
	return EStateTreeRunStatus::Running;
}

void FST_LookAroundStateTreeTask::ExitState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor)
	{
		Cast<IST_CharacterBaseInterface>(InstanceData.ContextActor)->SetHeadLookAroundActive(false);
		InstanceData.CharacterAnimInstance->SetHeadLookAngle(0.0f);
		InstanceData.ResetData();
	}
}

#if WITH_EDITOR
FName FST_LookAroundStateTreeTask::GetIconName() const
{
	return FName("");
}

FColor FST_LookAroundStateTreeTask::GetIconColor() const
{
	return FColor::Silver;
}

FText FST_LookAroundStateTreeTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FST_LookAroundInstanceData>();
	
	if (InstanceData == nullptr)
	{
		return FText::GetEmpty();
	}
	
	return FText::Format(
		NSLOCTEXT(
			"FST_LookAroundStateTreeTask",
			"Context Actor Look Around Description",
			"Context Actor Look Around With {0} Angle"
		),
		FText::AsNumber(InstanceData->MaxLookAngle)
	);
}
#endif






















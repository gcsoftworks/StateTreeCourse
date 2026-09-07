#include "StateTree/Task/ST_UpdateMovementSpeedStateTreeTask.h"

#include "StateTreeExecutionContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


const UStruct* FST_UpdateMovementSpeedStateTreeTask::GetInstanceDataType() const
{
	return FST_UpdateMovementSpeedTaskInstanceData::StaticStruct();
}

EStateTreeRunStatus FST_UpdateMovementSpeedStateTreeTask::EnterState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FST_UpdateMovementSpeedTaskInstanceData& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	ACharacter* Character = Cast<ACharacter>(InstanceData.ContextActor);
	
	if (Character == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	Character->GetCharacterMovement()->MaxWalkSpeed = InstanceData.DesiredMaxWalkSpeed;
	return EStateTreeRunStatus::Succeeded;
}

#if WITH_EDITOR
FColor FST_UpdateMovementSpeedStateTreeTask::GetIconColor() const
{
	return FColor::Silver;
}

FName FST_UpdateMovementSpeedStateTreeTask::GetIconName() const
{
	return FName("");
}

FText FST_UpdateMovementSpeedStateTreeTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FST_UpdateMovementSpeedTaskInstanceData* InstanceData = InstanceDataView.GetPtr<FST_UpdateMovementSpeedTaskInstanceData>();
	
	if (InstanceData == nullptr)
	{
		return FText::GetEmpty();
	}
	
	return FText::Format(
		NSLOCTEXT(
			"FST_UpdateMovementSpeedStateTreeTask",
			"Update Context Actor Movement Speed",
			"Update <b>Context Actor</> Movement Speed To {0}"
		),
		FText::AsNumber(InstanceData->DesiredMaxWalkSpeed)
	);
}
#endif
















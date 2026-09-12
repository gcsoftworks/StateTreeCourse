#include "StateTree/Task/ST_PlayMontageAndWaitStateTreeTask.h"

#include "StateTreeExecutionContext.h"
#include "GameFramework/Character.h"

const UStruct* FST_PlayMontageAndWaitStateTreeTask::GetInstanceDataType() const
{
	return FST_PlayMontageAndWaitTaskInstanceData::StaticStruct();
}

EStateTreeRunStatus FST_PlayMontageAndWaitStateTreeTask::EnterState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	InstanceData.bIsFinished = false;
	InstanceData.bWasInterrupted = false;
	
	if (InstanceData.ContextActor == nullptr || InstanceData.MontageToPlay == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	UAnimInstance* AnimInstance = 
		Cast<ACharacter>(InstanceData.ContextActor)->GetMesh() ? 
			Cast<ACharacter>(InstanceData.ContextActor)->GetMesh()->GetAnimInstance() : nullptr;
	
	if (AnimInstance == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	const float Duration = AnimInstance->Montage_Play(InstanceData.MontageToPlay, InstanceData.PlayRate);
	if (Duration <= 0.0f)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	if (InstanceData.StartSection != NAME_None)
	{
		AnimInstance->Montage_JumpToSection(InstanceData.StartSection, InstanceData.MontageToPlay);	
	}
	
	FOnMontageEnded OnMontageEnded;
	OnMontageEnded.BindLambda([&InstanceData](UAnimMontage* Montage, bool bInterrupted)
	{
		InstanceData.bIsFinished = true;
		InstanceData.bWasInterrupted = bInterrupted;
	});
	
	AnimInstance->Montage_SetEndDelegate(OnMontageEnded, InstanceData.MontageToPlay);
	
	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FST_PlayMontageAndWaitStateTreeTask::Tick(FStateTreeExecutionContext& Context,
	const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.bIsFinished)
	{
		return InstanceData.bWasInterrupted ? EStateTreeRunStatus::Failed : EStateTreeRunStatus::Succeeded;
	}
	
	return EStateTreeRunStatus::Running;
}

void FST_PlayMontageAndWaitStateTreeTask::ExitState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor == nullptr)
	{
		return;
	}
	
	UAnimInstance* AnimInstance = 
		Cast<ACharacter>(InstanceData.ContextActor)->GetMesh() ? 
			Cast<ACharacter>(InstanceData.ContextActor)->GetMesh()->GetAnimInstance() : nullptr;
	
	if (AnimInstance == nullptr)
	{
		return;
	}
	
	FOnMontageEnded OnMontageEnded;
	AnimInstance->Montage_SetEndDelegate(OnMontageEnded, InstanceData.MontageToPlay);
	
	if (InstanceData.bStopWhenExitState && AnimInstance->Montage_IsPlaying(InstanceData.MontageToPlay))
	{
		AnimInstance->Montage_Stop(0.2f, InstanceData.MontageToPlay);
	}
}

#if WITH_EDITOR
FName FST_PlayMontageAndWaitStateTreeTask::GetIconName() const
{
	return FName("");
}

FColor FST_PlayMontageAndWaitStateTreeTask::GetIconColor() const
{
	return FColor::Silver;
}

FText FST_PlayMontageAndWaitStateTreeTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FST_PlayMontageAndWaitTaskInstanceData>();
	
	if (InstanceData == nullptr)
	{
		return FText::GetEmpty();
	}
	
	if (InstanceData->MontageToPlay == nullptr)
	{
		return NSLOCTEXT(
			"FST_PlayMontageAndWaitStateTreeTask",
			"Play Montage And Wait Task Description",
			"Play Montage And Wait On Context Actor"
		);
	}
	
	return FText::Format(
		NSLOCTEXT(
		"FST_PlayMontageAndWaitStateTreeTask",
		"Play Montage And Wait Task Description",
		"Play {0} Montage And Wait On Context Actor"
		),
		FText::FromString(InstanceData->MontageToPlay->GetName())
	);
}
#endif



















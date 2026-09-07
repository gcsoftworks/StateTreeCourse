#include "StateTree/Task/ST_GetRandomLocationStateTreeTask.h"

#include "NavigationSystem.h"
#include "StateTreeExecutionContext.h"

const UStruct* FST_GetRandomLocationAroundContextActorStateTreeTask::GetInstanceDataType() const
{
	return FST_GetRandomLocationAroundContextActorTaskInstanceData::StaticStruct();
}

EStateTreeRunStatus FST_GetRandomLocationAroundContextActorStateTreeTask::EnterState(
	FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FST_GetRandomLocationAroundContextActorTaskInstanceData& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	UWorld* World = InstanceData.ContextActor->GetWorld();
	
	if (World == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	UNavigationSystemV1* NavigationSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
	
	if (NavigationSystem == nullptr)
	{
		return EStateTreeRunStatus::Failed;
	}
	
	const FVector Origin = InstanceData.ContextActor->GetActorLocation();
	
	FNavLocation NavLocation;
	
	if (NavigationSystem->GetRandomReachablePointInRadius(Origin, InstanceData.SearchRadius, NavLocation))
	{
		InstanceData.RandomLocation = NavLocation.Location;
		return EStateTreeRunStatus::Succeeded;
	}
	else
	{
		return EStateTreeRunStatus::Failed;
	}
}

FColor FST_GetRandomLocationAroundContextActorStateTreeTask::GetIconColor() const
{
	return FColor::Silver;
}

FName FST_GetRandomLocationAroundContextActorStateTreeTask::GetIconName() const
{
	return FName("");
}

FText FST_GetRandomLocationAroundContextActorStateTreeTask::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	const FST_GetRandomLocationAroundContextActorTaskInstanceData* InstanceData 
	= InstanceDataView.GetPtr<FST_GetRandomLocationAroundContextActorTaskInstanceData>();
	
	if (InstanceData == nullptr)
	{
		return FText::GetEmpty();
	}
	
	return FText::Format(
		NSLOCTEXT(
		"FST_GetRandomLocationAroundContextActorStateTreeTask",
		"Get Random Location Around Context Actor",
		"Get Random Location Around Context Actor In Radius: {0} Units"
		),
		FText::AsNumber(InstanceData->SearchRadius)
	);
}


















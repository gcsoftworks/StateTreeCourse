#include "StateTree/Condition/ST_DoesActorHasTagStateTreeCondition.h"

#include "StateTreeExecutionContext.h"
#include "ST_BlueprintFunctionLibrary.h"

const UStruct* FST_DoesContextActorHasTagStateTreeCondition::GetInstanceDataType() const
{
	return FST_DoesContextActorHasTagConditionInstanceData::StaticStruct();
}

bool FST_DoesContextActorHasTagStateTreeCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.ContextActor == nullptr)
	{
		return false;
	}
	
	if (InstanceData.GameplayTag.IsValid() == false)
	{
		return false;
	}
	
	const bool bHasTag = UST_BlueprintFunctionLibrary::NativeDoesActorHasTag(InstanceData.ContextActor, InstanceData.GameplayTag);
	
	return InstanceData.bInvert ? !bHasTag : bHasTag;
	
}

#if WITH_EDITOR
FText FST_DoesContextActorHasTagStateTreeCondition::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FST_DoesContextActorHasTagConditionInstanceData>();
	
	if (!InstanceData)
	{
		return FText::GetEmpty();
	}
	
	return FText::Format(
		NSLOCTEXT(
			"FST_DoesActorHasTagStateTreeCondition",
			"Does Context Actor Has Tag Description",
			"Context Actor {0} {1}"
		),
		InstanceData->bInvert ? FText::FromString("not have") : FText::FromString("has"),
		FText::FromString(InstanceData->GameplayTag.ToString())
	);
}
#endif





















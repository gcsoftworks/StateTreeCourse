#include "StateTree/Evaluator/ST_AIControllerStateTreeEvaluator.h"

#include "StateTreeExecutionContext.h"
#include "Controller/AI/ST_AIController.h"

void FST_AIControllerEvaluatorInstanceData::ResetData()
{
	HostileActor = nullptr;
}

const UStruct* FST_AIControllerStateTreeEvaluator::GetInstanceDataType() const
{
	return FST_AIControllerEvaluatorInstanceData::StaticStruct();
}

void FST_AIControllerStateTreeEvaluator::TreeStart(FStateTreeExecutionContext& Context) const
{
	FST_AIControllerEvaluatorInstanceData& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.AIController == nullptr)
	{
		InstanceData.ResetData();
	}
}

void FST_AIControllerStateTreeEvaluator::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FST_AIControllerEvaluatorInstanceData& InstanceData = Context.GetInstanceData(*this);
	
	if (InstanceData.AIController == nullptr)
	{
		InstanceData.ResetData();
	}
	
	InstanceData.HostileActor = Cast<AST_AIController>(InstanceData.AIController)->GetHostileActor();
}

void FST_AIControllerStateTreeEvaluator::TreeStop(FStateTreeExecutionContext& Context) const
{
	FST_AIControllerEvaluatorInstanceData& InstanceData = Context.GetInstanceData(*this);
	
	InstanceData.ResetData();
}

#if WITH_EDITOR
FText FST_AIControllerStateTreeEvaluator::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	return NSLOCTEXT(
		"FST_AIControllerStateTreeEvaluator",
		"AI Controller Evaluator Description",
		"Evaluate AI Controller Data"
	);
}
#endif













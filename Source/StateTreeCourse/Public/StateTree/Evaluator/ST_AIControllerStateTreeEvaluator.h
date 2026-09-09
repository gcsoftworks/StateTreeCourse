#pragma once

#include "CoreMinimal.h"
#include "StateTreeEvaluatorBase.h"

#include "ST_AIControllerStateTreeEvaluator.generated.h"

class AAIController;

USTRUCT()
struct FST_AIControllerEvaluatorInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Context)
	TObjectPtr<AAIController> AIController;
	
	UPROPERTY(VisibleAnywhere, Category=Output)
	TObjectPtr<AActor> HostileActor = nullptr;
	
	void ResetData();
};

USTRUCT()
struct FST_AIControllerStateTreeEvaluator : public FStateTreeEvaluatorCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_AIControllerEvaluatorInstanceData;
	
	virtual const UStruct* GetInstanceDataType() const override;
	
	virtual void TreeStart(FStateTreeExecutionContext& Context) const override;
	virtual void Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void TreeStop(FStateTreeExecutionContext& Context) const override;
	
#if WITH_EDITOR
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif
	
};

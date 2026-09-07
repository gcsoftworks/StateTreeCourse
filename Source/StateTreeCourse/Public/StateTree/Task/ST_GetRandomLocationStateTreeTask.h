#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "ST_GetRandomLocationStateTreeTask.generated.h"

USTRUCT()
struct FST_GetRandomLocationAroundContextActorTaskInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Context, meta=(DisplayName="Context Actor"))
	TObjectPtr<APawn> ContextActor;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	float SearchRadius = 1000.0f;
	
	UPROPERTY(VisibleAnywhere, Category=Output)
	FVector RandomLocation = FVector::ZeroVector;
};

USTRUCT(Category="AI|Movement", meta=(DisplayName="Get Random Location Around Context Actor",
	ToolTip="Get a random location around the context actor within a specified radius",
	Keywords="Random Location, Context Actor, Search Radius, AI, Navigation")
)
struct STATETREECOURSE_API FST_GetRandomLocationAroundContextActorStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_GetRandomLocationAroundContextActorTaskInstanceData;
	
	virtual const UStruct* GetInstanceDataType() const override;
	
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	
#if WITH_EDITOR
	virtual FColor GetIconColor() const override;
	virtual FName GetIconName() const override;
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif
};

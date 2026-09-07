#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "ST_UpdateMovementSpeedStateTreeTask.generated.h"

USTRUCT()
struct FST_UpdateMovementSpeedTaskInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Context, meta=(DisplayName="Context Actor"))
	TObjectPtr<APawn> ContextActor;
	
	UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0"))
	float DesiredMaxWalkSpeed = 600.0f;
};

USTRUCT(Category="AI|Movement", meta=(DisplayName="Update Context Actor Movement Speed",
	ToolTip="Set the movement speed of the context actor",
	Keywords="Movement Speed, Context Actor, Max Walk Speed, Character Movement Component")
)
struct STATETREECOURSE_API FST_UpdateMovementSpeedStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_UpdateMovementSpeedTaskInstanceData;
	
	virtual const UStruct* GetInstanceDataType() const override;
	
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	
#if WITH_EDITOR
	virtual FColor GetIconColor() const override;
	virtual FName GetIconName() const override;
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif
};

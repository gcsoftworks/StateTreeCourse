#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"

#include "ST_LookAroundStateTreeTask.generated.h"

class UST_CharacterAnimInstance;

USTRUCT()
struct FST_LookAroundInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Context, meta=(DisplayName="Context Actor"))
	TObjectPtr<APawn> ContextActor;
	
	UPROPERTY()
	TObjectPtr<UST_CharacterAnimInstance> CharacterAnimInstance;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	float MaxLookAngle = 30.0f;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	float LookSpeed = 2.0f;
	
	float ElapsedTime = 0.0f;
	
	void ResetData();
	
};

USTRUCT(Category="AI|Movement", meta=(
	DisplayName="Context Actor Look Around"
))
struct STATETREECOURSE_API FST_LookAroundStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_LookAroundInstanceData;
	
	virtual const UStruct* GetInstanceDataType() const override;
	
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	
#if WITH_EDITOR
	virtual FName GetIconName() const override;
	virtual FColor GetIconColor() const override;
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif
	
};

































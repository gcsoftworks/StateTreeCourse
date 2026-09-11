#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "ST_PlayMontageAndWaitStateTreeTask.generated.h"

USTRUCT()
struct FST_PlayMontageAndWaitTaskInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category=Context, meta=(DisplayName="Context Actor"))
	TObjectPtr<APawn> ContextActor;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	TObjectPtr<UAnimMontage> MontageToPlay;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	float PlayRate = 1.0f;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	FName StartSection = NAME_None;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	bool bStopWhenExitState = true;
	
	bool bIsFinished = false;
	bool bWasInterrupted = false;
};

USTRUCT(Category="AI|Animation", meta=(
	DisplayName="Play Montage And Wait",
	ToolTip="Play Montage And Wait On Context Actor",
	Keywords="AI, Animation, Montage, StateTree"
))
struct FST_PlayMontageAndWaitStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_PlayMontageAndWaitTaskInstanceData;
	
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

















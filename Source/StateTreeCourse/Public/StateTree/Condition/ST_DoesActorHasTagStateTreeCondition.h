#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeConditionBase.h"

#include "ST_DoesActorHasTagStateTreeCondition.generated.h"

USTRUCT()
struct FST_DoesContextActorHasTagConditionInstanceData
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Context, meta=(DisplayName="Context Actor"))
	TObjectPtr<APawn> ContextActor;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	FGameplayTag GameplayTag;
	
	UPROPERTY(EditAnywhere, Category=Parameter)
	bool bInvert = false;
};

USTRUCT(Category="Condition|GameplayTags", 
	meta=(DisplayName="Does Context Actor Has Tag")
)
struct FST_DoesContextActorHasTagStateTreeCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()
	
	using FInstanceDataType = FST_DoesContextActorHasTagConditionInstanceData;
	
	virtual const UStruct* GetInstanceDataType() const override;
	
	virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
	
#if WITH_EDITOR
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif
	
};























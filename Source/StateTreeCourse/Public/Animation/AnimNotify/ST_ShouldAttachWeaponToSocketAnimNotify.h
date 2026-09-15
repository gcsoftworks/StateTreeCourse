// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ST_ShouldAttachWeaponToSocketAnimNotify.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="Should Attach Weapon To Socket"))
class STATETREECOURSE_API UST_ShouldAttachWeaponToSocketAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
	bool bIsArmed;
	
	virtual bool ShouldFireInEditor() override;
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
	virtual FString GetNotifyName_Implementation() const override;
};

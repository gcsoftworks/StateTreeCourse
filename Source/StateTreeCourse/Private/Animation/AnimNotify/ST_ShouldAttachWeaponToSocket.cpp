// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify/ST_ShouldAttachWeaponToSocket.h"

#include "Component/Character/ST_CharacterCombatComponent.h"
#include "Interface/ST_CharacterCombatInterface.h"

bool UST_ShouldAttachWeaponToSocket::ShouldFireInEditor()
{
	return false;
}

void UST_ShouldAttachWeaponToSocket::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	
	IST_CharacterCombatInterface* CharacterCombatInterface = Cast<IST_CharacterCombatInterface>(MeshComp->GetOwner());
	
	if (CharacterCombatInterface == nullptr)
	{
		return;
	}
	
	CharacterCombatInterface->GetCharacterCombatComponent()->AttachWeaponToSocket(bIsArmed);
}

FString UST_ShouldAttachWeaponToSocket::GetNotifyName_Implementation() const
{
	if (bIsArmed)
	{
		return "Attach Weapon To Hand";
	}
	else
	{
		return "Attach Weapon To Back";
	}
}
















// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Character/ST_CharacterCombatComponent.h"

#include "Character/ST_CharacterBase.h"


// Sets default values for this component's properties
UST_CharacterCombatComponent::UST_CharacterCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UST_CharacterCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	IST_CharacterBaseInterface* CharacterBaseInterface = Cast<IST_CharacterBaseInterface>(GetOwner());
	
	if (CharacterBaseInterface == nullptr || WeaponStaticMesh == nullptr || WeaponUnarmedSocketName == NAME_None)
	{
		return;
	}
	
	WeaponStaticMeshComponent = CharacterBaseInterface->GetWeaponStaticMeshComponent();
	
	if (WeaponStaticMeshComponent == nullptr)
	{
		return;
	}
	
	FAttachmentTransformRules AttachmentRules = 
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepWorld, true
	);
	
	WeaponStaticMeshComponent->SetStaticMesh(WeaponStaticMesh);
	WeaponStaticMeshComponent->AttachToComponent(CharacterBaseInterface->GetSkeletalMeshComponent(), AttachmentRules, WeaponUnarmedSocketName);
}


// Called every frame
void UST_CharacterCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

























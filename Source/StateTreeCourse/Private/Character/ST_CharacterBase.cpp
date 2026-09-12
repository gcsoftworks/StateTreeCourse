// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ST_CharacterBase.h"

#include "Component/Character/ST_CharacterCombatComponent.h"

// Sets default values
AST_CharacterBase::AST_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	WeaponStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponStaticMeshComponent"));
	WeaponStaticMeshComponent->SetupAttachment(GetMesh());
	
	CharacterCombatComponent = CreateDefaultSubobject<UST_CharacterCombatComponent>(TEXT("CharacterCombatComponent"));
}

// Called when the game starts or when spawned
void AST_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AST_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AST_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

USkeletalMeshComponent* AST_CharacterBase::GetSkeletalMeshComponent() const
{
	return GetMesh();
}

UStaticMeshComponent* AST_CharacterBase::GetWeaponStaticMeshComponent() const
{
	return WeaponStaticMeshComponent;
}

UST_CharacterCombatComponent* AST_CharacterBase::GetCharacterCombatComponent() const
{
	return CharacterCombatComponent;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/ST_EnemyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AST_EnemyCharacter::AST_EnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->MaxAcceleration = 1800.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;
}

// Called when the game starts or when spawned
void AST_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AST_EnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AST_EnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


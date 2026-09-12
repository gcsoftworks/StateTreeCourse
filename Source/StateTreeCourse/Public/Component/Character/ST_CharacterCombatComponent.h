// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ST_CharacterCombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STATETREECOURSE_API UST_CharacterCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UST_CharacterCombatComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterCombat", meta=(AllowPrivateAccess=true))
	UStaticMesh* WeaponStaticMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterCombat", meta=(AllowPrivateAccess=true))
	FName WeaponArmedSocketName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterCombat", meta=(AllowPrivateAccess=true))
	FName WeaponUnarmedSocketName;
	
	UPROPERTY()
	UStaticMeshComponent* WeaponStaticMeshComponent;
};

















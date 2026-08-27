// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/Player/ST_PlayerController.h"

AST_PlayerController::AST_PlayerController()
{
	TeamID = FGenericTeamId(0);
}

FGenericTeamId AST_PlayerController::GetGenericTeamId() const
{
	return TeamID;
}

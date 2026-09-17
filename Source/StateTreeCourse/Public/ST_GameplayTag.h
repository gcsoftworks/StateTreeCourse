#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace ST_GameplayTag
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Armed);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_AI_Event_Idle);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_AI_Event_Patrol);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_AI_Event_Combat);
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_State_Idle);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_State_Patrol);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(StateTree_State_Combat);
}

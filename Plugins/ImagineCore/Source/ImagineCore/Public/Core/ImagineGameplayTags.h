#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

/**
 * @brief UImagineGameplayTags is a static class that provides easy access to
 * commonly used GameplayTags for the ImagineCore plugin.
 *
 * Design Philosophy:
 * - Centralized Tag Access: Provides a single point of truth for ImagineCore's
 * generic GameplayTags, making them easy to find and use.
 * - Avoids Magic Strings: Encourages using defined constants instead of hardcoded strings.
 */

namespace Imagine
{
	// --- Input Action Tags ---
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Move);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Look);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Jump);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Crouch);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Sprint);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Interact);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_PrimaryAttack);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Aim);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Reload);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_SwitchWeapon);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_UseAbility_1);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_UseAbility_2);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_UI_PauseMenu);
	IMAGINECORE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_UI_Inventory);
	

	struct FGameplayTags
	{
		static void InitializeNativeTags();
	};

}

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

/**
 * @brief UCortexGameplayTags is a static class that provides easy access to
 * commonly used GameplayTags for the Cortex game.
 *
 * Design Philosophy:
 * - Centralized Tag Access: Provides a single point of truth for Cortex's
 *  GameplayTags, making them easy to find and use.
 * - Avoids Magic Strings: Encourages using defined constants instead of hardcoded strings.
 */

namespace Cortex
{
	// --- Input Action Tags ---
	CORTEX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_SwitchCameraMode);
	CORTEX_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Debug);
	
	struct FGameplayTags
	{
		static void InitializeNativeTags();
	};

}


#include "GASLite/ImagineGameplayAbility.h"
#include "GASLite/ImagineAbilitySystemComponent.h"

UImagineGameplayAbility::UImagineGameplayAbility()
{
}

void UImagineGameplayAbility::ActivateAbility()
{
    OnActivateAbility();
}

void UImagineGameplayAbility::SetOwner(UImagineAbilitySystemComponent* InOwner)
{
    Owner = InOwner;
}

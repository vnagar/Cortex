
#include "GASLite/ImagineAttributeSet.h"
#include "GASLite/ImagineAbilitySystemComponent.h"

UImagineAttributeSet::UImagineAttributeSet()
{
}

void UImagineAttributeSet::PreAttributeChange(const FName& AttributeName, float& NewValue)
{
    // This function is meant to be overridden by game-specific subclasses.
}

void UImagineAttributeSet::PostGameplayEffectExecute(const UImagineGameplayEffect* Effect, float ExecutedMagnitude)
{
    // This function is meant to be overridden by game-specific subclasses.
}


UWorld* UImagineAttributeSet::GetWorld() const
{
    if (OwningAbilitySystemComponent)
    {
        return OwningAbilitySystemComponent->GetWorld();
    }
    return nullptr;
}

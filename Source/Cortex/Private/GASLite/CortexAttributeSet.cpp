#include "GASLite/CortexAttributeSet.h"

UCortexAttributeSet::UCortexAttributeSet()
{
}

void UCortexAttributeSet::PreAttributeChange(const FName& AttributeName, float& NewValue)
{
    Super::PreAttributeChange(AttributeName, NewValue);

    // Clamp the new value for certain attributes.
    if (AttributeName == GetHealthAttributeName())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
    else if (AttributeName == GetStaminaAttributeName())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
    }
}

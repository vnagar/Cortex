
#include "GASLite/ImagineAbilitySystemComponent.h"
#include "GASLite/ImagineGameplayAbility.h"
#include "GASLite/ImagineAttributeSet.h"
#include "GASLite/ImagineGameplayEffect.h"

UImagineAbilitySystemComponent::UImagineAbilitySystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Should not need to tick
}

void UImagineAbilitySystemComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UImagineAbilitySystemComponent::GrantAbility(TSubclassOf<UImagineGameplayAbility> AbilityClass)
{
    if (AbilityClass)
    {
        UImagineGameplayAbility* Ability = NewObject<UImagineGameplayAbility>(this, AbilityClass);
        if (Ability)
        {
            Ability->SetOwner(this);
            GrantedAbilities.Add(Ability);
        }
    }
}

void UImagineAbilitySystemComponent::ApplyEffectToSelf(TSubclassOf<UImagineGameplayEffect> EffectClass)
{
    if (!EffectClass)
    {
        return;
    }

    UImagineGameplayEffect* Effect = EffectClass->GetDefaultObject<UImagineGameplayEffect>();
    if (!Effect)
    {
        return;
    }

    for (const FImagineModifierInfo& Mod : Effect->Modifiers)
    {
        float CurrentValue = GetAttributeValue(Mod.AttributeName);
        float NewValue = CurrentValue;

        switch (Mod.Operation)
        {
            case EImagineModOp::Add:
                NewValue += Mod.Magnitude;
                break;
            case EImagineModOp::Multiply:
                NewValue *= Mod.Magnitude;
                break;
            case EImagineModOp::Override:
                NewValue = Mod.Magnitude;
                break;
        }

        SetNumericAttributeBase(Mod.AttributeName, NewValue);

        for (UImagineAttributeSet* Set : AttributeSets)
        {
            Set->PostGameplayEffectExecute(Effect, Mod.Magnitude);
        }
    }
}

void UImagineAbilitySystemComponent::AddAttributeSet(UImagineAttributeSet* InAttributeSet)
{
    if(InAttributeSet)
    {
        AttributeSets.Add(InAttributeSet);
        InAttributeSet->OwningAbilitySystemComponent = this;
    }
}

float UImagineAbilitySystemComponent::GetAttributeValue(FName AttributeName) const
{
    for (const UImagineAttributeSet* Set : AttributeSets)
    {
        if (!Set) continue;

        FProperty* Prop = Set->GetClass()->FindPropertyByName(AttributeName);
        if (FStructProperty* StructProp = CastField<FStructProperty>(Prop))
        {
            if (StructProp->Struct == FImagineAttributeData::StaticStruct())
            {
                const FImagineAttributeData* Data = StructProp->ContainerPtrToValuePtr<FImagineAttributeData>(Set);
                return Data->CurrentValue;
            }
        }
    }
    return 0.f;
}

void UImagineAbilitySystemComponent::SetNumericAttributeBase(FName AttributeName, float NewBaseValue)
{
    for (UImagineAttributeSet* Set : AttributeSets)
    {
        if (!Set) continue;

        FProperty* Prop = Set->GetClass()->FindPropertyByName(AttributeName);
        if (FStructProperty* StructProp = CastField<FStructProperty>(Prop))
        {
            if (StructProp->Struct == FImagineAttributeData::StaticStruct())
            {
                FImagineAttributeData* Data = StructProp->ContainerPtrToValuePtr<FImagineAttributeData>(Set);
                
                float OldValue = Data->CurrentValue;
                float TempNewValue = NewBaseValue; // Use a temporary variable for PreAttributeChange

                Set->PreAttributeChange(AttributeName, TempNewValue);

                Data->SetBaseValue(TempNewValue);
                Data->SetCurrentValue(TempNewValue);
                return; // Found and set, so exit
            }
        }
    }
}

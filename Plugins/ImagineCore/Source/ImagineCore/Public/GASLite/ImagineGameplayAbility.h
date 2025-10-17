
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "ImagineGameplayAbility.generated.h"

class UImagineAbilitySystemComponent;

UCLASS(Blueprintable)
class IMAGINECORE_API UImagineGameplayAbility : public UObject
{
    GENERATED_BODY()

public:
    UImagineGameplayAbility();

    UFUNCTION(BlueprintImplementableEvent, Category = "Imagine|GASLite")
    void OnActivateAbility();

    UFUNCTION(BlueprintCallable, Category = "Imagine|GASLite")
    void ActivateAbility();

    UPROPERTY(EditDefaultsOnly, Category = "Imagine|GASLite")
    FGameplayTagContainer AbilityTags;

    void SetOwner(UImagineAbilitySystemComponent* InOwner);

protected:
    UPROPERTY()
    UImagineAbilitySystemComponent* Owner;
};

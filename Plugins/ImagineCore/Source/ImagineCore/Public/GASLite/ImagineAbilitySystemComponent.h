
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ImagineAbilitySystemComponent.generated.h"

class UImagineGameplayAbility;
class UImagineAttributeSet;
class UImagineGameplayEffect;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IMAGINECORE_API UImagineAbilitySystemComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UImagineAbilitySystemComponent();

    UFUNCTION(BlueprintCallable, Category = "Imagine|GASLite")
    void GrantAbility(TSubclassOf<UImagineGameplayAbility> AbilityClass);

    UFUNCTION(BlueprintCallable, Category = "Imagine|GASLite")
    void ApplyEffectToSelf(TSubclassOf<UImagineGameplayEffect> EffectClass);

    void AddAttributeSet(UImagineAttributeSet* InAttributeSet);

    float GetAttributeValue(FName AttributeName) const;
    void SetNumericAttributeBase(FName AttributeName, float NewBaseValue);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(Transient)
    TArray<UImagineGameplayAbility*> GrantedAbilities;

    UPROPERTY(Transient)
    TArray<UImagineAttributeSet*> AttributeSets;
};

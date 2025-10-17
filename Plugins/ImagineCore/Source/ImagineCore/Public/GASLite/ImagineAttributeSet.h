#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GASLite/ImagineAbilitySystemComponent.h"
#include "ImagineAttributeSet.generated.h"

// Forward declaration
class UImagineGameplayEffect;

USTRUCT(BlueprintType)
struct FImagineAttributeData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	float BaseValue = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	float CurrentValue = 0.f;

	void SetBaseValue(float NewVal) { BaseValue = NewVal; }
	void SetCurrentValue(float NewVal) { CurrentValue = NewVal; }
};

//
// Macro to create the boilerplate functions for an attribute
//
#define GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	static FName Get##PropertyName##AttributeName() \
	{ \
		static FName PropName(TEXT(#PropertyName)); \
		return PropName; \
	}

#define GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	float Get##PropertyName() const \
	{ \
		return PropertyName.CurrentValue; \
	}

#define GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	void Set##PropertyName(float NewVal) \
	{ \
		UImagineAbilitySystemComponent* ASC = OwningAbilitySystemComponent; \
		if (ASC) \
		{ \
			ASC->SetNumericAttributeBase(Get##PropertyName##AttributeName(), NewVal); \
		} \
	}

#define GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \
	void Init##PropertyName(float NewVal) \
	{ \
		PropertyName.SetBaseValue(NewVal); \
		PropertyName.SetCurrentValue(NewVal); \
	}


// Defines a set of helper functions for accessing and initializing attributes
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class IMAGINECORE_API UImagineAttributeSet : public UObject
{
	GENERATED_BODY()

public:
	UImagineAttributeSet();

	virtual void PreAttributeChange(const FName& AttributeName, float& NewValue);
	virtual void PostGameplayEffectExecute(const UImagineGameplayEffect* Effect, float ExecutedMagnitude);

	UWorld* GetWorld() const override;

	UPROPERTY()
	UImagineAbilitySystemComponent* OwningAbilitySystemComponent;
};

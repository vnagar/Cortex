#pragma once

#include "CoreMinimal.h"
#include "GASLite/ImagineAttributeSet.h"
#include "CortexAttributeSet.generated.h"

UCLASS()
class CORTEX_API UCortexAttributeSet : public UImagineAttributeSet
{
	GENERATED_BODY()

public:
	UCortexAttributeSet();

	virtual void PreAttributeChange(const FName& AttributeName, float& NewValue) override;

	// -- Attributes --

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FImagineAttributeData Health;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FImagineAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FImagineAttributeData Stamina;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FImagineAttributeData MaxStamina;

	// -- Accessors --

	ATTRIBUTE_ACCESSORS(UCortexAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCortexAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UCortexAttributeSet, Stamina)
	ATTRIBUTE_ACCESSORS(UCortexAttributeSet, MaxStamina)
};

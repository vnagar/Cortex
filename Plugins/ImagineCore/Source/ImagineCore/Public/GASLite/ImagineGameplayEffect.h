
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ImagineGameplayEffect.generated.h"

UENUM(BlueprintType)
enum class EImagineModOp : uint8
{
    Add,
    Multiply,
    Override
};

USTRUCT(BlueprintType)
struct FImagineModifierInfo
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName AttributeName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EImagineModOp Operation = EImagineModOp::Add;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Magnitude = 0.f;
};

UCLASS(Blueprintable)
class IMAGINECORE_API UImagineGameplayEffect : public UObject
{
    GENERATED_BODY()

public:
    UImagineGameplayEffect();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Imagine|GASLite")
    float Duration;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Imagine|GASLite")
    TArray<FImagineModifierInfo> Modifiers;
};

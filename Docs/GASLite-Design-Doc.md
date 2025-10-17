# GASLite Design Doc

## Overview

GASLite is a lightweight, simplified version of Unreal Engine's Gameplay Ability System (GAS) framework. It is designed to provide a similar API to GAS, but without using any of the Unreal Engine's GAS framework classes (except for gameplay tags). This makes it a good choice for projects that need a flexible and powerful ability system, but don't want to be tied to the full GAS framework.

## Core Components

The GASLite framework is made up of the following core components:

*   **`ImagineAbilitySystemComponent`**: This component is responsible for managing abilities, attributes, and effects. It is the central piece of the GASLite framework.
*   **`ImagineGameplayAbility`**: This is the base class for all abilities in the GASLite framework. It defines the basic structure of an ability, including how it's activated and what it does.
*   **`ImagineAttributeSet`**: This class holds a set of attributes for a character, such as health, stamina, etc. It is a simple container for `FGameplayAttributeData` properties.
*   **`ImagineGameplayEffect`**: This class represents effects that can be applied to an `ImagineAbilitySystemComponent` to modify its attributes.

## Granting vs. Activating Abilities

It is important to understand the difference between granting and activating an ability. `GrantAbility` adds the ability to the `ImagineAbilitySystemComponent`, but it does not execute the ability's logic. `ActivateAbility` is what actually triggers the `OnActivateAbility` event in the `ImagineGameplayAbility` Blueprint.

So, the typical workflow would be:

1.  Call `GrantAbility` to give the ability to the character.
2.  At some later point (e.g., when the player presses a button), call `ActivateAbility` on the ability instance to make it do something.

## Usage

To use the GASLite framework, you will need to do the following:

1.  Add an `ImagineAbilitySystemComponent` to your character's Blueprint.
2.  Create a new Blueprint class that inherits from `ImagineGameplayAbility`.
3.  In the `ImagineGameplayAbility` Blueprint, implement the `OnActivateAbility` event.
4.  In your character's Blueprint, call the `GrantAbility` function on the `ImagineAbilitySystemComponent` to grant the ability to the character.

## Examples

### Example 1: Creating a simple "Jump" ability

1.  Create a new Blueprint class that inherits from `ImagineGameplayAbility` and name it `GA_Jump`.
2.  In the `GA_Jump` Blueprint, implement the `OnActivateAbility` event to call the `Jump` function on the character.
3.  In your character's Blueprint, add an `ImagineAbilitySystemComponent`.
4.  In the character's Blueprint, call the `GrantAbility` function on the `ImagineAbilitySystemComponent` and pass in the `GA_Jump` Blueprint class.

## Scenario: Sprint Ability with Stamina

Here is a scenario that demonstrates how to use the GASLite framework to implement a sprint ability with stamina consumption and regeneration.

**1. Create the Stamina Attribute:**

First, you'll need to create a `Stamina` attribute. You can do this by creating a new C++ class that inherits from `UImagineAttributeSet` and adding a `FGameplayAttributeData` property for stamina.

**`MyAttributeSet.h`**
```cpp
#pragma once

#include "CoreMinimal.h"
#include "GASLite/ImagineAttributeSet.h"
#include "MyAttributeSet.generated.h"

UCLASS()
class IMAGINECORE_API UMyAttributeSet : public UImagineAttributeSet
{
    GENERATED_BODY()

public:
    UMyAttributeSet();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Stamina;
};
```

**2. Create the Sprint Ability:**

Next, you'll create the `Sprint` ability. This will be a C++ class that inherits from `UImagineGameplayAbility`. This ability will have two parts:

*   **`OnActivateAbility`**: This will be called when the player starts sprinting. It will apply a gameplay effect that drains stamina over time.
*   **`OnEndAbility`**: This will be called when the player stops sprinting. It will remove the stamina drain effect and apply a gameplay effect that regenerates stamina over time.

**`GA_Sprint.h`**
```cpp
#pragma once

#include "CoreMinimal.h"
#include "GASLite/ImagineGameplayAbility.h"
#include "GA_Sprint.generated.h"

UCLASS()
class IMAGINECORE_API UGA_Sprint : public UImagineGameplayAbility
{
    GENERATED_BODY()

public:
    UGA_Sprint();

    virtual void OnActivateAbility() override;
    virtual void OnEndAbility();

    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TSubclassOf<class UImagineGameplayEffect> StaminaDrainEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TSubclassOf<class UImagineGameplayEffect> StaminaRegenEffect;
};
```

**`GA_Sprint.cpp`**
```cpp
#include "GA_Sprint.h"
#include "GASLite/ImagineAbilitySystemComponent.h"

UGA_Sprint::UGA_Sprint()
{
}

void UGA_Sprint::OnActivateAbility()
{
    Super::OnActivateAbility();

    if (Owner)
    {
        Owner->ApplyEffectToSelf(StaminaDrainEffect);
    }
}

void UGA_Sprint::OnEndAbility()
{
    Super::OnEndAbility();

    if (Owner)
    {
        Owner->RemoveEffect(StaminaDrainEffect);
        Owner->ApplyEffectToSelf(StaminaRegenEffect);
    }
}
```

**3. Create the Gameplay Effects:**

Now, you'll need to create the two gameplay effects: `StaminaDrainEffect` and `StaminaRegenEffect`. These will be Blueprint classes that inherit from `UImagineGameplayEffect`.

*   **`GE_StaminaDrain`**: This effect will have a negative `Magnitude` and a `Duration` of `-1` (meaning it lasts forever until removed).
*   **`GE_StaminaRegen`**: This effect will have a positive `Magnitude` and a `Duration` of `-1`.

**4. Grant and Activate the Ability:**

Finally, you'll need to grant the `Sprint` ability to the character and activate it when the player presses the sprint button.

*   In your character's C++ class or Blueprint, get the `ImagineAbilitySystemComponent` and call `GrantAbility` with the `GA_Sprint` class.
*   When the player presses the sprint button, call `ActivateAbility` on the `GA_Sprint` ability instance.
*   When the player releases the sprint button, call `EndAbility` on the `GA_Sprint` ability instance.

This is a basic implementation of the sprint ability. You can expand on it by adding more features, such as:

*   Preventing the player from sprinting if they don't have enough stamina.
*   Showing the stamina bar on the UI.
*   Playing animations and sound effects when the player is sprinting.


1.  Create a new C++ class that inherits from `ImagineGameplayAbility` and name it `MyGameplayAbility`.
2.  In the `MyGameplayAbility.h` file, add the following code:

```cpp
#pragma once

#include "CoreMinimal.h"
#include "GASLite/ImagineGameplayAbility.h"
#include "MyGameplayAbility.generated.h"

UCLASS()
class IMAGINECORE_API UMyGameplayAbility : public UImagineGameplayAbility
{
    GENERATED_BODY()

public:
    UMyGameplayAbility();

    virtual void OnActivateAbility() override;
};
```

3.  In the `MyGameplayAbility.cpp` file, add the following code:

```cpp
#include "MyGameplayAbility.h"

UMyGameplayAbility::UMyGameplayAbility()
{
}

void UMyGameplayAbility::OnActivateAbility()
{
    // Your ability logic here
}
```

4.  In your character's Blueprint, call the `GrantAbility` function on the `ImagineAbilitySystemComponent` and pass in the `MyGameplayAbility` C++ class.

1.  Create a new Blueprint class that inherits from `ImagineGameplayEffect` and name it `GE_HealthBuff`.
2.  In the `GE_HealthBuff` Blueprint, set the `Duration` to `10.0` and the `Magnitude` to `25.0`.
3.  Create a new Blueprint class that inherits from `ImagineGameplayAbility` and name it `GA_ApplyHealthBuff`.
4.  In the `GA_ApplyHealthBuff` Blueprint, implement the `OnActivateAbility` event to call the `ApplyEffectToSelf` function on the `ImagineAbilitySystemComponent` and pass in the `GE_HealthBuff` Blueprint class.
5.  In your character's Blueprint, call the `GrantAbility` function on the `ImagineAbilitySystemComponent` to grant the `GA_ApplyHealthBuff` ability to the character.

# Revised Implementation Plan: The "Corrupted Substation" Demo

This document outlines the revised, step-by-step implementation plan for the "Corrupted Substation" proof-of-concept. The plan is structured to build foundational systems first, adhering to the `ImagineCore` philosophy by separating the reusable framework from game-specific code.

---

### **Phase 1: Core Character & Ability Framework**

**Goal:** To establish a playable character with basic movement and the foundational attribute system, adhering to the `ImagineCore` and `GASLite` design.

1.  **`ImagineCore` - GASLite Foundation:**
    *   **What:** Implement the core of the ability system.
    *   **How:** In `ImagineCore`, create the base `UGASLiteComponent` and the `IImagineAbilitySystemInterface`. Define the base `UImagineAttributeSet` where attributes like `Health` will be declared.

2.  **`ImagineCore` - Base Character:**
    *   **What:** Create the base C++ class for all characters in the game.
    *   **How:** Create `AImagineCharacterBase` in `ImagineCore`. It should include a `UGASLiteComponent`.

3.  **`Cortex` - Player Character:**
    *   **What:** Create the game-specific player character.
    *   **How:** In the `Cortex` project, create `ACortexPlayerCharacter` inheriting from `AImagineCharacterBase`. Create a Blueprint version `BP_CortexPlayerCharacter` from this C++ class.

4.  **`Cortex` - Input System & Movement:**
    *   **What:** Implement basic player movement.
    *   **How:** Using Unreal's Enhanced Input system, configure `InputActions` for movement (`IA_Move`, `IA_Look`, `IA_Jump`) and an `InputMappingContext` (`IMC_Default`). In the `ACortexPlayerController`, map these inputs to character movement functions.

**Result of Phase 1:** A playable character that can run and jump in an empty level. The foundational `GASLiteComponent` is attached, but no attributes are actively used yet.

---

### **Phase 2: Foundational Demo Systems**

**Goal:** To implement the interfaces and logic for the demo's core state-switching mechanics (`LowPower`, `Corruption`, `Default`).

5.  **`ImagineCore` - Generic Interfaces:**
    *   **What:** Define the generic interfaces for themes and interactions.
    *   **How:** In `ImagineCore`, create `IImagineThemeManagerInterface.h` and `IImagineInteractableInterface.h`.

6.  **`Cortex` - Hacking Interface:**
    *   **What:** Create the **game-specific** hacking interface.
    *   **How:** In the `Cortex` project source, create `ICortexHackableInterface.h`. This correctly places the specific gameplay feature within the game project, not the engine plugin.

7.  **`Cortex` - Level & State Logic:**
    *   **What:** Block out the level and implement the theme-switching logic.
    *   **How:**
        *   Create the `Substation_POC.umap` with blockout meshes.
        *   Create `UCortexThemeManager` which implements `IImagineThemeManagerInterface`.
        *   Create `BP_InteractiveTerminal`, which now implements `IImagineInteractableInterface` and `ICortexHackableInterface`.
        *   Create `BP_StateTriggerVolume` to switch the theme to `Corruption`.
        *   Configure the GameMode to manage the state flow: `LowPower` -> `Corruption` -> `Default`.

**Result of Phase 2:** A playable but plain level. Interacting with the terminal and entering the trigger volume now correctly drives the theme state machine, verifiable with debug logs.

---

### **Phase 3: The Presentation Layer**

**Goal:** To create the visual and audio assets that provide feedback for the state changes.

8.  **Materials & Shaders:** Create `M_Master_Corruption`, `PP_Global` (for glitching), and connect them to the `MPC_Visuals_Global`. The `UCortexThemeManager` will now update this MPC.
9.  **UI Widgets:** Create `WBP_HUD` and `WBP_TerminalUI`. The HUD's appearance will change based on the active theme.
10. **VFX & SFX:** Create the placeholder `VFX_ScanPulse`, `VFX_CorruptionGrowth`, `VFX_PowerRestored`, and the ambient audio loops for each theme.

**Result of Phase 3:** The demo is now visually and audibly responsive. The world and UI physically change as the player progresses through the sequence.

---

### **Phase 4: Gameplay Systems (GASLite in Practice)**

**Goal:** To implement combat and the scan ability using the GASLite framework.

11. **`Cortex` - GASLite Attributes & Abilities:**
    *   **What:** Configure attributes and create the Scan ability.
    *   **How:**
        *   In the `Cortex` project, create a `UCortexAttributeSet` inheriting from the base, defining `Health`.
        *   Implement the "Pulse Reveal" as a `UGameplayAbility` (`GA_Scan`). Bind it to an input action (`IA_PulseReveal`). When activated, it will trigger the `VFX_ScanPulse` and `SFX_Scan` events.

12. **Enemy & Combat:**
    *   **What:** Create the enemy and the damage system.
    *   **How:**
        *   Create `BP_FeralEnemy` and add a `GASLiteComponent` to it with the `UCortexAttributeSet`.
        *   The player's weapon will no longer deal direct damage. Instead, it will apply a `GameplayEffect` to the target. This `GameplayEffect` will be configured to reduce the `Health` attribute on the target's `GASLiteComponent`.
        *   The enemy's `Health` attribute changing will trigger its death (`VFX_Enemy_DeathDissolve`).

13. **Combat Presentation:** Create the weapon, impact, and death effects (`VFX_MuzzleFlash`, `VFX_Impact_Default`, etc.) and wire them up.

**Result of Phase 4:** The demo now has a simple combat loop and a functional player ability, all driven by the proper GASLite framework.

---

### **Phase 5: Narrative & Polish**

**Goal:** To add the final narrative element and polish the experience.

14. **Memory Fragment:** Implement the `WBP_MemoryFragment` widget, which is displayed by the `BP_InteractiveTerminal` after a successful hack.
15. **Polish Pass:** Refine lighting, audio levels, effect timing, and post-process settings to create a cohesive and impactful experience.

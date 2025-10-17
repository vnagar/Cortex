# Gemini Project Context: Cortex & ImagineCore

This document summarizes the key architectural decisions, conventions, and context for the Cortex project to ensure consistent collaboration.

## 1. Project Overview

- **Project Name:** Cortex
- **Engine:** Unreal Engine
- **Genre:** Story-driven, Sci-Fi Action-Adventure
- **Core Framework:** The project is built upon a reusable, hyper-modular plugin named `ImagineCore`.

## 2. Core Architectural Philosophy (`ImagineCore`)

The framework is built on four pillars that enforce a strict separation of concerns:

1.  **Interface-Driven Design:** Systems do **not** reference each other by their concrete class. All cross-system communication happens through C++ **Interfaces** (e.g., `IImagineQuestInterface`). The only exception is the Event Bus (`UImagineEventSubsystem`), which is a foundational service accessed directly via its concrete class.
2.  **Dependency Injection via Service Locator:** A central `Service Locator` (on the Game Instance) finds and **injects** concrete system implementations into the properties that only hold abstract interfaces. Subsystems are initialized and post-initialized in a controlled order using an `OnPostInitialize` step to manage dependencies.
3.  **Type-Safe, Contract-Based Events:** The event bus is central to the architecture. Events are broadcast using `FGameplayTag` for identification and strongly-typed `struct` payloads (inheriting from `FImagineEventData`) for compile-time safety.
4.  **Separation of Logic and Data:** Systems access data through abstract **"Provider" interfaces** (e.g., `IImagineQuestDataProvider`), not by directly reading `UDataAsset`s.

## 3. Key Conventions & Patterns

### Gameplay Tags

- **Definition Method:** Gameplay Tags are defined in C++ for compile-time safety, not in `.ini` files.
- **Location:**
    - Declarations (`UE_DECLARE_GAMEPLAY_TAG_EXTERN`): `Plugins/ImagineCore/Source/ImagineCore/Public/Core/ImagineGameplayTags.h`
    - Definitions (`UE_DEFINE_GAMEPLAY_TAG`): `Plugins/ImagineCore/Source/ImagineCore/Private/Core/ImagineGameplayTags.cpp`
- **Namespace:** All tags are defined within the `Imagine` C++ namespace.
- **Initialization:** Tags are registered with the engine by calling `Imagine::FGameplayTags::InitializeNativeTags()` in the `ImagineCore` plugin's `StartupModule` function.

### System Interaction Flow

The architecture enforces a strict one-way data flow to decouple gameplay from its presentation:

1.  **Gameplay System:** A core system (e.g., Combat) broadcasts a **state change event** (e.g., `Imagine.State.Combat.DamageDealt`). It has no knowledge of the UI, sound, or effects.
2.  **Presentation Orchestrator:** This is the *only* presentation-layer system that listens for `Imagine.State.*` events.
3.  **Translation:** The orchestrator translates the state change into one or more **presentation events** (e.g., `Imagine.Presentation.UI.ShowHitMarker`, `Imagine.Presentation.Audio.PlayImpactSound`).
4.  **Presentation Systems:** The UI, Audio, and VFX subsystems *only* listen for these `Imagine.Presentation.*` events.

### Directory Structure

Within `Plugins/ImagineCore/Source/ImagineCore/Public/Core` and `Plugins/ImagineCore/Source/ImagineCore/Private/Core`, the following subdirectories are used for organization:

*   **`Interfaces`**: Contains all C++ interface definitions (e.g., `IImagineQuestInterface.h`).
*   **`Events`**: Contains the `UImagineEventSubsystem` and base event data structures (e.g., `ImagineEventData.h`).
*   **`Services`**: Contains the `UImagineServiceLocator`.

### Character State Management

- The `AImagineCharacterBase` class is kept clean of complex conditional logic.
- A `UImagineStateMachineComponent` is attached to the character to manage its state.
- Each state (e.g., `UWalkingState`, `UVaultingState`) is a self-contained `UImagineCharacterState` UObject that handles its own logic, input, and transitions.

## 4. High-Level Implementation Plan

A phased plan exists in `Docs/Implementation-Plan.md`. It prioritizes building foundational systems first (Event Bus, Service Locator), followed by the UI, then Player/Input, then core gameplay and narrative systems.

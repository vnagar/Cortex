# Cortex Game Architecture & Design

## 1. Introduction

This document outlines the comprehensive architecture and design for the Cortex project, a story-driven, Sci-Fi Action-Adventure game built on Unreal Engine. It adheres strictly to the `ImagineCore` framework's principles of modularity, interface-driven design, and event-driven communication, extending these concepts to all major game subsystems. The goal is to create a scalable, maintainable, and robust foundation that supports the game's narrative depth and dynamic gameplay.

## 2. ImagineCore Principles Recap

The Cortex architecture is built upon the following `ImagineCore` pillars:

*   **Interface-Driven Design:** Systems communicate via C++ Interfaces (e.g., `IImagineCombatInterface`), minimizing direct class coupling.
*   **Dependency Injection via Service Locator:** A central `UImagineServiceLocator` (on the Game Instance) manages and injects concrete system implementations.
*   **Type-Safe, Contract-Based Events:** The `UImagineEventSubsystem` facilitates communication using `FGameplayTag` for identification and strongly-typed `FImagineEventData` payloads.
*   **Separation of Logic and Data:** Systems access data through abstract "Provider" interfaces (e.g., `IImagineQuestDataProvider`), not direct asset references.

## 3. Core Subsystems Architecture

Each major game system will be implemented as a distinct subsystem, integrating with `ImagineCore`'s event bus, service locator, and gameplay tag system.

### 3.1. Game State & Progression System (`UImagineGameStateSubsystem`)

*   **Purpose:** Manages the overall persistent state of the game, including mission progress, player choices, world flags, and global game parameters. It acts as the authoritative source for game state.
*   **Core Concepts:**
    *   **State Tags:** Uses `FGameplayTag` to represent various game states (e.g., `Cortex.State.Mission.Phase1.Awakening`, `Cortex.State.World.PowerRestored`, `Cortex.State.Player.InCombat`).
    *   **State Data:** Stores associated data for states (e.g., current mission objective, player location in a mission).
    *   **Mission Graph:** A data-driven structure (e.g., `UDataAsset_MissionGraph`) defining mission dependencies, objectives, and rewards.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Broadcasts `Imagine.System.GameState.Changed` when a significant game state changes. Listens for events from other systems (e.g., `Imagine.Event.Story.ObjectiveUpdated`, `Imagine.Event.Combat.EnemyKilled`) to update its internal state.
    *   **Service Locator:** Accessible via `UImagineServiceLocator` for other systems to query or subscribe to state changes.
    *   **Interfaces:** `IImagineGameStateInterface` for querying and modifying game state.
*   **Interaction:** Informs Quest, UI, AI, and World systems about state changes.
*   **Data-Driven:** `UDataAsset_MissionGraph`, `UDataAsset_WorldStateFlags`.

### 3.2. Quest & Mission System (`UImagineQuestSubsystem`)

*   **Purpose:** Manages the active main and side quests, tracks objectives, handles quest progression, and triggers narrative events.
*   **Core Concepts:**
    *   **Quest Definitions:** `UDataAsset_Quest` defining objectives, rewards, and narrative beats.
    *   **Objective Tracking:** Components attached to relevant actors (e.g., `UQuestObjectiveComponent`) or direct event listeners.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.Event.Env.TerminalInteracted`, `Imagine.Event.Combat.EnemyKilled`, `Imagine.Event.Interaction.ObjectInteracted` etc., to update quest objectives. Broadcasts `Imagine.Event.Story.ObjectiveUpdated`, `Imagine.Event.Story.MissionCompleted`.
    *   **Service Locator:** `UImagineQuestSubsystem` provides `IImagineQuestInterface`.
    *   **Interfaces:** `IImagineQuestInterface` for other systems to interact with quests.
*   **Interaction:** Relies on Game State for overall progression, informs UI for objective display, and Narrative for triggering dialogue.
*   **Data-Driven:** `UDataAsset_Quest`, `UDataAsset_Objective`.

### 3.3. Character System (`UImagineCharacterSubsystem`)

*   **Purpose:** Manages player and NPC character core functionalities, including movement, health, attributes, and state management.
*   **Core Concepts:**
    *   **`AImagineCharacterBase`:** Base class for all characters.
    *   **`UGASLiteComponent`:** Attached to characters for attributes (Health, Stamina) and abilities (Jump, Attack).
    *   **`UImagineStateMachineComponent`:** Manages character states (e.g., `WalkingState`, `VaultingState`, `HackingState`).
    *   **Input Handling:** Uses Unreal's Enhanced Input system, mapped to `Imagine.Input.*` Gameplay Tags (e.g., `Imagine.Input.Move`, `Imagine.Input.Jump`).
*   **Integration with ImagineCore:**
    *   **Event Bus:** `UGASLiteComponent` broadcasts `Imagine.Event.Player.Damaged`, `Imagine.Event.Player.Healed`, `Imagine.Event.Player.AbilityUsed`. `UImagineStateMachineComponent` broadcasts `Cortex.State.Player.InCombat`, `Cortex.State.Suit.StealthActive`.
    *   **Gameplay Tags:** Heavily uses `Cortex.State.Player.*` for character conditions, `Cortex.State.Suit.*` for suit states.
    *   **Interfaces:** `IImagineCharacterInterface` for querying character state, `IImagineAbilitySystemInterface` for interacting with GASLite.
*   **Interaction:** Interacts with Combat (damage application), AI (behavior), UI (health bars), and Visual Coordinator (VFX for abilities).
*   **Data-Driven:** `UDataAsset_CharacterAttributes`, `UDataAsset_CharacterAbilities`.

### 3.4. Combat System (`UImagineCombatSubsystem`)

*   **Purpose:** Handles all combat-related logic, including damage calculation, hit detection, weapon mechanics, and status effects.
*   **Core Concepts:**
    *   **Damage Types:** `FGameplayTag` for different damage types (e.g., `Imagine.Damage.Kinetic`, `Imagine.Damage.Energy`).
    *   **Hit Registration:** Uses Unreal's collision system and custom trace logic.
    *   **`UGASLiteEffect`:** Applied for damage, healing, and status effects.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Broadcasts `Imagine.Event.Combat.DamageDealt`, `Imagine.Event.Combat.EnemyKilled`, `Imagine.Event.Combat.Headshot`. Listens for `Imagine.Event.Player.WeaponFired`, `Imagine.Event.Player.AbilityUsed`.
    *   **Gameplay Tags:** Uses `Imagine.Event.Combat.*` for events and `Cortex.State.Player.InCombat` for state.
    *   **Interfaces:** `IImagineCombatInterface` for applying damage, querying combat state.
*   **Interaction:** Relies on Character System for health/attributes, AI for target selection, and Visual Coordinator for hit VFX/SFX.
*   **Data-Driven:** `UDataAsset_WeaponStats`, `UDataAsset_DamageTypes`.

### 3.5. AI System (`UImagineAISubsystem`)

*   **Purpose:** Manages the behavior, perception, and decision-making of all non-player characters (NPCs) and enemies.
*   **Core Concepts:**
    *   **Behavior Trees:** Primary tool for defining AI logic.
    *   **AI Perception System:** For sensing players, sounds, and other stimuli.
    *   **AI States:** `FGameplayTag` to represent AI states (e.g., `Imagine.AI.State.Patrolling`, `Imagine.AI.State.Attacking`).
    *   **AI Factions:** `FGameplayTag` to define allegiances (e.g., `Cortex.Faction.Echoes`, `Cortex.Faction.Ferals`).
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.Event.Combat.DamageDealt` (to react to being hit), `Imagine.Event.Env.SecurityAlert`. Broadcasts `Imagine.Event.Combat.EnemyDetected`, `Imagine.Event.Combat.EnemySpawned`.
    *   **Gameplay Tags:** Uses `Imagine.Event.Combat.EnemyDetected`, `Cortex.State.Player.Detected`, `Cortex.State.Player.Hidden`.
    *   **Interfaces:** `IImagineAIInterface` for querying AI state, `IImaginePerceptionInterface`.
*   **Interaction:** Interacts with Combat (attacking targets), Character (movement), and World (pathfinding).
*   **Data-Driven:** `UDataAsset_BehaviorTreeConfig`, `UDataAsset_AIPerceptionSettings`.

### 3.6. Interaction System (`UImagineInteractionSubsystem`)

*   **Purpose:** Handles player interaction with world objects, including picking up items, activating terminals, opening doors, and environmental puzzles.
*   **Core Concepts:**
    *   **Interactable Actors:** `IImagineInteractableInterface` implemented by actors that can be interacted with.
    *   **Interaction Types:** `FGameplayTag` for different interaction types (e.g., `Imagine.Interaction.Pickup`, `Imagine.Interaction.Activate`, `Imagine.Interaction.Hack`).
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.Input.Interact`. Broadcasts `Imagine.Event.Env.TerminalInteracted`, `Imagine.Event.Env.DoorOpened`.
    *   **Gameplay Tags:** Uses `Imagine.Event.Env.TerminalInteracted`, `Imagine.Event.Env.DoorOpened`, `Imagine.Event.Env.DoorLocked`.
    *   **Interfaces:** `IImagineInteractionInterface` for player interaction, `IImagineInteractableInterface` for world objects.
*   **Interaction:** Informs Inventory (for pickups), Quest (for objective completion), and UI (for interaction prompts).
*   **Data-Driven:** `UDataAsset_InteractionPrompts`.

### 3.7. Inventory & Loot System (`UImagineInventorySubsystem`)

*   **Purpose:** Manages player inventory, equipment, item properties, and loot generation.
*   **Core Concepts:**
    *   **Item Definitions:** `UDataAsset_Item` defining item type, stats, icon, and usage.
    *   **Inventory Component:** `UInventoryComponent` attached to characters/containers.
    *   **Loot Tables:** Data-driven tables for generating loot from enemies or containers.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.Event.Interaction.PickupItem`, `Imagine.Event.Combat.EnemyKilled` (for loot drop). Broadcasts `Imagine.Event.Inventory.ItemAdded`, `Imagine.Event.Inventory.ItemUsed`.
    *   **Gameplay Tags:** Uses `Imagine.Item.*` for item types, `Imagine.Inventory.*` for events.
    *   **Interfaces:** `IImagineInventoryInterface` for managing inventory, `IImagineLootGeneratorInterface`.
*   **Interaction:** Informs UI (inventory screen), Character (equipment stats), and Combat (weapon usage).
*   **Data-Driven:** `UDataAsset_Item`, `UDataAsset_LootTable`.

### 3.8. Narrative & Dialogue System (`UImagineNarrativeSubsystem`)

*   **Purpose:** Manages dialogue sequences, narrative events, lore delivery, and player choices that impact the story.
*   **Core Concepts:**
    *   **Dialogue Trees:** Data-driven structures for branching conversations.
    *   **Lore Entries:** `UDataAsset_Lore` for collectible lore.
    *   **Memory Fragments:** Specific data assets for story revelations.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.Event.Story.ObjectiveUpdated`, `Imagine.Event.Env.TerminalInteracted`. Broadcasts `Imagine.Event.Story.MemoryFragmentFound`, `Imagine.Event.Story.WardenTransmission`, `Imagine.Event.Story.LegionWhisper`.
    *   **Gameplay Tags:** Uses `Imagine.Event.Story.*` for events.
    *   **Interfaces:** `IImagineNarrativeInterface` for triggering dialogue, `IImagineLoreInterface`.
*   **Interaction:** Informs UI (dialogue display), Game State (player choices), and Visual Coordinator (cinematic triggers).
*   **Data-Driven:** `UDataAsset_Dialogue`, `UDataAsset_Lore`, `UDataAsset_MemoryFragment`.

### 3.9. World & Environment System (`UImagineWorldSubsystem`)

*   **Purpose:** Manages level streaming, environmental hazards, destructible environments, and dynamic world elements.
*   **Core Concepts:**
    *   **Level Streaming Volumes:** For managing loading/unloading of world sections.
    *   **Environmental Actors:** Actors implementing `IImagineEnvironmentalHazardInterface` or `IImagineDestructibleInterface`.
    *   **Dynamic World States:** Responding to `Legion's Growing Influence` as described in `Cortex_Story_Missions.md` (e.g., `Cortex.State.World.Influence.Legion`).
*   **Integration with ImagineCore:**
    *   **Event Bus:** Listens for `Imagine.System.GameState.Changed` (e.g., `Cortex.State.World.Influence.Legion`). Broadcasts `Imagine.Event.Env.Explosion`, `Imagine.Event.Env.SecurityAlert`.
    *   **Gameplay Tags:** Uses `Cortex.State.World.*` for states and `Imagine.Event.Env.*` for events.
    *   **Interfaces:** `IImagineWorldInterface` for querying world state, `IImagineDestructibleInterface`.
*   **Interaction:** Interacts with Visual Coordinator (VFX for destruction), AI (pathfinding around hazards), and Game State (world progression).
*   **Data-Driven:** `UDataAsset_EnvironmentalHazardConfig`, `UDataAsset_DestructibleProperties`.

### 3.10. Save/Load System (`UImagineSaveLoadSubsystem`)

*   **Purpose:** Manages saving and loading the game's state, including player progress, inventory, world state, and character data.
*   **Core Concepts:**
    *   **Save Game Objects:** Custom `USaveGame` classes for different data domains.
    *   **Serialization:** Mechanisms for systems to expose their state for saving.
*   **Integration with ImagineCore:**
    *   **Event Bus:** Broadcasts `Imagine.Event.SaveLoad.GameSaved`, `Imagine.Event.SaveLoad.GameLoaded`.
    *   **Service Locator:** `UImagineSaveLoadSubsystem` provides `IImagineSaveLoadInterface`.
    *   **Interfaces:** `IImagineSaveLoadInterface` for initiating save/load, `IImagineSaveableInterface` for systems/actors to implement to provide their data.
*   **Interaction:** Interacts with almost all other systems to gather/restore their state.
*   **Data-Driven:** Configuration for save slots, auto-save intervals.

## 4. Cross-Cutting Concerns

### 4.1. Visual Coordination (UImagineVisualCoordinatorSubsystem)

As detailed in `Imagine-Visual-Coordinator-System.md`, this subsystem is central to all visual and audio feedback. All gameplay systems will broadcast their state changes and events, and the Visual Coordinator will translate these into `Imagine.Presentation.*` events for the UI, VFX, and Audio subsystems. It will leverage `Imagine.Theme.*` tags for global visual/audio identity changes and `Imagine.UI.*`, `Imagine.VFX.*`, `Imagine.Audio.*` tags for specific presentation events.

### 4.2. Audio System (UImagineAudioSubsystem)

Manages all in-game audio, including SFX, music, and dialogue. It listens for `Imagine.Audio.*` events from the Visual Coordinator and directly from other systems for critical, immediate audio cues. It will utilize `Imagine.Audio.Mix.*` tags for sound mix states.

### 4.3. UI System (UImagineUISubsystem)

Manages all user interface elements, including HUD, menus, inventory, and dialogue displays. It listens for `Imagine.UI.*` events from the Visual Coordinator and directly from systems like Narrative for dialogue. It will manage `Imagine.UI.Layer.*` for widget organization and respond to `Imagine.UI.Show.*`, `Imagine.UI.Hide.*`, `Imagine.UI.Alert.*` events.

### 4.4. Input System

Utilizes Unreal's Enhanced Input system. Input actions are mapped to `Imagine.Input.*` Gameplay Tags (e.g., `Imagine.Input.Move`, `Imagine.Input.Interact`), which are then processed by relevant character components or subsystems.

### 4.5. Error Handling & Logging

A centralized logging system will be implemented, leveraging Unreal's logging categories. Critical errors will trigger specific `Imagine.System.Error` events, which the Visual Coordinator can use to display error messages to the player.

### 4.6. Object Pooling Manager (`UImagineObjectPoolSubsystem`)

To enhance performance and memory efficiency, a centralized object pooling manager will be implemented. This subsystem will manage pools of frequently instantiated actors and components (e.g., projectiles, AI enemies, VFX particles, UI elements, destructible pieces).

*   **Purpose:** Reduce garbage collection overhead and instantiation costs by reusing pre-allocated objects.
*   **Core Concepts:**
    *   **Poolable Interface:** Actors/components implementing `IImaginePoolableInterface` to handle initialization and reset logic when acquired/released from a pool.
    *   **Configurable Pools:** Data-driven configuration for pool sizes, growth strategies, and object types.
*   **Integration with ImagineCore:**
    *   **Service Locator:** Accessible via `UImagineServiceLocator` for any system to request or return pooled objects.
    *   **Interfaces:** `IImagineObjectPoolInterface` for managing pools.
*   **Interaction:** Used by Combat (projectiles), AI (enemies), World (destructibles, environmental effects), and Visual Coordinator (VFX).

## 5. Conclusion

This architecture provides a highly modular, scalable, and maintainable framework for the Cortex project. By strictly adhering to `ImagineCore`'s principles and leveraging an event-driven, data-driven approach, each subsystem can operate independently while contributing to a cohesive and dynamic game experience. This design facilitates parallel development, simplifies debugging, and allows for flexible iteration on gameplay mechanics and narrative elements.

## 6. Gameplay & Design Depth Enhancements (Architectural Scaffolding)

To elevate Cortex to a AAA experience, the following gameplay and design depth enhancements will be supported by dedicated architectural scaffolding from the outset. This ensures that these features are not merely bolted on but are integral to the game's systemic design.

### 6.1. Advanced AI Behaviors

The `UImagineAISubsystem` will be designed with extensibility to support complex, emergent AI behaviors.

*   **Dynamic Group Tactics:**
    *   **Architectural Scaffolding:** The `UImagineAISubsystem` will expose interfaces (`IImagineAITeamInterface`) for AI controllers to query and update team-level objectives and states. Behavior Trees will utilize shared Blackboard keys for squad-level decision-making. `Imagine.AI.Team.*` Gameplay Tags will broadcast group intentions (e.g., `Imagine.AI.Team.Flanking`, `Imagine.AI.Team.Suppression`).
    *   **Integration:** AI controllers will listen for `Imagine.Event.Combat.EnemyDetected` and coordinate responses via the `UImagineAISubsystem`.
*   **Environmental Interaction & Exploitation:**
    *   **Architectural Scaffolding:** The `UImagineAISubsystem` will integrate with the `UImagineWorldSubsystem` via `IImagineWorldQueryInterface` to identify interactive environmental elements (`IImagineDestructibleInterface`, `IImagineEnvironmentalHazardInterface`). Behavior Tree tasks will include nodes for evaluating and interacting with these elements.
    *   **Integration:** AI perception will be enhanced to include environmental cues, allowing AI to dynamically adjust pathfinding and cover usage.
*   **Emergent AI Tactics & Adaptation:**
    *   **Architectural Scaffolding:** A meta-AI component within the `UImagineAISubsystem` will track player combat patterns (e.g., preferred weapon types, movement patterns) by subscribing to `Imagine.Event.Player.*` and `Imagine.Event.Combat.*` tags. This data will inform dynamic adjustments to AI parameters stored in `UDataAsset_AIPerceptionSettings` and `UDataAsset_BehaviorTreeConfig` at runtime.
    *   **Integration:** This system will influence the spawning and loadouts of enemies managed by the `UImagineWorldSubsystem` and `UImagineCombatSubsystem`.

### 6.2. Player Progression & Customization

The `UImagineInventorySubsystem` and `UImagineCharacterSubsystem` will be designed to support deep player customization and progression.

*   **Crafting & Resource Management:**
    *   **Architectural Scaffolding:** The `UImagineInventorySubsystem` will include a `UDataAsset_CraftingRecipe` system, defining inputs and outputs. `IImagineCraftingInterface` will expose crafting functionalities. Resources will be tagged with `Imagine.Item.Resource.*` and managed within the inventory.
    *   **Integration:** The `UImagineInteractionSubsystem` will trigger `Imagine.Event.Interaction.Salvage` events, feeding resources into the inventory. The UI system will provide dedicated crafting interfaces (`Imagine.UI.CraftingMenu`).
*   **Weapon & Suit Modding:**
    *   **Architectural Scaffolding:** `UDataAsset_Item` will be extended to define mod slots and mod properties. `IImagineModdingInterface` on weapons/suit components will allow dynamic application and removal of mods, which will directly influence `UGASLiteComponent` attributes or `UImagineCombatSubsystem` weapon stats.
    *   **Integration:** The `UImagineInventorySubsystem` will manage mod items, and the `UImagineCharacterSubsystem` will apply their effects.
*   **Reputation System (Faction-Based):**
    *   **Architectural Scaffolding:** The `UImagineGameStateSubsystem` will manage `Cortex.Faction.*.Reputation` values, exposed via `IImagineFactionReputationInterface`. Actions impacting reputation will broadcast `Imagine.Event.Faction.ReputationChanged` with relevant data.
    *   **Integration:** The `UImagineAISubsystem` will query faction reputation to adjust AI behavior (e.g., aggression, dialogue options). The `UImagineNarrativeSubsystem` can use reputation to unlock specific dialogue paths or quests.

### 6.3. Dynamic World Systems

The `UImagineWorldSubsystem` will be the central hub for managing and orchestrating dynamic world events and environmental changes.

*   **Emergent Environmental Events:**
    *   **Architectural Scaffolding:** The `UImagineWorldSubsystem` will host a `UDataAsset_WorldEventConfig` defining various dynamic events, their trigger conditions (e.g., time, player proximity, `Cortex.State.World.Influence.Legion` level), and associated effects. Events will broadcast `Imagine.Event.World.DynamicEventTriggered` with contextual data.
    *   **Integration:** The Visual Coordinator will listen for these events to trigger appropriate VFX/SFX. AI will react to these events (e.g., seeking cover during a power surge).
*   **Ecological Feedback Loop (Subtle):
    *   **Architectural Scaffolding:** The `UImagineWorldSubsystem` will track abstract "ecological" states (e.g., `Cortex.State.World.LocalFeralPopulation`, `Cortex.State.World.LocalFloraDensity`) based on player actions or time. These states will be exposed via `IImagineWorldQueryInterface`.
    *   **Integration:** Changes in these states will trigger `Imagine.Event.World.EcologicalStateChanged`, which the Visual Coordinator can use for subtle visual cues (e.g., increased foliage density) or influence resource spawn rates via the `UImagineInventorySubsystem`.
*   **Dynamic Weather System:**
    *   **Architectural Scaffolding:** The `UImagineWorldSubsystem` will manage `Cortex.State.World.Weather.*` tags (e.g., `Cortex.State.World.Weather.Storm`), transitioning between them based on a `UDataAsset_WeatherConfig`. `IImagineWeatherInterface` will provide current weather conditions.
    *   **Integration:** The Visual Coordinator will listen for weather state changes to apply global visual effects (e.g., rain, fog) and audio (e.g., wind, thunder). The `UImagineAISubsystem` will adjust AI perception based on weather conditions (e.g., reduced visibility in fog).

## 7. Conclusion

This architecture provides a highly modular, scalable, and maintainable framework for the Cortex project. By strictly adhering to `ImagineCore`'s principles and leveraging an event-driven, data-driven approach, each subsystem can operate independently while contributing to a cohesive and dynamic game experience. This design facilitates parallel development, simplifies debugging, and allows for flexible iteration on gameplay mechanics and narrative elements.

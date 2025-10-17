Imagine Reactive Visual Coordination Architecture

(Project Context: Oasis / ImagineCore Framework — Updated: includes GameState + Theme Management)

⸻

🧭 Overview

This document describes the reactive visual coordination architecture used in Oasis, built atop the ImagineCore framework.
It unifies Game State, UI, VFX, Audio, and theme systems under a cohesive event-driven design powered by Gameplay Tags.

The system is modular, scalable, and reusable across multiple games and genres — enabling a fully reactive and data-driven audiovisual ecosystem.

Core Design Principles

Principle Description
Event-driven All systems respond to GameplayTag-based events and state changes broadcast through the Imagine Event System.
Separation of concerns
Each subsystem (GameState, UI, VFX, Audio, MPC) has a single, well-defined responsibility.
Data-driven
Behavior is defined through Data Assets (Themes, Event Maps, Widget Configs), not hardcoded logic.
Reactive architecture
Widgets, materials, and VFX respond dynamically to gameplay and theme/state changes.
Extensibility
Base framework classes live in ImagineCore; game-specific subclasses (Oasis) extend them.

High-Level System Overview
+--------------------------+
| ImagineEventSubsystem    |
|  - Broadcasts events     |
|  - Manages data payloads |
+-----------+--------------+
            |
            ▼
+------------------------------+          +----------------------+
| ImagineVisualCoordinator     |◀────────▶| ImagineGameStateSubsy |
|  - Central event router      |          |                      |
|  - Routes tags to subsystems |          | - Manages persistent |
|  - Handles filtering/logic   |          |   game state tags    |
+------+------+----------------+          +----------------------+
       |      |       |
       ▼      ▼       ▼
+------+  +------+  +------+
| UI   |  | VFX  |  | Audio|
| Sub  |  | Sub  |  | Sub  |
+------+  +------+  +------+
   |          |         |
   ▼          ▼         ▼
Widgets    Niagara   SoundMixes
+ MPC + CommonUI  Systems   Effects

Subsystem Responsibilities (Expanded)

1. UImagineEventSubsystem

Purpose: Core communication hub using gameplay tags and data payloads.
	•	Broadcasts events (OnEventBroadcasted) with a flexible UImagineEventData payload.
	•	Payloads can contain: instigator, targets, hit locations, sound/VFX overrides, etc.
	•	Used by all systems for decoupled communication.

    Example Usage:
    EventSubsystem->BroadcastEvent(TAG_Event_ScanInitiated, EventData);

2. UImagineGameStateSubsystem

Purpose: Centralized storage and management of persistent game state as gameplay tags and state data. This differs from ephemeral events.

Responsibilities
	•	Holds authoritative state tags (e.g., State.Theme.LowPower, State.Scan.Active, State.Player.InCombat).
	•	Exposes API to Set, Clear, Query, and Subscribe to state tag changes.
	•	Manages state precedence, stacking, and expiration rules (e.g., push/pop state stack).
	•	Optionally persists or replicates state in multiplayer builds (if needed later).

Semantics & Example
	•	State tags are persistent (until cleared) — e.g., State.Theme.LowPower stays active until State.Theme.Default or ClearStateTag(Theme.LowPower) occurs.
	•	Events are one-shot transient notifications (e.g., Event.Combat.Hit).
	•	Systems such as UISubsystem subscribe to state tags to auto-show/hide widgets or switch themes.

3. UImagineVisualCoordinatorSubsystemBase

Purpose: The central “brain” that interprets events and state changes and orchestrates reactions across subsystems.

Responsibilities
	•	Listens to UImagineEventSubsystem events and UImagineGameStateSubsystem state changes (subscribe).
	•	Applies routing rules (via an EventMap or modular UImagineVisualEventHandlers) to determine which subsystems should respond and how.
	•	Translates high-level game intent into multiple subsystem actions:
	•	UI show/hide
	•	MPC updates
	•	VFX spawn requests
	•	Audio play / mix changes
	•	Game state mutation (if necessary)

Example Flow
PlayerHealthLow (event/state)
 → VisualCoordinator:
    - Set State: State.Player.LowHealth
    - Call UISubsystem: ApplyTheme(LowHealth)
    - Trigger VFX: spawn heartbeat pulse at player
    - Trigger Audio: play heartbeat sound and low-pass mix

4. UImagineUISubsystem

Purpose: Manages UI stacks, theme application (both CommonUI and MPC-driven), and broadcasts theme/state changes to widgets.

Responsibilities
	•	Registers CommonUI stacks (HUD, GameMenu, Modal, Toast) and pushes/pops widgets.
	•	Has ThemeMap: FGameplayTag -> UImagineThemeData mapping.
	•	ApplyTheme responsibilities:
	•	Load theme asset (data-driven)
	•	Call UImagineMPCSubsystem::ApplyTheme() (update MPCs)
	•	Call UImagineAudioSubsystem::ApplyTheme() (optional)
	•	Apply CommonUI styles (text/button) to registered style managers
	•	Broadcast OnThemeChanged to all subscribed widgets
	•	Play transition effects (via UImagineVisualEffectBase)

Integration with GameState
	•	Subscribes to relevant state tags (via UImagineGameStateSubsystem) to auto-apply themes when state changes (e.g., when State.Theme.LowPower is set).
	•	Supports tag-to-widget mapping so widgets auto-show/hide based on state tags.

5. UImagineVFXSubsystem

Purpose: Spawns and manages Niagara systems for gameplay visuals.
	•	Listens for VFX-related gameplay tags and spawn requests from the VisualCoordinator.
	•	Maintains a tag→NiagaraSystem registry (data-driven).
	•	Spawns Niagara effects with payloads (location, scale, instigator, overrides).
	•	Optionally reads MPC values for material-driven particle visuals.

6. UImagineAudioSubsystem

Purpose: Central control for sound playback and soundscape adjustments.
	•	Maintains tag→Sound mapping.
	•	Plays 2D/3D sounds with context from payload (location, instigator).
	•	Applies SoundMix/Submix changes for theme transitions (e.g., LowPower low-pass).
	•	Supports push/pop stack semantics for soundmixes tied to state tags.

7. UImagineMPCSubsystem

Purpose: Manages global Material Parameter Collections (MPCs) to ensure UI, VFX, and world materials are synchronized.
	•	Holds references to relevant Material Parameter Collections.
	•	Exposes set/get scalar and vector operations in a safe way:
	•	SetScalarParameter(CollectionName, ParamName, Value, BlendDuration=0.0f)
	•	SetVectorParameter(...)
	•	Supports blending (lerp) over Duration for smooth theme transitions.

8. UImagineThemeData (Data Asset)

Purpose: Centralized theme definition combining visual and audio style, MPC parameter values, CommonUI style references, and transition metadata.

Example Fields
	•	FName ThemeName
	•	FImagineThemeStyleSet StyleSet (CommonTextStyle, CommonButtonStyle, PrimaryColor, AccentColor)
	•	TSoftObjectPtr<UMaterialParameterCollection> MPC_Global
	•	TArray<FImagineMPCParameter> (CollectionName, ParamName, Scalar/Vector value)
	•	FImagineThemeTransition TransitionEffect (EffectClass, Duration, Intensity)
	•	FImagineThemeAudioSettings AudioSettings (SoundMix, ActivationCue, LowPassFrequency)

9. UImagineVisualEventHandler

Purpose: Encapsulated logic to handle specific events or state changes (modular, testable).
	•	Implementations receive (EventTag, EventData, Coordinator) and perform complex routing (spawn multiple VFX, send multiple UI tags, set multiple states).
	•	Avoids big switch/if chains in the VisualCoordinator.


10. UImagineWidgetBase, UImagineScreenWidget, UImagineWorldWidget

Purpose: The widget hierarchy that subscribes to UI events and theme changes.
	•	UImagineScreenWidget (CommonUI-based) for screen-space HUD widgets; handles activation, deactivation, theme callback OnThemeChanged.
	•	UImagineWorldWidget for diegetic world-space widgets (uses UWidgetComponent attachment patterns); framework-level hooks (OnAttachedToActor / OnDetachedFromActor) to be overridden by project classes.

Widgets respond to:
	•	OnThemeChanged (apply CommonUI styles or adjust material-driven visuals)
	•	OnVisualEffectTriggered (animations/effects triggered by tags)
	•	OnStateChanged (optional; specific state tag subscription)


Theme Management — Detailed

Theme management coordinates persistent state, visual changes, blending, and transitions.

Key Concepts
	•	Theme Activation vs Event
	•	State-driven: A theme is activated via a state tag (State.Theme.X) — persistent until changed.
	•	Event-driven: Visual transitions can be kicked by events (one-shot), but theme persistence is via GameState.
	•	Theme Registry
	•	UImagineUISubsystem keeps a TMap<FGameplayTag, TSoftObjectPtr<UImagineThemeData>> ThemeMap.
	•	UImagineGameStateSubsystem may also track active theme tag as a canonical source for other systems.
	•	ApplyTheme Flow
	1.	UISubsystem receives theme request (from VisualCoordinator or GameState change).
	2.	Load target UImagineThemeData.
	3.	Save PreviousTheme = ActiveTheme, set ActiveTheme = NewTheme.
	4.	If transition specified:
	•	Initiate MPCSubsystem blends: for each MPC parameter, lerp from current to new over Duration.
	•	Spawn UImagineVisualEffectBase (if EffectClass specified) to handle screen-wide transitions (fade/pulse).
	5.	Apply CommonUI style overrides:
	•	Update CommonTextStyle, CommonButtonStyle where applicable (via style manager or direct widget calls).
	6.	Broadcast OnThemeChanged with (OldTheme, NewTheme, TransitionInfo).
	7.	Optionally call AudioSubsystem->ApplyTheme() (push SoundMix/preset).
	8.	Persist theme state via UImagineGameStateSubsystem.SetStateTag(ThemeTag) (so other systems know the active theme).
	•	Blending & Priority
	•	Themes may have priority. For example, Theme.Combat may override Theme.Default, but Theme.Cinematic may have highest priority.
	•	Use a theme stack (push/pop) or priority values to handle layered themes:
	•	PushTheme(ThemeTag, Priority) → becomes Active if highest priority
	•	PopTheme(ThemeTag) → re-evaluate top priority theme
	•	Blending between themes uses Transition.Duration and Easing curves specified in FImagineThemeTransition.
	•	Reverting / Stacking
	•	UI subsystem should support RevertToPreviousTheme() and ResetTheme() APIs.
	•	When complex states occur (e.g., LowPower + Cinematic), stacking rules decide which theme wins or how to blend.

⸻

🎬 Example Flows

A — LowPower Theme Activation (persistent)
	1.	Game detects low helmet power -> GameStateSubsystem.SetStateTag("State.Theme.LowPower", data)
	2.	VisualCoordinator sees the state change and calls UISubsystem.ApplyTheme(Theme.LowPower)
	3.	UISubsystem:
	•	Loads DA_Theme_LowPower
	•	Calls MPCSubsystem.ApplyTheme(DA_Theme_LowPower) (blends MPCs over Duration)
	•	Calls AudioSubsystem.ApplyTheme(DA_Theme_LowPower) (push SoundMix)
	•	Broadcasts OnThemeChanged(Old, New)
	4.	Widgets update on receiving OnThemeChanged.
	5.	When power returns:
	•	Clear state tag or push Theme.Default -> theme reverts via same flow.

B — Combat Hit (event)
	1.	EventSubsystem broadcasts Event.Combat.Hit with payload including HitLocation.
	2.	VisualCoordinator routes:
	•	VFXSubsystem.SpawnEffect("VFX.Hit.Impact", HitLocation)
	•	AudioSubsystem.PlaySound("SFX.Impact", HitLocation)
	•	UISubsystem.HandleUIEventTag("UI.Damage.Flash", payload) -> widget flash
	3.	No persistent theme change occurs (transient reaction only).

Architectural Summary (Updated)

    Layer
Component
Purpose
Framework
ImagineCore
Base reactive subsystems and data assets
Project
Oasis
Game-specific materials, themes, VFX, and audio assets
Runtime
VisualCoordinator
Event routing brain
State
GameStateSubsystem
Persistent state tags, theme activation, stacking
UI Layer
UISubsystem + Widgets
Manages CommonUI stacks and reactive visuals
Rendering
MPCSubsystem
Centralized material parameter control
Feedback
Audio/VFX Subsystems
Handles sensory output of events
Theme
ThemeData Assets
Defines style identity and transitions

## Future Enhancements

To further refine and optimize the Imagine Reactive Visual Coordination Architecture, the following enhancements are proposed:

*   **Event Prioritization and Filtering:** Implement a robust priority system for visual events, allowing critical feedback to override or suppress less important visuals. Introduce filtering capabilities based on game state, player settings, or distance to the player to intelligently manage visual clutter.
*   **Optimized Asset Management (Pooling & Asynchronous Loading):** Implement object pooling for frequently used visual effects (Niagara systems) and UI widgets to reduce instantiation overhead. Ensure that all visual assets (textures, particle systems, sounds) are loaded asynchronously to prevent hitches during event execution.
*   **Enhanced Contextual Data Utilization:** While event payloads provide context, further emphasize and provide patterns for `UImagineVisualEventHandler` implementations to intelligently utilize this data (e.g., hit location, damage type, source actor) for more dynamic and precise visual responses.
*   **Comprehensive Debugging and Validation Tools:** Develop in-editor and in-game debugging overlays to visualize active visual events, their delays, durations, and associated data. Implement automated validation checks for data assets (e.g., `UImagineThemeData`, event maps) to identify missing references or misconfigurations early in development.
*   **Streamlined `UImagineVisualEvent` Definition:** Explore methods to define simpler visual events directly within data assets (e.g., using generic event structs or scriptable objects) to reduce the need for creating new C++ classes for every minor visual variation. This would promote faster iteration and reduce C++ class bloat.
*   **Leveraging Native Unreal Systems:** Continuously ensure that `UImagineVisualEventHandler` implementations fully leverage and integrate with Unreal Engine's native systems like Niagara for VFX and CommonUI/UMG for UI, rather than reimplementing core functionalities.


Key Conventions & Best Practices:
	•	Use Gameplay Tags for all cross-system signalling.
	•	State vs Event: Use GameStateSubsystem for persistent state-tags; use EventSubsystem for ephemeral one-shot events.
	•	Single Source for Theme Activation: UISubsystem remains authoritative for applying themes (it calls MPCSubsystem and AudioSubsystem).
	•	VisualCoordinator routes intent — not implementation details. It should not set MPC values directly.
	•	Data-Driven: All tag→asset mappings, widget configs, and event maps should be data assets to avoid code churn.
	•	No hardcoded parameter names: Theme assets should map CollectionName + ParameterName; subsystems take parameter identifiers from ThemeData—do not hardcode string literals across modules.
	•	Subsystem Decoupling: Keep ImagineCore subsystems agnostic of project-specific assets. Projects (Oasis) provide subclasses/assets.

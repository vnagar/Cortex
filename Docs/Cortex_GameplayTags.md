## Root Categories: Prefixes are "Imagine." and "Cortex."
State.
Event.
Theme.
UI.
VFX.
Audio.
System.
Ability.
Attribute.
Effect.

## Input Tags (Direct mapping from Enhanced Input Actions)
Imagine.Input.Move
Imagine.Input.Look
Imagine.Input.Jump
Imagine.Input.Crouch
Imagine.Input.Sprint
Imagine.Input.Interact
Imagine.Input.PrimaryAttack
Imagine.Input.SecondaryAttack (or Aim)
Imagine.Input.Reload
Imagine.Input.SwitchWeapon
Imagine.Input.UseAbility.1
Imagine.Input.UseAbility.2
Imagine.Input.UI.PauseMenu
Imagine.Input.UI.Inventory

## State Tags (Persistent World & Gameplay Conditions):
### Power / Suit State
Imagine.State.Power.Low
Imagine.State.Power.Critical
Imagine.State.Power.Restored
Cortex.State.Suit.Operational
Cortex.State.Suit.Overheat
Cortex.State.Suit.Damaged
Cortex.State.Suit.StealthActive
Cortex.State.Suit.ScanActive

### Player Conditions
Cortex.State.Player.InCombat
Cortex.State.Player.Hidden
Cortex.State.Player.Detected
Cortex.State.Player.LowHealth
Cortex.State.Player.CriticalHealth
Cortex.State.Player.Infected
Cortex.State.Player.Stable
Cortex.State.Player.DialogueActive

### Environment/World
Cortex.State.World.Surface
Cortex.State.World.Underground
Cortex.State.World.SectorZero
Cortex.State.World.Influence.Legion
Cortex.State.World.Influence.Warden
Cortex.State.World.Weather.Storm
Cortex.State.World.Weather.Clear
Cortex.State.World.Weather.Rain
Cortex.State.World.Weather.Fog
Cortex.State.World.LocalFeralPopulation.High
Cortex.State.World.LocalFeralPopulation.Low
Cortex.State.World.LocalFloraDensity.High
Cortex.State.World.LocalFloraDensity.Low

### Story/Mission Progression
Cortex.State.Mission.Phase1.Awakening
Cortex.State.Mission.Phase2.Surface
Cortex.State.Mission.Phase3.Monolith
Cortex.State.Mission.Phase4.Core
Cortex.State.Mission.Objective.Active
Cortex.State.Mission.Objective.Completed
Cortex.State.Mission.Objective.Failed

### AI States
Imagine.AI.State.Patrolling
Imagine.AI.State.Attacking
Imagine.AI.State.Searching
Imagine.AI.State.Alerted
Imagine.AI.State.Team.Flanking
Imagine.AI.State.Team.Suppression

### Faction States
Cortex.Faction.Echoes.Reputation.Hostile
Cortex.Faction.Echoes.Reputation.Neutral
Cortex.Faction.Ferals.Reputation.Hostile
Cortex.Faction.Ferals.Reputation.Neutral

### Item/Inventory States
Imagine.Item.Equipped
Imagine.Item.InInventory
Imagine.Item.Modded

### Character States (Generic)
Imagine.Character.State.Movement.Idle
Imagine.Character.State.Movement.Walking
Imagine.Character.State.Movement.Sprinting
Imagine.Character.State.Movement.Crouching
Imagine.Character.State.Movement.Jumping
Imagine.Character.State.Movement.Falling
Imagine.Character.State.Combat.Aiming
Imagine.Character.State.Combat.Reloading
Imagine.Character.State.Dead
Imagine.Character.State.Stunned
Imagine.Character.State.Rooted
Imagine.Character.State.Invulnerable


### Quest States (Generic)
Imagine.Quest.State.Active
Imagine.Quest.State.Completed
Imagine.Quest.State.Failed
Imagine.Quest.State.Available
Imagine.Quest.State.Unavailable

### Theme (Persistent Visual/Audio Identity)
Imagine.Theme.Default
Imagine.Theme.LowPower
Imagine.Theme.Combat
Imagine.Theme.Stealth
Imagine.Theme.Corruption
Imagine.Theme.LegionControl
Imagine.Theme.Cinematic
Imagine.Theme.MemoryFlashback
Imagine.Theme.SystemOverride


## Event Tags (Transient, Broadcast Gameplay Events)

### Player Events
Imagine.Event.Player.Spawned
Imagine.Event.Player.Damaged
Imagine.Event.Player.Healed
Imagine.Event.Player.Death
Imagine.Event.Player.LowHealthWarning
Imagine.Event.Player.Reload
Imagine.Event.Player.WeaponFired
Imagine.Event.Player.AbilityUsed

### Suit/System Events
Imagine.Event.Suit.Boot
Imagine.Event.Suit.CalibrationStart
Imagine.Event.Suit.CalibrationComplete
Imagine.Event.Suit.ScanInitiated
Imagine.Event.Suit.ScanComplete
Imagine.Event.Suit.ScanFailed
Imagine.Event.Suit.HackInitiated
Imagine.Event.Suit.HackComplete

### Environment Events
Imagine.Event.Env.PowerRestored
Imagine.Event.Env.LockdownTriggered
Imagine.Event.Env.SecurityAlert
Imagine.Event.Env.TerminalInteracted
Imagine.Event.Env.DoorOpened
Imagine.Event.Env.DoorLocked
Imagine.Event.Env.Explosion

### Combat Events
Imagine.Event.Combat.WeaponFired
Imagine.Event.Combat.ProjectileHit
Imagine.Event.Combat.EnemyKilled
Imagine.Event.Combat.EnemyDetected
Imagine.Event.Combat.EnemySpawned
Imagine.Event.Combat.Headshot
Imagine.Event.Combat.ComboAchieved
Imagine.Event.Combat.PulseBlast
Imagine.Event.Combat.MeleeStrike
Imagine.Event.Combat.Weapon.Reloaded
Imagine.Event.Combat.Weapon.Overheated
Imagine.Event.Combat.Target.WeakPointHit

### Story/Narrative Events
Imagine.Event.Story.MemoryFragmentFound
Imagine.Event.Story.WardenTransmission
Imagine.Event.Story.LegionWhisper
Imagine.Event.Story.ObjectiveUpdated
Imagine.Event.Story.MissionStarted
Imagine.Event.Story.MissionCompleted
Imagine.Event.Narrative.DialogueStarted
Imagine.Event.Narrative.DialogueEnded
Imagine.Event.Narrative.LoreDiscovered

### Interaction Events
Imagine.Event.Interaction.ObjectInteracted
Imagine.Event.Interaction.PickupItem
Imagine.Event.Interaction.Salvage
Imagine.Event.Interaction.Hack

### Inventory Events
Imagine.Event.Inventory.ItemAdded
Imagine.Event.Inventory.ItemRemoved
Imagine.Event.Inventory.ItemUsed
Imagine.Event.Inventory.ItemEquipped
Imagine.Event.Inventory.ItemUnequipped
Imagine.Event.Inventory.ModApplied
Imagine.Event.Inventory.ModRemoved
Imagine.Event.Inventory.CraftingComplete
Imagine.Event.Inventory.LootDropped
Imagine.Event.Inventory.LootCollected

### Faction Events
Imagine.Event.Faction.ReputationChanged

### World Events
Imagine.Event.World.DynamicEventTriggered
Imagine.Event.World.EcologicalStateChanged
Imagine.Event.World.LocationEntered
Imagine.Event.World.LocationExited
Imagine.Event.World.EnvironmentalHazardTriggered
Imagine.Event.World.DynamicEventStarted
Imagine.Event.World.DynamicEventEnded

### Scene Director Events
Imagine.Event.Scene.SceneStarted
Imagine.Event.Scene.SceneEnded
Imagine.Event.Scene.EventTriggered
Imagine.Event.Scene.Skipped

### Visual/Reactive Events
Imagine.Event.Visual.HUDDistortion
Imagine.Event.Visual.GlitchPulse
Imagine.Event.Visual.CorruptionSpread
Imagine.Event.Visual.ScreenFade
Imagine.Event.Visual.HologramMaterialize
Imagine.Event.Visual.HologramDissolve
Imagine.Event.Visual.AlertFlash
Imagine.Event.Visual.LowPowerBlink
Imagine.Event.Visual.ThemeTransition

### AI Events (Generic)
Imagine.Event.AI.TargetSighted
Imagine.Event.AI.TargetLost
Imagine.Event.AI.BehaviorChanged
Imagine.Event.AI.PerceptionUpdated

### Save/Load Events (Generic)
Imagine.Event.SaveLoad.GameSaved
Imagine.Event.SaveLoad.GameLoaded
Imagine.Event.SaveLoad.AutoSaveTriggered

## Theme Tags (Visual + Audio Identity States)
These map directly to UImagineThemeData assets.

Imagine.Theme.Default
Imagine.Theme.LowPower
Imagine.Theme.Combat
Imagine.Theme.Stealth
Imagine.Theme.Corruption
Imagine.Theme.Legion
Imagine.Theme.Cinematic
Imagine.Theme.MemoryFlashback
Imagine.Theme.SystemOverride

Each theme may modify:
	•	MPC parameters (color tint, distortion, emission)
	•	CommonUI styles (font, brightness)
	•	Audio mixes (lowpass, reverb)
	•	Transition effects (Niagara pulses, fade overlays)

## UI Tags
### Widget Layers
Imagine.UI.Layer.Root
Imagine.UI.Layer.HUD
Imagine.UI.Layer.GameMenu
Imagine.UI.Layer.Modal
Imagine.UI.Layer.Toast
Imagine.UI.Layer.Dialogue

### Widget Events
Imagine.UI.Show.HUD
Imagine.UI.Hide.HUD
Imagine.UI.Alert.LowHealth
Imagine.UI.Alert.CriticalHealth
Imagine.UI.Alert.ScanInitiated
Imagine.UI.Alert.ScanComplete
Imagine.UI.Alert.EnemyDetected
Imagine.UI.Alert.MemoryFragmentFound
Imagine.UI.Combat.DamageFlash
Imagine.UI.Combat.TargetHit
Imagine.UI.Combat.EnemyKilled
Imagine.UI.Combat.WeaponOverheat
Imagine.UI.Cinematic.TransitionIn
Imagine.UI.Cinematic.TransitionOut
Imagine.UI.Show.CraftingMenu
Imagine.UI.Hide.CraftingMenu
Imagine.UI.Show.ModdingMenu
Imagine.UI.Hide.ModdingMenu
Imagine.UI.Show.SkillTree
Imagine.UI.Hide.SkillTree
Imagine.UI.Show.Map
Imagine.UI.Hide.Map
Imagine.UI.Show.Inventory
Imagine.UI.Hide.Inventory
Imagine.UI.Alert.ResourceLow
Imagine.UI.Alert.NewObjective
Imagine.UI.Alert.NewLore
Imagine.UI.Alert.NewQuest
Imagine.UI.Alert.QuestUpdated
Imagine.UI.Alert.QuestCompleted
Imagine.UI.Alert.QuestFailed
Imagine.UI.Prompt.Interaction
Imagine.UI.Prompt.DialogueChoice
Imagine.UI.Prompt.Tutorial

### Widget States
Imagine.UI.State.Visible
Imagine.UI.State.Hidden
Imagine.UI.State.Disabled
Imagine.UI.State.Animating
Imagine.UI.State.ThemeApplied

## VFX Tags
### Environmental
Imagine.VFX.Scan.Pulse
Imagine.VFX.Scan.Ring
Imagine.VFX.Power.Restore
Imagine.VFX.Power.Low
Imagine.VFX.Hologram.Spawn
Imagine.VFX.Hologram.Dissolve
Imagine.VFX.Corruption.Growth
Imagine.VFX.Corruption.Fade
Imagine.VFX.Environment.Sparks
Imagine.VFX.Environment.EnergySurge
Imagine.VFX.World.PowerSurge
Imagine.VFX.World.AtmosphericDistortion
Imagine.VFX.World.StructuralCollapse
Imagine.VFX.Weather.Rain
Imagine.VFX.Weather.Fog

### Combat
Imagine.VFX.Weapon.MuzzleFlash
Imagine.VFX.Weapon.Impact
Imagine.VFX.Weapon.HitScanTrail
Imagine.VFX.Enemy.Explosion
Imagine.VFX.Enemy.DeathDissolve
Imagine.VFX.Player.DamageFlash
Imagine.VFX.Player.LowHealthPulse
Imagine.VFX.Character.Stunned
Imagine.VFX.Character.Healed
Imagine.VFX.Character.Buffed
Imagine.VFX.Character.Debuffed

## Damage Tags
### Damage Types
Imagine.Damage.Type.Kinetic
Imagine.Damage.Type.Energy
Imagine.Damage.Type.Explosive
Cortex.Damage.Type.Corruption
Cortex.Damage.Type.EMP

### Damage Resistances / Vulnerabilities
Imagine.Damage.Resistance.Kinetic
Imagine.Damage.Vulnerability.Energy

### Thematic
Imagine.VFX.ThemeTransition.DefaultToLowPower
Imagine.VFX.ThemeTransition.LowPowerToCombat
Imagine.VFX.ThemeTransition.Corruption

### Crafting/Modding
Imagine.VFX.Crafting.Success
Imagine.VFX.Crafting.Failure
Imagine.VFX.Modding.Applied

### Interaction
Imagine.VFX.Interaction.HackSuccess
Imagine.VFX.Interaction.HackFail
Imagine.VFX.Interaction.Pickup

## Audio Tags
### Sound Events
Imagine.Audio.Suit.Boot
Imagine.Audio.Suit.Scan
Imagine.Audio.Suit.Error
Imagine.Audio.Suit.PowerLow
Imagine.Audio.Suit.PowerRestored
Imagine.Audio.Combat.WeaponFire
Imagine.Audio.Combat.Reload
Imagine.Audio.Combat.EnemyHit
Imagine.Audio.Combat.EnemyDeath
Imagine.Audio.Combat.LowHealthHeartbeat
Imagine.Audio.Ambient.City
Imagine.Audio.Ambient.Underground
Imagine.Audio.Ambient.SectorZero
Imagine.Audio.Theme.Default
Imagine.Audio.Theme.LowPower
Imagine.Audio.Theme.Combat
Imagine.Audio.Theme.Corruption
Imagine.Audio.World.PowerSurge
Imagine.Audio.World.AtmosphericDistortion
Imagine.Audio.World.StructuralCollapse
Imagine.Audio.Weather.Rain
Imagine.Audio.Weather.Wind
Imagine.Audio.Weather.Thunder
Imagine.Audio.Crafting.Success
Imagine.Audio.Crafting.Failure
Imagine.Audio.Modding.Applied
Imagine.Audio.Scene.CinematicStart
Imagine.Audio.Scene.CinematicEnd
Imagine.Audio.Character.Stunned
Imagine.Audio.Character.Healed
Imagine.Audio.Character.Buffed
Imagine.Audio.Character.Debuffed
Imagine.Audio.Interaction.HackSuccess
Imagine.Audio.Interaction.HackFail
Imagine.Audio.Interaction.Pickup
Imagine.Audio.UI.NewQuest
Imagine.Audio.UI.QuestComplete
Imagine.Audio.UI.Alert

### SoundMix States
Imagine.Audio.Mix.Default
Imagine.Audio.Mix.LowPower
Imagine.Audio.Mix.Combat
Imagine.Audio.Mix.Corruption
Imagine.Audio.Mix.Cinematic

## System Tags (Coordinator, Framework, Debug)
Imagine.System.VisualCoordinator.EventRouting
Imagine.System.VisualCoordinator.StateUpdate
Imagine.System.GameState.Changed
Imagine.System.Theme.Applied
Imagine.System.Theme.TransitionStart
Imagine.System.Theme.TransitionComplete
Imagine.System.Debug.Enable
Imagine.System.Debug.Disable
Imagine.System.Pool.ObjectAcquired
Imagine.System.Pool.ObjectReleased
Imagine.System.Pool.PoolCreated
Imagine.System.Pool.PoolDestroyed

## Item Tags
### Item Types
Imagine.Item.Type.Weapon
Imagine.Item.Type.Consumable
Imagine.Item.Type.Resource
Imagine.Item.Type.Mod
Imagine.Item.Type.KeyItem

### Specific Item Categories
Imagine.Item.Weapon.Type.Pistol
Imagine.Item.Weapon.Type.Rifle
Imagine.Item.Weapon.Type.Melee
Imagine.Item.Consumable.Type.HealthPack
Imagine.Item.Resource.Type.ScrapMetal
Imagine.Item.Resource.Type.EnergyCell

## Interaction Tags
### Interaction Types
Imagine.Interaction.Type.Examine
Imagine.Interaction.Type.Activate
Imagine.Interaction.Type.Open
Imagine.Interaction.Type.Close
Imagine.Interaction.Type.Hack
Imagine.Interaction.Type.Pickup
Imagine.Interaction.Type.Talk

### Interaction States
Imagine.Interaction.State.Locked
Imagine.Interaction.State.Unlocked
Imagine.Interaction.State.Active
Imagine.Interaction.State.Inactive
Imagine.Interaction.State.Broken

## World Object Tags
### Object Types
Cortex.World.Object.Type.Terminal
Cortex.World.Object.Type.Door
Cortex.World.Object.Type.Container
Cortex.World.Object.Type.CraftingStation
Cortex.World.Object.Type.PowerConduit
Cortex.World.Object.Type.DestructibleCover
Cortex.World.Object.Type.MemoryFragment

### Specific Object Categories
Cortex.World.Object.Terminal.Type.DataLog
Cortex.World.Object.Terminal.Type.ControlPanel
Cortex.World.Object.Door.Type.BlastDoor
Cortex.World.Object.Container.Type.LootCrate

## Ability Tags
### Ability Types
Imagine.Ability.Type.Active
Imagine.Ability.Type.Passive
Imagine.Ability.Type.Movement
Imagine.Ability.Type.Combat
Imagine.Ability.Type.Utility

### Ability States
Imagine.Ability.State.Active
Imagine.Ability.State.Cooldown
Imagine.Ability.State.Blocked

### Ability Costs
Imagine.Ability.Cost.Energy
Imagine.Ability.Cost.Stamina
Imagine.Ability.Cost.Ammo

### Cortex-Specific Abilities
Cortex.Ability.Infiltrator.ActiveCamouflage
Cortex.Ability.Infiltrator.EnhancedPulse
Cortex.Ability.Engineer.ConvertEcho
Cortex.Ability.Engineer.DisableRobotics
Cortex.Ability.Operator.MeleeFinisher
Cortex.Ability.Operator.EnergyBlast

## Attribute Tags
Imagine.Attribute.Health
Imagine.Attribute.MaxHealth
Imagine.Attribute.Energy
Imagine.Attribute.MaxEnergy
Imagine.Attribute.Stamina
Imagine.Attribute.MaxStamina
Imagine.Attribute.Damage
Imagine.Attribute.Armor
Imagine.Attribute.MovementSpeed
Imagine.Attribute.ScanRange
Imagine.Attribute.HackSpeed

## Effect Tags
### Effect Types
Imagine.Effect.Type.Buff
Imagine.Effect.Type.Debuff
Imagine.Effect.Type.DamageOverTime
Imagine.Effect.Type.HealOverTime
Imagine.Effect.Type.InstantDamage
Imagine.Effect.Type.InstantHeal

### Effect States
Imagine.Effect.State.Active
Imagine.Effect.State.Expired
Imagine.Effect.State.Stackable
Imagine.Effect.State.Unique

## Example Gameplay Flow with Tags
### Scenario: Low Power Mode Activation
Step Tag Description System
1 Imagine.Event.Suit.PowerLow Broadcast by ImagineEventSubsystem Event
2 VisualCoordinator receives event, sets state Imagine.Theme.LowPower GameState
3 UISubsystem.ApplyTheme(Imagine.Theme.LowPower) UI switches to low power visuals UI
4 MPCSubsystem applies dimmed emission, distortion Visual VFX
5 AudioSubsystem pushes Imagine.Audio.Mix.LowPower Audio Audio

### Scenario: Player Crafts an Item
Step Tag Description System
1 Imagine.Event.Inventory.CraftingComplete Broadcast by Inventory Subsystem Event
2 VisualCoordinator receives event Imagine.VFX.Crafting.Success Visual 
3 VisualCoordinator receives event Imagine.Audio.Crafting.Success Audio
4 UISubsystem updates inventory display Imagine.UI.Alert.NewItem UI


## Suggested Tag Group for Editor Organization
Category EditorTagRoot Description
State State.* Persistent global states
Event Event.* Transient game events
Theme Theme.* Theme data and transitions
UI UI.* Widget visibility, layers, alerts
VFX VFX.* Visual and particle effects
Audio Audio.* Sound effects and soundmixes
System System.* Coordinator, debug, and framework
Ability Ability.* Ability types, states, costs
Attribute Attribute.* Character attributes and stats
Effect Effect.* Effect types and states
Item Item.* Item types and properties
Interaction Interaction.* Interaction types and states
World Object World.Object.* Types and categories of world objects


Suggestions:
Add FGameplayTagContainer fields to:
	•	UImagineVisualCoordinatorSubsystem
	•	UImagineThemeData
	•	UImagineEventData
	•	UImagineWidgetConfig
for flexible event-driven filtering.

Create mappings:
•	Tag → UImagineThemeData (for Theme.*)
•	Tag → NiagaraSystem (for VFX.*)
•	Tag → USoundBase (for Audio.*)
•	Tag → WidgetConfig (for UI.*)


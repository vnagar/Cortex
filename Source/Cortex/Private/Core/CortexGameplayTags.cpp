
#include "Core/CortexGameplayTags.h"

namespace Cortex
{
	// --- Input Action Tags ---
	UE_DEFINE_GAMEPLAY_TAG(Input_SwitchCameraMode, "Cortex.Input.SwitchCameraMode");
	UE_DEFINE_GAMEPLAY_TAG(Input_Debug, "Cortex.Input.Debug");

	/*
	// State Tags (Persistent World & Gameplay Conditions):
	// Power / Suit State
	Cortex.State.Power.Low
	Cortex.State.Power.Critical
	Cortex.State.Power.Restored
	Cortex.State.Suit.Operational
	Cortex.State.Suit.Overheat
	Cortex.State.Suit.Damaged
	Cortex.State.Suit.StealthActive
	Cortex.State.Suit.ScanActive

	// Player Conditions
	Cortex.State.Player.InCombat
	Cortex.State.Player.Hidden
	Cortex.State.Player.Detected
	Cortex.State.Player.LowHealth
	Cortex.State.Player.CriticalHealth
	Cortex.State.Player.Infected
	Cortex.State.Player.Stable
	Cortex.State.Player.DialogueActive

	// Environment/World
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

	// Story/Mission Progression
	Cortex.State.Mission.Phase1.Awakening
	Cortex.State.Mission.Phase2.Surface
	Cortex.State.Mission.Phase3.Monolith
	Cortex.State.Mission.Phase4.Core
	Cortex.State.Mission.Objective.Active
	Cortex.State.Mission.Objective.Completed
	Cortex.State.Mission.Objective.Failed

	// Theme (Persistent Visual/Audio Identity)
	Cortex.Theme.Default
	Cortex.Theme.LowPower
	Cortex.Theme.Combat
	Cortex.Theme.Stealth
	Cortex.Theme.Corruption
	Cortex.Theme.LegionControl
	Cortex.Theme.Cinematic
	Cortex.Theme.MemoryFlashback
	Cortex.Theme.SystemOverride

	// Faction States
	Cortex.Faction.Echoes.Reputation.Hostile
	Cortex.Faction.Echoes.Reputation.Neutral
	Cortex.Faction.Ferals.Reputation.Hostile
	Cortex.Faction.Ferals.Reputation.Neutral

	// Suit/System Events
	Imagine.Event.Suit.Boot
	Imagine.Event.Suit.CalibrationStart
	Imagine.Event.Suit.CalibrationComplete
	Imagine.Event.Suit.ScanInitiated
	Imagine.Event.Suit.ScanComplete
	Imagine.Event.Suit.ScanFailed
	Imagine.Event.Suit.HackInitiated
	Imagine.Event.Suit.HackComplete

	// Environment Events
	Cortex.Event.Env.PowerRestored
	Cortex.Event.Env.LockdownTriggered
	Cortex.Event.Env.SecurityAlert
	Cortex.Event.Env.TerminalInteracted
	Cortex.Event.Env.DoorOpened
	Cortex.Event.Env.DoorLocked
	Cortex.Event.Env.Explosion

	// Story/Narrative Events
	Cortex.Event.Story.MemoryFragmentFound
	Cortex.Event.Story.WardenTransmission
	Cortex.Event.Story.LegionWhisper
	Cortex.Event.Story.ObjectiveUpdated
	Cortex.Event.Story.MissionStarted
	Cortex.Event.Story.MissionCompleted
	Cortex.Event.Narrative.DialogueStarted
	Cortex.Event.Narrative.DialogueEnded
	Cortex.Event.Narrative.LoreDiscovered

	// Interaction events
	Cortex.Event.Interaction.Salvage
	Cortex.Event.Interaction.Hack

	// Faction Events
	Cortex.Event.Faction.ReputationChanged

	// World Events
	Cortex.Event.World.EcologicalStateChanged
	Cortex.Event.World.EnvironmentalHazardTriggered

	// Visual/Reactive Events
	Cortex.Event.Visual.HUDDistortion
	Cortex.Event.Visual.GlitchPulse
	Cortex.Event.Visual.CorruptionSpread
	Cortex.Event.Visual.ScreenFade
	Cortex.Event.Visual.HologramMaterialize
	Cortex.Event.Visual.HologramDissolve
	Cortex.Event.Visual.AlertFlash
	Cortex.Event.Visual.LowPowerBlink

	//Theme Tags (Visual + Audio Identity States)
	Cortex.Theme.Default
	Cortex.Theme.LowPower
	Cortex.Theme.Combat
	Cortex.Theme.Stealth
	Cortex.Theme.Corruption
	Cortex.Theme.Legion
	Cortex.Theme.Cinematic
	Cortex.Theme.MemoryFlashback
	Cortex.Theme.SystemOverride

	// Widget events
	Cortex.UI.Alert.ScanInitiated
	Cortex.UI.Alert.ScanComplete
	Cortex.UI.Alert.MemoryFragmentFound

	// Damage Type
	Cortex.Damage.Type.Corruption
	Cortex.Damage.Type.EMP
	
	// VFX Tags
	// Environmental
	Cortex.VFX.Scan.Pulse
	Cortex.VFX.Scan.Ring
	Cortex.VFX.Power.Restore
	Cortex.VFX.Power.Low
	Cortex.VFX.Hologram.Spawn
	Cortex.VFX.Hologram.Dissolve
	Cortex.VFX.Corruption.Growth
	Cortex.VFX.Corruption.Fade
	Cortex.VFX.Environment.Sparks
	Cortex.VFX.Environment.EnergySurge
	Cortex.VFX.World.PowerSurge
	Cortex.VFX.World.AtmosphericDistortion
	Cortex.VFX.World.StructuralCollapse
	Cortex.VFX.Weather.Rain
	Cortex.VFX.Weather.Fog
	// Thematic
	Cortex.VFX.ThemeTransition.DefaultToLowPower
	Cortex.VFX.ThemeTransition.LowPowerToCombat
	Cortex.VFX.ThemeTransition.Corruption
	// Interaction VFX
	Cortex.VFX.Interaction.HackSuccess
	Cortex.VFX.Interaction.HackFail

	// Audio Tags
	// Sound Events
	Cortex.Audio.Suit.Boot
	Cortex.Audio.Suit.Scan
	Cortex.Audio.Suit.Error
	Cortex.Audio.Suit.PowerLow
	Cortex.Audio.Suit.PowerRestored
	Cortex.Audio.Combat.LowHealthHeartbeat
	Cortex.Audio.Theme.Default
	Cortex.Audio.Theme.LowPower
	Cortex.Audio.Theme.Combat
	Cortex.Audio.Theme.Corruption
	Cortex.Audio.World.PowerSurge
	Cortex.Audio.World.AtmosphericDistortion
	Cortex.Audio.World.StructuralCollapse
	Cortex.Audio.Weather.Rain
	Cortex.Audio.Weather.Wind
	Cortex.Audio.Weather.Thunder
	Cortex.Audio.Modding.Applied
	Cortex.Audio.Interaction.HackSuccess
	Cortex.Audio.Interaction.HackFail

	// SoundMix States
	Cortex.Audio.Mix.Default
	Cortex.Audio.Mix.LowPower
	Cortex.Audio.Mix.Combat
	Cortex.Audio.Mix.Corruption
	Cortex.Audio.Mix.Cinematic

	// Specific Item Categories
	Cortex.Item.Weapon.Type.Pistol
	Cortex.Item.Weapon.Type.Rifle
	Cortex.Item.Weapon.Type.Melee
	Cortex.Item.Consumable.Type.HealthPack
	Cortex.Item.Resource.Type.ScrapMetal
	Cortex.Item.Resource.Type.EnergyCell

	// World Object Tags
	// Object Types
	Cortex.World.Object.Type.Terminal
	Cortex.World.Object.Type.Door
	Cortex.World.Object.Type.Container
	Cortex.World.Object.Type.CraftingStation
	Cortex.World.Object.Type.PowerConduit
	Cortex.World.Object.Type.DestructibleCover
	Cortex.World.Object.Type.MemoryFragment

	// Specific Object Categories
	Cortex.World.Object.Terminal.Type.DataLog
	Cortex.World.Object.Terminal.Type.ControlPanel
	Cortex.World.Object.Door.Type.BlastDoor
	Cortex.World.Object.Container.Type.LootCrate

	// Cortex-Specific Abilities
	Cortex.Ability.Infiltrator.ActiveCamouflage
	Cortex.Ability.Infiltrator.EnhancedPulse
	Cortex.Ability.Engineer.ConvertEcho
	Cortex.Ability.Engineer.DisableRobotics
	Cortex.Ability.Operator.MeleeFinisher
	Cortex.Ability.Operator.EnergyBlast

	// Attribute Tags
	Cortex.Attribute.Health
	Cortex.Attribute.MaxHealth
	Cortex.Attribute.Energy
	Cortex.Attribute.MaxEnergy
	Cortex.Attribute.Stamina
	Cortex.Attribute.MaxStamina
	Cortex.Attribute.Damage
	Cortex.Attribute.Armor
	Cortex.Attribute.MovementSpeed
	Cortex.Attribute.ScanRange
	Cortex.Attribute.HackSpeed
	
	*/
}

void Cortex::FGameplayTags::InitializeNativeTags()
{
}

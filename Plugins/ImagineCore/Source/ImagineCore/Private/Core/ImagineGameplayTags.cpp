
#include "Core/ImagineGameplayTags.h"

namespace Imagine
{
	// --- Input Action Tags ---
	UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Imagine.Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Imagine.Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(Input_Jump, "Imagine.Input.Jump");
	UE_DEFINE_GAMEPLAY_TAG(Input_Crouch, "Imagine.Input.Crouch");
	UE_DEFINE_GAMEPLAY_TAG(Input_Sprint, "Imagine.Input.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(Input_Interact, "Imagine.Input.Interact");
	UE_DEFINE_GAMEPLAY_TAG(Input_PrimaryAttack, "Imagine.Input.PrimaryAttack");
	UE_DEFINE_GAMEPLAY_TAG(Input_Aim, "Imagine.Input.Aim");
	UE_DEFINE_GAMEPLAY_TAG(Input_Reload, "Imagine.Input.Reload");
	UE_DEFINE_GAMEPLAY_TAG(Input_SwitchWeapon, "Imagine.Input.SwitchWeapon");
	UE_DEFINE_GAMEPLAY_TAG(Input_UseAbility_1, "Imagine.Input.UseAbility.1");
	UE_DEFINE_GAMEPLAY_TAG(Input_UseAbility_2, "Imagine.Input.UseAbility.2");
	UE_DEFINE_GAMEPLAY_TAG(Input_UI_PauseMenu, "Imagine.Input.UI.PauseMenu");
	UE_DEFINE_GAMEPLAY_TAG(Input_UI_Inventory, "Imagine.Input.UI.Inventory");

	/*
	// AI States
	Imagine.AI.State.Patrolling
	Imagine.AI.State.Attacking
	Imagine.AI.State.Searching
	Imagine.AI.State.Alerted
	Imagine.AI.State.Team.Flanking
	Imagine.AI.State.Team.Suppression

	// Item/Inventory States
	Imagine.Item.Equipped
	Imagine.Item.InInventory
	Imagine.Item.Modded

	// Character States (Generic)
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

	// Quest States (Generic)
	Imagine.Quest.State.Active
	Imagine.Quest.State.Completed
	Imagine.Quest.State.Failed
	Imagine.Quest.State.Available
	Imagine.Quest.State.Unavailable

	// Event Tags (Transient, Broadcast Gameplay Events)

	// Player Events
	Imagine.Event.Player.Spawned
	Imagine.Event.Player.Damaged
	Imagine.Event.Player.Healed
	Imagine.Event.Player.Death
	Imagine.Event.Player.LowHealthWarning
	Imagine.Event.Player.Reload
	Imagine.Event.Player.WeaponFired
	Imagine.Event.Player.AbilityUsed

	// Combat Events
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

	// Interaction Events
	Imagine.Event.Interaction.ObjectInteracted
	Imagine.Event.Interaction.PickupItem

	// Inventory Events
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

	// World Events
	Imagine.Event.World.DynamicEventTriggered
	Imagine.Event.World.LocationEntered
	Imagine.Event.World.LocationExited
	Imagine.Event.World.DynamicEventStarted
	Imagine.Event.World.DynamicEventEnded

	// Scene Director Events
	Imagine.Event.Scene.SceneStarted
	Imagine.Event.Scene.SceneEnded
	Imagine.Event.Scene.EventTriggered
	Imagine.Event.Scene.Skipped

	// Visual/Reactive events
	Imagine.Event.Visual.ThemeTransition

	// AI Events (Generic)
	Imagine.Event.AI.TargetSighted
	Imagine.Event.AI.TargetLost
	Imagine.Event.AI.BehaviorChanged
	Imagine.Event.AI.PerceptionUpdated

	// Save/Load Events (Generic)
	Imagine.Event.SaveLoad.GameSaved
	Imagine.Event.SaveLoad.GameLoaded
	Imagine.Event.SaveLoad.AutoSaveTriggered

	// UI Tags
	// Widget Layers
	Imagine.UI.Layer.Root
	Imagine.UI.Layer.HUD
	Imagine.UI.Layer.GameMenu
	Imagine.UI.Layer.Modal
	Imagine.UI.Layer.Toast
	Imagine.UI.Layer.Dialogue

	// Widget Events
	Imagine.UI.Show.HUD
	Imagine.UI.Hide.HUD
	Imagine.UI.Alert.LowHealth
	Imagine.UI.Alert.CriticalHealth
	Imagine.UI.Alert.EnemyDetected
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

	// Widget States
	Imagine.UI.State.Visible
	Imagine.UI.State.Hidden
	Imagine.UI.State.Disabled
	Imagine.UI.State.Animating
	Imagine.UI.State.ThemeApplied

	// Combat
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
	// Crafting/Modding
	Imagine.VFX.Crafting.Success
	Imagine.VFX.Crafting.Failure
	Imagine.VFX.Modding.Applied
	// Interaction
	Imagine.VFX.Interaction.Pickup

	// Damage Tags
	// Damage Types
	Imagine.Damage.Type.Kinetic
	Imagine.Damage.Type.Energy
	Imagine.Damage.Type.Explosive
	// Damage Resistances / Vulnerabilities
	Imagine.Damage.Resistance.Kinetic
	Imagine.Damage.Vulnerability.Energy

	// Audio Tags
	// Sound Events
	Imagine.Audio.Combat.WeaponFire
	Imagine.Audio.Combat.Reload
	Imagine.Audio.Combat.EnemyHit
	Imagine.Audio.Combat.EnemyDeath
	Imagine.Audio.Combat.LowHealthHeartbeat
	Imagine.Audio.Crafting.Success
	Imagine.Audio.Crafting.Failure
	Imagine.Audio.Modding.Applied
	Imagine.Audio.Scene.CinematicStart
	Imagine.Audio.Scene.CinematicEnd
	Imagine.Audio.Character.Stunned
	Imagine.Audio.Character.Healed
	Imagine.Audio.Character.Buffed
	Imagine.Audio.Character.Debuffed
	Imagine.Audio.Interaction.Pickup
	Imagine.Audio.UI.NewQuest
	Imagine.Audio.UI.QuestComplete
	Imagine.Audio.UI.Alert

	// System Tags (Coordinator, Framework, Debug)
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

	// Item Tags
	// Item Types
	Imagine.Item.Type.Weapon
	Imagine.Item.Type.Consumable
	Imagine.Item.Type.Resource
	Imagine.Item.Type.Mod
	Imagine.Item.Type.KeyItem

	// Interaction Tags
	// Interaction Types
	Imagine.Interaction.Type.Examine
	Imagine.Interaction.Type.Activate
	Imagine.Interaction.Type.Open
	Imagine.Interaction.Type.Close
	Imagine.Interaction.Type.Hack
	Imagine.Interaction.Type.Pickup
	Imagine.Interaction.Type.Talk

	// Interaction States
	Imagine.Interaction.State.Locked
	Imagine.Interaction.State.Unlocked
	Imagine.Interaction.State.Active
	Imagine.Interaction.State.Inactive
	Imagine.Interaction.State.Broken

	// Ability Types
	Imagine.Ability.Type.Active
	Imagine.Ability.Type.Passive
	Imagine.Ability.Type.Movement
	Imagine.Ability.Type.Combat
	Imagine.Ability.Type.Utility

	// Ability States
	Imagine.Ability.State.Active
	Imagine.Ability.State.Cooldown
	Imagine.Ability.State.Blocked

	// Ability Costs
	Imagine.Ability.Cost.Energy
	Imagine.Ability.Cost.Stamina
	Imagine.Ability.Cost.Ammo

	// Effect Types
	Imagine.Effect.Type.Buff
	Imagine.Effect.Type.Debuff
	Imagine.Effect.Type.DamageOverTime
	Imagine.Effect.Type.HealOverTime
	Imagine.Effect.Type.InstantDamage
	Imagine.Effect.Type.InstantHeal

	// Effect States
	Imagine.Effect.State.Active
	Imagine.Effect.State.Expired
	Imagine.Effect.State.Stackable
	Imagine.Effect.State.Unique
*/

}

void Imagine::FGameplayTags::InitializeNativeTags()
{
}

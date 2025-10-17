# Cortex: Visual & Audio Design Specification

This document outlines the key visual and audio assets required to build the world of Cortex, based on the game's architecture and gameplay tag dictionary. The aesthetic is a blend of clean, futuristic sci-fi and a glitchy, decaying "Corruption" theme, all orchestrated by the `ImagineCore`'s theme system.

---

### 1. UI Widgets (UMG)

The UI will be diegetic or semi-diegetic, appearing as part of the player's suit HUD. It needs to be highly responsive to the `Imagine.Theme.*` and `Imagine.UI.Alert.*` tags.

*   **Main HUD (WBP_HUD):**
    *   **Player Vitals:** Health, Energy, and Stamina bars. These should glitch and change color based on `Imagine.State.Power.Low` and `Cortex.State.Player.Infected`.
    *   **Weapon Display:** Ammo count, weapon icon, and a visual indicator for `Imagine.Weapon.State.Overheated`.
    *   **Crosshair:** A dynamic crosshair that changes based on weapon, target, and `Imagine.Character.State.Combat.Aiming`.
    *   **Status Indicators:** Icons for `Cortex.State.Suit.StealthActive`, `Cortex.State.Player.InCombat`, and active buffs/debuffs.
    *   **Objective Tracker:** A clean display for the current mission objective, driven by `Imagine.Event.Story.ObjectiveUpdated`.

*   **Interaction & Alerts:**
    *   **Interaction Prompts (WBP_InteractionPrompt):** A widget that appears over world objects, showing the interaction type (e.g., "[E] Hack," "[F] Open").
    *   **Toast/Alerts (WBP_ToastNotification):** A generic pop-up for alerts like `Imagine.UI.Alert.NewLore`, `Imagine.UI.Alert.NewQuest`, and `Imagine.UI.Alert.ResourceLow`.
    *   **Damage Indicator (WBP_DamageIndicator):** Directional flashes on screen when the player is hit.

*   **Full-Screen Menus:**
    *   **Inventory & Crafting (WBP_InventoryMenu):** A grid-based inventory, character equipment view, and a dedicated tab for crafting that uses `UDataAsset_CraftingRecipe`.
    *   **Map (WBP_MapScreen):** A 2D or 3D map of the current level.
    *   **Terminals & Hacking (WBP_TerminalUI):** A dedicated interface for interacting with terminals, displaying lore, and hosting the hacking minigame.
    *   **Dialogue & Narrative (WBP_DialogueSystem):** A system to display branching dialogue choices and Warden/Legion transmissions.

---

### 2. Visual Effects (VFX - Niagara)

VFX are critical for selling the sci-fi action and the core themes of the game. They will be triggered by the `Imagine.VFX.*` tags.

*   **Combat VFX:**
    *   **Weapon Effects:** Unique muzzle flashes, projectile trails (for energy weapons), and hit-scan tracers for all firearms.
    *   **Impact Effects:** A robust library of impact effects for different surface types (metal, concrete, glass, flesh, corrupted surfaces). These must be differentiated based on `Imagine.Damage.Type.*`.
    *   **Explosions:** Grenade explosions, environmental explosions (`Imagine.Event.Env.Explosion`).
    *   **Enemy Effects:** A "dissolve" or "de-rez" effect for enemy deaths (`Imagine.VFX.Enemy.DeathDissolve`), and unique VFX for enemy abilities.

*   **Player & Suit VFX:**
    *   **Scanning:** A world-space pulse or wave effect for the `Imagine.VFX.Scan.Pulse`.
    *   **Stealth:** An effect for entering/leaving stealth (`Cortex.State.Suit.StealthActive`), likely involving a refractive fresnel effect.
    *   **Hacking:** A stream of data or energy from the player to the hacked object.
    *   **Status Effects:** Visuals for being stunned, buffed, or debuffed (`Imagine.VFX.Character.*`).

*   **Thematic & Environmental VFX:**
    *   **Corruption:** This is a key visual pillar. A "creeping" growth effect (`Imagine.VFX.Corruption.Growth`), corrupted energy VFX, and particles in the air in Legion-influenced zones.
    *   **Low Power:** Screen-space glitching, flickering lights, and electrical sparks (`Imagine.Event.Visual.GlitchPulse`).
    *   **Holograms:** A materialization/dissolve effect for holographic displays and characters (`Imagine.VFX.Hologram.Spawn`).
    *   **Weather:** GPU-based particle systems for rain and dense, volumetric fog.

---

### 3. Sound Effects (SFX)

Audio provides crucial feedback and enhances the atmosphere. Sounds will be triggered by the `Imagine.Audio.*` tags.

*   **Combat SFX:**
    *   **Weapons:** Distinctive firing sounds for kinetic vs. energy weapons, mechanical reload sounds, and satisfying "thump" sounds for impacts. A sharp "crack" for headshots.
    *   **Enemies:** Unique vocalizations for different enemy types (e.g., robotic whirs for Echoes, guttural sounds for Ferals), and death sounds that match the VFX.

*   **Player & Suit SFX:**
    *   **Suit Voice:** A subtle, calm AI voice for suit events (`Imagine.Audio.Suit.Boot`, `Imagine.Audio.Suit.Scan`, `Imagine.Audio.Suit.Error`).
    *   **Movement:** Footsteps that change based on surface type, cloth movement, and servo sounds for sprinting/jumping.
    *   **Vitals:** A low, rhythmic heartbeat when health is critical (`Imagine.Audio.Combat.LowHealthHeartbeat`).

*   **UI & Interaction SFX:**
    *   Clean, futuristic "beeps" and "clicks" for UI navigation.
    *   Distinct sounds for hacking success and failure.
    *   A satisfying sound for completing an objective or discovering lore.

*   **Ambiance & Music:**
    *   **Ambient Loops:** Background audio for different environments (e.g., the hum of a city, the drip of water in the underground).
    *   **Dynamic Music:** The music system should react to `Imagine.Theme.*` tags, shifting from ambient exploration tracks to high-energy combat music, or tense, atmospheric stealth music.

---

### 4. Materials & Shaders

Procedural and parameter-driven materials are essential for achieving the dynamic visual themes.

*   **Master Hologram Material:** The existing `M_Master_Hologram_UI` and `M_Master_Hologram_VFX` are a great start. This will be a core material, used for UI elements, world-space markers, and narrative devices like "Memory Fragments." It should have parameters for glitching, color, and intensity.
*   **Master Corruption Material:** A complex, procedural material that can "grow" over surfaces. This could use vertex animation or world-position-offset to create a creeping, pulsating effect. It should be controllable via Material Parameter Collections (MPCs).
*   **Dynamic Screen-Space Shaders:** Post-process materials for full-screen effects like the `LowPower` glitch, `Corruption` vignettes, and distortion during high-energy events.
*   **Shield/Forcefield Material:** A refractive, energy-based material for player and enemy shields.
*   **Dissolve/De-rez Shader:** A versatile material function that can be used on enemies, holograms, and other objects to make them dissolve or fade out, driven by a dynamic mask.

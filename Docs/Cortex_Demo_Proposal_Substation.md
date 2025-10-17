# Proposal: The "Corrupted Substation" Demo Slice

This document outlines a proposal for a small, self-contained vertical slice to serve as a proof-of-concept for the game *Cortex*. This slice is designed to be both visually impressive and a robust technical test of the game's core architectural pillars.

### High-Level Goal

To demonstrate the dynamic interplay between the player's actions and the game's core presentation themes (`LowPower`, `Corruption`, `Default`), while testing the `ImagineCore` event-driven architecture.

### The Scene

A single, detailed room: a derelict power substation. It's dark, with a large, central power conduit that is visibly overgrown with a pulsating, glitchy "Corruption." There is one main control terminal at the far end of the room.

### Player Objective

The player must navigate the dark substation, purge the corruption by hacking the main terminal, and restore power.

---

### Proposed Demo Flow & Showcase Moments

Here is a step-by-step breakdown of the player experience, highlighting what each step demonstrates:

**1. Entry: The `LowPower` Theme**
*   **Player Action:** The player enters the dark, sparking substation.
*   **What it Showcases:**
    *   **Theme System:** The `Imagine.Theme.LowPower` is active.
    *   **UI:** The HUD is minimal and glitches periodically (`Imagine.Event.Visual.GlitchPulse`).
    *   **VFX:** Environmental sparks, minimal emergency lighting.
    *   **Audio:** An oppressive, quiet ambient track with electrical hums and crackles (`Imagine.Audio.Mix.LowPower`).

**2. Exploration: The `Scan` Mechanic**
*   **Player Action:** The player uses the "Pulse Reveal" ability to navigate.
*   **What it Showcases:**
    *   **Core Gameplay:** The player uses a key exploration tool.
    *   **VFX:** A world-space `Imagine.VFX.Scan.Pulse` emanates from the player, briefly highlighting interactive objects (the terminal) and environmental details with a holographic effect.
    *   **Audio:** A satisfying `Imagine.Audio.Suit.Scan` sound effect.

**3. The `Corruption` Theme**
*   **Player Action:** The player approaches the central conduit.
*   **What it Showcases:**
    *   **Dynamic Thematic Shift:** The system smoothly transitions to the `Imagine.Theme.Corruption`.
    *   **Materials:** The "Master Corruption Material" visibly creeps and pulsates on the conduit and nearby surfaces.
    *   **VFX:** Corrupted particle effects fill the air.
    *   **UI:** The HUD becomes more distorted and tinged with the corruption's color.
    *   **Audio:** The audio mix shifts to something more tense and unsettling (`Imagine.Audio.Mix.Corruption`).

**4. Combat Encounter**
*   **Player Action:** A single, simple "Feral" enemy, formed from the corruption, emerges and attacks. The player engages in a brief fight.
*   **What it Showcases:**
    *   **Basic Combat Loop:** Demonstrates weapon firing, SFX, and VFX.
    *   **Impact VFX:** Shows the library of impact effects on different surfaces.
    *   **Enemy Death:** The enemy dies with a satisfying `Imagine.VFX.Enemy.DeathDissolve` effect and sound.

**5. Climax: The `Hack` and Power Restoration**
*   **Player Action:** The player reaches the main terminal and initiates a hack.
*   **What it Showcases:**
    *   **Interaction System:** The player interacts with a world object.
    *   **UI:** A simple hacking minigame appears on the `WBP_TerminalUI` widget.
    *   **Climactic Event:** Upon success, the `Imagine.Event.Env.PowerRestored` event is fired.
    *   **Full Thematic Shift:** The `Corruption` theme fades, and the `Imagine.Theme.Default` activates. The room's main lights turn on, the corruption material recedes, and the UI and audio become clean and stable.

**6. Narrative Payoff**
*   **Player Action:** With power restored, the terminal screen now shows a "Memory Fragment" available for viewing.
*   **What it Showcases:**
    *   **Narrative System:** A simple text or image is displayed, showing how lore and story can be delivered.
    *   **Reward:** The player is rewarded for their actions with a piece of the game's story.

### Why This Proposal Works

*   **Visually Impressive:** It hits all the major visual beats defined in the design doc.
*   **Technically Robust:** The entire flow is driven by the event and theme systems, proving the core architecture works.
*   **Focused Scope:** By limiting it to one room, one enemy, and one terminal, the art and engineering effort is concentrated on quality rather than quantity.

This "Corrupted Substation" slice would serve as a powerful, functional, and beautiful demonstration of the *Cortex* experience.

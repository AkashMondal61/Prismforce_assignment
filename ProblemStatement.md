
Certainly! Below is the content formatted as a README.md file.

# Abhimanyu's Escape from the Chakravyuha

## Problem Statement

Imagine Abhimanyu in the **Chakravyuha**, a formation of 11 concentric circles, each guarded by a powerful enemy. Abhimanyu starts in the innermost circle and must battle through to escape and reunite with the Pandavas. The problem is defined as follows:

- **Enemy Powers**: Each circle is guarded by an enemy with a specific power `k1, k2, ..., k11`.
- **Initial Energy**: Abhimanyu begins with an initial energy `p`.
- **Skips**: Abhimanyu can skip fighting up to `a` enemies.
- **Recharges**: Abhimanyu can recharge his energy up to `b` times.
- **Battle Mechanics**: Entering a circle with energy less than the enemy's power results in defeat. Battling an enemy reduces Abhimanyu's energy by the enemy's power.
- **Regenerating Enemies**: Enemies in the 4th and 8th circles (`k3` and `k7`) can regenerate once with half their initial power and attack Abhimanyu from behind if he is in the next circle.

The goal is to determine if Abhimanyu can successfully cross all 11 circles.

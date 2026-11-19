# Cartesian Pac-Man (C++)

A terminal-based twist on the classic Pac-Man game set on a **20 × 10 Cartesian grid**, built in C++ under strict first-semester Programming Fundamentals constraints (**no `if-else` statements, arrays, strings, or user-defined functions**—all control flow is handled exclusively via `switch` statements, ternary operators, and loops)[cite: 10].

---

## Objective

* **Win Condition:** Reach **Clyde (`C`)**[cite: 10]. Clyde is secretly a double agent—landing on the same cell as Clyde activates a siren that summons the Ghostbusters and saves Pac-Man[cite: 10].
* **Lose Condition:** Get caught by **Blinky (`B`)**, **Pinky (`P`)**, or **Inky (`I`)** before reaching Clyde[cite: 10].

---

## Controls & Board Legend

| Symbol  | Character / Tile |
| :---:   | :--- |
| **`@`** | Pac-Man (Player)[cite: 10] |
| **`C`** | Clyde (Ally / Double Agent)[cite: 10] |
| **`B`** | Blinky (Ghost)[cite: 10] |
| **`P`** | Pinky (Ghost)[cite: 10] |
| **`I`** | Inky (Ghost)[cite: 10] |
| **`*`** | Empty space[cite: 10] |

* **Controls:** Enter `W` (Up), `A` (Left), `S` (Down), or `D` (Right) and press `Enter` each turn[cite: 10].

---

## Character Movement Rules

All character positions are randomized at the start of the game without overlapping[cite: 10]. Each turn executes in the following order: **Pac-Man → Clyde → Inky → Pinky → Blinky**[cite: 10].

* **Pac-Man (`@`):** Moves one cell in the chosen direction (`W`/`A`/`S`/`D`), staying within the `20 × 10` grid boundaries[cite: 10].
* **Clyde (`C`):** Mirrors Pac-Man's exact movement every turn[cite: 10]. Because Clyde cannot pass through walls, you can corner him against a grid edge to close the distance and land on his tile[cite: 10].
* **Inky (`I`):** Remains stationary unless he is strictly the closest ghost to Pac-Man by Euclidean distance[cite: 10]. When triggered, he teleports 1 unit away from Pac-Man into the first unoccupied cell checked clockwise starting directly above Pac-Man (`Top → Top-Right → Right → Bottom-Right → Bottom → Bottom-Left → Left → Top-Left`)[cite: 10].
* **Pinky (`P`):** Moves 1 step toward Pac-Man along whichever axis (horizontal or vertical) currently has the **smaller** non-zero distance—or moves along the dominant axis to close the gap, stepping **diagonally** if her horizontal and vertical distances to Pac-Man are equal[cite: 10].
* **Blinky (`B`):** Patrols fixed horizontal ley lines 1 step per turn[cite: 10]. He travels left-to-right along row 3 from the top (`y = 2`); upon reaching the right edge, he warps down to row 3 from the bottom (`y = 7`) and travels right-to-left before warping back to the top-left[cite: 10].

---

## How to Compile and Run

Make sure you have a C++ compiler (such as `g++`) installed:

```bash
g++ main.cpp -o pacman
./pacman
# Nevalar

**Nevalar** is a command-line text adventure written in C++. The project was created as a way to practice and demonstrate fundamental C++ programming concepts through a simple fantasy role-playing game.

Players create an adventurer, choose a class, manage their gold and inventory, and make choices as they explore the land of Nevalar.

## Current Version

Current Version: v0.1.0-alpha

Nevalar is currently in early development and is not yet a complete playable game. Core gameplay systems and story content are actively being implemented.

## Features

* Character name and class selection
* Nine playable adventurer classes
* Branching player choices using conditional logic
* Input validation and repeated prompts using loops
* Gold and spending system
* Character stats
* Player inventory
* Randomized events and outcomes
* Text-based exploration and interactions

## Classes

Players can choose from nine classes:

1. Warrior
2. Ranger
3. Rogue
4. Wizard
5. Cleric
6. Bard
7. Paladin
8. Druid
9. Monk

## Commands

In addition to numbered story choices, players can use commands to view information about their character during the adventure.

| Command     | Description                         |
| ----------- | ----------------------------------- |
| `stats`     | View character information          |
| `inventory` | View the player's current inventory |
| `gold`      | Check the player's money bag        |

## Concepts Demonstrated

This project is intended to demonstrate my understanding of introductory C++ concepts, including:

* Variables and data types
* User input and output
* `if`, `else if`, and `else` statements
* Logical operators
* `while` loops
* Functions and parameters
* Strings
* Random number generation
* Input validation
* Basic game-state management

## Running the Game

Compile `main.cpp` using a C++ compiler such as `g++`:

```bash
g++ main.cpp -o nevalar
```

Then run the program:

**Windows:**

```bash
nevalar.exe
```

**macOS/Linux:**

```bash
./nevalar
```

## Project Status

**In Development**

Nevalar is an ongoing learning project. Additional story paths, encounters, inventory items, and gameplay systems may be added as I continue developing the game and expanding my knowledge of C++.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

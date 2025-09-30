# So Long - And thanks for all the fish!

## 🎯 Project Overview

**So Long** is a small 2D game project that introduces you to computer graphics programming using the MiniLibX library. You'll create a basic game where a character collects items and navigates through a map to reach an exit.

> **Summary:** This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

**Version:** 3

## 🎮 Game Concept

Create a 2D game where:
- A player character moves around a map
- Collects all collectible items
- Finds the shortest path to the exit
- The theme can be anything you choose (dolphin/fish is just an example)

## ⚙️ Technical Specifications

### Program Requirements
| Component | Specification |
|-----------|---------------|
| **Program Name** | `so_long` |
| **Language** | C |
| **Graphics Library** | MiniLibX |
| **Input** | `.ber` map file |
| **External Functions** | MiniLibX, math library, `ft_printf` |

### Mandatory Features
- **2D view** (top-down or profile)
- **Smooth window management**
- **Clean exit** on ESC or window close
- **Movement counter** displayed in shell
- **Map validation** and error handling

## 🗺️ Map System

### Map Components
| Character | Meaning |
|-----------|---------|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start position |

### Map Validation Rules
- **Must be rectangular**
- **Surrounded by walls**
- **Exactly 1 exit**
- **At least 1 collectible**
- **Exactly 1 player start position**
- **Valid path** must exist
- **No duplicate characters** (exit/start)

<iframe width="560" height="315" src="https://www.youtube.com/embed/J5c-WpOGoOc" frameborder="0" allowfullscreen></iframe>
## 🎯 Gameplay Features

### Player Movement
- **WASD keys** for movement (up, down, left, right)
- **Arrow keys** also allowed as alternative
- **Cannot move through walls**
- **Movement counter** updates after each move

### Win Condition
- Collect **all collectibles**
- Reach the **exit**
- Follow the **shortest possible route**

## 🖼️ Graphics & Display

### Window Management
- **Smooth window handling** (minimize, switch, etc.)
- **Clean exit** on ESC or window close
- **MiniLibX images** required for display
- **2D view** implementation

## 🎯 Learning Objectives

- **Window management** with MiniLibX
- **Event handling** (keyboard input)
- **2D graphics programming**
- **Game loop implementation**
- **Map parsing and validation**
- **Pathfinding algorithms**
- **Texture and sprite management**
- **Game state management**

## 🔧 Implementation Details

### Required Components
- **Map parser** for `.ber` files
- **Game state tracker** (collectibles, moves, position)
- **Graphics renderer** using MiniLibX
- **Input handler** for keyboard events
- **Collision detection** system
- **Path validation** algorithm

### Error Handling
- **Comprehensive map validation**
- **Clean error messages** with "Error\n" prefix
- **Proper memory management** (no leaks)
- **Graceful program termination**

## ⚠️ Important Notes

- **Use official assets** or properly credited resources
- **Respect other artists' work** when using external assets
- **Test with various map configurations**
- **Ensure smooth performance** without crashes
- **Follow norm requirements** strictly

---

*Create your first 2D game while mastering graphics programming, event handling, and game development fundamentals with MiniLibX!*


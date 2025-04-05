# 🎯 My Hunter: The Duck Hunt Legacy

## 🕹️ Description

**My Hunter** is a 2D arcade shooting game written in C using the CSFML library. Inspired by the classic **Duck Hunt**, your objective is simple: click to shoot ducks as they fly across the screen. The game combines sprite animations, mouse input, and timed movement for a responsive, fun gameplay experience.

---

## 📦 Binary

- **Executable name**: `my_hunter`
- **Language**: C
- **Compilation**: via `Makefile` with the following rules:
  - `make` — Compile the project  
  - `make clean` — Remove object files  
  - `make fclean` — Remove object files and binary  
  - `make re` — Clean and recompile

---

## 🎮 Features

### ✅ Implemented Core Features

- Event-driven window closure using events  
- Mouse click input to shoot ducks  
- Animated sprites using sprite sheets  
- Moving ducks with translation across the screen  
- `-h` option to display usage help

### ⏱️ Performance Features

- Time-based movement using `sfClock`  
- Frame rate capped to prevent lag  
- Animation independent of system speed  
- Fixed window resolution: **1920x1080**

## 🧠 Usage

### Run the game

```bash
./my_hunter

### Show help

```bash
./my_hunter -h


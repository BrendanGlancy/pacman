# Pac-Man Game 

An attempt to create something similar to the original Pac-Man game in C

## Getting Started

### Prerequisites

Ensure you have the following installed:
- A C++ compiler (e.g., GCC, Clang)
- Make (optional for easier building)

## Dependencies:

1. **SDL2**: A cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

2. **SDL2_gfx**: An extension of the SDL2 library to provide basic drawing functions such as lines, circles, or polygons.

### Installing Dependencies:

#### macOS (using Homebrew):

```bash
brew install sdl2
brew install sdl2_gfx
brew install csfml
```

#### Linux:

```bash
sudo apt update
sudo apt install libsdl2-dev
sudo apt install libsdl2-gfx-dev
sudo apt-get install libcsfml-dev
```

Project Structure

```
pac-man/
│
├── src/                        # Source files
│   ├── main.c                  # Main game loop
│   ├── game/                   # Game logic components
│   │   ├── pac-man.c           # Pac-Man related logic
│   │   ├── ghost.c             # Ghost related logic
│   │   ├── maze.c              # Maze generation and logic
│   │   └── ...
│   │
│   ├── graphics/               # Graphics rendering components
│   │   ├── renderer.c          # Rendering functions
│   │   ├── textures.c          # Texture loading and management
│   │   └── ...
│   │
│   ├── sound/                  # Sound components
│   │   ├── sound.c             # Sound loading and playback
│   │   └── ...
│   │
│   └── utils/                  # Utility functions and structures
│       ├── collision.c         # Collision detection utilities
│       ├── input.c             # Input handling utilities
│       └── ...
│
├── include/                    # Header files
│   ├── game/
│   │   ├── pac-man.h
│   │   ├── ghost.h
│   │   ├── maze.h
│   │   └── ...
│   │
│   ├── graphics/
│   │   ├── renderer.h
│   │   ├── textures.h
│   │   └── ...
│   │
│   ├── sound/
│   │   ├── sound.h
│   │   └── ...
│   │
│   └── utils/
│       ├── collision.h
│       ├── input.h
│       └── ...
│
├── assets/                     # Game assets
│   ├── textures/               # Image assets for the game
│   │   ├── pac-man.png
│   │   ├── ghost.png
│   │   ├── maze.png
│   │   └── ...
│   │
│   └── sounds/                 # Sound assets for the game
│       ├── eat-fruit.wav
│       ├── ghost-chase.wav
│       └── ...
│
├── lib/                        # External libraries (e.g., SDL)
│
├── build/                      # Compiled binaries and object files
│
├── scripts/                    # Build scripts, installation scripts, etc.
│
├── docs/                       # Documentation
│   ├── design.md               # Design document
│   ├── user-manual.md          # User manual
│   └── ...
│
├── .gitignore                  # Git ignore file
├── Makefile                    # Makefile for building the project
└── README.md                   # Project overview and setup instructions
```

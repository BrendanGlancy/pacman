Project Structure

`
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
`

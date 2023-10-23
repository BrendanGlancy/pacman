#include "../include/game/maze.h"
#include "../include/game/pac-man.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// Function to print the maze to the console
void draw_maze() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black color
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

  // Draw maze walls using SDL2
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      Cell cell = maze[i][j];
      int x = j * CELL_SIZE;
      int y = i * CELL_SIZE;

      // Draw the top wall
      if (cell.top_wall) {
        SDL_RenderDrawLine(renderer, x, y, x + CELL_SIZE, y);
      }
      // Draw the bottom wall
      if (cell.bottom_wall) {
        SDL_RenderDrawLine(renderer, x, y + CELL_SIZE, x + CELL_SIZE,
                           y + CELL_SIZE);
      }
      // Draw the left wall
      if (cell.left_wall) {
        SDL_RenderDrawLine(renderer, x, y, x, y + CELL_SIZE);
      }
      // Draw the right wall
      if (cell.right_wall) {
        SDL_RenderDrawLine(renderer, x + CELL_SIZE, y, x + CELL_SIZE,
                           y + CELL_SIZE);
      }
    }
  }

  // Draw Pac-Man
  int pacmanCenterX = pacman.x * CELL_SIZE + CELL_SIZE / 2;
  int pacmanCenterY = pacman.y * CELL_SIZE + CELL_SIZE / 2;
  int pacmanRadius = CELL_SIZE / 2;

  filledCircleRGBA(renderer, pacmanCenterX, pacmanCenterY, pacmanRadius, 255,
                   255, 0, 255);

  // Optionally, draw Pac-Man's mouth here based on movement direction
  // ... [logic to draw Pac-Man's mouth depending on his direction]
}

int main() {
  srand(time(NULL));
  init_maze();
  generate_maze(0, 0);

  if (SDL_Init(SDL_INIT_VIDEO)) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  window =
      SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  int game_loop = 1;
  SDL_Event event;

  while (game_loop) {
    while (SDL_PollEvent(&event)) {
      handle_input(event); // This now simply processes the event
      if (event.type == SDL_QUIT) {
        game_loop = 0;
      }
    }

    key_input();
    update_pacman_position();
    draw_maze();
    SDL_RenderPresent(renderer);
    SDL_Delay(16); // 60 FPS would be approximately 16ms delay
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

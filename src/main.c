#include "../include/game/maze.h"
#include "../include/game/pac-man.h"
#include "../include/graphics/renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void render_maze() {
  SDL_SetRenderDrawColor(renderer, BLACK_COLOR.r, BLACK_COLOR.g, BLACK_COLOR.b,
                         BLACK_COLOR.a);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, BLUE_COLOR.r, BLUE_COLOR.g, BLUE_COLOR.b,
                         BLUE_COLOR.a);
  for (int i = 0; i < HEIGHT; i++) { for (int j = 0; j < WIDTH; j++) {
      const Cell *cell = &maze[i][j];
      int x = j * CELL_SIZE;
      int y = i * CELL_SIZE;

      if (cell->top_wall)
        SDL_RenderDrawLine(renderer, x, y, x + CELL_SIZE, y);
      if (cell->bottom_wall)
        SDL_RenderDrawLine(renderer, x, y + CELL_SIZE, x + CELL_SIZE,
                           y + CELL_SIZE);
      if (cell->left_wall)
        SDL_RenderDrawLine(renderer, x, y, x, y + CELL_SIZE);
      if (cell->right_wall)
        SDL_RenderDrawLine(renderer, x + CELL_SIZE, y, x + CELL_SIZE,
                           y + CELL_SIZE);
    }
  }

  filledCircleRGBA(renderer, pacman.x * CELL_SIZE + CELL_SIZE / 2,
                   pacman.y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE / 2.5,
                   PACMAN_COLOR.r, PACMAN_COLOR.g, PACMAN_COLOR.b,
                   PACMAN_COLOR.a);
}

int main() {
  srand(time(NULL));
  init_maze();
  generate_maze(0, 0);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  window =
      SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE, SDL_WINDOW_SHOWN);
  if (!window) {
    fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  int game_loop = 1;
  SDL_Event event;
  while (game_loop) {
    while (SDL_PollEvent(&event)) {
      handle_input(event);
      if (event.type == SDL_QUIT)
        game_loop = 0;
    }

    key_input();
    update_pacman_position();
    render_maze();
    SDL_RenderPresent(renderer);
    SDL_Delay(FPS_DELAY);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

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
SDL_Texture *mazeTexture = NULL;

int prevPacmanX = -1;
int prevPacmanY = -1;

void render_maze() {
  SDL_SetRenderDrawColor(renderer, BLUE_COLOR.r, BLUE_COLOR.g, BLUE_COLOR.b,
                         BLUE_COLOR.a);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
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
}

void render_pacman() {
  if (prevPacmanX != -1 && prevPacmanY != -1) {
    filledCircleRGBA(renderer, prevPacmanX, prevPacmanY, CELL_SIZE / 2.5,
                     BLACK_COLOR.r, BLACK_COLOR.g, BLACK_COLOR.b,
                     BLACK_COLOR.a);
  }

  filledCircleRGBA(renderer, pacman.x * CELL_SIZE + CELL_SIZE / 2,
                   pacman.y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE / 2.5,
                   PACMAN_COLOR.r, PACMAN_COLOR.g, PACMAN_COLOR.b,
                   PACMAN_COLOR.a);

  prevPacmanX = pacman.x * CELL_SIZE + CELL_SIZE / 2;
  prevPacmanY = pacman.y * CELL_SIZE + CELL_SIZE / 2;
}

int main() {
  srand(time(NULL));
  generate_nav_maze();
  print_nav_maze();
  init_pacman();

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

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Initialize mazeTexture before using it as a render target
  mazeTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                  SDL_TEXTUREACCESS_TARGET, WIDTH * CELL_SIZE,
                                  HEIGHT * CELL_SIZE);

  // Render the maze to the texture
  SDL_SetRenderTarget(renderer, mazeTexture);
  SDL_SetRenderDrawColor(renderer, BLACK_COLOR.r, BLACK_COLOR.g, BLACK_COLOR.b,
                         BLACK_COLOR.a);
  SDL_RenderClear(renderer);
  render_maze();
  SDL_SetRenderTarget(renderer, NULL);

  const int FPS = 60;
  const int FRAME_DELAY = 5000 / FPS;

  int game_loop = 1;
  SDL_Event event;
  while (game_loop) {
    Uint32 frameStart = SDL_GetTicks();

    while (SDL_PollEvent(&event)) {
      handle_input(event);
      if (event.type == SDL_QUIT)
        game_loop = 0;
    }

    key_input();
    update_pacman_position();

    SDL_RenderCopy(renderer, mazeTexture, NULL, NULL);
    render_pacman();
    SDL_RenderPresent(renderer);

    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if (FRAME_DELAY > frameTime) {
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }

  SDL_DestroyTexture(mazeTexture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

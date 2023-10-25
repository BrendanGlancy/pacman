#include "../../include/utils/input.h"
#include <SDL2/SDL_keycode.h>

static int key_states[4];

void init_input_system() {
  for (int i = 0; i < 4; i++) {
    key_states[i] = 0;
  }
}

void handle_input(SDL_Event event) {
    switch (event.type) {
    case SDL_QUIT:
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_LEFT:
      case SDLK_a:
      case SDLK_h:
        key_states[LEFT] = 1;
        break;
      case SDLK_RIGHT:
      case SDLK_d:
      case SDLK_l:
        key_states[RIGHT] = 1;
        break;
      case SDLK_UP:
      case SDLK_w:
      case SDLK_k:
        key_states[UP] = 1;
        break;
      case SDLK_DOWN:
      case SDLK_s:
      case SDLK_j:
        key_states[DOWN] = 1;
        break;
      }
      break;

    case SDL_KEYUP:
      switch (event.key.keysym.sym) {
      case SDLK_LEFT:
      case SDLK_a:
      case SDLK_h:
        key_states[LEFT] = 0;
        break;
      case SDLK_RIGHT:
      case SDLK_d:
      case SDLK_l:
        key_states[RIGHT] = 0;
        break;
      case SDLK_UP:
      case SDLK_w:
      case SDLK_k:
        key_states[UP] = 0;
        break;
      case SDLK_DOWN:
      case SDLK_s:
      case SDLK_j:
        key_states[DOWN] = 0;
        break;
      }
      break;
    }
}

int key_pressed(int key) {
  if (key >= 0 && key < 4) {
    return key_states[key];
  }

  return 0;
}

#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#define LEFT  0
#define RIGHT 1
#define UP    2
#define DOWN  3

void init_input_system();
void handle_input(SDL_Event event);
int key_pressed(int key);

#endif // INPUT_H

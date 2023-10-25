#ifndef PACMAN_H
#define PACMAN_H

#include "../../include/game/maze.h"
#include "../../include/utils/input.h"

typedef struct {
  int x, y;
  int dx, dy;
  int isMoving;
  int lives;
} Pacman;

extern Pacman pacman;

void init_pacman();
void update_pacman_position();
void key_input();
int val_position(int x, int y);

#endif

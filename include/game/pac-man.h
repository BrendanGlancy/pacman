#pragma once

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
int move_right(int nextX);
int move_left(int nextX);
int move_up(int nextY);
int move_down(int nextY);


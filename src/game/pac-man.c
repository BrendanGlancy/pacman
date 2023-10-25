#include "../../include/game/pac-man.h"
#include <stdio.h>
#include <stdlib.h>

Pacman pacman;

void init_pacman() {
  pacman.x = 0;
  pacman.y = 0;
  pacman.dx = 0;
  pacman.dy = 0;

  pacman.isMoving = 0;
  pacman.lives = 0;
}

void key_input() {
  int temp_dx = 0, temp_dy = 0;
  
  if (key_pressed(LEFT)) {
    temp_dx = -1;
    if (val_position(pacman.x - 1, pacman.y)) {
      pacman.dx = temp_dx;
      pacman.isMoving = 1;
    }
  }
  else if (key_pressed(RIGHT)) {
    temp_dx = 1;
    if (val_position(pacman.x + 1, pacman.y)) {
      pacman.dx = temp_dx;
      pacman.isMoving = 1;
    }
  }
  else if (key_pressed(DOWN)) {
    temp_dy = 1;
    if (val_position(pacman.x, pacman.y + 1)) {
      pacman.dy = temp_dy;
      pacman.isMoving = 1;
    }
  }
  else if (key_pressed(UP)) {
    temp_dy = -1;
    if (val_position(pacman.x, pacman.y - 1)) {
      pacman.dy = temp_dy;
      pacman.isMoving = 1;
    }
  }
}

int val_position(int nextX, int nextY) {
  if (nextX < 0 || nextX > WIDTH - 1 || nextY < 0 || nextY > HEIGHT - 1) {
    return 0;
  }

  if (nextX > pacman.x && maze[pacman.x][pacman.y].right_wall) // Moving right
    return 0;
  if (nextX < pacman.x && maze[pacman.x][pacman.y].left_wall) // Moving left
    return 0;
  if (nextY > pacman.y && maze[pacman.x][pacman.y].bottom_wall) // Moving down
    return 0;
  if (nextY < pacman.y && maze[pacman.x][pacman.y].top_wall) // Moving up
    return 0;

  return 1;
}

void update_pacman_position() {
  if (pacman.isMoving) {
    pacman.x += pacman.dx;
    pacman.y += pacman.dy;

    pacman.dx = 0;
    pacman.dy = 0;
    pacman.isMoving = 0;
  }

  printf("{%d, %d}\n", pacman.x, pacman.y);
}

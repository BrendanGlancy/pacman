#include "../../include/game/pac-man.h"
#include <stdio.h>
#include <stdlib.h>

Pacman pacman;

void init_pacman() {
  pacman.x = WIDTH/ 2;
  pacman.y = HEIGHT / 2 + 2;
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
      printf("VAL\n");
      pacman.dx = temp_dx;
      pacman.isMoving = 1;
    }
  } else if (key_pressed(RIGHT)) {
    temp_dx = 1;
    if (val_position(pacman.x + 1, pacman.y)) {
      printf("VAL\n");
      pacman.dx = temp_dx;
      pacman.isMoving = 1;
    }
  } else if (key_pressed(DOWN)) {
    temp_dy = 1;
    if (val_position(pacman.x, pacman.y + 1)) {
      printf("VAL\n");
      pacman.dy = temp_dy;
      pacman.isMoving = 1;
    }
  } else if (key_pressed(UP)) {
    temp_dy = -1;
    if (val_position(pacman.x, pacman.y - 1)) {
      printf("VAL\n");
      pacman.dy = temp_dy;
      pacman.isMoving = 1;
    }
  }
}

int val_position(int nextX, int nextY) {
  printf("Checking position: (%d, %d) from current position: (%d, %d)\n", nextX,
         nextY, pacman.x, pacman.y);

  if (nextX < 0 || nextX > WIDTH - 1 || nextY < 0 || nextY > HEIGHT - 1) {
    return 0;
  }

  // If the tile in the next position is a wall (0), return 0 (invalid position)
  if (nav_maze[nextY][nextX] == 1) {
    return 0;
  }

  return 1; // Valid position
}

void update_pacman_position() {
  if (pacman.isMoving) {
    pacman.x += pacman.dx;
    pacman.y += pacman.dy;

    pacman.dx = 0;
    pacman.dy = 0;
    pacman.isMoving = 0;
  }
}

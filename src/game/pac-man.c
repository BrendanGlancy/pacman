#include "../../include/game/pac-man.h"
#include <stdio.h>

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
  int nextX = pacman.x + pacman.dx;
  int nextY = pacman.y + pacman.dy;

  // Check LEFT
  if (key_pressed(LEFT) && nextX > 0 && !maze[nextX - 1][pacman.y].left_wall) {
    pacman.dx = -1;
    pacman.dy = 0;
    pacman.isMoving = 1;
  }
  // Check RIGHT
  else if (key_pressed(RIGHT) && nextX < WIDTH - 1 &&
           !maze[nextX + 1][pacman.y].right_wall) {
    pacman.dx = 1;
    pacman.dy = 0;
    pacman.isMoving = 1;
  }
  // Check DOWN
  else if (key_pressed(DOWN) && nextY < HEIGHT - 1 &&
           !maze[pacman.x][nextY + 1].bottom_wall) {
    pacman.dx = 0;
    pacman.dy = 1;
    pacman.isMoving = 1;
  }
  // Check UP
  else if (key_pressed(UP) && nextY > 0 &&
           !maze[pacman.x][nextY - 1].top_wall) {
    pacman.dx = 0;
    pacman.dy = -1;
    pacman.isMoving = 1;
  }
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

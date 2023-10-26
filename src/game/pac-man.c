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

  if (nextX > pacman.x && move_right(nextX)) {
    printf("nextX %d, pacman.x %d \n", nextX, pacman.x);
    return 0;
  } else {
    printf("right_wall %d \n", maze[pacman.x][pacman.y].right_wall);
  }

  if (nextX < pacman.x && move_left(nextX)) {
    return 0;
  } else {
    printf("left_wall %d \n", maze[pacman.x][pacman.y].left_wall);
  }

  if (nextY >= pacman.y && move_down(nextY)) {
    return 0;
  } else {
    printf("bottom_wall %d \n", maze[pacman.x][pacman.y].bottom_wall);
  }

  if (nextY <= pacman.y && move_up(nextY)) {
    return 0;
  } else {
    printf("top_wall %d \n", maze[pacman.x][pacman.y].top_wall);
  }
  return 1;
}

int move_right(int nextX) {
  if (!maze[nextX][pacman.y].right_wall) {
    printf("Can move right\n");
    return 0;
  }
  printf("%d\n", maze[nextX][pacman.y].right_wall);
  printf("Can't move right\n");
  return 1;
}

int move_left(int nextX) {
  if (maze[nextX][pacman.y].left_wall) {
    printf("Can move left\n");
    return 0;
  }
  printf("Can't move left\n");
  return 1;
}

int move_down(int nextY) {
  if (maze[nextY][pacman.y].bottom_wall) {
    printf("Can move down\n");
    return 0;
  }
  printf("Can't move down\n");
  return 1;
}

int move_up(int nextY) {
  if (maze[nextY][pacman.y].top_wall) {
    printf("Can move up\n");
    return 0;
  }
  printf("Can't move up\n");
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
}

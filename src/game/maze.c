#include "../../include/game/maze.h"
#include "../../include/graphics/renderer.h"
#include <stdio.h>

Cell maze[HEIGHT][WIDTH];
int nav_maze[HEIGHT][WIDTH];

void generate_nav_maze() {
  // decode the playfield from an ASCII map into tiles codes
  static const char *tiles = "0000000000000000000000000000"
                             "0222222222222002222222222220"
                             "0200002000002002000002000020"
                             "0301102011102002011102011030"
                             "0200002000002002000002000020"
                             "0222222222222222222222222220"
                             "0200002002000000002002000020"
                             "0200002002000000002002000020"
                             "0222222002222002222002222220"
                             "0000002000001001000002000000"
                             "0000002000001001000002000000"
                             "0000002001111111111002000000"
                             "0000002001000000001002000000"
                             "0000002001000000001002000000"
                             "1111112111011111101112111111"
                             "0000002001000000001002000000"
                             "0000002001000000001002000000"
                             "0000002001111111111002000000"
                             "0000002001000000001002000000"
                             "0000002001000000001002000000"
                             "0222222222222002222222222220"
                             "0200002000002002000002000020"
                             "0200002000002002000002000020"
                             "0322002222222112222222002230"
                             "0002002002000000002002002000"
                             "0002002002000000002002002000"
                             "0222222002222002222002222220"
                             "0200000000002002000000000020"
                             "0200000000002002000000000020"
                             "0222222222222222222222222220"
                             "0000000000000000000000000000";

  for (int y = 3, i = 0; y <= 33; y++) {
    for (int x = 0; x < 28; x++, i++) {
      char tile = tiles[i];

      // Mark paths as 0 and walls as 1
      if (tile == '0') {
        nav_maze[y - 3][x] = 1;
      } else {
        nav_maze[y - 3][x] = 0;
      }

      maze[y - 3][x].x = x;
      maze[y - 3][x].y = y - 3;
      maze[y - 3][x].visited = 0;
      maze[y - 3][x].top_wall = (tile == '0') ? 0 : 1;
      maze[y - 3][x].bottom_wall = (tile == '0') ? 0 : 1;
      maze[y - 3][x].right_wall = (tile == '0') ? 0 : 1;
      maze[y - 3][x].left_wall = (tile == '0') ? 0 : 1;
    }
  }
}

void print_nav_maze() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d", nav_maze[i][j]);
    }
    printf("\n");
  }
}

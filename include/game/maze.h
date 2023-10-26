#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 28
#define WIDTH 28
#define CELL_SIZE 30
#define LEFT 1
#define RIGHT 2
#define TOP 4
#define BOTTOM 8

// Structs
typedef struct {
  int x, y;
  int visited;
  int walls;
} Cell;

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point neighbors[4];
  int count;
} NeighborData;

// Global maze variable (if needed in other files)
extern Cell maze[HEIGHT][WIDTH];

// Function prototypes
void init_maze();
NeighborData get_randomized_neighbors(int x, int y);
void remove_wall_between(Point curr, Point neighbor);
void generate_maze(int x, int y);
int move_right(int nextX);
int move_left(int nextX);
int move_up(int nextY);
int move_down(int nextY);

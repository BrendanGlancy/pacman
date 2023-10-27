#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HEIGHT 31
#define WIDTH 28
#define CELL_SIZE 30

// Structs
typedef struct {
  int x, y;
  int visited;
  int top_wall;
  int bottom_wall;
  int right_wall;
  int left_wall;
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
extern int nav_maze[HEIGHT][WIDTH];

// Function prototypes
void generate_nav_maze();
void print_nav_maze();

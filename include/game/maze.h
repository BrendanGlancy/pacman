#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <time.h>

#define HEIGHT 15
#define WIDTH 15
#define CELL_SIZE 40

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

// Function prototypes
void init_maze();
NeighborData get_randomized_neighbors(int x, int y);
void remove_wall_between(Point curr, Point neighbor);
void generate_maze(int x, int y);

#endif // MAZE_H

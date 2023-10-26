#include "../../include/game/maze.h"

#define LEFT 1
#define RIGHT 2
#define TOP 4
#define BOTTOM 8

Cell maze[HEIGHT][WIDTH];

void init_maze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].visited = 0;
            maze[i][j].walls = LEFT | RIGHT | TOP | BOTTOM;
        }
    }
}

NeighborData get_randomized_neighbors(int x, int y) {
    NeighborData data;
    int count = 0;

    // up
    if (x > 0) {
        data.neighbors[count].x = x - 1;
        data.neighbors[count].y = y;
        count++;
    }

    // down
    if (x < HEIGHT - 1) {
        data.neighbors[count].x = x + 1;
        data.neighbors[count].y = y;
        count++;
    }

    // right
    if (y < WIDTH - 1) {
        data.neighbors[count].x = x;
        data.neighbors[count].y = y + 1;
        count++;
    }

    // left
    if (y > 0) {
        data.neighbors[count].x = x;
        data.neighbors[count].y = y - 1;
        count++;
    }

    // shuffle data.neighbors
    for (int i = 0; i < count; i++) {
        int j = rand() % count;
        Point temp = data.neighbors[i];
        data.neighbors[i] = data.neighbors[j];
        data.neighbors[j] = temp;
    }

    data.count = count;

    return data;
}

void remove_wall_between(Point curr, Point neighbor) {
    if (neighbor.x < curr.x) {
        maze[curr.x][curr.y].walls &= ~TOP;
        maze[neighbor.x][neighbor.y].walls &= ~BOTTOM;
    } else if (neighbor.x > curr.x) {
        maze[curr.x][curr.y].walls &= ~BOTTOM;
        maze[neighbor.x][neighbor.y].walls &= ~TOP;
    } else if (neighbor.y < curr.y) {
        maze[curr.x][curr.y].walls &= ~LEFT;
        maze[neighbor.x][neighbor.y].walls &= ~RIGHT;
    } else if (neighbor.y > curr.y) {
        maze[curr.x][curr.y].walls &= ~RIGHT;
        maze[neighbor.x][neighbor.y].walls &= ~LEFT;
    }
}

void generate_maze(int x, int y) {
    maze[x][y].visited = 1;

    NeighborData neighborData = get_randomized_neighbors(x, y);

    for (int i = 0; i < neighborData.count; i++) {
        Point neighbor = neighborData.neighbors[i];
        if (!maze[neighbor.x][neighbor.y].visited) {
            remove_wall_between((Point) {x, y}, neighbor);
            generate_maze(neighbor.x, neighbor.y);
        }
    }
}

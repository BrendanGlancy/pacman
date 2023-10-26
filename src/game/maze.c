#include "../../include/game/maze.h"

Cell maze[HEIGHT][WIDTH];

void init_maze() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      maze[i][j].x = i;
      maze[i][j].y = j;
      maze[i][j].visited = 0;
      maze[i][j].top_wall = 1;
      maze[i][j].bottom_wall = 1;
      maze[i][j].right_wall = 1;
      maze[i][j].left_wall = 1;
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
  // neighbor is above the current wall
  if (neighbor.x < curr.x) {
    maze[curr.x][curr.y].top_wall = 0;
    maze[neighbor.x][neighbor.y].bottom_wall = 0;
  }
  // neighbor is below the current wall
  else if (neighbor.x > curr.x) {
    maze[curr.x][curr.y].bottom_wall = 0;
    maze[neighbor.x][neighbor.y].top_wall = 0;
  }
  // neighbor is left of the current wall
  else if (neighbor.y < curr.y) {
    maze[curr.x][curr.y].left_wall = 0;
    maze[neighbor.x][neighbor.y].right_wall = 0;
  }
  // neighbor is right of current wall
  else if (neighbor.y > curr.y) {
    maze[curr.x][curr.y].right_wall = 0;
    maze[neighbor.x][neighbor.y].left_wall = 0;
  }
}

// Generate the Maze design with a randomized depth first search algorithm
void generate_maze(int x, int y) {
  maze[x][y].visited = 1;

  NeighborData neighborData = get_randomized_neighbors(x, y);

  for (int i = 0; i < neighborData.count; i++) {
    Point neighbor = neighborData.neighbors[i];
    if (!maze[neighbor.x][neighbor.y].visited) {
      Point curr = {x, y};
      // remove the wall between the current cell and the neighbor
      remove_wall_between(curr, neighbor);
      // ... this will depend on which neighbor you're looking at

      // recursively generate the maze from this neighbor
      generate_maze(neighbor.x, neighbor.y);
    }
  }
}

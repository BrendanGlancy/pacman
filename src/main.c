#include <stdio.h>
#include "../include/game/maze.h"

// Function to print the maze to the console
void print_maze() {
    for (int i = 0; i < HEIGHT; i++) {
        // Print top walls of all cells in the row
        for (int j = 0; j < WIDTH; j++) {
            printf("+");  // Corner of each cell
            printf(maze[i][j].top_wall ? "---" : "   ");
        }
        printf("+\n");
        
        // Print left walls, cell content, and right walls of all cells in the row
        for (int j = 0; j < WIDTH; j++) {
            printf(maze[i][j].left_wall ? "|" : " ");
            printf(maze[i][j].visited ? "   " : " X ");  // Cell content (either visited or unvisited)
            if(j == WIDTH-1) printf(maze[i][j].right_wall ? "|" : " ");
        }
        printf("\n");
    }
    
    // Print bottom walls for the last row
    for (int j = 0; j < WIDTH; j++) {
        printf("+");
        printf(maze[HEIGHT-1][j].bottom_wall ? "---" : "   ");
    }
    printf("+\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the maze
    init_maze();

    // Generate the maze starting from the top-left corner
    generate_maze(0, 0);

    // Print the maze to the console
    print_maze();

    return 0;
}

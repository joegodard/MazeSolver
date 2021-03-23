#ifndef MAZE_H
#define MAZE_H

#include "cell_list.h"
#include <string.h>
#define MAX_DIMENSION 20

//Defines the maze structure
typedef struct MAZE
{
    int mazeRows;
    int mazeCols;
    char maze[MAX_DIMENSION][MAX_DIMENSION];
    Cell mouse;
    Cell escape;
} Maze;

//Functions to be defined
void printMaze(Maze *maze);
Maze* loadMaze(FILE *file);
bool solveMaze(Maze *maze);


#endif
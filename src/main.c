/************** main.c *******************
 * Main method to run the maze solver.
 * Takes in an argument of a txt file
 * with the maze you wish to solve.
 * The maze should be of the format:
 * 4 4
 * 1 1 1 1
 * 1 r 0 1
 * 1 0 e 1
 * 1 1 1 1
 * Where the first row holds the total
 * rows and columns in the maze, then
 * each space in the maze is separated
 * by one space. 
 * Char representations:
 *   1 - Wall
 *   0 - Empty Space
 *   r - The Mouse
 *   e - The Exit
 * The maze can be up to a 20x20 square,
 * and can be rectangular in shape.
 * Just pass in the argument as such
 * when running the main method:
 *      ./maze maze1.txt
**************************************/
#include "maze.h"

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen(argv[1], "r");
    Maze *maze = loadMaze(file);
    if(solveMaze(maze))
    {
        printf("The mouse is free!!!!\n");
    }
    else
    {
        printf("The mouse is trapped!!!!\n");
    }
    printf("\nEnd of processing\n");

    return EXIT_SUCCESS;
}
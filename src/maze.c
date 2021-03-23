/************** maze.c *******************
 * Functions to create and manage the maze
 * structure. The maze consists of a
 * 2d array of chars, total number of
 * rows and cols, and Cells holding the
 * positions of the mouse and escape.
 * 
 * Primary Functions:
 * Reads a txt file with the maze, 
 * creates the maze structure, then can
 * print or solve the maze using a cell
 * list to hold each possible route the
 * mouse could take to get out, evaluating
 * each route until a path out is found
 * or it is determined the mouse can't
 * reach the exit.
**************************************/

#include "maze.h"

//What each char represents
const char WALL    = '1';
const char SPACE   = '0';
const char VISITED = '.';
const char MOUSE   = 'r';
const char EXIT    = 'e';

//Prints the maze structure
void printMaze(Maze *maze)
{
    for(int i = 0; i <= maze->mazeRows; i++)
    {
        printf("%s\n", maze->maze[i]);
    }
    printf("\n");
}

//Reads in a txt file to create the maze structure
Maze* loadMaze(FILE *file)
{
    //Allocate space for the maze
    Maze *maze = (Maze*)malloc(sizeof(Maze));
    //Counters for current row and col
    int row = 0;
    int col = 0;
    //Checks if size has been found yet
    bool sized = false;

    //String to hold the current line to be parsed
    char line[MAX_DIMENSION+1];

    //Loops through each line in the txt file
    while(fgets(line, MAX_DIMENSION, file))
    {
        //If size hasn't been gotten, we are on the first line
        if(!sized)
        {
            //Tokenize the line
            char *token = strtok(line, " ");
            //Assing total maze rows and columns
            maze->mazeRows = atoi(token);
            token = strtok(NULL, " ");
            maze->mazeCols = atoi(token);
            sized = true;
            row++;
        }
        //If this is a line of the maze
        else if(line[0] == '1')
        {
            //Tokenize the line and iterate through them
            char *token = strtok(line, " ");
            while(token)
            {
                //Add each token to the maze in order
                maze->maze[row][col] = *token;
                col++;
                token = strtok(NULL, " ");
            }
            row++;
        }

        //Checks for and eliminates and newline characters in the row
        for(int j = 0; j < maze->mazeCols; j++)
        {
            if(maze->maze[row][j] == '\n')
            {
                maze->maze[row][j] = '\0';
            }
        }

        col = 0;
    }

    //Prints the maze once it has been loaded in
    printMaze(maze);

    //Checks for the locations of the mouse and exit, adds them into maze
    for(int i = 0; i < maze->mazeRows; i++)
    {
        for(int j = 0; j < maze->mazeCols; j++)
        {
            if(maze->maze[i][j] == MOUSE)
            {
                maze->mouse = makeCell(i, j);
            }
            if(maze->maze[i][j] == EXIT)
            {
                maze->escape = makeCell(i, j);
            }
        }
    }

    //Return the maze
    return maze;
}

//Solves the maze by finding a path between mouse and exit
bool solveMaze(Maze *maze)
{
    //Creates a cell list and sets mouse to the current cell, adds it to the list
    CellList *list = createList();
    Cell curr = maze->mouse;
    addCell(curr, list);

    //While there are still cells in the list and we haven't found the escape
    while(!noMoreCells(list) && !(equalCells(curr, maze->escape)))
    {
        //Set the current cell as visited
        maze->maze[curr.row][curr.column] = VISITED;
        //Get the next cell in the cell list
        list->top = list->top->next;

        //Checks if any adjacent space is either a space or the exit, if so add it to the cell list
        //Checks in the order below, above, left and right
        if(maze->maze[curr.row-1][curr.column] == SPACE || maze->maze[curr.row-1][curr.column] == EXIT)
        {
            addCell(makeCell(curr.row-1, curr.column), list);
        }
        if(maze->maze[curr.row+1][curr.column] == SPACE || maze->maze[curr.row+1][curr.column] == EXIT)
        {
            addCell(makeCell(curr.row+1, curr.column), list);
        }
        if(maze->maze[curr.row][curr.column-1] == SPACE || maze->maze[curr.row][curr.column-1] == EXIT)
        {
            addCell(makeCell(curr.row, curr.column-1), list);
        }
        if(maze->maze[curr.row][curr.column+1] == SPACE || maze->maze[curr.row][curr.column+1] == EXIT)
        {
            addCell(makeCell(curr.row, curr.column+1), list);
        }

        //If there are still cells in the list, continue to the next cell
        if(!noMoreCells(list))
        {
            curr = nextCell(list);
        }

        //Print the maze at each step
        printMaze(maze);
    }

    //Once the list has been completely checked, determine if the exit was found
    if(equalCells(curr, maze->escape))
    {
        return true;
    }
    else
    {
        return false;
    }
}
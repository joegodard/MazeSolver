/************** cell.c ***************
 * Class to create and manage the basic
 * cells in the maze. Each cell is just
 * one of the spaces in the maze, holds
 * a row and a column.
**************************************/

#include "cell.h"

//Checks if two cells are in the same place
bool equalCells(const Cell cell1, const Cell cell2)
{
    bool result = false;
    if(cell1.row == cell2.row && cell1.column == cell2.column)
    {
        result = true;
    }
    return result;
}

//Creates and returns a cell with the given row and column
Cell makeCell(const int row, const int col)
{
    Cell cell;
    cell.row = row;
    cell.column = col;
    return cell;
}
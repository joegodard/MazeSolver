#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Defines the CELL structure
typedef struct CELL
{
    int row;
    int column;
} Cell;

//Functions to be defined
bool equalCells(const Cell cell1, const Cell cell2);
Cell makeCell(const int row, const int col);

#endif
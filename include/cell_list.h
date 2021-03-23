#ifndef CELL_LIST_H
#define CELL_LIST_H

#include "cell.h"

//Defines the cell node structure
typedef struct CELL_NODE CellNode;
struct CELL_NODE
{
    Cell cell;
    CellNode *next;
};

//Defines the cell list structure
typedef struct CELL_LIST
{
    CellNode *top;
} CellList;

//The methods to be defined
CellList* createList();
bool noMoreCells(CellList *list);
Cell nextCell(CellList *list);
void addCell(const Cell cell, CellList *list);

#endif
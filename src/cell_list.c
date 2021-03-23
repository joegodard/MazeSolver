/************** cell_list.c ***************
 * Implementation of a linked list to hold
 * all of the cell nodes to be evaluated in
 * the main solve maze method. A Cell Node
 * contains a cell and a pointer to another
 * cell node.
*******************************************/

#include "cell_list.h"

//Allocates memory for a list and returns it, initializes top to null
CellList* createList()
{
    CellList *list = (CellList*)malloc(sizeof(CellList));
    list->top = NULL;
    return list;
}

//Checks if any cells remain in the list (if top is null)
bool noMoreCells(CellList* list)
{
    bool result = false;
    if(list->top == NULL)
    {
        result = true;
    }
    return result;
}

//Gets the next cell in the list
Cell nextCell(CellList* list)
{
    return list->top->cell;
}

//Adds a cell to the list by allocating memory for a cellnode and adding it in
void addCell(const Cell cell, CellList* list)
{
    CellNode *node;
    node = (CellNode*)malloc(sizeof(CellNode));
    node->cell = cell;
    node->next = list->top;
    list->top = node;
}
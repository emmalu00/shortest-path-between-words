/*
* Author: Emma Lucas
* stack.c
* This file implements a stack.
*/

#include "types.h"
#include "stack.h"
#include <stdlib.h>

void push(LIST_NODE** headptr, WORD_NODE* n) 
{
    LIST_NODE* newNode = malloc(sizeof(LIST_NODE));
    newNode->data = n;
    newNode->next = *headptr;
    *headptr = newNode;
}

WORD_NODE* pop(LIST_NODE** headptr) 
{
    LIST_NODE* temp = *headptr;
    WORD_NODE* result = temp->data;
    *headptr = (*headptr)->next;
    free(temp);
    return result;
}
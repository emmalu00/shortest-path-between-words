/*
* Author: Emma Lucas
* queue.c
* This file implements a queue.
*/

#include "types.h"
#include "queue.h"
#include <stdlib.h>

void enqueue(LIST_NODE** headptr, LIST_NODE** tailptr, WORD_NODE* data)
{
    LIST_NODE* newNode = malloc(sizeof(LIST_NODE));
    newNode->data = data;
    newNode->next = NULL;
    if (*headptr == NULL)
    {
        *headptr = newNode;
        *tailptr = newNode;
    }
    else
    {
        (*tailptr)->next = newNode;
        *tailptr = newNode;
    }
}

WORD_NODE* dequeue(LIST_NODE** headptr, LIST_NODE** tailptr) 
{
    LIST_NODE* temp = *headptr;
    WORD_NODE* data = temp->data;
    *headptr = temp->next;
    if (*headptr == NULL)
    {
        *tailptr = NULL;
    }
    free(temp);
    return data;
}
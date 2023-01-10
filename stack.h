//This file is complete except for your documentation block at the top

#ifndef STACK_H
#define STACK_H

#include "types.h"

/*
* Push adds a node to the top of a stack
*
* headptr: a pointer to the pointer to the top node on a stack
* n: the new node to push
*/
void push(LIST_NODE** headptr, WORD_NODE* n);

/*
* Pop removes and returns the top node on a stack. It assumes the 
* stack has at least one node.
*
* headptr: a pointer to the pointer to the top node on the stack
* returns: the old top node on the stack
*/
WORD_NODE* pop(LIST_NODE** headptr);

#endif
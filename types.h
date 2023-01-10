#ifndef TYPES_H
#define TYPES_H

//This file is complete except for your documentation block at the top

/*
* BOOL defines a boolean (true/false) type
*/
typedef enum {false, true} BOOL;

/*
* WORD_NODE represents a node in the graph of words, where two nodes are adjacent
* if their words differ by exactly one letter. The index of a node corresponds to
* its position in the adjacency matrix (defined in proj3.c). The visited and prev
* fields will be updated by breadth-first search (in proj3.c). The len field
* is strlen(word).
*/
typedef struct cell {
    int len;
    char word[30];
    BOOL visited;
    struct cell* prev;
    int index;
} WORD_NODE;

/*
* LIST_NODE represents a node in a linked structure. This
* type is used to represent nodes in a queue and nodes
* in a stack. The data field is type WORD_NODE (defined above),
* and the next field is a reference to the next node in the 
* stack/queue.
*/
typedef struct node {
    WORD_NODE* data;
    struct node* next;
} LIST_NODE;

#endif
//This file is complete except for your documentation block at the top

 #ifndef QUEUE_H
 #define QUEUE_H

 #include "types.h"

 /*
  * Enqueue adds a node to the front of a queue
  *
  * headptr: a pointer to the pointer to the first node in a queue
  * tailptr: a point to the pointer to the last node in a queue
  * data: the new node to add
  */
 void enqueue(LIST_NODE** headptr, LIST_NODE** tailptr, WORD_NODE* data);

 /*
  * Dequeue removes and returns the first node in a queue. It assumes the 
  * queue has at least one node.
  *
  * headptr: a pointer to the pointer to the first node in the queue
  * tailptr: a pointer to the pointer to the last node in the queue
  * returns: the old first node in the queue
  */
 WORD_NODE* dequeue(LIST_NODE** headptr, LIST_NODE** tailptr);

 #endif
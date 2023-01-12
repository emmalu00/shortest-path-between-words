# Word-Path
## Project Description
This is a program in C that takes the name of a file as a command-line argument. The input file contains a list of words. The first line of the file is the number of words contained in the file, one per line. The program repeatedly asks the user to enter two words. For each pair of words, the program prints the shortest “path” from the first word to the second. In the path, two words can be connected if they are the same length and they contain exactly the same characters in the same positions except for one. For example, _“cat”_ and _“car”_ can be connected since they only differ by the 3rd letter. On the other hand, _“art”_ and _“arts”_ are not connected since they are not the same length. _“vein”_ and _“vine”_ are not connected even though they contain the same letters, as their letters differ in three different positions. Stacks and queues are implemented in this program.
Here is an example output of the program: 

`Enter starting word: fit`

`Enter stopping word: cat`

`Shortest path from fit to cat:`

`fit`

`sit`

`sat`

`cat`


## Running the Program
The program compiles through the command line with the following statement: 

`make`

This will produce the executable **_project3.c_**

The program will then run through the command line with the following statement:

`./proj3 inputFile`

Here, _inputFile_ is the name of an input file (such as words56.txt).

## types.h
Note that the **_types.h_** file defines the following types:
* _BOOL_ – represents a boolean type, with true/false values
* _WORD_NODE_ – will be used in **_project3.c_** to represent a node in a graph
* _LIST_NODE_ – used by stack and queue to represent a node in a linked data
structure whose data is a pointer to a WORD_NODE.

***
## `stack.c`
stack.c implements push and pop functions.

### _`void push(LIST_NODE** headptr, WORD_NODE* n)`_
_headptr_ is a pointer to the top node on the stack, and _n_ is the data item to be added. **_push_** adds a new node containing _n_ to the top of the stack and updates _headptr_ to hold the address of the new top of the stack.

### _`WORD_NODE* pop(LIST_NODE** headptr)`_
_headptr_ is a pointer to the top node on the stack. **_pop_** returns the data that is on top of the stack. It also removes the top node of the stack and updates _headptr_ to hold the address of the new top. Finally, it frees any memory that is no longer being used.

***
## `queue.c`
queue.c implements enqueue and dequeue functions.

### _`void enqueue(LIST_NODE** headptr, LIST_NODE** tailptr, WORD_NODE* data)`_
_headptr_ and _tailptr_ are pointers to the first and last nodes in the queue, and _data_ is the data item to be added. **_enqueue_** adds a new node containing _data_ to the end of the queue and updates _headptr_ and _tailptr_ to hold the addresses of the new first and last nodes in the queue.

### _`WORD_NODE* dequeue(LIST_NODE** headptr, LIST_NODE** tailptr)`_
_headptr_ and _tailptr_ are pointers to the first and last nodes in the queue. **_dequeue_** returns the data that is at the front of the queue. It also removes the first node in the queue and updates _headptr_ and _tailptr_ to hold the addresses of the new first and last nodes in the queue. Finally, it frees any memory that is no longer being used.
***
**_project3.c_** handles all of the main logic for the program, and user input and output.
The **_project3.c_** file utilizes **_stack.c_** and **_queue.c_**.


## Global Variables
* _**WORD_NODE****_ _**_nodelist**_ – an array of pointers to WORD_NODES, where each
WORD_NODE corresponds to a word in the input file
* _**BOOL**** **_adj**_ – the adjacency matrix that lets us represent the words as a graph.
Each _adj[i][j] is true if _nodelist[i]->word and _nodelist[j]->word differ by exactly
one letter, and is false otherwise.
* _**int _numwords**_ – the number of words (as read from the input file). _nodeList
will be size _numwords, and _adj will be size _numwords by _numwords.

## Methods
### `int main(int argc, char* argv[])`
Reads the input file, initializes the global variables (__numwords_, __nodelist_, __adj_), and repeatedly prints the shortest path between two user input words. 


### `WORD_NODE* get_word(char* word)`
Returns the WORD_NODE in _nodelist whose word field matches the word parameter.

### `void build_adj(WORD_NODE* n)`
Initializes column n->index in the _adj 2D array. Each _adj[i][n->index] should is true if _nodelist[i]->word and n->word differ by exactly one letter and is false otherwise.

### `BOOL bfs(NODE_WORD* start, NODE_WORD* stop)`
Uses breadth-first search to find the shortest path from start to stop, and returns whether a path was found. 

### `void print_results(NODE_WORD* start, NODE_WORD* stop)`
Uses a stack to print the words in the shortest path from start->word to stop->word. 

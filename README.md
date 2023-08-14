# shortest-path-between-words
## About
This program finds the shortest "path" between two words entered as input by the user. In the path, two words can be connected if they are the same length and they contain exactly the same characters in the same positions except for one. For example, _“cat”_ and _“car”_ can be connected since they only differ by the 3rd letter. On the other hand, _“art”_ and _“arts”_ are not connected since they are not the same length. _“vein”_ and _“vine”_ are not connected even though they contain the same letters, as their letters differ in three different positions.

### Running the Program
The program compiles through the command line with the following statement: 

`make`

This will produce the executable **_project3.c_**

The program will then run through the command line with the following statement:

`./project3 inputFile`

Here, _inputFile_ is the name of an input file (such as words56.txt).

## Code Specifications

**_project3.c_** handles all of the main logic for the program, and user input and output.
The **_project3.c_** file utilizes **_stack.c_** and **_queue.c_**. 

Note that the **_types.h_** file defines the following types:
* _BOOL_ – represents a boolean type, with true/false values
* _WORD_NODE_ – used in **_project3.c_** to represent a node in a graph
* _LIST_NODE_ – used by stack and queue to represent a node in a linked data
structure whose data is a pointer to a WORD_NODE.

# shortest-path-between-words

## About
This program finds the shortest "path" between two words entered as input by the user. In the path, two words can be connected if they are the same length and they contain exactly the same characters in the same positions except for one. For example, _“cat”_ and _“car”_ can be connected since they only differ by the 3rd letter. On the other hand, _“art”_ and _“arts”_ are not connected since they are not the same length. _“vein”_ and _“vine”_ are not connected even though they contain the same letters, as their letters differ in three different positions. 

Here is an example output of the program: 

<img width="265" alt="Screen Shot 2023-08-15 at 11 43 35 AM" src="https://github.com/emmalu00/shortest-path-between-words/assets/106994328/c2e4168a-a8b5-4cc2-a7c7-879b6b6d7992">

## Running the Program
The program must be compiled through the command line with the following statement:

`make`

This will produce the executable for **_shortestpath.c_**

The program must then be run through the command line with the following statement:

`./shortestpath <inputFileName.txt>`

where **_inputFileName.txt_** is the input text file. If the user does not enter a filename as a command line argument, the program will produce an error message and exit.

The file **_words56.txt_** is provided as an example test file for running this program, containing over 8000 words, with each word on a separate line. All input files should be formatted exactly as **_words56.txt_**. 


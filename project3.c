/*
* Author: Emma Lucas
* project3.c
* This file reads in the text file. The user is prompted to enter 
* a start word and stop word, and the program finds the shortest 
* path from start to stop, changing one letter at a time.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include "types.h"
#include "stack.h"
#include "queue.h"

//the list of all words
WORD_NODE** _nodelist;

//the adjacency matrix for the graph
BOOL** _adj;

//the number of words stored
int _numwords;

WORD_NODE* get_word(char* word);
void build_adj(WORD_NODE* n);
int countDiff(WORD_NODE* n1, WORD_NODE* n2);
BOOL bfs(WORD_NODE* start, WORD_NODE* stop);
void print_results(WORD_NODE* start, WORD_NODE* stop);

int main(int argc, char* argv[]) 
{
    if (argc != 2)
    {
        printf("Proper command line arguments were not supplied.");
        return 1;
    }
    FILE* in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("File not found.");
        return 1;
    }
    char buffer[30];
    fscanf(in, "%d\n", &_numwords);
    //read in words from the file and store them in _nodelist
    _nodelist = malloc(_numwords*sizeof(WORD_NODE*));
    int i = 0;
    while(fgets(buffer, 30, in) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        _nodelist[i] = malloc(sizeof(WORD_NODE));
        strcpy((_nodelist[i])->word, buffer);
        _nodelist[i]->len = strlen(buffer);
        _nodelist[i]->index = i;
        i++;
    }
    fclose(in);
    //constructing adjacency matrix
    _adj = (BOOL**)malloc(_numwords*sizeof(BOOL*));
    for (int i = 0; i < _numwords; i++)
    {
        _adj[i] = (BOOL*)malloc(_numwords*sizeof(BOOL));
    }
    //building adjacency matrix
    for (int i = 0; i < _numwords; i++)
    {
        build_adj(_nodelist[i]);
    }

    int result = 0;
    while (result == 0)
    {
        printf("Enter start word: ");
        fgets(buffer, 30, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        WORD_NODE* startword = get_word(strtok(buffer, " "));
        printf("Enter stop word: ");
        fgets(buffer, 30, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        WORD_NODE* stopword = get_word(strtok(buffer, " "));
        //BOOL testing = bfs(startword, stopword);
        if (startword == NULL || stopword == NULL)
        {
            printf("Invalid input.\n");
            if (startword == NULL)
            {
                printf("Start word was not found.\n");
            }
            if (stopword == NULL)
            {
                printf("Stop word was not found.\n");
            }
        }
        else
        {
            if (bfs(startword, stopword) == true)
            {
                print_results(startword, stopword);
            }
            else
            {
                printf("Path not found.");
            }
        }

        printf("\n\n");

        printf("Would you like to play again? (y/n): ");
        fgets(buffer, 30, stdin);
        buffer[1] = '\0';
        if (strcmp(&buffer[0], "y") == 0 || strcmp(&buffer[0], "Y") == 0)
        {
            result = 0;
        }
        else 
        {
            result = 1;
        }
    }
    for (int i = 0; i < _numwords; ++i)
    {
        free(_nodelist[i]);
    }
    free(_nodelist);
    return 0;
}

/*
* Finds the WORD_NODE in _nodelist whose word field matches the word parameter
*
* word: word to search for in the _nodelist
* 
* returns WORD_NODE in _nodelist whose word field matches the word parameter,
* or NULL if not found
*/
WORD_NODE* get_word(char* word) 
{ 
    for (int i = 0; i < _numwords; i++)
    {
        if (strcmp(word, _nodelist[i]->word) == 0)
        {
            return _nodelist[i];
        }
    }
    return NULL;
}

/*
* Initializes column n->index in the _adj 2D array. Each _adj[i][n->index] is true
* if _nodelist[i]->word and n->word differ by exactly one letter, false otherwise.
*
* n: WORD_NODE to compare to
*/
void build_adj(WORD_NODE* n) 
{
    for (int i = 0; i < _numwords; ++i)
    {
        if (countDiff(_nodelist[i], n) == 1)
        {
            _adj[i][n->index] = true;
        }
        else
        {
            _adj[i][n->index] = false;
        }
    }
}

/*
* Counts the letter differences in two words
*
* n1: WORD_NODE* to compare word parameter
* n2: WORD_NODE* to compare word parameter
* 
* returns number of differences between two words, or -1 if words are unequal lengths
*/
int countDiff(WORD_NODE* n1, WORD_NODE* n2)
{
    int count = 0;
    if (n1->len != n2->len)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < (n2->len); ++i)
        {
            if (n1->word[i] != n2->word[i])
            {
                count++;
            }
        }
    }
    return count;
}

/*
* Uses breadth-first search to find the shortest path from start to stop
*
* start: WORD_NODE* to start at
* stop: WORD_NODE* to stop at
* 
* returns whether a path was found
*/
BOOL bfs(WORD_NODE* start, WORD_NODE* stop) 
{
    for (int i = 0; i < _numwords; i++)
    {
        _nodelist[i]->visited = false;
        
    }
    LIST_NODE* qHead = NULL;  
    LIST_NODE* qTail = NULL;
    start->visited = true;
    enqueue(&qHead, &qTail, start);
    while (qHead != NULL)
    {
        WORD_NODE* cur = dequeue(&qHead, &qTail);
        if (cur == stop)
        { 
            return true; 
        }
        else
        {
            for(int i = 0; i < _numwords; i++)
            {   
        
                if(_adj[cur->index][i] == true && _nodelist[i]->visited == false)
                {
                        _nodelist[i]->visited = true;
                        _nodelist[i]->prev = cur;
                        enqueue(&qHead, &qTail, _nodelist[i]);
                }
            }
        }
    }
    return false;
}

/*
* Uses a stack to print the words in the shortest path from start->word to stop->word
*
* start: WORD_NODE* to start at
* stop: WORD_NODE* to stop at
*/
void print_results(WORD_NODE* start, WORD_NODE* stop) 
{
    LIST_NODE* top = NULL;
    for (WORD_NODE* cur = stop; cur != start; cur = cur->prev)
    {
        push(&top, cur);
    }
    push(&top, start);

    printf("\nShortest path from %s to %s: \n", start->word, stop->word);
    while (top != NULL)
    {
        printf("%s\n", pop(&top)->word);
    }
}
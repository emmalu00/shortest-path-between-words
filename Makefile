CC=gcc
CFLAGS=-g -Wall
EXE=shortestpath
HEADERS=types.h queue.h stack.h
CODE=queue.c stack.c shortestpath.c

OBJECTS = $(CODE:.c=.o)

shortestpath: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

clean: 
	rm -f *.o *.exe *.out
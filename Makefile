CC=gcc
CFLAGS=-g -Wall
EXE=project3
HEADERS=types.h queue.h stack.h
CODE=queue.c stack.c project3.c

OBJECTS = $(CODE:.c=.o)

project3: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

clean: 
	rm -f *.o *.exe *.out
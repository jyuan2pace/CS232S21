UNAME_S := $(shell uname -s)
CC=gcc
LD=gcc
CFLAGS=-ggdb -Wall -std=c99
LDFLAGS=

ifeq ($(UNAME_S), Darwin)
    MEMCHECK=valgrind --tool=memcheck --leak-check=full --track-origins=yes --dsymutil=yes --suppressions=osx_vector.supp
endif

ifeq ($(UNAME_S), Linux)
    MEMCHECK=valgrind --tool=memcheck --leak-check=full --track-origins=yes
endif

VECTOR_OBJS=vector.o main.o asciimation.o frame.o 
VECTOR_PROG=asciimation

BINARIES=$(VECTOR_PROG)

all: $(BINARIES)

$(VECTOR_PROG): $(VECTOR_OBJS)
	$(LD) -o $(VECTOR_PROG) $(VECTOR_OBJS) $(LDFLAGS)

.c.o:
	$(CC) -c -pedantic $(CFLAGS) $<

vector-memcheck: $(VECTOR_PROG)
	$(MEMCHECK) ./$(VECTOR_PROG)

clean: 
	-rm -rf core *.o *~ "#"*"#" Makefile.bak $(BINARIES) *.dSYM
        
vector.c: vector.h
main.c: vector.h


UNAME_S := $(shell uname -s)
CC=gcc
LD=gcc
CFLAGS=-ggdb -Wall -std=c11
LDFLAGS=

ifeq ($(UNAME_S), Darwin)
    MEMCHECK=valgrind --tool=memcheck --leak-check=full --track-origins=yes --dsymutil=yes --suppressions=osx_vector.supp
endif

ifeq ($(UNAME_S), Linux)
    MEMCHECK=valgrind --tool=memcheck --leak-check=full --track-origins=yes
endif

MYSTRING_OBJS=mystring.o mystring-test.o
MYSTRING_PROG=mystring-test

BINARIES=$(MYSTRING_PROG)

all: $(BINARIES)

$(MYSTRING_PROG): $(MYSTRING_OBJS)
	$(LD) -o $(MYSTRING_PROG) $(MYSTRING_OBJS) $(LDFLAGS)

.c.o:
	$(CC) -c -pedantic $(CFLAGS) $<

mystring-memcheck: $(MYSTRING_PROG)
	$(MEMCHECK) ./$(MYSTRING_PROG)

clean: 
	-rm -rf core *.o *~ "#"*"#" Makefile.bak $(BINARIES) *.dSYM
        
mystring.c: mystring.h
mystring-test.c: mystring.h


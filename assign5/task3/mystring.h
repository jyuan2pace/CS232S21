#ifndef MYSTRING_H_CS232
#define MYSTRING_H_CS232
#include <sys/types.h>

typedef struct mystring_t mystring_t;

/*
 *  Next, we provide the prototypes for the functions defined in mystring.c.  This
 *  is a way of telling the .c files that #include this header what they will
 *  have access to.
 */

/* Create a new string */
mystring_t *mystring_new();

/* return the length of chars in string */
int mystring_get_len();

/* return the char array in string */
char * mystring_get_data();

/* Free up the memory allocated for the passed string */
void mystring_delete(mystring_t *v);

/* Return the char in the mystring */
char mystring_get(mystring_t *v, size_t loc);

/* Set a value in the string */
void mystring_set(mystring_t *v, size_t loc, char value);

/* concatenate a char array to mystring */
void mystring_cat(mystring_t *v, char * str);
#endif

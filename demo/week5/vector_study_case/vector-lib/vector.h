#include <stdio.h>
#include <stdlib.h>
//interface
typedef struct vector vector_t;
vector_t * vector_new();
void vector_delete(vector_t *);
void vector_set(vector_t*,  int loc,  int val);
int vector_get(vector_t *, int loc);



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct snode {
  //TODO: change str to dynamic allcoation
  char str[101];
  int length;
  struct snode *next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s, int length) ; 
void snode_destroy(struct snode * s) ;
 

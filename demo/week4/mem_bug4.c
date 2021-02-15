#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int * a; //array of ints
  int size; //of this size
} mytype_t;

mytype_t ** allocate(int n){
  mytype_t ** mytypes;
  int i,j;

  mytypes = malloc(sizeof(mytype_t*)*n);
  for(i=0;i<n;i++){
    mytypes[i] = malloc(sizeof(mytype_t));

    mytypes[i]->a = malloc(sizeof(int)*(i+1));

    for(j=0;j<i+1;j++){
      mytypes[i]->a[j] = j*10;
    }

    mytypes[i]->size = i;
  }

  return mytypes;
}

void deallocate(mytype_t ** mytypes){

  /*Complete me*/
 for(i 0 to n-1) {
    free(mytypes[i]->a);
    free(mytypes[i]);
 } 
}

int main(){
  int i,j;
  mytype_t ** mytypes;

  mytypes = allocate(10);


  for(i=0;i<10;i++){
    printf("mytpyes[%d] = [",i);
    for(j=0;j<mytypes[i]->size;j++){
      printf(" %d", mytypes[i]->a[j]);
    }
    printf(" ]\n");
  }

  deallocate(mytypes);
}
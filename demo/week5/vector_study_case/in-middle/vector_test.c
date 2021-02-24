#include <stdio.h>
#include <stdlib.h>
//interface
typedef struct vector {
   int size;
   int * data; //point to an array
} vector_t;
vector_t * vector_new();
void vector_delete(vector_t *);
void vector_set(vector_t*,  int loc,  int val);
int vector_get(vector_t *, int loc);
//interface
int main(int argc, char **argv) {
	vector_t *v;
	
	printf("Calling vector_new()\n");
	v = vector_new();
	
	printf("Calling vector_delete()\n");
	vector_delete(v);
	
	printf("vector_new() again\n");
	v = vector_new();

	printf("These should all return 0 (vector_get()): ");
	printf("%d ", vector_get(v, 0));
	printf("%d ", vector_get(v, 1));
	printf("%d\n", vector_get(v, 2));

	printf("Doing a bunch of vector_set()s\n");
	vector_set(v, 0, 98);
	vector_set(v, 11, 15);
	vector_set(v, 15, -23);
	vector_set(v, 24, 65);
        vector_set(v, 500, 3);
	vector_set(v, 12, -123);
	vector_set(v, 15, 21);
	vector_set(v, 25, 43);

	printf("These should be equal:\n");
	printf("98 = %d\n", vector_get(v, 0));
	printf("15 = %d\n", vector_get(v, 11));
	printf("65 = %d\n", vector_get(v, 24));
	printf("-123 = %d\n", vector_get(v, 12));
	printf("21 = %d\n", vector_get(v, 15));
	printf("43 = %d\n", vector_get(v, 25));
    printf("0 = %d\n", vector_get(v, 23));
    printf("0 = %d\n", vector_get(v, 1));
    printf("0 = %d\n", vector_get(v, 501));
    printf("3 = %d\n", vector_get(v, 500));

    vector_delete(v);

	printf("Test complete.\n");
	
	return 0;
}

//size=1 and data points to one integer array on the heap
//bad new:
// stack                 |    heap
//  ret--|               |
//       v               |
//  v: |size 1|          |
//     |data -|---+----> |[0]

// good new:
// stack                 |    heap
//  ret------------------+--> |size: 1|
//                       |    |data --]+------
//                       |                   |
//                       |    +---------------
//                       |    |
//                       |    --->[0]
vector_t * vector_new(){
	vector_t * ret = (vector_t*) malloc(sizeof(vector_t));
	if(ret == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}
	ret->size = 1;
	ret->data = (int *) malloc(sizeof(int));
	if(ret->data == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}

	ret->data[0]=0;
	return ret;

}
void vector_delete(vector_t * v){
 free(v->data);
 free(v);
}

// before vector_set(5,99) 
// stack                 |        heap
//  ret------------------+------> |size: 3|
//                       |        |data --]+--
//                       |                   |
//                       |        ------------
//                       |        |
//                       |        ->[0|1|2]


void vector_set(vector_t* v,  int loc,  int val){
	if(loc<v->size && loc>=0) {
   	    v->data[loc] = val;
   	} else {
 //what if vector_set(5, 99), then above diagram will transform into the 
 //following diagram:	
 	    v->data = (int *) realloc(v->data, sizeof(int)*(loc+1));
	    for(int i= v->size; i<loc+1; i++)
		v->data[i] = 0;
 	    v->data[loc] = val;
	    v->size = loc+1; //what happens if we forget to update size?
	}	

}
// 
// stack                 |        heap
//  ret------------------+------> |size: 6|   //size should be updated to loc+1
//                       |        |data --]+--
//                       |                   |
//                       |        +-----------
//                       |        |
//                       |        ->[0|1|2|0|0|99]


int vector_get(vector_t *v, int loc){
   if(loc<v->size && loc>=0) {
   	return  v->data[loc];
   } else {
  	perror("blahblah");
       return 0;	
   }
}



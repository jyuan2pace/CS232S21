#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
    
   return head;
}

void teardown(/*what parameter?*/) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(/*what argument?*/);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}

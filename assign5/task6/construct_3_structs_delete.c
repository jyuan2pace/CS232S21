#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from previous task
}

void teardown(/*what parameter?*/) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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

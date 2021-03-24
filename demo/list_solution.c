#include "list.h"

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
//** head_ptr == pointer that stores the addresss of head pointer, which stores the address of first node in LL.
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	/* YOUR CODE HERE */
	struct node * new_node = (node*)malloc(sizeof (struct node));
	new_node->val = new_data;//put in data
	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		/* YOUR CODE HERE */
		*head_ptr = new_node;
		return;
	}
	node* curr = *head_ptr; //curr now stores org_head's @
	while (curr->next != NULL) {  //
		curr = curr->next;
	}
	//curr now points to the last node in LL
	curr->next = new_node;
	new_node->next = NULL;
	/* Insert node at the end of the list */
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	node* prev = NULL;
	node* curr = *head_ptr;
	node* next = NULL;
	while (curr != NULL) {
		/* INSERT CODE HERE */
		//store
		next = curr->next;
		//advance all pointers
		curr->next = prev;
		prev = curr;
		curr = next;

	}
	/* Set the new head to be what originally was the last node in the list */
	*head_ptr = prev;
}

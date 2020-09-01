
/*
	Code for doubly linked list
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
	
	struct Node *prev;
	int cargo;
	struct Node *next;
	
};


struct Node *start = NULL;

struct Node *display (struct Node *parentNode) {
	
	struct Node *ptr = parentNode;
	
	while (ptr) {
		printf ("\n Cargo = %d, Current = %p, Prev = %p and Next = %p", ptr->cargo, ptr, ptr->prev, ptr->next);
		ptr = ptr->next;
	}
	
	return start;
}

struct Node *insert (struct Node *start, int cargo) {
	
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	
	if (start == NULL) {
		node->prev = NULL;
		node->next = NULL;
		start = node;
	}
	
	else {
		struct Node *ptr = start;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		
		node->prev = ptr;
		node->next = NULL;
		ptr->next = node;
		
	}
	
	return start;
	
}


int main (int argc, char *argv[]) {
	for (int i = 0;i < 5;i ++) {
		start = insert (start, i);
	}
	
	start = display (start);
	
	return 0;
}

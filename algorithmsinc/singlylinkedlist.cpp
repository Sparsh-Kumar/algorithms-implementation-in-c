/*
	Code for singly linked list
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
	
	int cargo;
	struct Node *next;
	
};

struct Node *start = NULL;

struct Node *display (struct Node *parentNode) {
	
	struct Node *ptr = parentNode;
	while (ptr) {
		printf ("\n Cargo = %d ", ptr->cargo);
		ptr = ptr->next;
	}
	
	return start;
}



struct Node *insert (int cargo) {

	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	node->next = NULL;
	
	
	if (start == NULL) {
		start = node;
	}
	else {
		
		struct Node *ptr = start;
		while (ptr->next) {
			ptr = ptr->next;
		}
		
		ptr->next = node;
	}
	
	return start;
}


int main (int argc, char *argv[]) {
	for (int i = 0;i < 5;i++) {
		start = insert (i);
	}
	
	start = display (start);
}


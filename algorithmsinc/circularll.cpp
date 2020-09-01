/*
	Code for circular linked list
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
	while (ptr->next != start) {
		printf ("\n Cargo = %d, Current = %p and Next = %p", ptr->cargo, ptr, ptr->next);
		ptr = ptr->next;
	}
	
	printf ("\n Cargo = %d, Current = %p and Next = %p", ptr->cargo, ptr, ptr->next);
	return start;
}

struct Node *insert (struct Node *start, int cargo) {
	
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	
	if (start == NULL) {
		
		start = node;
		node->next = start;
		
	}
	
	else {
		
		struct Node *ptr = start;
		while (ptr->next != start) {
			ptr = ptr->next;
		}
		
		ptr->next = node;
		node->next = start;
		
	}
	
	return start;
	
}


int main (int argc, char *argv[]) {
	
	for (int index = 0;index < 10;index = index + 1) {
		start = insert (start, index);
	}
	
	start = display (start);
	return 0;
}

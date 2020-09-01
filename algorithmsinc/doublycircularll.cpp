
/*
	Code for doubly circular linked list
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
	while (ptr->next != start) {
		printf ("\n Cargo = %d, Current = %p, Prev = %p, Next = %p", ptr->cargo, ptr, ptr->prev, ptr->next);
		ptr = ptr ->next;
	}
	
	printf ("\n Cargo = %d, Current = %p, Prev = %p, Next = %p", ptr->cargo, ptr, ptr->prev, ptr->next);
	return start;
}

struct Node *insert (struct Node *start, int cargo) {
	
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	
	if (start == NULL) {
		
		start = node;
		node->prev = start;
		node->next = start;
		
	}
	
	else {
		struct Node *ptr = start;
		while (ptr->next != start) {
			ptr = ptr->next;
		}
		
		node->prev = ptr;
		node->next = start;
		ptr->next = node;
		start->prev = node;
		
	}
	
	return start;
}

int main (int argc, char *argv[]) {
	
	for (int i = 0;i < 6;i++) {
		start = insert (start, i);
	}
	
	start = display (start);
	return 0;
}

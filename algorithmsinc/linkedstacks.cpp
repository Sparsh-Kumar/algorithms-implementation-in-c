#include <stdio.h>
#include <stdlib.h>

struct Node {
	int cargo;
	struct Node *next;
};

struct Node *top = NULL;

struct Node *push (int cargo) {
	struct Node *item = (struct Node *)(malloc (sizeof (struct Node)));
	item->cargo = cargo;
	item->next = NULL;
	if (!top) {
		top = item;
	}
	else {
		struct Node *start = top;
		item->next = start;
		top = item;
	}
	return top;
}

struct Node *displayStack (struct Node *stackTop) {
	struct Node *start = stackTop;
	while (stackTop) {
		printf ("\n Cargo = %d",stackTop->cargo);
		stackTop = stackTop->next;
	}
	return stackTop;
}

struct Node *pop () {
	struct Node *item = top;
	top = top->next;
	return item;
}

int main (int argc, char *argv[]) {
	for (int i = 0;i < 4;i++) {
		top = push (i + 1);
	}
	displayStack (top);
	struct Node *poppedItem = pop ();
	printf ("\n Popped item = %d",poppedItem->cargo);
	displayStack (top);
	return 0;
}

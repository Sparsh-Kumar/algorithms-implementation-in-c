

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int cargo;
	int priority;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
unsigned int queuelength = 0;

struct Node *insert (int cargo = 0, int priority = 0) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	node->priority = priority;

	if (!front|| front->priority >= node->priority) {
		node->next = front;
		front = node;
	}

	else {
		struct Node *startNode = front;
		while (startNode->next && startNode->next->priority <= node->priority) {
			startNode = startNode->next;
		}
		node->next = startNode->next;
		startNode->next = node;
	}

	queuelength = queuelength + 1;
	return front;
}

struct Node *remove (struct Node *startNode = front) {
	struct Node *node = NULL;
	if (front) {
		node = front;
		front = front->next;
		queuelength = queuelength - 1;
	}
	return node;
}

int Queuelength () {
	return queuelength;
}

struct Node *display (struct Node *node = front) {
	struct Node *startNode = node;
	while (startNode) {
		printf ("\n Cargo = %d, Priority = %d",startNode->cargo, startNode->priority);
		startNode = startNode->next;
	}
	return node;
}

int main (int argc, char *argv []) {
	front = insert (23, 4);
	front = insert (22, 3);
	front = insert (23, 9);
	front = insert (27, 2);
	front = insert (87, 6);
	front = insert (123, -2);

	printf ("\n Length of the priority queue is %d",Queuelength ());
	front = display (front);

	printf ("\n Removing two values from the priority queue");
	for (int i = 0;i < 2;i++) {
		struct Node *poppedNode = remove ();
		printf ("\n Popped Node = %d Priority = %d", poppedNode->cargo, poppedNode->priority);
	}

	printf ("\n Length of the priority queue is %d",Queuelength ());
	printf ("\n Displaying the Priority Queue");
	front = display (front);
	return 0;
}
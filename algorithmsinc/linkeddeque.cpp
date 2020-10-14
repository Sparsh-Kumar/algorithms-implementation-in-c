

/*
	Implementation of Deque using doubly linked list
	Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.
	enqueue (push) an item at the rear or the front end of deque and dequeue(pop) an item from both rear and front end.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	struct Node *prev;
	int cargo;
	struct Node *next;
};

struct Queue {
	struct Node *front;
	struct Node *rear;
};

struct Queue *q;

struct Queue *createDeQ (struct Queue *q) {
	q = (struct Queue *)(malloc (sizeof (struct Queue)));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

struct Queue *insertfront (struct Queue *q, int cargo) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->prev = NULL;
	node->cargo = cargo;
	node->next = NULL;
	if (!q->front || !q->rear) {
		q->front = node;
		q->rear = node;
	}
	else {
		struct Node *currentNode = q->front;
		node->next = currentNode;
		currentNode->prev = node;
		q->front = node;
	}
	return q;
}

struct Node *removefront (struct Queue *q) {
	struct Node *node = NULL;
	if (q->front && q->rear) {
		node = q->front;
		q->front = q->front->next;
		q->front->prev = NULL;
		node->next = NULL;
	}
	return node;
}

struct Queue *insertrear (struct Queue *q, int cargo) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->prev = NULL;
	node->cargo = cargo;
	node->next = NULL;
	if (!q->front || !q->rear) {
		q->front = node;
		q->rear = node;
	}
	else {
		q->rear->next = node;
		node->prev = q->rear;
		q->rear = node;
	}
	return q;
}

struct Node *removerear (struct Queue *q) {
	struct Node *node = NULL;
	if (q->front && q->rear) {
		node = q->rear;
		q->rear = q->rear->prev;
		q->rear->next = NULL;
		node->prev = NULL;
	}
	return node;
}

struct Queue *displayDequeQ (struct Queue *q) {
	struct Node *front = q->front;
	struct Node *rear = q->rear;
	while (front != rear) {
		printf ("\nprev = %2x, current = %2x, cargo = %d, next = %2x",front->prev, front, front->cargo, front->next);
		front = front->next;
	}
	printf ("\nprev = %2x, current = %2x, cargo = %d, next = %2x",front->prev, front, front->cargo, front->next);
	return q;
}

int main (int argc, char *argv []) {
	q = createDeQ (q);
	q = insertfront (q, 1);
	q = insertfront (q, 2);
	q = insertfront (q, 3);
	q = insertrear (q, 4);	
	q = insertrear (q, 6);
	q = displayDequeQ (q);
	printf ("\nRemoving from the front");
	struct Node *node1 = removefront (q);
	printf ("\nremoved node having cargo = %d",node1->cargo);
	q = displayDequeQ (q);
	printf ("\nRemoving from the rear");
	struct Node *node2 = removerear (q);
	printf ("\nremoved node having cargo = %d",node2->cargo);
	q = displayDequeQ (q);
	printf ("\nRemoving from the rear again");
	struct Node *node3 = removerear (q);
	printf ("\nremoved node having cargo = %d",node3->cargo);
	q = displayDequeQ (q);
	return 0;
}
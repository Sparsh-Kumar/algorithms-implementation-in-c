

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int cargo;
	struct Node *next;
};

struct Queue {
	struct Node *front;
	struct Node *rear;
};

struct Queue *queue;

struct Queue *createQ (struct Queue *q) {
	q = (struct Queue *)(malloc (sizeof (struct Queue)));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

struct Queue *insert (struct Queue *q, int cargo) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	node->next = NULL;
	if (!q->front || !q->rear) {
		q->front = node; /* Setting front node and rear node to the same node*/
		q->rear = node;
	}
	else {
		q->rear->next = node; /*setting node to the rear->next value thus incrementing another node in the queue*/
		q->rear = q->rear->next; /*resetting the q->rear to the last inserted node*/
	}
	return q;
}

/*In linked queue insertion takes place from rear node and deletion takes place from front node*/

struct Node *remove (struct Queue *q) {
	struct Node *node = NULL;
	if (q->front) {
		node = q->front;
		q->front = q->front->next;
	}
	return node;
}

struct Queue *display (struct Queue *queue) {
	struct Node *front = queue->front;
	struct Node *rear = queue->rear;
	while (front != rear->next) { /*as rear->next = NULL*/
		printf ("\nCargo=%d",front->cargo);
		front = front->next;
	}
	return queue;
}

int main (int argc, char *argv[]) {
	queue = createQ (queue);
	for (int i = 0;i < 4;i++) {
		queue = insert (queue,i);
	}
	queue = display (queue);
	struct Node *node = remove (queue);
	//printf ("\nRemovedNode = %d, %p",node->cargo,node->next);
	queue = display (queue);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 6
int data [MAX_LENGTH];

int front = -1,rear = -1;

int insert (int cargo) {
	/*
		if the first item is being inserted
	*/
	if ((front == -1) || (rear == -1)) {
		front++;
		rear++;		
	}
	
	/*
		then it means that the queue is full
	*/
	else if ((front == 0) && (rear == MAX_LENGTH - 1)) {
		return -1;
	}
	
	/*
		this is the case when the queue has some free space in the beginning
	*/
	else if ((front != 0) && (rear == MAX_LENGTH - 1)) {
		rear = 0;
	}

	/*
		otherwise just increment the rear pointer (sort of)
	*/
	else {
		rear++;
	}
	data [rear] = cargo;
	return 0;
}

int remove () {
	/*
		checking for underflow condition
	*/
	if ((front == -1) || (rear == -1)) {
		printf ("\n Underflow condition")	;
		return -1;
	}

	int value = data [front];

	/*
		this is the condition in which we continously delete until front comes to rear
	*/
	if ((front == rear)) {
		front = rear = -1;
	}

	/*
		checking if the front == MAX_LENGTH - 1
	*/
	else if ((front == MAX_LENGTH - 1)) {
		printf ("\n Cond 2");
		front = 0;
	}

	/*
		otherwise just get value and increment front
	*/
	else {
		front++;
	}
	return value;
}

int display () {
	for (int i = 0;i < MAX_LENGTH;i++) {
		printf ("\nCargo = %d",data [i]);
	}
	return 0;
}

int main (int argc, char *argv[]) {
	/*
		inserting the elements
	*/
	for (int i = 0;i < 3;i++) {
		if (insert (i * 4) == -1) {
			break;
		}
	}
	/*
		displaying the queue
	*/
	display ();
	remove ();
	remove ();
	remove ();
	printf ("\n front = %d, rear = %d",front, rear);
	remove ();
	return 0;
}

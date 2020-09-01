
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
	int cargo;
	struct Node *next;
};

struct Node *top = NULL;

struct Node *push (int cargo) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	node->next = NULL;
	if (!top) {
		top = node;
	}
	else {
		struct Node *start = top;
		node->next = start;
		top = node;
	}
	return top;
}

struct Node *pop () {
	struct Node *node = NULL;
	if (top) {
		node = top;
		top = top->next;
	}
	return node;
}

struct Node *display (struct Node *parentNode) {
	struct Node *start = parentNode;
	printf ("\n");
	while (start) {
		printf ("\n%d",start->cargo);
		start = start->next;
	}
	return parentNode;
}

int evalpostfix (char exp []) {
	int result = 0;
	for (int i = 0;i < strlen (exp);i++) {
		if (isdigit (exp[i])) {
			char value = exp[i];
			push (atoi (&value));
		}
		else {
			int value1 = pop ()->cargo;
			int value2 = pop ()->cargo;
			if (exp[i] == '+') {
				push (value1 + value2);
			}
			else if (exp[i] == '-') {
				push (value1 - value2);
			}
			else if (exp[i] == '*') {
				push (value1 * value2);
			}
			else if (exp[i] == '/') {
				push (value1 / value2);
			}
			else {
				push (value2);
				push (value1);
				printf ("\noperator not recognized");
				return -1;
			}
		}
	}
	result = pop ()->cargo;
	return result;
}

int main (int argc, char *argv[]) {
	char exp [] = {"23-6+"};
	int result = evalpostfix (exp);
	if (result == -1) {
		printf ("\nerror");
	}
	else {
		printf ("\nresult = %d", result);
	}
	return 0;
}

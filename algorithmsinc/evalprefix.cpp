
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int cargo;
	struct Node *next;
};

struct Node *stacktop = NULL;

struct Node *push (int cargo) {
	struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
	node->cargo = cargo;
	node->next = NULL;
	if (!stacktop) {
		stacktop = node;
	}
	else {
		struct Node *start = stacktop;
		node->next = start;
		stacktop = node;
	}
	return stacktop;
}

struct Node *pop () {
	struct Node *node = NULL;
	if (stacktop) {
		node = stacktop;
		stacktop = stacktop->next;
	}
	return node;
}

struct Node *display (struct Node *parentNode) {
	struct Node *start = parentNode;
	printf ("\n");
	while (start) {
		printf ("%d",start->cargo);
		start = start->next;
	}
	return parentNode;
}

int CalcPrefix (char prefix []) {
	int length = strlen (prefix);
	char a;
	int number;
	for (int i = length - 1;i >=0;--i) {
		if (isdigit (prefix [i])) {
			a = prefix [i];
			number = atoi (&a);
			stacktop = push (number);
		}
		else {
			struct Node *number1 = pop ();
			struct Node *number2 = pop ();
			int result;
			if (prefix[i] == '+') {
				result = number1->cargo + number2->cargo;				
			}
			else if (prefix[i] == '-') {
				result = number1->cargo - number2->cargo;
			}
			else if (prefix[i] == '*') {
				result = number1->cargo * number2->cargo;
			}
			else if (prefix [i] == '/') {
				result = number1->cargo / number2->cargo;
			}
			stacktop = push (result);
		}
	}
	return 0;
}

int main (int argc, char *argv[]) {
	char prefix [] = {"*+23+45"};
	CalcPrefix (prefix);
	stacktop = display (stacktop);
	return 0;
}

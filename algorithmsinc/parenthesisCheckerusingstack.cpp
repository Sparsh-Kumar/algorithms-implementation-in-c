
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char cargo;;
	struct Node *next;
};

struct Node *top = NULL;

struct Node *push (char cargo) {
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

struct Node *display (struct Node *parentNode) {
	//printf ("\n ================== STACK START ==========================");
	struct Node *start = parentNode;
	while (start) {
		printf ("\n Cargo = %c", start->cargo);
		start = start->next;
	}
	//printf ("\n ================== STACK END =======================");
	return parentNode;
}

struct Node *pop () {
	struct Node *node = NULL;
	if (top) {
		node = top;
		top = top->next;
	}
	return node;
}

bool check (char *expression) {
	for (int i = 0;i < strlen (expression);i++) {
		if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) {
			top = push (expression[i]);
		}
		else if (expression[i] == ')') {
			struct Node *node = pop ();
			if (!node || node->cargo != '(') {
				return false;
			}
		}
		else if (expression[i] == ']') {
			struct Node *node = pop ();
			if (!node || node->cargo != '[') {
				return false;
			}
		}
		else if (expression[i] == '}') {
			struct Node *node = pop ();
			if (!node || node->cargo != '{') {
				return false;
			}
		}
		else {
			continue;
		}
	}
	return true;
}

int main (int argc, char *argv[]) {
	char expression [] = "{}[(1+2]*3+5]";
	if (check (expression)) {
		printf ("Valid");
	}
	else {
		printf ("Not Valid");
	}
	return 0;
}

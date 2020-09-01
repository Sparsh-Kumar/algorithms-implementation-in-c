
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char cargo;
	struct Node *next;
};

class Stack {
	private:
		struct Node *top = NULL;
	public:
		Stack () {
			top = NULL;
		}
		int push (char cargo) {
			struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
			node->cargo = cargo;
			node->next = NULL;
			if (!this->top) {
				this->top = node;
			}
			else {
				struct Node *start = this->top;
				node->next = start;
				this->top = node;
			}
			return 0;
		}
		struct Node *pop () {
			struct Node *node = NULL;
			if (this->top) {
				node = this->top;
				this->top = this->top->next;
			}
			return node;
		}
		int display () {
			struct Node *start = this->top;
			printf ("\n");
			while (start) {
				printf ("%c",start->cargo);
				start = start->next;
			}
			return 0;
		}
};

class List {
	private:
		struct Node *listNode = NULL;
	public:
		List () {
			this->listNode = NULL;
		}
		int append (char cargo) {
			struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
			node->cargo = cargo;
			node->next = NULL;
			if (!this->listNode) {
				this->listNode = node;
			}
			else {
				struct Node *start = this->listNode;
				while (start->next) {
					start = start->next;
				}
				start->next = node;
			}
			return 0;
		}
		int displaylist () {
			struct Node *start = this->listNode;
			printf("\n");
			while (start) {
				printf ("%c",start->cargo);
				start = start->next;
			}
			return 0;
		}
};

int getpref (char op) {
	if ((op == '+') || (op == '-')) {
		return 0;
	}
	else if ((op == '*') || (op == '/')){
		return 1;
	}
	else {
		return -1;
	}
}

int infixtopostfix (char expression[]) {
	Stack s1;
	List l1;
	s1.push('('); 
	for (int i = 0; i < strlen (expression);i++) {
		if (expression[i] == '(') {
			s1.push('('); 
		}
		else if (isalpha(expression[i])) {
			l1.append(expression[i]);
		}
		else if (expression[i] == ')') {
			while (true) {
				struct Node *node = s1.pop();
				if ((node->cargo == '(') || (!node)) {
					break;
				}
				else {
					l1.append (node->cargo);
				}
			}
		}
		else {
			while (true) {
				struct Node *node = s1.pop();
				if ((getpref (node->cargo) > getpref (expression[i])) || (getpref (node->cargo) == -1)) {
					s1.push(node->cargo); // as the item is already popped then if we break then stack place would be vacant so pushing again into the stack
					break; 
				}
				else {
					l1.append (node->cargo);
				}
			}
			s1.push(expression[i]); 
		}
	}
	l1.displaylist();
	return 0;
}

int main (int argc, char *argv[]) {
	List l1;
	char expression [] = {"(A+B)*(C+D))"};
	infixtopostfix (expression);
	return 0;
}	

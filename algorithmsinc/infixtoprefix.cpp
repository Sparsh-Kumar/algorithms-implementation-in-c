
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

struct Node {
	char cargo;
	struct Node *next;
};

class Stack {
	private:
		struct Node *stacktop = NULL;
	public:
		Stack () {
			this->stacktop = NULL;
		}
		int push (char cargo) {
			struct Node *node = (struct Node *)(malloc(sizeof (struct Node)));
			node->cargo = cargo;
			node->next = NULL;
			if (!this->stacktop) {
				this->stacktop = node;
			}
			else {
				struct Node *start = this->stacktop;
				node->next = start;
				this->stacktop = node;
			}
			return 0;
		}
	
		struct Node *pop () {
			struct Node *node = NULL;
			if (this->stacktop) {
				node = this->stacktop;
				this->stacktop = this->stacktop->next;
			}
			return node;
		}
	
		int display () {
			struct Node *node = this->stacktop;
			printf ("\n");
			while (node) {
				printf("%c",node->cargo);
				node = node->next;
			}
			return 0;
		}
};

class List {
	private:
		struct Node *listtop = NULL;
	public:
		List () {
			this->listtop = NULL;
		}
		int append (char cargo) {
			struct Node *node = (struct Node *)(malloc (sizeof (struct Node)));
			node->cargo = cargo;
			node->next = NULL;
			if (!this->listtop) {
				this->listtop = node;
			}
			else {
				struct Node *start = this->listtop;
				while (start->next) {
					start = start->next;
				}
				start->next = node;
			}
		}
		int display () {
			struct Node *start = this->listtop;
			printf ("\n");
			while (start) {
				printf ("%c",start->cargo);
				start = start->next;
			}
			return 0;
		}
};

int getpref (char symbol) {
	if ((symbol == '+') || (symbol == '-')) {
		return 0;
	}
	else if ((symbol == '*') || (symbol == '/')) {
		return 1;
	}
	else {
		return -1;
	}
}

int infixtoprefix (char arr[]) {
	Stack s1;
	List l1;
	// Pushing ( into the stack
	s1.push('('); 
	int length = strlen(arr);
	for (int i = length; i >=0; i--) {
		if (arr[i] == ')') {
			s1.push('(');
		}
		else if (arr[i] == '(') {
			while (true) {
				struct Node *node = s1.pop();
				if (node->cargo == '(') {
					break;
				}
				else {
					l1.append(node->cargo);
				}
			}
		}
		else if (isalpha(arr[i])) {
			l1.append(arr[i]);
		}
		else {
			int a = getpref (arr[i]);
			if (a == -1) {
				continue;
			}
			else {
				while (true) {
					struct Node *node = s1.pop();
					int b = getpref (node->cargo);
					if ((b == -1) || (b > a)) {
						s1.push(node->cargo);
						break;
					}
					else {
						l1.append(node->cargo);
					}
				}
				s1.push(arr[i]);
			}
		}
	}
	// just now reverse the display you got the prefix expression
	l1.display();
	return 0;
}

int main (int argc, char *argv[]) {
	char exp [] = {"((A+B)-(C*D)"}; // Adding extra ( just for simplicity
	infixtoprefix (exp);
	return 0;
}

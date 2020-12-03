

#include <iostream>
#include <stdio.h>

using namespace std;

class Node {
	private:
		class Node *parent;
		class Node *child;
		class Node *sibling;
		int cargo;
		int identifier;
	public:

		Node () {
			this->cargo = 0;
			this->parent = NULL;
			this->child = NULL;
			this->sibling = NULL;
			this->identifier = 0;
		}
		Node (int cargo) {
			this->cargo = cargo;
			this->parent = NULL;
			this->child = NULL;
			this->sibling = NULL;
			this->identifier = 0; 
		}

		// setters
		class Node *setParent (class Node *);
		class Node *setChild (class Node *);
		class Node *setSibling (class Node *);
		class Node *setCargo (int);
		class Node *setId (int);

		// getters
		class Node *getParent ();
		class Node *getChild ();
		class Node *getSibling ();
		int getCargo ();
		int getId ();

		// show details
		class Node *getDetails ();

		~Node () { }
};

class Node *Node::setParent (class Node *parent = NULL) {
	this->parent = parent;
	return this;
}

class Node *Node::setSibling (class Node *sibling = NULL) {
	this->sibling = sibling;
	return this;
}

class Node *Node::setChild (class Node *child = NULL) {
	this->child = child;
	return this;
}

class Node *Node::setCargo (int cargo = 0) {
	this->cargo = cargo;
	return this;
}

class Node *Node::setId (int id = 0) {
	this->identifier = id;
	return this;
}

class Node *Node::getChild () {
	return this->child;
}

class Node *Node::getParent () {
	return this->parent;
}

class Node *Node::getSibling () {
	return this->sibling;
}

int Node::getCargo () {
	return this->cargo;
}

int Node::getId () {
	return this->identifier;
}

class Node *Node::getDetails () {
	printf ("\nCurrent = %p, Cargo = %d, Child = %p, Sibling = %p, Parent = %p, Id = %d", this, this->cargo, this->child, this->sibling, this->parent, this->identifier);
	return this;
}


class Tree {
	private:
		Node *rootnode;
		int identifier;
	public:
		Tree () { this->rootnode = NULL; this->identifier = 0; }

		// insertion functions
		class Node *insertChild (class Node *, int);
		class Node *insertSibling (class Node *, int);

		// display functions
		class Node *displayChild (class Node *);
		class Node *displaySibling (class Node *);
		class Node *displayTree (class Node *);

		// find node function
		class Node *findNode (class Node *, int);

		// root node functions
		class Node *getRoot ();
		class Node *setRoot (class Node *);
		~Tree () { }
};

class Node *Tree::getRoot () {
	return this->rootnode;
}

class Node *Tree::setRoot (class Node *root = NULL) {
	this->rootnode = root;
	return this->rootnode;
}

class Node *Tree::insertChild (class Node *root = NULL, int cargo = 0) {
	Node *node = new Node (cargo);
	node->setId (this->identifier);
	if (!root) {
		root = node;
	} else {
		node->setParent (root);
		if (!root->getChild ()) {
			root->setChild (node);
		} else {
			Node *firstChild = root->getChild ();
			while (firstChild->getSibling ()) {
				firstChild = firstChild->getSibling ();
			}
			firstChild->setSibling (node);
		}
	}
	this->identifier = this->identifier + 1;
	return root;
}

class Node *Tree::displayChild (class Node *root = NULL) {
	if (!root || !root->getChild ()) {
		return NULL;
	} else {
		Node *firstChild = root->getChild ();
		while (firstChild) {
			firstChild->getDetails ();
			firstChild = firstChild->getSibling ();
		}
	}
	return root;
}

class Node *Tree::insertSibling (class Node *root = NULL, int cargo = 0) {
	Node *node = new Node (cargo);
	node->setParent (root->getParent ());
	node->setId (this->identifier);
	if (!root) {
		return NULL;
	} else {
		Node *traversenode = root;
		while (traversenode->getSibling ()) {
			traversenode = traversenode->getSibling ();
		}
		traversenode->setSibling (node);
	}
	this->identifier = this->identifier + 1;
	return root;
}

class Node *Tree::displaySibling (class Node *root = NULL) {
	if (!root) {
		return NULL;
	} else {
		Node *node = root;
		while (node) {
			node->getDetails ();
			node = node->getSibling ();
		}
	}
	return root;
}

class Node *Tree::displayTree (class Node *root = NULL) {
	if (!root) {
		return NULL;
	} else {
		root->getDetails ();
		Node *firstChild = root->getChild ();
		while (firstChild) {
			this->displayTree (firstChild);
			firstChild = firstChild->getSibling ();
		}
	}
	return root;
}

class Node *Tree::findNode (class Node *root = NULL, int identifier = 0) {
	if (!root) {
		return NULL;
	} else if (identifier == 0) {
		return this->rootnode;
	} else if (root->getId () == identifier) {
		return root;
	}
	else {
		Node *firstChild = root->getChild ();
		while (firstChild) {
			if (firstChild->getId () == identifier) {
				return firstChild;
			}
			firstChild = this->findNode (firstChild, identifier);
			if ((firstChild) && (firstChild->getId () == identifier)) {
				return firstChild;
			}
			if (firstChild) {
				firstChild = firstChild->getSibling ();
			}
		}
	}
	return root;
}

int main (int argc, char *argv []) {
	Tree *tree = new Tree ();
	tree->setRoot (tree->insertChild (tree->getRoot(), 123));
	tree->setRoot (tree->insertChild (tree->getRoot (), 4223));
	tree->setRoot (tree->insertChild (tree->getRoot (), 345));
	tree->setRoot (tree->insertChild (tree->getRoot (), 213));
	Node *node = tree->findNode (tree->getRoot (), 2);
	node = tree->insertChild (node, 890);
	node = tree->insertChild (node, 908);
	node = tree->insertSibling (node, 789);
	node = tree->findNode (tree->getRoot (), 5);
	node = tree->insertChild (node, 67);
	node = tree->insertChild (node, 89);
	node = tree->insertSibling (node, 987);
	tree->setRoot (tree->displayTree (tree->getRoot ()));
	cout<<"\nfinding the node\n";
	node = tree->findNode (tree->getRoot (), 9);
	node->getDetails ();
	return 0;
}
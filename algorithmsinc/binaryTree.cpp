

#include <iostream>
using namespace std;

// defining the defination of 1 Node in a Binary Tree

class Node {
    
    private:

        int cargo;
        class Node *leftNode;
        class Node *rightNode;
        class Node *parentNode;
        int id;

    public:

        Node () {
            this->cargo = 0;
            this->id = 0;
            this->leftNode = NULL;
            this->rightNode = NULL;
            this->parentNode = NULL;
        }

        Node (int cargo, class Node *leftNode, class Node *rightNode) {
            this->cargo = cargo;
            this->leftNode = leftNode;
            this->rightNode = rightNode;
        }

        int setId (int id = 0);
        int getId ();

        int getCargo ();
        int setCargo (int cargo = 0);
        
        class Node *getLeftNode ();
        class Node *getRightNode ();
        class Node *getParentNode ();

        class Node *setLeftNode (class Node *leftNode = NULL);
        class Node *setRightNode (class Node *rightNode = NULL);
        class Node *setParentNode (class Node *parentNode = NULL);

        ~Node () {}
};

class Node *Node::getLeftNode () {
    return this->leftNode;
}

class Node *Node::getRightNode () {
    return this->rightNode;
}

class Node *Node::setLeftNode (class Node *leftNode = NULL) {
    this->leftNode = leftNode;
}

class Node *Node::setRightNode (class Node *rightNode = NULL) {
    this->rightNode = rightNode;
}

class Node *Node::getParentNode () {
    return this->parentNode;
}

class Node *Node::setParentNode (class Node *parentNode = NULL) {
    this->parentNode = parentNode;
}

int Node::setCargo (int cargo = 0) {
    this->cargo = cargo;
}

int Node::getCargo () {
    return this->cargo;
}

int Node::setId (int id = 0) {
    this->id = id;
}

int Node::getId () {
    return this->id;
}

// defining the Binary Tree  structure

class BinaryTree {
    
    private:
        class Node *rootNode;
    public:
        
        BinaryTree () {
            this->rootNode = NULL;
        }

        class Node *getRootNode ();
        class Node *setRootNode ();
        class Node *insertLeftNode (int cargo = 0, class Node *root = NULL);
        class Node *insertRightNode (int cargo = 0, class Node *root = NULL);
        int DisplayBinaryTree (class Node *rootNode = NULL);
        class Node *findNode (class Node *rootNode = NULL);
        ~BinaryTree () {}
};


int main (int argc, char *argv []) {
    return 0;
}
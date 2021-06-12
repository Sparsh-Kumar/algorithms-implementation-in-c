

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

        Node (int cargo, class Node *leftNode, class Node *rightNode, class Node *parentNode, int id) {
            this->cargo = cargo;
            this->leftNode = leftNode;
            this->rightNode = rightNode;
            this->parentNode = parentNode;
            this->id = id;
        }

        int setId (int id);
        int getId ();

        int getCargo ();
        int setCargo (int cargo);
        
        class Node *getLeftNode ();
        class Node *getRightNode ();
        class Node *getParentNode ();

        class Node *setLeftNode (class Node *leftNode);
        class Node *setRightNode (class Node *rightNode);
        class Node *setParentNode (class Node *parentNode);

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
    return this->leftNode;
}

class Node *Node::setRightNode (class Node *rightNode = NULL) {
    this->rightNode = rightNode;
    return this->rightNode;
}

class Node *Node::getParentNode () {
    return this->parentNode;
}

class Node *Node::setParentNode (class Node *parentNode = NULL) {
    this->parentNode = parentNode;
    return this->parentNode;
}

int Node::setCargo (int cargo = 0) {
    this->cargo = cargo;
    return this->cargo;
}

int Node::getCargo () {
    return this->cargo;
}

int Node::setId (int id = 0) {
    this->id = id;
    return 0;
}

int Node::getId () {
    return this->id;
}

// defining the Binary Tree  structure

class BinaryTree {
    
    private:
        class Node *rootNode;
        int id = 0;
    public:
        
        BinaryTree () {
            this->rootNode = NULL;
        }

        class Node *getRootNode ();
        class Node *setRootNode (class Node *rootNode);
        class Node *insertLeftNode (int cargo, class Node *root);
        class Node *insertRightNode (int cargo, class Node *root);
        class Node *DisplayBinaryTree (class Node *rootNode);
        class Node *findNode (int id, class Node *rootNode);
        int getID ();
        int increaseID ();
        ~BinaryTree () {}
};


class Node *BinaryTree::getRootNode () {
    return this->rootNode;
}

class Node *BinaryTree::setRootNode (class Node *rootNode = NULL) {
    this->rootNode = rootNode;
    return this->rootNode;
}

class Node *BinaryTree::insertLeftNode (int cargo = 0, class Node *root = NULL) {

    class Node *node = new Node (cargo, NULL, NULL, root, this->getID ());
    if (!root) {
        root = node;
    } else {
        root->setLeftNode (node);
    }
    this->increaseID ();
    return root;

}


class Node *BinaryTree::insertRightNode (int cargo = 0, class Node *root = NULL) {

    class Node *node = new Node (cargo, NULL, NULL, root, this->getID ());
    if (!root) {
        root = node;
    } else {
        root->setRightNode (node);
    }
    this->increaseID ();
    return root;
}

class Node *BinaryTree::DisplayBinaryTree (class Node *rootNode = NULL) {
    if (!rootNode) {
        return NULL;
    } else {
        cout<<rootNode->getCargo ()<<endl;
        this->DisplayBinaryTree (rootNode->getLeftNode ());
        this->DisplayBinaryTree (rootNode->getRightNode ());
    }
    return rootNode;
}

class Node *BinaryTree::findNode (int id = 0, class Node *rootNode = NULL) {
    //cout<<" In find node ID = "<<id<<", Cargo = "<<rootNode->getCargo ()<<endl<<", Node ID = "<<rootNode->getId ()<<endl;
    if (!rootNode) {
        return NULL;
    } else if (id == 0) {
        return this->rootNode;
    } else if (rootNode->getId () == id) {
        return rootNode;
    } else {
        class Node *node1 = this->findNode (id, rootNode->getLeftNode ());
        if (node1 && node1->getId () == id) {
            return node1;
        }
        class Node *node2 = this->findNode (id, rootNode->getRightNode ());
        if (node2 && node2->getId () == id) {
            return node2;
        }
    }
    return NULL;
}

int BinaryTree::getID () {
    return this->id;
}

int BinaryTree::increaseID () {
    this->id = this->id + 1;
    return this->id;
}

int main (int argc, char *argv []) {
    BinaryTree *binaryTree = new BinaryTree ();
    
    binaryTree->setRootNode (binaryTree->insertLeftNode (3, binaryTree->getRootNode ()));
    binaryTree->setRootNode (binaryTree->insertLeftNode (4, binaryTree->getRootNode ()));
    binaryTree->setRootNode (binaryTree->insertRightNode (5, binaryTree->getRootNode ()));
    binaryTree->setRootNode (binaryTree->DisplayBinaryTree (binaryTree->getRootNode ()));

    // finding the node with the id 1
    class Node *node = binaryTree->findNode (2, binaryTree->getRootNode ());
    cout<<"Cargo = "<<node->getCargo ()<<" Id = "<<node->getId ()<<endl;
    return 0;
}
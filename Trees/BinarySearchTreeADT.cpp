//
// Created by prasad on 5/26/21.
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int value){
        data = value;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

struct BinarySearchTree{
    Node *rootNode;

    BinarySearchTree(){
        rootNode = nullptr;
    }

    void InsertNode(int key);

    void DeleteNode(int key);

    void SearchNode(int key);

    bool isEmpty();

    void InOrder(Node *node);
};

void BinarySearchTree::InsertNode(int key) {
    Node *temp, *newNode;
    newNode = new Node(key);

    if(rootNode == nullptr){
        rootNode = newNode;
        return;
    }

    temp = rootNode;

    while (temp != nullptr) {
        if (temp->data < key) {
            if (temp->rightChild == nullptr) {
                temp->rightChild = newNode;
                return;
            } else
                temp = temp->rightChild;
        }
        else {
            if (temp->leftChild == nullptr) {
                temp->leftChild = newNode;
                return;
            }
            temp = temp->leftChild;
        }
    }
}

void BinarySearchTree::DeleteNode(int key) {
    if(rootNode == nullptr){
        return;
    }
    Node *temp = rootNode, *parent;
    int foundFlag = 0;
    parent = temp;

    while (temp != nullptr){
        if(temp->data == key){
            foundFlag = 1;
            break;
        }
        else if(temp->data > key){
            parent = temp;
            temp = temp -> leftChild;
        }
        else if(temp->data < key){
            parent = temp;
            temp = temp -> rightChild;
        }
    }

    if(!foundFlag) {
        return;
    }

    if (temp->rightChild == nullptr && temp->leftChild == nullptr){
        temp = nullptr;
        return;
    }

    else if(temp->leftChild == nullptr || temp->rightChild == nullptr){
        if(temp -> rightChild == nullptr){
            if(parent->leftChild == temp){
                parent->leftChild = temp->leftChild;
            }else {
                parent->rightChild = temp->leftChild;
            }
        }
        else{
            if(parent->leftChild == temp){
                parent->leftChild = temp->rightChild;
            }else {
                parent->rightChild = temp->rightChild;
            }
        }
    }

    else if(temp->leftChild != nullptr && temp->rightChild != nullptr){
        Node *successor = temp->leftChild, *successorParent, *temp2;
        successorParent = successor;
        while (true){
            if(successor -> leftChild == nullptr){
                break;
            }
            successorParent = successor;
            successor = successor->leftChild;
        }
        if(successor->rightChild != nullptr){
            if (parent->leftChild == temp){
                parent->leftChild = successor;
                successorParent->leftChild = successor->rightChild;
                successor->rightChild = temp->rightChild;
                temp = nullptr;
            }
            else if (parent->rightChild == temp){
                parent->rightChild = successor;
                successorParent->leftChild = successor->rightChild;
                successor->rightChild = temp->rightChild;
                temp = nullptr;
            }
        }
        else if(successor->rightChild == nullptr){
            if (parent->leftChild == temp){
                parent->leftChild = successor;
                successorParent->leftChild = nullptr;
                successor->rightChild = temp->rightChild;
                temp = nullptr;
            }
            else if (parent->rightChild == temp){
                parent->rightChild = successor;
                successorParent->leftChild = nullptr;
                successor->rightChild = temp->rightChild;
                temp = nullptr;
            }
        }
    }
    return;
}

void BinarySearchTree::SearchNode(int key) {

    if(rootNode == nullptr){
        return;
    }

    Node *temp = rootNode;
    int foundFlag = 0;

    while (temp != nullptr){
        if(temp->data == key){
            foundFlag = 1;
            break;
        }
        else if(temp->data > key){
            temp = temp -> leftChild;
        }
        else if(temp->data < key){
            temp = temp -> rightChild;
        }
    }

    if(foundFlag == 1){
        cout << "Element found." << endl;
    }
    else
        cout << "Element not found." << endl;

    return;
}

bool BinarySearchTree::isEmpty() {
    if(rootNode != nullptr){
        return false;
    }
    return true;
}

void BinarySearchTree::InOrder(Node *node){
    if(node == nullptr){
        return;
    }
    InOrder(node->leftChild);
    cout << node->data << " " << endl;
    InOrder(node->rightChild);
};

int main(){
    BinarySearchTree b1;
    b1.InsertNode(7);
    b1.InsertNode(2);
    b1.InsertNode(9);
    b1.InsertNode(1);
    b1.InsertNode(3);
    b1.InsertNode(11);
    b1.InOrder(b1.rootNode);
    b1.SearchNode(11);
    b1.DeleteNode(9);
    b1.InOrder(b1.rootNode);
    return 0;
}

//clang++ BinarySearchTreeADT.cpp -o BSTADT && ./BSTADT
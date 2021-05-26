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

class BinaryTree{

    Node *rootNode;

public:

    BinaryTree(){
        rootNode = nullptr;
    }

    Node * searchNode();

    Node * InsertNode(Node *root, int data){
        if(root == nullptr){
            root = new Node(data);
            return root;
        }

        else if(root->leftChild == nullptr){
            return InsertNode(root->leftChild, data);
        }

        else if(root->rightChild == nullptr){
            return InsertNode(root->rightChild, data);
        }

        else if(root->leftChild->rightChild == nullptr || root->leftChild->leftChild == nullptr){
            return InsertNode(root->leftChild, data);
        }
        else if(root->leftChild->rightChild != nullptr && root->leftChild->leftChild != nullptr) {
            return InsertNode(root->rightChild, data);
        }
    };

//    void DeleteNode(Node *);

    void InOrder(Node *node){
        if(node == nullptr){
            return;
        }
        InOrder(node->leftChild);
        cout << node->data << " " << endl;
        InOrder(node->rightChild);
    };
//
//    void PreOrder(Node *);
//
//    void PostOrder(Node *);
//
//    Node * CopyTree();
//
//    void MirrorTree();
//
//    void TreeHeight(Node *);
//
//    int CountLeaf(Node *);
//
//    int CountNode(Node *);
//
//    void BreadthFirstTree(Node *);
//
//    void DepthFirstTree(Node *);


};
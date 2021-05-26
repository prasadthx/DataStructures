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

    void InOrder(Node *node){
        if(node == nullptr){
            return;
        }
        InOrder(node->leftChild);
        cout << node->data << " " << endl;
        InOrder(node->rightChild);
    };

    void PreOrder(Node *node){
        if(node == nullptr){
            return;
        }
        cout << node->data << " " << endl;
        InOrder(node->leftChild);
        InOrder(node->rightChild);
    };

    void PostOrder(Node *node){
        if(node == nullptr){
            return;
        }
        InOrder(node->leftChild);
        InOrder(node->rightChild);
        cout << node->data << " " << endl;
    };

    Node * CopyTree(){

        Node *temp;

        if(rootNode == nullptr){
            return nullptr;
        }

        temp = new Node(rootNode->data);

        temp->rightChild = CopyTree(temp->rightChild);
        temp->leftChild = CopyTree(temp->leftChild);

        return temp;
    };

    void MirrorTree(Node *node){
        if (node==nullptr || (node->rightChild==nullptr && node->leftChild== nullptr)){
            return;
        }
        Node *temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;

        MirrorTree(node->left);
        MirrorTree(node->right);
    };

    int TreeHeight(Node *node){
        if(node == nullptr){
            return 0;
        }
        if(node->rightChild == nullptr && node->leftChild == nullptr){
            return 1;
        }

        int leftHeight = 1 + TreeHeight(node->leftChild);
        int rightHeight = 1 + TreeHeight(node->rightChild);

        if (leftHeight>rightHeight){
            return leftHeight;
        }
        else
            return rightHeight;

    };

    int CountLeaf(Node *node){
        if (node == nullptr){
            return 0;
        }
        if(node->leftChild == nullptr && node->rightChild == nullptr){
            return 1;
        }
        return (CountLeaf(node->leftChild) + CountLeaf(node->rightChild));
    };

    int CountNode(Node *node){
        if (node == nullptr){
            return 0;
        }
        return (1 + CountNode(node->rightChild) + CountNode(node->leftChild));
    };

};
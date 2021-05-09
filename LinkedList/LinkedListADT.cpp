//
// Created by Prasad on 4/29/2021.
//

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    Node *Head;
    Node *Tail;
    int Size;

public:

    LinkedList(){
        Head = Tail = nullptr;
        Size = 0;
    }

    ~LinkedList(){
        Node *temp = Head;
        while(Head != nullptr){
            temp = Head;
            Head = Head->next;
            delete Temp;
        }
    }

    void Create();
    void Display();
    Node* GetNode();
    void Append(Node *newNode);
    void InsertAtPosition(int data, position);
    void RecursiveTraverse(Node *temp);
    void Delete(int position);
    int Reverse();
};

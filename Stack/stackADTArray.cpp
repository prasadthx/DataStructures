//
// Created by Prasad on 4/26/2021.
//

#include<iostream>

using namespace std;

class Stack{
    int StackArr[50];
    int MaxCapacity;
    int Top;
    int currentSize;

public:

    Stack(){
        MaxCapacity = 50;
        Top = -1;
        currentSize = 0;
    }

    int getTop();
    int pop();
    void push(int element);
    bool isEmpty();
    bool isFull();
    int CurrentSize();
};

int Stack::getTop() {
    try {
        if(!isEmpty()){
            return StackArr[Top];
        }
        else{
            throw underflow_error("Stack is empty");
        }
    }
    catch (underflow_error e) {
        cout << e.what() << endl;
    }
}

int Stack::pop() {
    try {
        if (!isEmpty()){
            return StackArr[Top--];
        }
        else throw underflow_error("Stack is empty");
    }
    catch (underflow_error &e) {
        cout << e.what() << endl;
    }
}

bool Stack::isFull() {
    if (Top == (MaxCapacity - 1)){
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if(Top == -1){
        return true;
    }
    return false;
}

int Stack::CurrentSize(){
    return Top + 1;
}

void Stack::push(int element) {
    try{
        if(!isFull()){
            StackArr[++Top] = element;
        }
        else throw overflow_error("Stack is full");
    }
    catch(overflow_error &e){
        cout << e.what() << endl;
    }
}

int main() {
    Stack S;
    S.pop();
    S.push(1);
    S.push(2);
    cout << S.getTop() << endl;
    cout << S.pop() << endl;
    cout << S.pop() << endl;
}

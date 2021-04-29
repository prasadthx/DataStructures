//
// Created by Prasad on 4/29/2021.
//

#include<iostream>

using namespace std;

class Queue{

    int Rear, Front;
    int QueueArr[50];
    int maxSize;
    int currentSize;

public:

    Queue(){
        currentSize = 0;
        maxSize = 50;
        Rear = -1;
        Front = 0;
    }

    bool IsEmpty(){
        if(currentSize == 0){
            return true;
        }
        return false;
    }

    bool IsFull(){
        if(currentSize == 50){
            return true;
        }
        return false;
    }

    void addElement(int element){
        if(!IsFull()){
            QueueArr[++Rear] = element;
            currentSize++;
        }
        else {
            return;
        }
    }

    int deleteElement() {
        if(!IsEmpty()){
            --currentSize;
            --Rear;
            for(int i = 0; i < currentSize; i++){
                QueueArr[i] = QueueArr[i+1];
            }
        }
    }

    int getFrontElement(){
        if(!IsEmpty()){
            return QueueArr[Front];
        }
    }
};


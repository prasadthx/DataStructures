//
// Created by Prasad on 4/29/2021.
//

#include<iostream>

using namespace std;

class CircularQueueAdt{
    int CircularQueueArr[50];
    int MaxSize;
    int Front, Rear;
    int currentSize;

public:

    CircularQueueAdt(){
        MaxSize = 50;
        currentSize = 0;
        Front = Rear = -1;
    }

    bool IsEmpty(){
        if(currentSize == 0){
            return true;
        }
        return false;
    }

    bool IsFull(){
        if(currentSize == MaxSize){
            return true;
        }
        return false;
    }

    void addElement(int element){
        if(!IsFull()) {
            Rear = (Rear + 1) % MaxSize;
            CircularQueueArr[Rear] = element;
            currentSize++;
        }
        else return;
    }

    int deleteElement(){
        if(!IsEmpty()){
            Front = (Front + 1) % MaxSize;
            currentSize--;
            return QueueArr[Front];
        }
    }

    int getFrontElement(){
        if(!IsEmpty()) {
            int Temp;
            Temp = (Front + 1) % MaxSize;
            return CircularQueueArr[Temp];
        }
    }
};


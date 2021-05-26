//
// Created by prasad on 5/25/21.
//

#include <iostream>

using namespace std;

class HashTable{

    int MAX_SIZE;
    int *hashTable;

public:

    HashTable(int MAX_SIZE){
        this->MAX_SIZE = MAX_SIZE;
        this->hashTable = new int[MAX_SIZE];
        for(int i = 0; i < MAX_SIZE; i++){
            hashTable[i] = -1;
        }
    }

    void displayHashTable(){
        for (int i = 0; i < MAX_SIZE; i++){
            cout << "Index: " << i << " => " << hashTable[i] << endl;
        }
    }

    void InsertValue(int key){
        int index = key % MAX_SIZE;
        if (hashTable[index] == -1){
            hashTable[index] = key;
        }
        else{
            int probeIndex = 1;
            while (hashTable[index] != -1){
                index = (key + probeIndex) % MAX_SIZE;
                index++ ;
            }
            hashTable[index] = key;
        }
    }

};

int main(){
    HashTable h1(20);
    for (int i = 5; i < 25; i+=2){
        h1.InsertValue(i);
    }
    h1.displayHashTable();
}

//clang++ LinearProbing.cpp -o LinearProbing && ./LinearProbing



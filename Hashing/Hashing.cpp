//
// Created by prasad on 5/25/21.
//

#include <iostream>
#include <cmath>

using namespace std;

class HashTable{

    int MAX_SIZE;
    int *hashTable;

public:

    HashTable(int MAX_SIZE){
        this->MAX_SIZE = MAX_SIZE;
        this->hashTable = new int[MAX_SIZE];
        for(int i = 0; i < MAX_SIZE; i++){
            hashTable[i] = 0;
        }
    }

    void displayHashTable(){
        for (int i = 0; i < MAX_SIZE; i++){
            cout << "Index: " << i << " => " << hashTable[i] << endl;
        }
    }

    void PopulateHashTable(void (*hashMethod)(HashTable *, int)){
        for (int i = 0; i < 10; i++){
            hashMethod(this, i);
        }
    }

    friend struct HashFunction;
};

struct HashFunction{

    static void DivisionMethod(HashTable *HashTable, int key){
        int index = key % HashTable->MAX_SIZE;
        HashTable->hashTable[index] = key;
    }

    static void MultiplicationMethod(HashTable *HashTable, int key){
        double A = 0.618033;
        double intPart;
        int index = floor( HashTable->MAX_SIZE * ( modf(key * A, &intPart) ) );
        HashTable->hashTable[index] = key;
    }
};

int main(){
    void (*hashMethod)(HashTable *, int);
    HashTable ht1(10);
    HashFunction hf1;

    hashMethod = hf1.DivisionMethod;

    cout << "Implementing Division Method: " << endl;
    ht1.PopulateHashTable(hashMethod);
    ht1.displayHashTable();

    hashMethod = hf1.MultiplicationMethod;

    cout << "Implementing Multiplication Method: " <<endl;
    ht1.PopulateHashTable(hashMethod);
    ht1.displayHashTable();

    return 0;
}

//clang++ Hashing.cpp -o Hashing && ./Hashing

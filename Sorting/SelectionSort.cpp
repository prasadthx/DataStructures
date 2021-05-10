//
// Created by Prasad on 5/10/2021.
//

#include<iostream>

using namespace std;

void SelectionSort(int arrayLength, int *array){
    int j,temp, compareElement, minValue, minPos;
    for(int i = 0; i < arrayLength; i++){
        compareElement = *(array + i);
        minPos = i;
        minValue = compareElement;
        for(j = (i+1); j < arrayLength; j++){
            if(*(array + j) < minValue){
                minPos = j;
                minValue = *(array + j);
            }
        }
        temp = *(array + i);
        *(array + i) = *(array + minPos);
        *(array + minPos) = temp;
    }
}

int main(){
    int *array, arrayLength;
    cout << "Selection Sort Implementation" << endl;

    cout << "Enter the number of elements: " << endl;
    cin >> arrayLength;

    array = new int[arrayLength];

    for(int i = 0; i < arrayLength; i++){
        cout << "Enter the unsorted list elements: ";
        cin >> *(array + i);
    }

    cout << "\nUnsorted array: " ;
    for(int i = 0; i < arrayLength; i++){
        cout << *(array + i) << "  " ;
    }

    SelectionSort(arrayLength, array);

    cout << "\nSorted array: " ;
    for(int i = 0; i < arrayLength; i++){
        cout << *(array + i) << "  " ;
    }
}

//clang++ SelectionSort.cpp -o SelectionSort.exe && SelectionSort.exe

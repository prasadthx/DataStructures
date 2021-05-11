//
// Created by Prasad on 5/11/2021.
//

#include<iostream>

using namespace std;

void ShellSort(int array[], int arrayLength){
    int temp;
    for(int gap = arrayLength; gap >= 1; gap /= 2){
        for(int j = gap; j < arrayLength; j++){
            temp = array[j];
            int i;
            for(i = j; i >= gap && array[j - i] > temp; i -= gap){
                array[i] = array[i - gap];
            }
            array[i] = temp;
        }
    }
}

int main(){
    int *array, arrayLength;
    cout << "Shell Sort Implementation" << endl;

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

    ShellSort(array, arrayLength);

    cout << "\nSorted array: " ;
    for(int i = 0; i < arrayLength; i++){
        cout << *(array + i) << "  " ;
    }
}

//
// Created by Prasad on 5/9/2021.
//

#include<iostream>

using namespace std;

int sentinelSearch(int arrayLength, int *array,int element) {
    *(array + arrayLength) = element;
    int iterator = 0;
    while (*(array+iterator) != element) {
        iterator++;
    }
    if (iterator < arrayLength){
        return iterator + 1;
    }
    return -1;
}

int main(){

    int arrayLength, element, *array, resultant;

    cout << "Sequential Search implementation: " << endl;
    cout << "Enter the number of elements: " << endl;

    cin >> arrayLength;
    array = new int[arrayLength];

    for (int i = 0; i < arrayLength; i++){
        cout << "Enter the element in array: " << endl;
        cin >> *(array + i);
    }

    cout << "Enter the element to be searched: " << endl;
    cin >> element;


    resultant = sentinelSearch(arrayLength, array, element);

    if(resultant == -1){
        cout << "The element was not found.";
        return 0;
    }

    cout << "The element was found at position: " << resultant << endl;
    return 0;
}
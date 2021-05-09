//
// Created by Prasad on 5/9/2021.
//

#include<iostream>

using namespace std;

int binarySearch(int arrayLength, int *array, int element){
    int low = 0, high = arrayLength, middle;
    while(low < high){
        middle = (low + high) / 2;
        if (*(array + middle) == element){
            return middle + 1;
        }
        else if (*(array + middle) > element){
            high = middle - 1;
        }
        else if (*(array + middle) < element){
            low = middle + 1;
        }
    }
    return  -1;
}

int main(){

    int arrayLength, element, *array, resultant;

    cout << "Binary Search implementation: " << endl;
    cout << "Enter the number of elements: " << endl;

    cin >> arrayLength;
    array = new int[arrayLength];

    for (int i = 0; i < arrayLength; i++){
        cout << "Enter the element in array: " << endl;
        cin >> *(array + i);
    }

    cout << "Enter the element to be searched: " << endl;
    cin >> element;


    resultant = binarySearch(arrayLength, array, element);

    if(resultant == -1){
        cout << "The element was not found.";
        return 0;
    }

    cout << "The element was found at position: " << resultant << endl;
    return 0;
}

//
// Created by Prasad on 5/9/2021.
//

#include<iostream>

using namespace std;

int FibonacciGenerator(int index){
    int tempFibonacci1 = 0;
    int tempFibonacci2 = 1;
    int resultant = 0;
    if (index == 0){
        return tempFibonacci1;
    }
    else if (index == 1){
        return tempFibonacci2;
    }
    else if (index > 1){
        for (int i = 3; i <= index; i++){
            resultant = tempFibonacci1 + tempFibonacci2;
            tempFibonacci1 = tempFibonacci2;
            tempFibonacci2 = resultant;
        }
        return resultant;
    }
    return -1;
}

int FibonacciSearch(int arrayLength, int *array, int element){

    int limitFibonacci = 1;
    while(FibonacciGenerator(limitFibonacci) < arrayLength){
        limitFibonacci++;
    }

    int offset = -1,
        Fm = FibonacciGenerator(limitFibonacci),
        Fm_1 = FibonacciGenerator(limitFibonacci - 1),
        Fm_2 = FibonacciGenerator(limitFibonacci - 2),
        i;

    while(Fm > 1){

        i = (arrayLength-1) > Fm_2 ? (Fm_2 + offset) : (arrayLength - 1);

        if (*(array + i - 1) > element){
            Fm = Fm_2;
            Fm_1 = Fm_1 - Fm_2;
            Fm_2 = Fm - Fm_1;
        }
        else if (*(array + i - 1) < element){
            Fm = Fm_1;
            Fm_1 = Fm_1 - Fm_2;
            Fm_2 = Fm - Fm_1;
            offset = i;
        }
        else if(*(array + i - 1) == element){
            return i;
        }
    }

    if(Fm && *(array + (offset + 1))==element){
        return i;
    }

    return -1;
}

int main(){
    cout << "Fibonacci Search Implementation" << endl;
    int arrayLength, element, *array, resultant;

    cout << "Enter the number of elements: " << endl;
    cin >> arrayLength;
    array = new int[arrayLength];

    for (int i = 0; i < arrayLength; i++){
        cout << "Enter the element in array: " << endl;
        cin >> *(array + i);
    }

    cout << "Enter the element to be searched: " << endl;
    cin >> element;


    resultant = FibonacciSearch(arrayLength, array, element);

    if(resultant == -1){
        cout << "The element was not found.";
        return 0;
    }

    cout << "The element was found at position: " << resultant << endl;
    return 0;

}
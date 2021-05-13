////
//// Created by Prasad on 5/13/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//void CountingSort(int array[], int arrayLength){
//    int max = array[0];
//
//    // Finding the largest number in the given array
//    for(int i = 1; i < arrayLength; i++){
//        if(array[i] > max){
//            max = array[i];
//        }
//    }
//
//    //Dynamically allotment of space for the array
//    int *countingArray = new int[max + 1];
//    int *outputArray = new int[arrayLength];
//
//    //Initializing the value of elements of countingArray to 0;
//    for(int i = 0; i <= max ; i++){
//        *(countingArray + i) = 0;
//    }
//
//    //Calculating the value frequency.
//    for(int i = 0; i < arrayLength; i++){
//        *(countingArray + array[i]) += 1;
//    }
//
//    //Calculating the cumulative count of elements.
//    for(int i = 1; i <= max; i++){
//        *(countingArray + i) += *(countingArray + (i - 1));
//    }
//
//    //Outputting the sorted array to outputArray.
//    for(int i = arrayLength - 1; i >= 0; i--){
//        *(outputArray + *(countingArray + array[i]) - 1) = array[i];
//        *(countingArray + array[i]) -= 1;
//    }
//
//
//    //Copying the output array to main array
//    for(int i = 0; i < arrayLength; i++){
//        array[i] = *(outputArray + i);
//    }
//
//    //Deleting the dynamically allotted memory
//    delete[] countingArray;
//    delete[] outputArray;
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Counting Sort Implementation" << endl;
//
//    cout << "Enter the number of elements: " << endl;
//    cin >> arrayLength;
//
//    array = new int[arrayLength];
//
//    for(int i = 0; i < arrayLength; i++){
//        cout << "Enter the unsorted list elements: ";
//        cin >> *(array + i);
//    }
//
//    cout << "\nUnsorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//
//    CountingSort(array, arrayLength);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}
//
//
////clang++ CountingSort.cpp -o CountingSort.exe && CountingSort.exe


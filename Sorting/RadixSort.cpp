////
//// Created by Prasad on 5/13/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//int getMaxElement(int array[], int arrayLength){
//    int max = array[0];
//    for (int i = 1; i < arrayLength; i++){
//        if (array[i] > max){
//            max = array[i];
//        }
//    }
//    return max;
//}
//
//void CountingSort(int array[], int arrayLength, int placeValue){
//    int countingArray[10];
//
//    //Dynamically allotment of space for the array
//    int *outputArray = new int[arrayLength];
//
//    //Initializing the value of elements of countingArray to 0;
//    for(int i = 0; i < 10 ; ++i){
//        countingArray[i] = 0;
//    }
//
//    //Calculating the value frequency.
//    for(int i = 0; i < arrayLength; i++){
//        countingArray[(array[i] / placeValue) % 10]++;
//    }
//
//    //Calculating the cumulative count of elements.
//    for(int i = 1; i < 10; i++){
//        countingArray[i] += countingArray[i - 1];
//    }
//
//    //Outputting the sorted array to outputArray.
//    for(int i = arrayLength - 1; i >= 0; i--){
//        outputArray[(countingArray[(array[i] / placeValue) % 10] - 1)] = array[i];
//        countingArray[(array[i] / placeValue) % 10]--;
//    }
//
//    cout << "TIll here";
//
//
//    //Copying the output array to main array
//    for(int i = 0; i < arrayLength; i++){
//        array[i] = outputArray[i];
//    }
//
//   //Deleting the dynamically alloted memory
//    delete[] outputArray;
//}
//
//void RadixSort(int array[], int arrayLength){
//    int max = getMaxElement(array, arrayLength);
//    for(int place = 1; max / place > 0; place *= 10){
//        CountingSort(array, arrayLength, place);
//    }
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Radix Sort Implementation" << endl;
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
//    RadixSort(array, arrayLength);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}
//
//
////clang++ RadixSort.cpp -o RadixSort.exe && RadixSort.exe
//

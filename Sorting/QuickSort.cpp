////
//// Created by Prasad on 5/10/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//void QuickSort(int array[], int low, int high){
//    int *pivotElement = &array[low - 1],
//        upperLimit = high,
//        lowerLimit = low,
//        temp;
//    if(abs(high - low)==0 || high == 0){
//        if(*pivotElement > array[low]){
//            temp = *pivotElement;
//            *pivotElement = array[low];
//            array[low] = temp;
//        }
//        return;
//    }
//    cout << "before low: " << low << endl;
//    cout << "before upper: " << upperLimit << endl;
//    while(low < high){
//        while(array[low] < *pivotElement){
//            low++;
//        }
//        cout << "low " << low << endl;
//        while(array[high] > *pivotElement){
//            high--;
//        }
//        cout << "high " << high << endl;
//        if(!(low < high)){
//            break;
//        }
//        temp = array[low];
//        array[low] = array[high];
//        array[high] = temp;
//    }
//    temp = *pivotElement;
//    *pivotElement = array[high];
//    array[high] = temp;
//
//    if(lowerLimit != high && high - lowerLimit > 1){
//        cout << "Executing left" << endl;
//        QuickSort(array, lowerLimit, high - 1);
//    }
//
//    if(upperLimit != high && upperLimit - high > 1){
//        cout << "Executing right" << endl;
//        QuickSort(array, high + 2, upperLimit);
//    }
//
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Quick Sort Implementation" << endl;
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
//    QuickSort(array, 1, arrayLength - 1);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}
//
////clang++ QuickSort.cpp -o QuickSort.exe && QuickSort.exe
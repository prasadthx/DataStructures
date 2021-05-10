////
//// Created by Prasad on 5/10/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//void InsertionSort(int arrayLength, int *array){
//    int j,temp, compareElement;
//    for(int i = 1; i < arrayLength; i++){
//        compareElement = *(array + i);
//        j = i;
//        while(j > 0 && *(array + j - 1) > compareElement){
//            *(array + j) = *(array + j - 1);
//            j--;
//        }
//        *(array + j) = compareElement;
//    }
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Insertion Sort Implementation" << endl;
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
//    InsertionSort(arrayLength, array);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}


////clang++ InsertionSort.cpp -o InsertionSort.exe && InsertionSort.exe
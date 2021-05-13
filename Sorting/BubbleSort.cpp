////
//// Created by Prasad on 5/10/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//void BubbleSort(int arrayLength, int *array){
//    int temp;
//    for(int i = 0; i < arrayLength; i++){
//        for(int j = 1; j < (arrayLength - i) ; j++){
//            if(*(array + j - 1) > *(array + j)){
//                temp = *(array + j - 1);
//                *(array + j - 1) = *(array + j);
//                *(array + j) = temp;
//            }
//        }
//    }
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Bubble Sort Implementation" << endl;
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
//    BubbleSort(arrayLength, array);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}
//
////clang++ BubbleSort.cpp -o BubbleSort.exe && BubbleSort.exe

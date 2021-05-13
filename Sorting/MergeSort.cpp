////
//// Created by Prasad on 5/11/2021.
////
//
//#include<iostream>
//
//using namespace std;
//
//void merge(int array[], int low, int mid, int high);
//
//void MergeSort(int array[], int low, int high){
//    int mid;
//    if(low < high){
//        mid = (low + high)/2;
//        MergeSort(array, low, mid);
//        MergeSort(array, mid + 1, high);
//        merge(array, low, mid, high);
//    }
//}
//
//void merge(int array[], int low, int mid, int high){
//    int i, j, k, C[50];
//    i = low;
//    j = mid + 1;
//    k = 0;
//
//    while(i <= mid && j <= high){
//        if(array[i] < array[j]){
//            C[k] = array[i];
//            i++;
//        }
//        else{
//            C[k] = array[j];
//            j++;
//        }
//        k++;
//    }
//
//    while(i <= mid)
//        C[k++] = array[i++];
//
//    while(j <= high)
//        C[k++]=array[j++];
//
//    for(i = low, j = 0; i <= high; i++, j++)
//    {
//        array[i] = C[j];
//    }
//}
//
//int main(){
//    int *array, arrayLength;
//    cout << "Merge Sort Implementation" << endl;
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
//    MergeSort(array, 0, arrayLength - 1);
//
//    cout << "\nSorted array: " ;
//    for(int i = 0; i < arrayLength; i++){
//        cout << *(array + i) << "  " ;
//    }
//}
//
//
////clang++ MergeSort.cpp -o MergeSort.exe && MergeSort.exe
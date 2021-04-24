////
//// Created by Prasad on 4/24/2021.
////
//
//
//#include<iostream>
//
//using namespace std;
//
//template<typename T>
//struct Array{
//    int MaxSize;
//    T A[20];
//    int Size;
//    Array(){
//        MaxSize = 20;
//        Size = 0;
//    };
//    void readArray();
//    void displayArray();
//    void traverseBackward();
//    void insertElement(int location, T Element);
//    void removeElement(T element);
//    int searchElement(T element);
//};
//
////Array Array::Array(){
////    MaxSize = 20;
////    Size = 0;
////}
//
//void Array::readArray(){
//    int index, N;
//    cout << "Enter the size of the Array" << endl;
//    cin >> N;
//    if(N>MaxSize){
//        cout << "The array does not have so much capacity" << endl;
//        return;
//    }
//    for (index = 0; index < N ; index++){
//        cout << "Enter the number to be inserted: ";
//        cin >> A[index];
//    }
//    Size = N;
//    return;
//}
//
//void Array::displayArray(){
//    for (int index = 0; index < Size; index++){
//        cout << A[index] << ' ';
//    }
//    cout << endl;
//}
//
//void Array::traverseBackward(){
//    int lastIndex = Size - 1;
//    for (lastIndex ; lastIndex>=0 ; lastIndex--){
//        cout << A[lastIndex] << " ";
//    }
//    cout << endl;
//}
//
//int Array::searchElement(int element){
//    int index = 0;
//    for (index; index < Size; index++){
//        if(A[index]==element){
//            return index;
//        }
//    }
//    return -1;
//}
//
//void Array::insertElement(int location, int element){
//    if(Size + 1 > MaxSize){
//        cout << "Error: Array Overflow" << endl;
//        return;
//    }
//    int i;
//    for (i = Size; i >= location; i--){
//        A[i] = A[i-1];
//    }
//    A[location-1] = element;
//    Size = Size + 1;
//}
//
//void Array::removeElement(int element){
//    int index = searchElement(int (element));
//    if(index==-1){
//        return;
//    }
//    for(int i = index; i < Size-1; i++){
//        A[i] = A[i+1];
//    }
//    A[Size-1] = 0;
//    Size = Size - 1;
//}
//
//
//int main(){
//    Array a1;
//    a1.readArray();
//    a1.displayArray();
//    a1.traverseBackward();
//    cout << "Element found at: " << a1.searchElement(5) <<endl;
//    a1.insertElement(4,99);
//    a1.displayArray();
//    a1.removeElement(99);
//    a1.displayArray();
//    return 0;
//}
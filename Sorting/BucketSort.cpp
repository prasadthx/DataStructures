//
// Created by Prasad on 5/13/2021.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void BucketSort(float array[], int arrayLength){
    vector<float> bucketArray [arrayLength];

    for (int i=0; i < arrayLength; i++){
        bucketArray[int(arrayLength*array[i])].push_back(array[i]);
    }

    for (int i=0; i < arrayLength; i++){
        sort(bucketArray[i].begin(), bucketArray[i].end());
    }

    int index = 0;
    for (int i=0; i < arrayLength; i++){
        for(int j=0; j < bucketArray[i].size(); j++){
            array[index++] = bucketArray[i][j];
        }
    }
}

int main(){
    float *array, arrayLength;
    cout << "Bucket Sort Implementation" << endl;

    cout << "Enter the number of elements: " << endl;
    cin >> arrayLength;

    array = new float[arrayLength];

    for(int i = 0; i < arrayLength; i++){
        cout << "Enter the unsorted list elements: ";
        cin >> *(array + i);
    }

    cout << "\nUnsorted array: " ;
    for(int i = 0; i < arrayLength; i++){
        cout << *(array + i) << "  " ;
    }

    BucketSort(array, arrayLength);

    cout << "\nSorted array: " ;
    for(int i = 0; i < arrayLength; i++){
        cout << *(array + i) << "  " ;
    }
}


//clang++ BucketSort.cpp -o BucketSort.exe && BucketSort.exe

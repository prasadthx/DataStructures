//
// Created by Prasad on 4/24/2021.
//

#include<iostream>

using namespace std;

struct SparseMatrix{
    const int Max = 20;
    int sparseMatrix[Max][3];
    void ReadSparseMatrix();
    SparseMatrix SimpleTranspose();
    SparseMatrix FastTranspose();
    SparseMatrix AddSparseMatrix(SparseMatrix B);
    SparseMatrix MultiplySparseMatrix(SparseMatrix B);
};

SparseMatrix SparseMatrix::AddSparseMatrix(SparseMatrix B) {
    SparseMatrix C;
    int i, j , k , Row1, Row2, Column1, Column2, Value1, Value2;

    Row1 = sparseMatrix[0][0];
    Column1 = sparseMatrix[0][1];
    Value1 = sparseMatrix[0][2];

    Row2 = B.sparseMatrix[0][0];
    Column2 = B.sparseMatrix[0][1];
    Value2 = sparseMatrix[0][2];

    if (Row1==Row2 && Column1==Column2){

        i = j = k = 1;

        C.sparseMatrix[0][0] = sparseMatrix[0][0];
        C.sparseMatrix[0][1] = sparseMatrix[0][1];

        while (i <= Value1 && j <= Value2) {
            if (sparseMatrix[i][0] == B.sparseMatrix[j][0]){
                if (sparseMatrix[i][1] == B.sparseMatrix[j][1]){
                    C.sparseMatrix[k][0] = sparseMatrix[i][0];
                    C.sparseMatrix[k][1] = sparseMatrix[i][1];
                    C.sparseMatrix[k][2] = sparseMatrix[i][2];
                    i++;
                    j++;
                    k++;
                }
                else {
                    if (sparseMatrix[i][1] < B.sparseMatrix[i][1]){
                        C.sparseMatrix[k][0] = sparseMatrix[i][0];
                        C.sparseMatrix[k][1] = sparseMatrix[i][1];
                        C.sparseMatrix[k][2] = sparseMatrix[i][2];
                        i++;
                        k++;
                    }
                    else {
                        C.sparseMatrix[k][0] = B.sparseMatrix[j][0];
                        C.sparseMatrix[k][1] = B.sparseMatrix[j][1];
                        C.sparseMatrix[k][2] = B.sparseMatrix[j][2];
                        j++;
                        k++;
                    }
                }
            }
            else if{sparseMatrix[i][0] < B.sparseMatrix[j][0]}{
                C.sparseMatrix[k][0] = sparseMatrix[i][0];
                C.sparseMatrix[k][1] = sparseMatrix[i][1];
                C.sparseMatrix[k][2] = sparseMatrix[i][2];
                i++;
                k++;
            }
            else{
                C.sparseMatrix[k][0] = B.sparseMatrix[j][0];
                C.sparseMatrix[k][1] = B.sparseMatrix[j][1];
                C.sparseMatrix[k][2] = B.sparseMatrix[j][2];
                j++;
                k++;
            }
        }

        while(i <= Value1){
            C.sparseMatrix[k][0] = sparseMatrix[i][0];
            C.sparseMatrix[k][0] = sparseMatrix[i][1];
            C.sparseMatrix[k][0] = sparseMatrix[i][2];
            i++;
            k++;
        }

        while(j <= Value2){
            C.sparseMatrix[k][0] = sparseMatrix[j][0];
            C.sparseMatrix[k][1] = sparseMatrix[j][1];
            C.sparseMatrix[k][2] = sparseMatrix[j][2];
            j++;
            k++;
        }
    }
    else{
        cout << "Matrix cannot be added as they are not of the same dimension" << endl;
    }

}

SparseMatrix SparseMatrix::SimpleTranspose(){
    int Row = sparseMatrix[0][0], Column = sparseMatrix[0][1], Value = sparseMatrix[0][2];
    SparseMatrix transposeMatrix;
    transposeMatrix.sparseMatrix[0][0] = Column;
    transposeMatrix.sparseMatrix[0][1] = Row;
    transposeMatrix.sparseMatrix[0][2] = Value;

    if(Value==0){
        return transposeMatrix;
    }

    for(int i = 0; i < Column; i++){
        for(int j = 1; j <= Value; j++){
            if(sparseMatrix[j][1] == j){
                transposeMatrix.sparseMatrix[i][0] = sparseMatrix[i][1];
                transposeMatrix.sparseMatrix[i][1] = sparseMatrix[i][0];
                transposeMatrix.sparseMatrix[i][2] = sparseMatrix[i][2];
                i++;
            }
        }
    }
    return transposeMatrix;
}

//SparseMatrix SparseMatrix::FastTranspose() {
//    int Row, Col, Value, Frequency[], RowStartPosition[];
//    SparseMatrix transposeMatrix;
//
//    Row = sparseMatrix[0][0];
//    Col = sparseMatrix[0][1];
//    Value = sparseMatrix[0][2];
//
//    transposeMatrix.sparseMatrix[0][0] = Col;
//    transposeMatrix.sparseMatrix[0][1] = Row;
//    transposeMatrix.sparseMatrix[0][2] = Value;
//
//    if (Value==0){
//        return transposeMatrix;
//    }
//
//    for(int i=0; i < Col ; i++){
//        Frequency[i] = 0;
//    }
//
//    for(int j=1; j <=Value; j++){
//        Frequency[sparseMatrix[j][1]] += 1;
//    }
//
//    RowStartPosition[0] = 1;
//
//    for(int k=1; k<Col ; k++){
//
//    }
//}
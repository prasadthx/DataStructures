
// Created by Prasad on 4/27/2021.
//

#include<iostream>
#include<cstring>

using namespace std;

struct Stack{
    char *StackArr[5];
    int MaxSize;
    int Top;
    int currentSize;
    Stack(){
        MaxSize = 20;
        Top = -1;
        currentSize = 0;
    }

    void push(char * elementString) {
        try{
            if(!isFull()){
                cout << "Prepush " << elementString << endl;
                StackArr[++Top] = elementString;
                cout << "Post push " << StackArr[Top] << endl;
            }
            else throw overflow_error("");
        }
        catch(overflow_error &e){
            cout << e.what();
        }
    }


    char * pop() {
        try {
            if (!isEmpty()){
                cout << "Pre pop " << StackArr[Top] << endl;
                return StackArr[Top--];
            }
            else throw underflow_error("");
        }
        catch (underflow_error &e) {
            cout << e.what() ;
        }
    }

    bool isFull() {
        if (Top == (MaxSize - 1)){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(Top == -1){
            return true;
        }
        return false;
    }

    int CurrentSize(){
        return Top + 1;
    }

};

struct PrefixPostfix {

    Stack Resultant, operands;
    char Expression[50];

    PrefixPostfix(){
        cin.getline(Expression, sizeof(Expression));
    }

    int length() {
        int i = 0;
        while (Expression[i] != '='){
            i++;
        }
        return i-1;
    }

    const char * convertToPostfix(){
        int i = length();
        char *tempChar;
        char *operand_1;
        char *operand_2;
        char *tempString;
        char tempCharString[2];
        while(i>=0){
            tempChar = &Expression[i];
            tempCharString[0] = Expression[i];
            tempCharString[1] = '\0';
            if(*tempChar == '+' || *tempChar == '-' || *tempChar == '*' || *tempChar == '/' || *tempChar == '^'){
                tempString = new char[20];
                operand_1 = operands.pop();
                operand_2 = operands.pop();
                strcpy(tempString, operand_1);
                strcat(tempString, operand_2);
                strcat(tempString, tempCharString);
                operands.push(tempString);
            }

            else{
                tempString = new char[2];
                *tempString = *tempChar;
                *(tempString + 1) = '\0';
                operands.push(tempString);
            }

            i--;
        }

        return operands.StackArr[0];
    }
};

int main() {
    cout << "Enter the expression (prefix) and add '=' at the end: " << endl;
    PrefixPostfix S;
    cout << S.convertToPostfix();
    return 0;
}

//g++ prefix_postfix.cpp -o prefix_postfix.exe && prefix_postfix.exe
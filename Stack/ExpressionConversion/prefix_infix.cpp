//
// Created by Prasad on 4/27/2021.
//

#include<iostream>

using namespace std;

struct Stack{
    char StackArr[20];
    int MaxSize;
    int Top;
    int currentSize;
    Stack(){
        MaxSize = 20;
        Top = -1;
        currentSize = 0;
    }

    void push(char element) {
        try{
            if(!isFull()){
                StackArr[++Top] = element;
            }
            else throw overflow_error("");
        }
        catch(overflow_error &e){
            cout << e.what();
        }
    }


    char getTop() {
        try {
            if(!isEmpty()){
                return StackArr[Top];
            }
            else{
//                throw underflow_error("");
                return 'p';
            }
        }
        catch (underflow_error e) {
            cout << e.what();
        }
    }

    char pop() {
        try {
            if (!isEmpty()){
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

struct PrefixInfix {

    Stack Resultant, operands;
    char Expression[50];

    PrefixInfix(){
        cin.getline(Expression, sizeof(Expression));
    }

    int length() {
        int i = 0;
        while (Expression[i] != '='){
            i++;
        }
        return i-1;
    }

    const char * convertToInfix(){
        int i = length();
        char tempChar;
        char operand_1;
        char operand_2;
        while(i>=0){
            tempChar = Expression[i];
            if(tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/' || tempChar == '^'){
                operand_2 = operands.pop();
                operand_1 = operands.pop();
                Resultant.push(')');
                Resultant.push(operand_1);
                Resultant.push(tempChar);
                Resultant.push(operand_2);
                Resultant.push('(');
            }

            else{
                operands.push(Expression[i]);
            }

            i--;
        }

        Resultant.push('\0');
        char temp;
        for(int i = 0; i < (Resultant.Top-1)/2; i++){
            temp = Resultant.StackArr[i];
            Resultant.StackArr[i] = Resultant.StackArr[Resultant.Top - i - 1];
            Resultant.StackArr[Resultant.Top - i - 1] = temp;
        }
        return Resultant.StackArr;
    }
};

int main() {
    cout << "Enter the expression (postfix) and add '=' at the end: " << endl;
    PrefixInfix S;
    cout << S.convertToInfix();
    return 0;
}

//g++ prefix_infix.cpp -o prefix_infix.exe && prefix_infix.exe
//
// Created by Prasad on 4/26/2021.
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

int precedenceTable(char c) {
    switch(c){
        case('^'):
            return 3;
        case('*'):
            return 2;
        case('/'):
            return 2;
        case('+'):
            return 1;
        case('-'):
            return 1;
        default:
            return 0;
    }
}

class InfixExpression{
    Stack operators, Resultant;
    char Expression[50];
public:

    InfixExpression(){
        cin.getline(Expression,sizeof(Expression));
    }

    const char * ConvertToPostfix(){
        int i = 0;
        char tempChar;
        char complementParenthesis;
        while(Expression[i] != '='){
            tempChar = Expression[i];
            if(tempChar == '(' || tempChar == '{' || tempChar == '['){
                operators.push(tempChar);
            }

            else if(tempChar == ')' || tempChar == '}' || tempChar == ']'){
                switch(tempChar){
                    case(')'):
                        complementParenthesis = '(';
                        break;
                    case('}'):
                        complementParenthesis = '{';
                        break;
                    case(']'):
                        complementParenthesis = '[';
                }
                while(operators.getTop() != complementParenthesis){
                    Resultant.push(operators.pop());
                }
                operators.pop();
            }


            else if(tempChar=='^' || tempChar=='+' || tempChar=='-' || tempChar=='*' || tempChar=='/'){
                if((operators.getTop() == '(') || (operators.getTop() == '[') || (operators.getTop() == '{') || (precedenceTable(tempChar) > precedenceTable(operators.getTop()))){
                    operators.push(tempChar);
                }
                else{
                    while((precedenceTable(tempChar) <= precedenceTable(operators.getTop()))){
                        if((operators.getTop() != '(') || (operators.getTop() != '[') || (operators.getTop() != '{')){
                            Resultant.push(operators.pop());
                        }
                        else break;
                    }
                    operators.push(tempChar);
                }
            }

            else{
                Resultant.push(tempChar);
            }
            i++;
        }
        if(Expression[i] == '='){
            while(!operators.isEmpty()){
                Resultant.push(operators.pop());
            }
        }
        Resultant.push('\0');
        return Resultant.StackArr;
    }
};

int main() {
    cout << "Enter the infix expression with '=' at the end: " << endl;
    InfixExpression I1;
    cout << I1.ConvertToPostfix();
    return 0;
}


//g++ infix_postfix.cpp -o infix_postfix.exe && infix_postfix.exe
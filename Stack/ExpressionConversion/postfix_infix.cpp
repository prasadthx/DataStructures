////
//// Created by Prasad on 4/27/2021.
////
//
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//struct Stack{
//    char *StackArr[5];
//    int MaxSize;
//    int Top;
//    int currentSize;
//    Stack(){
//        MaxSize = 20;
//        Top = -1;
//        currentSize = 0;
//    }
//
//    void push(char * elementString) {
//        try{
//            if(!isFull()){
//                cout <<"Pre push" << *elementString <<endl;
//                StackArr[++Top] = elementString;
//                cout << "Post push" << *StackArr[Top] << endl;
//            }
//            else throw overflow_error("");
//        }
//        catch(overflow_error &e){
//            cout << e.what();
//        }
//    }
//
//
//    char * getTop() {
//        try {
//            if(!isEmpty()){
//                return StackArr[Top];
//            }
//            else{
//                throw underflow_error("");
//            }
//        }
//        catch (underflow_error e) {
//            cout << e.what();
//        }
//    }
//
//    char * pop() {
//        try {
//            if (!isEmpty()){
//                cout << "Pre pop" << *StackArr[Top] << endl;
//                return StackArr[Top--];
//            }
//            else throw underflow_error("");
//        }
//        catch (underflow_error &e) {
//            cout << e.what() ;
//        }
//    }
//
//    bool isFull() {
//        if (Top == (MaxSize - 1)){
//            return true;
//        }
//        return false;
//    }
//
//    bool isEmpty(){
//        if(Top == -1){
//            return true;
//        }
//        return false;
//    }
//
//};
//
//struct PostfixInfix {
//
//    Stack Resultant, operands;
//    char Expression[50];
//
//    PostfixInfix(){
//        cin.getline(Expression, sizeof(Expression));
//    }
//
//    const char * convertToInfix(){
//        int i = 0;
//        char *tempString;
//        char *tempChar;
//        char *operand_1;
//        char *operand_2;
//        char temp[2];
//        while(Expression[i] != '='){
//            tempChar = new char;
//            *tempChar = Expression[i];
//            temp[0] = *tempChar;
//            temp[1] = '\0';
//            if(*tempChar == '+' || *tempChar == '-' || *tempChar == '*' || *tempChar == '/' || *tempChar == '^'){
//
//                tempString = new char[20];
//
//                operand_2 = operands.pop();
//                operand_1 = operands.pop();
//
//                strcpy(tempString,"(");
//                cout <<"ts string 1"<< tempString << endl;
//                strcat(tempString, operand_1);
//                cout <<"ts string 2"<< tempString << "  " << *operand_1 << endl;
//                strcat(tempString, temp);
//                cout <<"ts string 3"<< tempString << endl;
//                strcat(tempString, operand_2);
//                cout <<"ts string 4"<< tempString << "  " << strlen(operand_2) << endl;
//                strcat(tempString, ")");
//                cout <<"ts string 5"<< tempString << endl;
//                operands.push(tempString);
//
//            }
//
//            else{
//                tempString = new char[2];
//                *tempString = *tempChar;
//                *(tempString + 1) = '\0';
//                operands.push(tempString);
//            }
//
//            i++;
//        }
//
//        operands.push("\0");
//        return operands.StackArr[0];
//    }
//};
//
//int main() {
//    cout << "Enter the expression (postfix) and add '=' at the end: " << endl;
//    PostfixInfix S;
//    cout << S.convertToInfix();
//    return 0;
//}
//
//
////g++ postfix_infix.cpp -o postfix_infix.exe && postfix_infix.exe
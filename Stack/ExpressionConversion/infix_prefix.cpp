//
//#include<iostream>
//
//using namespace std;
//
//struct Stack{
//    char StackArr[50];
//    int MaxCapacity;
//    int Top;
//    int currentSize;
//
//    Stack(){
//        MaxCapacity = 50;
//        Top = -1;
//        currentSize = 0;
//    }
//
//    char getTop();
//    char pop();
//    void push(int element);
//    bool isEmpty();
//    bool isFull();
//    int CurrentSize();
//};
//
//char Stack::getTop() {
//    try {
//        if(!isEmpty()){
//            return StackArr[Top];
//        }
//        else{
////            throw underflow_error("Stack is empty");
//            return 'p';
//        }
//    }
//    catch (underflow_error e) {
//        cout << e.what() << endl;
//    }
//}
//
//char Stack::pop() {
//    try {
//        if (!isEmpty()){
//            return StackArr[Top--];
//        }
//        else throw underflow_error("Stack is empty");
//    }
//    catch (underflow_error &e) {
//        cout << e.what() << endl;
//    }
//}
//
//bool Stack::isFull() {
//    if (Top == (MaxCapacity - 1)){
//        return true;
//    }
//    return false;
//}
//
//bool Stack::isEmpty(){
//    if(Top == -1){
//        return true;
//    }
//    return false;
//}
//
//int Stack::CurrentSize(){
//    return Top + 1;
//}
//
//void Stack::push(int element) {
//    try{
//        if(!isFull()){
//            StackArr[++Top] = element;
//        }
//        else throw overflow_error("Stack is full");
//    }
//    catch(overflow_error &e){
//        cout << e.what() << endl;
//    }
//}
//
//int precedenceTable(char c) {
//    switch(c){
//        case('^'):
//            return 3;
//        case('*'):
//            return 2;
//        case('/'):
//            return 2;
//        case('+'):
//            return 1;
//        case('-'):
//            return 1;
//        default:
//            return 0;
//    }
//}
//
//struct InfixExpression{
//    Stack operators, Resultant;
//    char Expression[50];
//
//    InfixExpression(){
//        cin.getline(Expression, sizeof(Expression));
//    }
//
//    int length(){
//        int i = 0;
//        for(i ; Expression[i] != '='; i++);
//        return i-1;
//    }
//
//    const char * convertToPrefix() {
//        int i = length();
//        char tempChar;
//        char complementParenthesis;
//        for (i; i >= 0; i--) {
//            tempChar = Expression[i];
//
//            if (tempChar == ')' || tempChar == '}' || tempChar == ']') {
//                operators.push(tempChar);
//            }
//
//            else if (tempChar == '(' || tempChar == '{' || tempChar == '[') {
//                switch (tempChar) {
//                    case ('('):
//                        complementParenthesis = ')';
//                        break;
//                    case ('{'):
//                        complementParenthesis = '}';
//                        break;
//                    case ('['):
//                        complementParenthesis = ']';
//                }
//                while (operators.getTop() != complementParenthesis) {
//                    Resultant.push(operators.pop());
//                }
//                operators.pop();
//            }
//
//            else if (tempChar == '^' || tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/') {
//                if ((operators.isEmpty()) || (operators.getTop() == ')') || (operators.getTop() == ']') || (operators.getTop() == '}') ||
//                    (precedenceTable(tempChar) > precedenceTable(operators.getTop()))) {
//                    operators.push(tempChar);
//                }
//                else {
//                    while ((precedenceTable(tempChar) <= precedenceTable(operators.getTop()))) {
//                        if ((operators.getTop() != ')') || (operators.getTop() != ']') || (operators.getTop() != '}')) {
//                            Resultant.push(operators.pop());
//                        } else break;
//                    }
//                    operators.push(tempChar);
//                }
//            }
//
//            else {
//                Resultant.push(tempChar);
//            }
//
//        }
//        if (i == -1) {
//            while (!operators.isEmpty()) {
//                Resultant.push(operators.pop());
//            }
//        }
//        Resultant.push('\0');
//        char temp;
//        for (int i = 0; i < (Resultant.Top-1)/2 ; i++){
//            temp = Resultant.StackArr[i];
//            Resultant.StackArr[i] = Resultant.StackArr[Resultant.Top - i - 1];
//            Resultant.StackArr[Resultant.Top - i - 1] = temp;
//        }
//
//        return Resultant.StackArr;
//    };
//};
//int main() {
//    cout << "Enter the infix expression with '=' at the end :" << endl;
//    InfixExpression S1;
//    cout << S1.convertToPrefix();
//    return 0;
//}

////g++ infix_prefix.cpp -o infix_prefix.exe && infix_prefix.exe
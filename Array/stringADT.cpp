//
// Created by Prasad on 4/25/2021.
//

#include<iostream>

using namespace std;

struct String{
    char Str[20] = "Prasad";
    String(){};
    int Length();
    void DisplayString()
    void Concatenate(String B);
    String Copy();
    String CopyReverse()
    int SubString(String S);
    bool IsPalindrome();
    void ReverseString();

};

int String::Length() {
    int length = 0;
    while(Str[length]!='\0'){
        length++;
    }
    return length;
}

void String::Concatenate(String B) {
    int length = Length();
    int it = 0;
    while(B.Str[it] != '\0'){
        Str[length + it] = B.Str[it];
        it++;
    }
    it = 0;
    while(Str[it]!='\0'){
        cout << Str[it];
        it++;
    }
}

String String::Copy() {
    String B;
    int it = 0;
    while(B.Str[it] != '\0'){
        B.Str[it] = Str[it];
        it++;
    }
    B.Str[it] = '\0';
    return B;
}

int main(){
    String S, S1;
//
//    cout << S.Length();
    S.Concatenate(S1);
    return 0;
}
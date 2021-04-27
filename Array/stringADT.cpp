//
// Created by Prasad on 4/25/2021.
//

#include<iostream>

using namespace std;

struct String{
    char Str[20] = "Prasad";
    String(){};
    int Length();
    void DisplayString();
    void Concatenate(String B);
    String Copy();
    String CopyReverse();
    int SubString(String S);
    bool IsPalindrome();
    void ReverseString();
    bool StrCompare(String S);
};

int String::Length() {
    int length = 0;
    while(Str[length]!='\0'){
        length++;
    }
    return length;
}

void String::DisplayString() {
    int i = 0;
    while(Str[i]!='\0'){
        cout << Str[i];
        i++;
    }
}

void String::Concatenate(String B) {
    int length = Length();
    int it = 0;
    while(B.Str[it] != '\0'){
        Str[length + it] = B.Str[it];
        it++;
    }
    it = 0;
    DisplayString();
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

void String::ReverseString() {
    int length = Length();
    char temp;
    for(int it=0 ; it < length/2 ; it++){
        temp = Str[it];
        Str[it] = Str[(length - 1) - it];
        Str[(length - 1) - it] = temp;
    }
}

String String::CopyReverse() {
    String B;
    int length = Length();
    int it = length;
    for(it; it > 0 ; it--){
        B.Str[length-it] = Str[it-1];
    }
    B.Str[length] = '\0';
    return B;
}

bool String::StrCompare(String S) {
    int length = Length();
    int length2 = S.Length();
    if (length != length2){
        return false;
    }
    for (int i = 0; i < length ; i++){
        if (Str[i] != S.Str[i]){
            return false;
        }
    }
    return true;
}

bool String::IsPalindrome() {
    int length = Length();
    for (int i = 0; i < length/2; i++){
        if(Str[i] != Str[(length - 1) - i]){
            return false;
        }
    }
    return true;
}

int main(){
    String S, S1;
    S.ReverseString();
    S.DisplayString();
    cout << '\n' << S.IsPalindrome() <<endl;
    return 0;
}
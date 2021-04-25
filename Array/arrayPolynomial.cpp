////
//// Created by Prasad on 4/24/2021.
////
//
//#include<iostream>
//#include<map>
//
//using namespace std;
//
//typedef struct {
//    int coefficient;
//    int exponent;
//}PolynomialTerm;
//
//struct Polynomial{
//    PolynomialTerm polynomial[20];
//    int totalTerms;
//    Polynomial(){
//        totalTerms = 0;
//    }
//    void ReadPolynomial();
//    void DisplayPolynomial();
//    double EvaluatePolynomial(double value);
//    Polynomial addPolynomial(Polynomial secondPolynomial);
//    Polynomial MultiplyPolynomial(Polynomial secondPolynomial);
//};
//
//void Polynomial::ReadPolynomial(){
//    cout << "Enter the total terms in the polynomial " << endl;
//    cin >> totalTerms;
//    for (int i = 0; i <= totalTerms; i++){
//        cout << "Enter the coefficient of " << i+1 << "term: " <<endl;
//        cin >> polynomial[i].coefficient ;
//        cout << "Enter the exponent of " << i+1 << "term: " <<endl;
//        cin >> polynomial[i].exponent;
//    }
//}
//
//void Polynomial::DisplayPolynomial(){
//    for (int index = 0 ; index <= totalTerms ; index++){
//        cout << polynomial[index].coefficient << "x^" <<polynomial[index].exponent << " + " ;
//        cout << "\b";
//    }
//    cout << endl;
//}
//
//double Polynomial::EvaluatePolynomial(double value){
//    double answer = 0;
//    for (int index=0;index<=totalTerms;index++){
//        answer = answer + polynomial[index].coefficient * pow(value,polynomial[index].exponent);
//    }
//    return answer;
//}
//
//Polynomial Polynomial::addPolynomial(Polynomial secondPolynomial) {
//    int k = 0;
//    int j = 0 ;
//    int i = 0;
//    Polynomial resultant;
//    while (i <= totalTerms && j <= secondPolynomial.totalTerms){
//        if(polynomial[i].exponent==secondPolynomial.polynomial[j].exponent){
//            resultant.polynomial[k].exponent = polynomial[i].exponent;
//            resultant.polynomial[k].coefficient = polynomial[i].coefficient + secondPolynomial.polynomial[j].coefficient;
//            i = i + 1;
//            j = j + 1;
//            k = k + 1;
//        }
//        else if (polynomial[i].exponent > secondPolynomial.polynomial[j].exponent){
//            resultant.polynomial[k].exponent = polynomial[i].exponent;
//            resultant.polynomial[k].coefficient = polynomial[i].coefficient;
//            i = i + 1;
//            k = k + 1;
//        }
//        else if(polynomial[i].exponent < secondPolynomial.polynomial[j].exponent){
//            resultant.polynomial[k].exponent = secondPolynomial.polynomial[j].exponent;
//            resultant.polynomial[k].coefficient = secondPolynomial.polynomial[j].coefficient;
//            j = j + 1;
//            k = k + 1;
//        }
//    }
//    if(i > totalTerms){
//        for(j; j<= secondPolynomial.totalTerms;j++){
//            resultant.polynomial[k].coefficient = secondPolynomial.polynomial[j].coefficient;
//            resultant.polynomial[k].exponent = secondPolynomial.polynomial[j].exponent;
//            k = k + 1;
//        }
//    }
//    if(j > secondPolynomial.totalTerms){
//        for(i; i<= totalTerms; i++){
//            resultant.polynomial[k].coefficient = polynomial[i].coefficient;
//            resultant.polynomial[k].exponent = polynomial[i].exponent;
//            k = k + 1;
//        }
//    }
//    resultant.totalTerms = k-1;
//    return resultant;
//}
//
//Polynomial Polynomial::MultiplyPolynomial(Polynomial secondPolynomial) {
//    Polynomial resultant;
//    int k = 0;
//    map<int, int> exponentStorage;
//    int tempCoefficient;
//    int tempExponent;
//    int index = -1;
//    for(int i = 0; i <= totalTerms; i++){
//        for(int j = 0; j <= totalTerms; j++){
//
//            tempCoefficient = polynomial[i].coefficient * secondPolynomial.polynomial[j].coefficient;
//            tempExponent = polynomial[i].exponent + secondPolynomial.polynomial[j].exponent;
//
//            if(exponentStorage[tempExponent]){
//                cout << "Existing "<<tempExponent<<endl;
//                resultant.polynomial[exponentStorage[tempExponent]].exponent += tempExponent;
//                resultant.polynomial[exponentStorage[tempExponent]].coefficient += tempCoefficient;
//            }
//
//            else{
//                cout << "New "<<index<< endl;
//                index = index + 1;
//                exponentStorage[tempExponent] = index;
//                resultant.polynomial[index].exponent = tempExponent;
//                resultant.polynomial[index].coefficient = tempCoefficient;
//            }
//        }
//    }
//    resultant.totalTerms = index;
//    return resultant;
//}
//
//int main(){
//    Polynomial S1, S2, S3;
//    double answer;
//    S1.ReadPolynomial();
//    S2.ReadPolynomial();
//    S1.DisplayPolynomial();
//    S2.DisplayPolynomial();
////    answer = S.EvaluatePolynomial(23.11);
////    cout << "The answer is " << answer << endl;
////    S3 = S1.addPolynomial(S2);
//    S3 = S1.MultiplyPolynomial(S2);
//    S3.DisplayPolynomial();
//    return 0;
//}
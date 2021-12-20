//
// Created by Think on 2021/5/20.
//
#include <iostream>
using namespace std;

template <typename T>
T Max(T one, T two);

int main(){
    //int i_one=3,i_two=5;
    //double i_one=1.3,i_two=35.5;
    string i_one="fffff",i_two="21b3";
    cout << "The max of " << i_one << " and " << i_two << " is "
    << Max(i_one,i_two) << endl;

    return 0;
}

template <typename T2>
T2 Max(T2 one, T2 two){
    T2 biggest;
    if (one < two) biggest = two;
    else biggest = one;
    return biggest;
}

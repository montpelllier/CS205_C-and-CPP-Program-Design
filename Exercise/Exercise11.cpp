//
// Created by Think on 2021/4/29.
//
#include <iostream>
#include "Complex.h"
#include "Number.h"

using namespace std;

void one(){
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a - 2 is " << a - 2 << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * a is " << 2 * a << endl;

    Complex c = b;
    cout << boolalpha;
    cout << "b == c is " << (b == c) << endl;
    cout << "b != c is " << (b != c) << endl;
    cout << "a == c is " << (a == c) << endl;
    cout << noboolalpha;

    Complex d;
    cout << "Enter a complex number: \n";
    cin >> d;
    cout << "d is " << d << endl;
}

void two(){
    Number n1(20);
    Number n2 = n1++;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;

    Number n3 = n2--;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;

    Number n4 = ++n3;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    Number n5 = --n4;
    cout << "n4 = " << n4 << endl;
    cout << "n5 = " << n5 << endl;
    //++n5++;
}
int main(){
    one();
    two();

    return 0;
}

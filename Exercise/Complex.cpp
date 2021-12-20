//
// Created by Think on 2021/4/29.
//
#include <iostream>
#include "Complex.h"

Complex::Complex() : real(0), imag(0){}
Complex::Complex(double re, double im) : real(re), imag(im){}
Complex Complex::Add(const Complex &data) {
    Complex sum;
    sum.real = data.real + this->real;
    sum.imag = data.imag + this->imag;
    return sum;
}
Complex Complex::operator+(const Complex &other) const {
    double result_real = real + other.real;
    double result_imag = real + other.imag;
    return Complex(result_real, result_imag);
}
Complex Complex::operator +(double real) const{
    return Complex(this->real+real, this->imag);
}
Complex Complex::operator -(const Complex& other) const{
    double result_real = real - other.real;
    double result_imag = imag - other.imag;
    return Complex(result_real, result_imag);
}
Complex Complex::operator -(double real) const{
    return Complex(this->real-real, this->imag);
}
Complex Complex::operator *(const Complex& other) const{
    double result_real = real*other.real - imag*other.imag;
    double result_imag = real*other.imag + imag*other.real;
    return Complex(result_real, result_imag);
}
Complex operator *(const Complex& complex, double real) {
    return Complex(complex.real*real, complex.imag*real);
}
Complex operator *(double real, const Complex& complex) {
    return Complex(complex.real*real, complex.imag*real);
}
Complex Complex::operator~() const {
    return Complex(this->real, -this->imag);
}
bool Complex::operator ==(const Complex& other) const{
    return (this->real==other.real)&&(this->imag==other.imag);
}
bool Complex::operator !=(const Complex& other) const{
    return !((this->real==other.real)&&(this->imag==other.imag));
}
void Complex::Show() const {
    std::cout << real << " + " << imag << "i\n";
}
std::ostream & operator<< (std::ostream& os, const Complex& other){
    os << other.real;
    if (other.imag > 0) os << " + " << other.imag << "i";
    else if (other.imag < 0) os << " - " << -other.imag << "i";
    return os;
}
void operator>> (std::istream &in, Complex &other) {
    std::cout << "real:";
    in >> other.real;
    std::cout << "imaginary:";
    in >> other.imag;
}



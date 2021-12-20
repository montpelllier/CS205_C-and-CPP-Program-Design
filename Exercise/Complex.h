//
// Created by Think on 2021/4/29.
//

#ifndef LAB_COMPLEX_H
#define LAB_COMPLEX_H


class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double re, double im);
    Complex Add(const Complex& data);
    Complex operator +(const Complex& other) const;
    Complex operator +(double real) const;
    Complex operator -(const Complex& other) const;
    Complex operator -(double real) const;
    Complex operator *(const Complex& other) const;
    friend Complex operator *(const Complex& complex, double real);
    friend Complex operator *(double real, const Complex& complex);
    Complex operator ~() const;
    bool operator ==(const Complex& other) const;
    bool operator !=(const Complex& other) const;

    void Show() const;
    friend std::ostream & operator << (std::ostream& os, const Complex& other);
    friend void operator >> (std::istream& in, Complex& other);
};


#endif //LAB_COMPLEX_H

//
// Created by Think on 2021/4/29.
//

#ifndef LAB_NUMBER_H
#define LAB_NUMBER_H


class Number {
private:
    int num;

public:
    Number();
    Number(int i);

    Number operator ++();
    Number operator ++(int);
    Number operator --();
    Number operator --(int);

    friend std::ostream & operator << (std::ostream& os, const Number& other);
    //friend void operator >> (std::istream& in, Complex& other);
};

#endif //LAB_NUMBER_H

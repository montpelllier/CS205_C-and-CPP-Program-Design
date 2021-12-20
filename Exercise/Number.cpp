//
// Created by Think on 2021/4/29.
//
#include <iostream>
#include "Number.h"


Number::Number() : num(0) {}
Number::Number(int i) : num(i) {}
Number Number::operator++() {//前置++
    ++num;
    return *this;
}
Number Number::operator++(int) {//后置++
    Number ret(num);
    num++;
    return ret;
}
Number Number::operator --(){
    --num;
    return *this;
}
Number Number::operator --(int){
    Number ret(num);
    num--;
    return ret;
}
std::ostream &operator<<(std::ostream &os, const Number &other) {
    os << other.num;
    return os;
}




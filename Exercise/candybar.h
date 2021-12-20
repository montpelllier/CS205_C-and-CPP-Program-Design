//
// Created by Think on 2021/4/8.
//
#ifndef LAB_CANDYBAR_H
#define LAB_CANDYBAR_H
#include <iostream>

const int LEN = 30;
struct CandyBar{
    char brand[30];
    double weight;
    int calories;
};

void set(CandyBar & cb);
void set(CandyBar* const cb);
void show(const CandyBar & cb);
void show(const CandyBar* cb);

#endif //LAB_CANDYBAR_H

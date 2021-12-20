//
// Created by Think on 2021/4/8.
//
#include "candybar.h"
#include <iostream>

using namespace std;

void set(CandyBar & cb){
    cout << "Call the set function of Passing by reference:\n"
    << "Enter brand name of a Candy bar:\n";
    cin >> cb.brand;
    cout << "Enter weight of the Candy bar:\n";
    cin >> cb.weight;
    cout << "Enter calories(an integer value) in the Candy bar:\n";
    cin >> cb.calories;
};
void set(CandyBar* const cb){
    cout << "Call the set function of Passing by pointer:\n"
    << "please input brand name\n";
    cin >> cb->brand;
    cout << "please input weight\n";
    cin >> cb->weight;
    cout << "please input calories\n";
    cin >> cb->calories;
};
void show(const CandyBar & cb){
    cout << "Call the show function of Passing by reference:\n"
    << "Brand: " << cb.brand << endl
    << "Weight: " << cb.weight << endl
    << "Calories: " << cb.calories << endl;
};
void show(const CandyBar* cb){
    cout << "Call the show function of Passing by pointer:\n"
         << "Brand: " << cb->brand << endl
         << "Weight: " << cb->weight << endl
         << "Calories: " << cb->calories << endl;
};

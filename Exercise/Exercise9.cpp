//
// Created by Think on 2021/4/15.
//
#include "golf.h"
#include "sale.h"
#include <iostream>

using namespace std;
using namespace SALES;

int main(){
    golf ann, andy;
    cout << "First version of setgolf function:\n";
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    cout << "Second version of setgolf function\n";
    while (!setgolf(andy));
    showgolf(andy);

    cout << "\nNon-interactive version of setSales():";
    Sales sales1, sales2;
    double arr[] = {345.2, 621.8, 1073.5};
    setSales(sales1, arr, 3);
    showSales(sales1);
    cout << "\nInteractive version of setSales():";
    setSales(sales2);
    showSales(sales2);
}
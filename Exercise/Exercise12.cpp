//
// Created by Think on 2021/5/6.
//
#include <iostream>
#include "Stock.h"
#include "Stack.h"

using namespace std;

int main(){
    Stock stock1("cpp");
    cout << stock1 << endl;
    stock1.buy(200,4.13);
    stock1.sell(300,3.1);
    cout << stock1 << endl;
    Stock stock2("cmm",30,413.23);
    stock2.sell(20,3);
    stock1.update(1);
    cout << stock1.topval(stock2) << endl;
    //~Stock(stock1);

    Stack stack1;
    cout << boolalpha;
    cout << stack1.push(90) << endl;
    stack1.show();
    Stack stack2(2);
    stack2.push(2);
    stack2.push(13);
    unsigned long pop = 0;
    stack2.show();
    cout << stack2.pop(pop) << " " << pop << endl;
    stack2 = stack1;
    stack2.push(12);
    stack2.show();

}
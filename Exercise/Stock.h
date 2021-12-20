//
// Created by Think on 2021/5/6.
//

#ifndef LAB_STOCK_H
#define LAB_STOCK_H
#include <string>

class Stock {
private:
    char* company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){total_val = shares * share_val;}

public:
    Stock();
    Stock(const char* co, long n = 0, double pr = 0.0);
    ~Stock();//destructor

    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    friend std::ostream & operator << (std::ostream& os, const Stock& s);
    const Stock& topval(const Stock& s) const;
};

#endif //LAB_STOCK_H

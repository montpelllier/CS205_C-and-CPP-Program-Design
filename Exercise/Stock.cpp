//
// Created by Think on 2021/5/6.
//
#include <cstring>
#include <iostream>
#include "Stock.h"
Stock::Stock() // default constructor
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const char* co, long n, double pr){
    if (co){
        company = new char[strlen(co)+1];
        strcpy(company, co);
        if (n < 0){
            std::cout << "Number of shares can't be negative; "
                      << company << " shares set to 0.\n";
            shares = 0;
        } else shares = n;
        share_val = pr;
        set_tot();
    } else{
        company = new char[1];
        *company = '\0';
    }
}
Stock::~Stock(){
    delete[] company;
}//destructor
void Stock::buy(long num, double price){
    if (num < 0){
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price){
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can't sell more than you have!' "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price){
    share_val = price;
    set_tot();
}
void Stock::show() const{
    std::cout << company << std::endl
    << shares << std::endl
    << share_val << std::endl
    << total_val << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Stock &s) {
    os << s.company << "\n" << s.shares << "\n" << s.share_val << "\n" << s.total_val << "\n";
    return os;
}
const Stock& Stock::topval(const Stock& s) const{
    if (s.total_val > total_val) return s;
    else return *this;
}



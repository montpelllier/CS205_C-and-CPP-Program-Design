//
// Created by Think on 2021/4/15.
//

#ifndef LAB_SALE_H
#define LAB_SALE_H

namespace SALES{
    const int QUARTERS = 4;
    struct Sales{
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales& s, const double ar[], int n);
    void setSales(Sales& s);
    void showSales(const Sales& s);
}

#endif //LAB_SALE_H

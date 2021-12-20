//
// Created by Think on 2021/4/15.
//
#include <algorithm>
#include <iostream>
#include "sale.h"

using namespace std;
namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        double arr[n];
        for (int i = 0; i < n; ++i) arr[i] = ar[i];
        sort(arr, arr + n);
        s.max = arr[n - 1];
        s.min = arr[0];
        s.average = 0;
        for (int i = 0; i < min(QUARTERS, n); ++i) {
            s.sales[i] = arr[i];
            s.average += arr[i];
        }
        for (int i = min(QUARTERS, n); i < max(QUARTERS, n); ++i) {
            if (i < QUARTERS) s.sales[i] = 0;
            if (i < n) s.average += arr[i];
        }
        s.average /= n;
    }

    void setSales(Sales &s) {
        cout << "\nEnter sales for 4 quarters: ";
        for (int i = 0; i < QUARTERS; ++i) {
            cin >> s.sales[i];
            s.average += s.sales[i];
        }
        s.average /= QUARTERS;
        s.max = s.sales[0];
        s.min = s.sales[0];
        for (int i = 0; i < QUARTERS; ++i) {
            if (s.max < s.sales[i]) s.max = s.sales[i];
            if (s.min > s.sales[i]) s.min = s.sales[i];
        }
    }

    void showSales(const Sales &s) {
        cout << "\nSales:";
        for (int i = 0; i < QUARTERS; ++i) {
            if (s.sales[i] != 0) cout << s.sales[i] << " ";
        }
        cout << "\nAverage:" << s.average
             << "\nMax:" << s.max
             << "\nMin:" << s.min;
    }
}



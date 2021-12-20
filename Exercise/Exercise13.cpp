//
// Created by Think on 2021/5/13.
//

#include <iostream>
#include "CStereoShape.h"

#define PI 3.1415926

using namespace std;

int main(){
    CCube a_cube(4,5,6);
    CSphere c_sphere(7.9);
    CStereoShape* p;
    p = &a_cube;
    p->Show();

    p = &c_sphere;
    p->Show();
    cout << p->GetNumOfObject() << " objects are created.\n";
    delete p;
}
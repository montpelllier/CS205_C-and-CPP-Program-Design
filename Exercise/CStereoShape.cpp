//
// Created by Think on 2021/5/13.
//
#include <iostream>
#include "CStereoShape.h"
#define PI 3.1415926

using namespace std;

int CStereoShape::numberOfObject = 0;

double CStereoShape::GetArea() {
    cout << "CStereoShape::GetArea()";
    return 0;
}

double CStereoShape::GetVolume() {
    cout << "CStereoShape::GetVolume()";
    return 0;
}

void CStereoShape::Show() {
    cout << "CStereoShape::Show()";
}

Formatting CStereoShape::SetFormat(int prec) const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(prec);
    return f;
}

void CStereoShape::Restore(Formatting& f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(3);
}

CCube::CCube(double length, double width, double height) {
    this->length = length;
    this->width = width;
    this->height = height;
}

CCube::CCube(CCube &cub) {
    length = cub.length;
    width = cub.width;
    height = cub.height;
}

double CCube::GetArea() {
    return 2*(length*width+length*height+width*height);
}

double CCube::GetVolume() {
    return length*width*height;
}

void CCube::Show() {
    Formatting flag = SetFormat(0);
    cout << "length: " << length
    << "\twidth: " << width
    << "\theight: " << height
    << "\tthe surface area: " << GetArea()
    << "\tthe volume: " << GetVolume() << endl;
    Restore(flag);
}

CSphere::CSphere(double radius) : radius(radius) {}

CSphere::CSphere(CSphere &sphere) {
    radius = sphere.radius;
}

double CSphere::GetArea() {
    return 4*PI*radius*radius;
}

double CSphere::GetVolume() {
    return 4.0/3.0*PI*radius*radius*radius;
}

void CSphere::Show() {
    Formatting flag = SetFormat(3);
    cout << "radius: " << radius
         << "\tthe surface area: " << GetArea()
         << "\tthe volume: " << GetVolume() << endl;
    Restore(flag);
}





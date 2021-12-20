//
// Created by Think on 2021/4/15.
//
#include "golf.h"
#include <iostream>
#include <cstring>

using namespace std;

void setgolf(golf& g, const char* name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}
int setgolf(golf& g){
    cout << "Enter the fullname: ";
    cin.getline(g.fullname, Len);
    cout << "Enter the handicap: ";
    cin >> g.handicap;
    cin.get();
    if (strcmp(g.fullname, "")) return 1;
    else return 0;
}
void handicap(golf& g, int hc){
    cout << "Enter the handicap: ";
    cin >> g.handicap;
}
void showgolf(const golf& g){
    cout << "The name of golf is " << g.fullname
    << " and its handicap is " << g.handicap << endl;
}
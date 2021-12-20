//
// Created by Think on 2021/4/15.
//

#ifndef LAB_GOLF_H
#define LAB_GOLF_H
const int Len = 40;
struct golf{
    char fullname[Len];
    int handicap;
};

void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);
#endif //LAB_GOLF_H

//
// Created by Think on 2021/4/1.
//
#include <iostream>
#include <cstring>

using namespace std;

struct stringy{
    char *str;  // points to a string
    int ct;     // length without counting '\0'
};
// prototypes for set( ), show( ) and show ( ) go here
void set(stringy string, char copy[]){
    strcpy(string.str, copy);
    string.ct = strlen(copy);
}

void show(stringy string, int i=1){
    while (i-->0) {
       cout << string.str << endl;
    }
}

void show(char ch[], int i=1){
    while (i-->0) cout << ch << endl;
}

void one(){
    stringy beany;

    char testing[] = "Reality isn't what it used to be.";
    beany.str = new char[strlen(testing)];

    set(beany, testing); // first argument is a reference
    show(beany);// print member string once
    show (beany, 2);// prints member string twice

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing) ;// prints testing string once
    show (testing,3);// prints test string thrice
    show ("Done!");

    delete beany.str;
}

template <typename T>
T max5(T arr[]){
    T max = arr[0];
    for (int i = 0; i <= sizeof(arr); ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void two(){
    int arr1[] = {1,2,3,4,5};
    double arr2[] = {2.34,3.1,5.3,1.2,13.2};
    cout << max5(arr1) << endl
         << max5(arr2) << endl;
}

int main(){
    one();
    two();
}
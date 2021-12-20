//
// Created by Think on 2021/5/27.
//
//use_tv.cpp -- using the Tv and Remote classes
#include <iostream>
#include "tv.h"

using namespace std;

class Error{
public:
    int para, num;
    Error(int p, int n) {para = p;num = n;}
};

float calculateAverage(int a, int b, int c, int d) {
    if (a>100 || a<0) throw Error(1,a);
    else if (b>100 || b<0) throw Error(2,b);
    else if (c>100 || c<0) throw Error(3,c);
    else if (d>100 || d<0) throw Error(4,d);
    return (a+b+c+d)/4.0;

}

int main()
{
    Tv s42;
    Remote grey;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    grey.show_state();
    s42.set_remote(grey);

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.onoff();
    s42.chanup();
    grey.set_chan(s42, 3);
    s42.settings();
    cout << "After toggling the Remote state:\n";
    s42.set_remote(grey);
    grey.show_state();

    int arr[4];
    float avg;
    char cont = 'n';
    while (true){
        try {
            cout << "Please enter marks for 4 courses:";
            cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
            avg = calculateAverage(arr[0],arr[1],arr[2],arr[3]);
            cout << "The average of four courses is " << avg << endl;
        }catch (Error &e){
            cout << "The parameter " << e.para << " is " << e.num
                 << " which out of range (0-100).\n";
        }

        cout << "Would you want to enter another marks for 4 courses(y/n)?";
        cin >> cont;
        if (cont == 'n'){
            cout << "Bye, see you next time.\n";
            return 0;
        }
    }


    return 0;
}
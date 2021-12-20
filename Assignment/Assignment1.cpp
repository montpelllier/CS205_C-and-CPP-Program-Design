#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define PI 3.1415926535898

double getDistance(float phi1,float phi2,float theta1,float theta2) {
    float c = sin(phi1)*sin(phi2)*cos(theta1-theta2) + cos(phi1)*cos(phi2);
    return 6371*acos(c);
}

int main(){
    string city1, city2, errorInf;
    errorInf = "Please input applicable numbers for latitude (from -90 to 90, float) and longitude (from -180 to 180, float)";
    float lat1, lat2, lon1, lon2, dis;
    //input
    cout << "The first city: ";
    getline(cin,city1);
    cout << "The latitude and longitude of first city: ";
    if(!(cin >> lat1 >> lon1) || lat1<-90 || lat1>90 || lon1<-180 || lon1>180) {
        cout << errorInf;
        exit(100);
    }
    cin.get();

    cout << "The second city: ";
    getline(cin,city2);
    cout << "The latitude and longitude of second city: ";
    if(!(cin >> lat2 >> lon2) || lat2<-90 || lat2>90 || lon2<-180 || lon2>180) {
        cout << errorInf;
        exit(100);
    }
    cin.get();
    //output
    dis = getDistance((90-lat1)/180*PI,(90-lat2)/180*PI,lon1/180*PI,lon2/180*PI);
    cout << "The distance between "+city1+" and "+city2+" is " << dis << " km" << endl;
    //terminate
    return 0;
}
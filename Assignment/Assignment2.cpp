//
// Created by Think on 2021/3/30.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>

#define ch_size 48
#define st_size 1000
#define PI 3.1415926535898

using namespace std;

int index = 0;//length of struct City
struct City{
    char city_name[ch_size];
    char province_state[ch_size];
    char country[ch_size];
    float latitude;
    float longitude;
};

int get_city(City cities[], string name){
    string temp;
    int city = -1, compare, num=0;
    while (true){
        if (name.length() > 3) {
            cout << "Search result(only when unique the result is valid):\n";
            for (int i = 0; i < index; ++i) {
                temp = cities[i].city_name;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                compare = temp.find(name);
                if (compare >= 0) {
                    city = i;
                    cout << "city name: " << cities[i].city_name
                         << ", latitude: " << cities[i].latitude
                         << ", longitude: " << cities[i].longitude << endl;
                    num++;
                }
            }
            if (num <= 1) return city;
            else return -2;
        } else {
            cout << "Too short! You may want to input:\n";
            for (int i = 0; i < index; ++i) {
                temp = cities[i].city_name;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                compare = temp.find(name);
                if (compare >= 0) {
                    cout << cities[i].city_name << endl;
                    num++;
                }
            }
            if (num==0) return -1;
            else return -2;
        }
    }
}

float getDistance(float phi1,float phi2,float theta1,float theta2) {
    float c = sin(phi1)*sin(phi2)*cos(theta1-theta2) + cos(phi1)*cos(phi2);
    return 6371*acos(c);
}

int main(){
    City city[st_size];
    string error = "Array out of boundary\n";
    string error2 = "(input) is too long\n";

    ifstream inFile;
    inFile.open("world_cities.csv",ios::in);//读入文件
    if (!inFile)
    {
        cout << "Failed to open :(\n";
        exit(1);
    }

    string line, field;
    while (getline(inFile,line)){
        if (index > st_size-1 && getline(inFile,line)) {
            cout << error;
            exit(1);
        }
        istringstream sin(line);

        getline(sin, field, ',');
        if (field.length()>ch_size) {
            cout << field << error2;
            exit(1);
        } else strcpy(city[index].city_name, field.c_str());

        getline(sin, field, ',');
        if (field.length()>ch_size) {
            cout << field << error2;
            exit(1);
        } else strcpy(city[index].province_state, field.c_str());

        getline(sin, field, ',');
        if (field.length()>ch_size) {
            cout << error2;
            exit(1);
        } else strcpy(city[index].country, field.c_str());

        getline(sin, field, ',');
        city[index].latitude = atof(field.c_str());

        getline(sin, field, ',');
        city[index++].longitude = atof(field.c_str());

    }
    //data loaded

    int city1=-1, city2=-1;
    while (city1<0 || city2<0) {
        cout << "Please input the name of a city:\n";
        getline(cin,field);
        transform(field.begin(), field.end(), field.begin(), ::tolower);
        if (field == "bye") {
            cout << "GOODBYE!\n";
            exit(2);
        }
        else if (city1 < 0){
            city1 = get_city(city, field);
            if (city1 == -1) cout << "No result!\n";
        } else if (city2 < 0) {
            city2 = get_city(city, field);
            if (city2 == -1) cout << "No result!\n";
        }
    }

    float lat1, lat2, lon1, lon2, dis;
    lat1 = city[city1].latitude;
    lon1 = city[city1].longitude;
    lat2 = city[city2].latitude;
    lon2 = city[city2].longitude;
    dis = getDistance((90 - lat1) / 180 * PI, (90 - lat2) / 180 * PI, lon1 / 180 * PI, lon2 / 180 * PI);
    cout << "The distance between " << city[city1].city_name << " and "
    << city[city2].city_name << " is " << dis << " km.\n";
}
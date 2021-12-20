//
// Created by Think on 2021/3/11.
//
#include <iostream>
#include <string>
using namespace std;

struct pizza{
    string company;
    int diameter;
    double weight;
};

struct CandyBar{
    string name;
    double weight;
    int calories;
};

void one(){
    pizza *p1 = new pizza();
    cout << "Enter the name of pizza company: ";
    getline(cin,p1->company);
    cout << "Enter the diameter of pizza (inches): ";
    cin >> p1->diameter;
    cout << "Enter the weight of pizza (g): ";
    cin >> p1->weight;
    cout << "Displaying the information of pizza" << endl << "Company name: "+p1->company << endl << "Pizza diameter: " << p1->diameter << " inches" << endl << "Pizza weight: " << p1->weight << " g" << endl;

}

void two(){
    CandyBar *candyBar = new CandyBar[3];
    for(int i=0;i<3;i++){
        cout << "Enter brand name of a Candy bar: ";
        getline(cin,candyBar[i].name);
        cout << "Enter weight of the Candy bar: ";
        cin >> candyBar[i].weight;
        cout << "Enter calories in the Candy bar: ";
        cin >> candyBar[i].calories;
        cin.get();
    }
    cout << "Displaying the CandyBar array contents" << endl;
    for(int i=0;i<3;i++){
        cout << "Brand name: "+candyBar[i].name << endl << "Weight: " << candyBar[i].weight << endl << "Calories: " << candyBar[i].calories << endl;
    }
}

void three() {
    cout << "Enter 5 integers: " << endl;
    int* arr;
    arr = new int[5];
    for(int i=0;i<5;i++) cin >> arr[i];
    for(int i=4;i>=0;i--) cout << arr[i] << " ";
    delete arr;
    cout<<arr[0];
}

int main(){
//    one();
//    cin.get();
//    two();
//    cin.get();
    three();
}
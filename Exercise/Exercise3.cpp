//
// Created by Think on 2021/3/4.
//
#include <iostream>
#include <string>
using namespace std;

struct CandyBar{
    string name;
    float weight;
    int calories;
};

void one(){
    string first_name, last_name;
    char grade;
    int age;
    cout << "What is your first name?";
    getline(cin,first_name);
    cout << "What is your last name?";
    getline(cin, last_name);
    cout << "What letter grade do you deserve?";
    grade = getchar();
    cout << "What is your age?";
    cin >> age;
    cout << "The information you entered is:" << endl << "Name: "+first_name+", "+last_name << endl << "Grade: " << grade << endl << "Age: " << age << endl;

}

void two(){
    CandyBar CB;
    cout << "Enter brand name of a Candy bar: ";
    getline(cin,CB.name);
    cout << "Enter weight of the Candy bar: ";
    cin >> CB.weight;
    cout << "Enter calories in the Candy bar: ";
    cin >> CB.calories;
    cout << "Brand: "+CB.name << endl << "Weight: " << CB.weight << endl << "Calories: " << CB.calories << endl;
}

void three(){
    CandyBar CB[2];
    float cpw[2];
    int max = 0;
    for(int i=0;i<3;i++){
        cout << "Enter brand name of a Candy bar: ";
        getline(cin,CB[i].name);
        cout << "Enter weight of the Candy bar: ";
        cin >> CB[i].weight;
        cout << "Enter calories in the Candy bar: ";
        cin >> CB[i].calories;
        cpw[i] = CB[i].calories/CB[i].weight;
    }

    for(int i=0;i<3;i++){
        cout << "Brand: "+CB[i].name << endl << "Weight: " << CB[i].weight << endl << "Calories: " << CB[i].calories << endl;
    }
    for(int i=0;i<3;i++){
        if(cpw[i] > cpw[max]) max = i;
    }
    cout << "The greatest calories per weight is:" << endl << "Brand name: "+CB[max].name << endl << "Calories per weight: " << cpw[max] << endl;

}

int main() {
    three();
}

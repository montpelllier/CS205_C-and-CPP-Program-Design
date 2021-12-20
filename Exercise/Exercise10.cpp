//
// Created by Think on 2021/4/22.
//
#include <iostream>

using namespace std;

class CandyBar{
public:
    string brand;
    float weight;
    int calories;

public:
    void setCandyBar(){
        cout << "Enter brand name of a Candy bar:";
        cin >> this->brand;
        cout << "Enter weight of the Candy bar:";
        cin >> this->weight;
        cout << "Enter calories(an integer value) in the Candy bar:";
        cin >> this->calories;
    }

    void showCandyBar(){
         //<< "Call the show function of Passing by reference:\n"
        cout << "Brand: " << this->brand << endl
             << "Weight: " << this->weight << endl
             << "Calories: " << this->calories << endl;
    }

};

class Rectangle{
private:
    double width;
    double height;
public:
    Rectangle(){
        width = 1;
        height = 1;
    }

    Rectangle(double w, double h){
        this->width = w;
        this->height = h;
    }

    double getArea(){
        return this->height * this->width;
    }

    double getPerimeter(){
        return 2*(this->height+this->width);
    }

    void display(){
        cout << "Width:\t\t" << this->width << endl
        << "Height:\t\t" << this->height << endl
        << "Area:\t\t" << getArea() << endl
        << "Perimeter:\t" << getPerimeter() << endl;
    }

};

int main(){
    CandyBar candyBar;
    candyBar.setCandyBar();
    candyBar.showCandyBar();

    Rectangle rectangle1(4, 40);
    cout << "Rectangle 1\n---------------------\n";
    rectangle1.display();

    Rectangle rectangle2(3.5, 35.9);
    cout << "Rectangle 2\n--------------------\n";
    rectangle2.display();
//
//    Rectangle r;
//    r.display();

}

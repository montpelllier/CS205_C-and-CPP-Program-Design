//
// Created by Think on 2021/3/25.
//
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void Displaymenu() {
    cout << "======================================"<<endl
    <<"\t\tMENU"<<endl<<"======================================"<<endl
    <<"\t1.Add"<<endl<<"\t2.Subtract"<<endl<<"\t3.Multiply"<<endl
    <<"\t4.Divide"<<endl<<"\t5.Modulus"<<endl;
}

int Add (int a, int b) {
    return a+b;
}

int Substract (int a, int b) {
    return a-b;
}

int Multiply (int a, int b) {
    return a*b;
}

int Divide (int a, int b) {
    return a/b;
}

int Modulus (int a, int b) {
    return a%b;
}

void displayBox(box box){
    cout << "Maker: " << box.maker
    << "\nHeight: " << box.height
    << "\nWidth: " << box.width
    << "\nLength: " << box.length
    << "\nVolume: " << box.volume << endl;
}

box setVolume(box box){
    box.volume = box.length*box.width*box.height;
    return box;
}

int Fill_array(double arr[], int size){
    int i;
    for (i = 0; i < size; ++i) {
        cout << "Enter value #" << i+1 << ": ";
        if(!(cin>>arr[i])) break;
    }
    return i;
}

void Show_array(double *arr, int size){
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

void Reverse_array(double *arr, int size){
    double temp;
    temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;
    *arr++;
    size = size-2;
    if (size > 0) return Reverse_array(arr,size);
}

void one(){
    Displaymenu();
    int YourChoice;
    int a, b;
    char confirm;
    do {
        cout << "Enter your choice(1~5):";
        cin >> YourChoice;
        cout << "Enter your integer numbers:";
        cin >> a >> b;
        cout << "\nResult:";
        switch (YourChoice)
        {
            case 1: cout << Add(a,b); break;
            case 2: cout << Substract(a,b); break;
            case 3: cout << Multiply(a,b); break;
            case 4: cout << Divide(a,b); break;
            case 5: cout << Modulus(a,b); break;
        }
        cout << "\nPress y or Y to continue:";
        cin >> confirm;
    } while (confirm == 'y' || confirm == 'Y');
}

void two(){
    box box1;
    strcpy(box1.maker, "Jack Smith");
    box1.height = 3.4;
    box1.width = 4.5;
    box1.length = 5.6;
    box1.volume = 0;
    cout << "Before setting volume\n";
    displayBox(box1);
    cout << "After setting volume\n";
    displayBox(setVolume(box1));
}

void three(){
    int size, size1;
    cout << "Enter the size of an array:";
    cin >> size;
    size1 = size;
    double arr[size], arr1[size1];
    size = Fill_array(arr,size);
    size1 = size;
    for (int i = 0; i < size1; ++i) {
        arr1[i] = arr[i];
    }

    Show_array(arr,size);
    cout << endl;

    Reverse_array(arr,size);
    Show_array(arr,size);
    cout << endl;

    Reverse_array(arr1+1,size1-2);
    Show_array(arr1,size1);
}


int main() {
    one();
    two();
    three();
}


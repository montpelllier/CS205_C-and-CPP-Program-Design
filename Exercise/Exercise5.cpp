//
// Created by Think on 2021/3/18.
//
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void one(){
    int sum = 0, entry;
    do {
        cout << "Enter an integer number:";
        cin >> entry;
        sum += entry;
        cout << "The cumulative sum of the entries to date is :" << sum << endl;
    } while (entry != 0);
}

void two(){
    string word;
    int count = 0;
    cout << "Enter words:" << endl;
    cin >> word;
    while (word != "done"){
        count++;
        cin >> word;
    }
    cout << "You entered a total of " << count << " word(s).";
}

void three(){
    string word;
    char first;
    int vowel=0, consonant=0, other=0;
    cout << "Enter word:" << endl;
    cin >> word;
    while (word != "q"){
        first = tolower(word[0]);
        if (isalpha(first)) {
            if (first=='a'||first=='e'||first=='i'||first=='o'||first=='u') consonant++;
            else vowel++;
        } else other++;
        cin >> word;
    }
    cout << vowel << " words beginnig with vowels" << endl
         << consonant << " words beginnig with consonauts" << endl
         << other << " others";

}

void four(){
    string s,text="", up="";

    ofstream file;
    file.open("f1.txt");

    if (file.is_open()){
        cout << "Please input a string:";
        getline(cin ,s);
        for (int i = 0; i < s.length(); ++i) {
            if (isalpha(s[i])) {
                text += s[i];
                up += toupper(s[i]);
            }else if(s[i]==' '){
                text += s[i];
                up += s[i];
            }
        }
        file << text;
        file.close();

        file.open("f2.txt");
        if (file.is_open()) file << up;

        ifstream in;
        in.open("f1.txt");
        in.get();
        getline(in,text);

        in.open("f2.txt");
        getline(in,up);
        cout << text << endl << up;
        in.close();
    }else cout << "failed" << endl;
}

int main(){
   two();

}
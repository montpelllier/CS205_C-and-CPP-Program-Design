//
// Created by Think on 2021/5/19.
//
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
int* SID;
int** lab_score;

int* getSID(int k, int n) {//return 数组指针
    srand(time(0));//随机种子
    int* arr;
    arr = new int [k];
    for(int i=0; i<n; i++){
        if((rand()%(n-i)<k)) {
            //cout<< i + 20000000 << "\n";
            arr[--k] = i + 20000000;
        }
    }
    return arr;
}

void getLabScore(int n){
    srand(time(0));//随机种子
    lab_score = new int * [n];
    for (int i = 0; i < n; ++i) {
        cout << SID[i] << ": ";
        lab_score[i] = new int [14];
        for (int j = 0; j < 14; ++j) {
            lab_score[i][j] = rand() % 6;
            if (j==13) cout << lab_score[i][j] << endl;
            else cout << lab_score[i][j] << ",";
        }
    }
}

void absent_student(int n){
    int count;
    for (int i = 0; i < n; ++i) {
        count = 0;
        for (int j = 0; j < 14; ++j) {
            if (lab_score[i][j]) continue;
            else if (++count>1) {
                cout << SID[i] << endl;
                break;
            }
        }
    }
}

void record_write(int n){
    ofstream outFile;
    outFile.open("lab_records.csv", ios::out);
    for (int i = 0; i < n; ++i) {
        outFile << SID[i] << ',';
        for (int j = 0; j < 14; ++j) {
            if (j==13) outFile << lab_score[i][j] << endl;
            else outFile << lab_score[i][j] << ',';
        }
    }
}

void record_read(){
    ifstream inFile("lab_records.csv", ios::in);
    string line;
    vector<vector<int>> lab_record;
    while (getline(inFile, line)) {
        // 存成二维表结构
        stringstream ss(line);
        string str;
        vector<int> student_record;
        // 按照逗号分隔
        getline(ss, str, ',');
        while (getline(ss, str, ',')) {
            student_record.push_back(atoi(str.c_str()));
        }
        lab_record.push_back(student_record);
    }
    double lab_average[14];//各lab课的平均分
    double average = 0;
    for (int i = 0; i < 14; ++i) {
        double sum = 0;
        for (int j = 0; j < lab_record.size(); ++j) sum += lab_record[j][i];
        lab_average[i] = sum / lab_record.size();
        average += lab_average[i];
    }
    average /= 14.0;
    for (int i = 0; i < 14; ++i) {
        if(lab_average[i] < average) cout << i+1 << endl;
    }
}

int main(){
    srand(time(0));//随机种子
    int n;
    cin >> n;
    if (n<0 || n>22000) {
        cout << "Please input an integer between 0 and 22000";
        exit(-1);
    }
    SID = new int [n];
    SID = getSID(n,22000);
    getLabScore(n);//全局变量不压栈
    //generate and print random id and score
    absent_student(n);//print absent students
    record_write(n);//write into file
    record_read();//read in file
}


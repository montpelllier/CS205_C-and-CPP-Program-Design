//
// Created by Think on 2021/4/15.
//
#include <iostream>

using namespace std;

int sqrt5(int num){
    int result = 0;
    while (num>0 && num%5==0){
        num /= 5;
        result++;
    }
    return result;
}

int main(){
    int num, i=5, ans=0;
    cin >> num;
    while (i <= num){
        ans += sqrt5(i);
        i += 5;
    }
    cout << ans;


    return 0;
}

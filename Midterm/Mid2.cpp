//
// Created by Think on 2021/4/15.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, x, y, m = 0, up_bound, low_bound;
    cin >> n >> x >> y;
    int score[n];
    for (int i = 0; i < n; ++i) cin >> score[i];

    up_bound = min(y, n-x);
    low_bound = max(x, n-y);
    sort(score,score + n);

    int low = low_bound, high = up_bound, mid = 0, temp;
    while(low <= high) {
        mid = (low + high)/2;
        temp = score[mid-1];
        while (mid+1 <= high) {
            if (temp != score[++mid-1]) break;
        }
        if (mid<=up_bound && score[mid] != temp) m = temp;
        high = mid-1;
    }
    cout << m << endl;

    return 0;
}

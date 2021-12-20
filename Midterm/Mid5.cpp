//
// Created by Think on 2021/4/15.
//
#include <iostream>

using namespace std;

int main(){
    int n, m, opera = 0;
    cin >> n >> m;
    char grid[n][m];
    bool isyellow[n][m];
    bool isbule[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            isyellow[i][j] = false;
            isbule[i][j] = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        //cout << grid[i][0];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if ((grid[i][j]=='Y' || grid[i][j]=='G') && !isyellow[i][j]){
                opera++;
                isyellow[i][j] = true;
                int a=i, b=j;
                if (a-1>0 && b+1<m-1 && (grid[a-1][b+1]=='Y' || grid[a-1][b+1]=='G')) {
                    while (--a>0 && ++b<m-1 && (grid[a][b]=='Y' || grid[a][b]=='G')) {
                        isyellow[a][b] = true;
                    }
                } else if (a+1<n-1 && b+1<m-1 && (grid[a+1][b+1]=='Y' || grid[a+1][b+1]=='G')) {
                    cout << "right down";
                    while (++a < n-1 && ++b < m - 1 && (grid[a][b]=='Y' || grid[a][b]=='G')) {
                        isyellow[a][b] = true;
                        cout <<  a << " " << b <<endl;
                    }
                }
            }
            //cout << isyellow[0][0];
            cout << opera << endl;


//            if (grid[i][j]=='B' || grid[i][j]=='G' && !isbule[i][j]){
//                opera++;
//                isbule[i][j] = true;
//                int a=1, b=j;
//                if (a>1 && b<m-1 && !isbule[a-1][b+1]) {
//                    while (a>1 && b<m-1 && !isbule[--a][++b]) {
//                        isbule[a][b] = true;
//                    }
//                } else if (a<n-1 && b<m-1 && !isbule[a+1][b+1]) {
//                    while (a > 1 && b < m - 1 && !isbule[++a][++b]) {
//                        isbule[a][b] = true;
//                    }
//                }
//            }
        }

    }

    cout << opera;

    return 0;
}

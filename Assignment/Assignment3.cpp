//
// Created by Think on 2021/4/13.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>

extern "C"{
#include "utf8.h"
}

using namespace std;

bool inSize(int x, int y){
    return (x==0&&y==1) || (x==0&&y==-1) || \
    (x==1&&y==0) || (x==1&&y==1) || (x==1&&y==-1) || \
    (x==-1&&y==1) || (x==-1&&y==0) || (x==-1&&y==-1);
}

void STG(){
    int n, m, k, x, y, dir_x, dir_y, ans = 0;
    cin >> n >> m >> k;
    bool screen_safe[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            screen_safe[i][j] = true;
        }
    }

    while (k--){
        cin >> x >> y >> dir_x >> dir_y;
        if (x>=n || y >=m || x<0 || y<0) {
            cout << "Wrong position input!\n";
            exit(1);
        }
        if (inSize(dir_x,dir_y)){
            cout << "Wrong direction input!\n";
            exit(1);
        }
        while (x<n && y<m && 0<=x && 0<=y) {
            screen_safe[x][y] = false;
            x += dir_x;
            y += dir_y;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (screen_safe[i][j]) ans++;
        }
    }

    cout << ans << endl;
}

void Spiral(){
    int m, n, num=1;
    cin >> m >> n;
    if (m<=0 || n<=0) {
        cout << "Please input the correct size\n";
        exit(1);
    }
    int matrix[m][n], row=0, col=n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }

    while (num <= m*n){
        while (col>0 && !matrix[row][col-1]) matrix[row][--col] = num++;
        while (row<m && !matrix[row+1][col]) matrix[++row][col] = num++;
        while (col<n && !matrix[row][col+1]) matrix[row][++col] = num++;
        while (row>0 && !matrix[row-1][col]) matrix[--row][col] = num++;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

struct unicode{
    unsigned int start, end;
    string name;
};
unicode block[300];

int find_index(uint32_t cp) {
    for (int i = 0; i < 300; ++i) {
        if (block[i].start <= cp && cp <= block[i].end) {
            return i;
        }
    }
    return -1;//should not execute
}

void count_most(){
    ifstream fileIn("Blocks.txt", ios::in);
    string line;
    if (!fileIn.is_open()) {
        cout << "failed to open!\n";
        exit(1);
    }

    int count = 0;
    while (getline(fileIn, line)) {
        if (line[0] == '#' || line.size() < 1) continue;
        stringstream start(line.substr(0, line.find_first_of('.')));
        start >> hex >> block[count].start;
        stringstream end(line.substr(line.find_last_of('.') + 1, line.find(';') - line.find_last_of('.')));
        end >> hex >> block[count].end;
        block[count++].name = line.substr(line.find(';') + 2);
    }//store the block into structure
    fileIn.close();

    map<string, int> mp;
    string name;

    int bytes_in_char;
    unsigned int codepoint;
    char temp[10000];
    unsigned char *p;
    while (!cin.eof()) {
        getline(cin, line);
        strcpy(temp, line.c_str());
        p = (unsigned char *) temp;
        while (*p) {
            codepoint = utf8_to_codepoint(p, &bytes_in_char);
            if (codepoint) {
                name = block[find_index(codepoint)].name;
                if (mp.find(name) != mp.end()) mp[name]++;
                else mp[name] = 1;
                _utf8_incr(p);
            } else {
                p++;  // Try the next character
            }
        }
    }

    int max = -1;
    map<string, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        if (it->second > max) {
            max = it->second;
            name = it->first;
        }
        it++;
    }
    cout << "Most character is " << name << endl;
}

int main() {
    //STG();
    //Spiral();
    count_most();

    return 0;
}

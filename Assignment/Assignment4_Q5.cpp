//
// Created by Think on 2021/5/19.
//
#include <iostream>
#include <algorithm>

using namespace std;

string command[6] = {"exit", "start", "stop", "restart", "reload", "status"};

int command_check(string cmd){
    int case_id = -1;
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    for (int i = 0; i < 6; ++i) {
        if (cmd==command[i]) return i;
    }
    return case_id;
}

int main() {
    while (true){
        cout << '>';
        string input;
        cin >> input;
        int case_id = command_check(input);
        switch (case_id) {
            case -1:{
                cout << "Invalid command\n";
                break;
            }
            case 0:{
                cout << "EXIT\n";
                exit(0);
            }
            default:{
                cout << "command <" << command[case_id] << "> recognized\n";
                break;
            }
        }
    }

}

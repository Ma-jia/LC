//
// Created by m'j'x on 2025/3/15.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s); // 读取整行输入

    int count = 0;
    for (char c: s) {
        if (c != ' ' && c != '\n') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
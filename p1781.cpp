//
// Created by m'j'x on 2025/3/10.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 比较两个字符串表示的数字大小
bool isBigger(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    } else {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false; // 相等
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (isBigger(votes[i], votes[maxIndex])) {
            maxIndex = i;
        }
    }

    cout << maxIndex + 1 << endl; // 编号从1开始
    cout << votes[maxIndex] << endl;

    return 0;
}
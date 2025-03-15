//
// Created by m'j'x on 2025/3/7.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int M;            // 进制
    string N;         // 输入的数字
    cin >> M >> N;

    string result = ""; // 存储最终的十进制表达式

    // 遍历每一位数字
    for (int i = 0; i < N.size(); i++) {
        int digit = N[i] - '0'; // 当前位的数字
        int power = N.size() - i - 1; // 当前位的幂次

        // 如果当前位的数字为 0，则跳过
        if (digit == 0) {
            continue;
        }

        // 构造当前项的表达式
        string term = "";
        term += to_string(digit); // 添加系数
        term += "*";              // 添加乘号
        term += to_string(M);     // 添加基数 M
        term += "^";              // 添加幂次符号
        term += to_string(power); // 添加幂次

        // 如果是第一个项，直接添加到结果中
        if (result.empty()) {
            result += term;
        } else {
            result += "+" + term; // 如果不是第一个项，添加加号和当前项
        }
    }

    // 如果结果为空，说明所有位都是 0，直接输出 0
    if (result.empty()) {
        cout << 0 << endl;
    } else {
        cout << result << endl; // 输出最终的表达式
    }

    return 0;
}
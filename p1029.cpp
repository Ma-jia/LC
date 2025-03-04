//
// Created by m'j'x on 2025/2/23.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

// 函数：计算最大公约数
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


// 函数：计算最小公倍数
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0; // 如果其中一个数为0，则LCM为0
    }
    return abs(a * b) / gcd(a, b);
}

int main() {
    int x, y;
    cin >> x >> y;
    int result = 0;
    for (int i = x; i <= y; ++i) {
        for (int j = x; j <= i; ++j) {
            if (gcd(i, j) == x && lcm(i, j) == y) {
                result += 2;
            }
        }
    }
    cout << result;
    return 0;
}

int gcd2(int a, int b) {
    int min_num = std::min(a, b);
    int result = 1;

    for (int i = min_num; i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            result = i;
            return result;
        }
    }

}
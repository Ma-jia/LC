//
// Created by m'j'x on 2025/3/15.
//
#include <iostream>

using namespace std;

// 判断一个数是否为质数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    for (int i = 4; i <= N; i += 2) {
        for (int j = 2; j < i; ++j) {
            if (isPrime(j) && isPrime(i - j)) {
                cout << i << "=" << j << "+" << (i - j) << endl;
                break;
            }
        }
    }

    return 0;
}
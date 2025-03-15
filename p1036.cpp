//
// Created by m'j'x on 2025/3/10.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int n, k;
int res = 0;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// 递归生成组合并计算和
void backtrack(int start, int depth, int sum) {
    if (depth == k) {
        if (isPrime(sum)) {
            res++;
        }
        return;
    }
    for (int i = start; i < n; ++i) {
        backtrack(i + 1, depth + 1, sum + nums[i]);
    }
}

int main() {
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    backtrack(0, 0, 0);
    cout << res << endl;
    return 0;
}
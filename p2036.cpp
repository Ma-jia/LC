//
// Created by m'j'x on 2025/3/6.
//
//#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void backtracking(vector<vector<int>> &a, int position, int &res, int n, int suan, int ku) {
    // 更新当前最小差值
    if (abs(suan - ku) < res && suan != 1) {
        res = abs(suan - ku);
    }

    // 剪枝：如果当前位置已经超出范围，或者当前差值已经大于等于当前最小差值，则返回
    if (position >= n || abs(suan - ku) >= res) {
        return;
    }

    // 遍历所有可能的下一步
    for (int i = position; i < n; ++i) {
        int new_suan = suan * a[i][0];
        int new_ku = ku + a[i][1];
        backtracking(a, i + 1, res, n, new_suan, new_ku);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    int res = 99999;
    backtracking(a, 0, res, n, 1, 0);
    cout << res;

    return 0;
}
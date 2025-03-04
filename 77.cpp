//
// Created by m'j'x on 2025/2/21.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;

        backtracking(n, k, 1, path, result);
        return result;
    }

    void backtracking(int n, int k, int startIndex, vector<int> &path, vector<vector<int>> &result) {
        if (path.size() == k) {
            result.push_back(path);
            cout << "AASDA";
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n = 4, k = 2;
//    cin>>n>>k;
    vector<vector<int>> result = solution.combine(n, k);
    // 打印结果
    for (const auto &vec: result) {
        for (int num: vec) {
            cout << num << " ";
        }

    }
    cout << "!!!" << endl;
}
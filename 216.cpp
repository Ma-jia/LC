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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        fuck(1, k, n, 0, result, path);
        return result;
    }


    void fuck(int sation, int k, int n, int sum, vector<vector<int>> &result, vector<int> path) {
        if (sum == n && path.size() == k) {
            result.push_back(path);
            cout << "AASDA";
            return;
        }
        if (sum > n || path.size() > k)return;
        for (int i = sation; i < 10; i++) {
            path.push_back(i);
            fuck(i + 1, k, n, sum + i, result, path);
            path.pop_back();
        }

    }

};

int main() {
    Solution solution;
    int n = 7, k = 3;
//    cin>>n>>k;
    vector<vector<int>> result = solution.combinationSum3(k, n);
    // 打印结果
    for (const auto &vec: result) {
        for (int num: vec) {
            cout << num << " ";
        }
        cout << "!!!" << endl;
    }

}
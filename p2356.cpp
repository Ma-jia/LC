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

int fun(vector<vector<int>> nums);

int main() {

    int n;

    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    vector<int> row;
    vector<int> col(n, 0);
    int cur1, cur2;
    for (int i = 0; i < n; ++i) {
        cur1 = 0;
        for (int j = 0; j < n; ++j) {
            cin >> nums[i][j];
            cur1 += nums[i][j];
            col[j] += nums[i][j];
        }
        row.push_back(cur1);
    }

    int result = 0;


    int flag = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[i][j] == 0) {
                flag = row[i] + col[j];
            }
            if (flag > result)result = flag;
        }
    }
    cout << result;
    return 0;
}


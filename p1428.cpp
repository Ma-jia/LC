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

vector<int> fun(vector<int> nums) {
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i < nums.size(); ++i) {
        int cur = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                cur++;
            }
        }
        res.push_back(cur);
    }
    return res;
}

int main() {

    int n;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result;
    result = fun(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1)cout << " ";
    }


    return 0;
}
//
// Created by m'j'x on 2025/2/22.
//
#include <iostream>
#include<sstream>
#include <utility>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
private:
    vector<vector<int>> result;

    vector<int> path;

    void fuck(int startIndex, vector<int> path, vector<vector<int>> &result, vector<int> &nums) {
        result.emplace_back(path);
        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            fuck(i + 1, path, result, nums); // 递归
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        fuck(0, path, result, nums);
        return result;
    }
};
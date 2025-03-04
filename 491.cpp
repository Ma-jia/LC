//
// Created by m'j'x on 2025/2/23.
//
#include <iostream>
#include<sstream>
#include <utility>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;
//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//
//数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
#include <stdio.h>
#include <stdbool.h>

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void fuck(int station, vector<int> &nums) {
        if (path.size() > 1) {
            result.push_back(path);
            // 注意这里不要加return，要取树上的节点
        }
        unordered_set<int> uset; // 使用set对本层元素进行去重
        for (int i = station; i < nums.size(); ++i) {
            if ((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()) {
                continue;
            }

            path.push_back(nums[i]);
            fuck(i + 1, nums);
            path.pop_back();

        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        fuck(0, nums);
        return result;
    }
};
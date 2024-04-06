//
// Created by m'j'x on 2024/3/2.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <hash_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // 先对数组进行排序
        for (int i = 0; i < nums.size() - 2; ++i) {
            // 跳过重复的元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 跳过重复的元素
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return ans;
    }
};
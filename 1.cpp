//
// Created by m'j'x on 2024/3/2.
//
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int res = nums[i] - target;
            for (int j = 0; j < nums.size(); ++i) {
                if (nums[j] == res) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
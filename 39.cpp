//
// Created by m'j'x on 2024/3/23.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int index = 0, sum = 0;
        backtracking(candidates, result, path, index, sum, target);
        return result;
    }

    void
    backtracking(vector<int> &nums, vector<vector<int>> &result, vector<int> path, int index, int sum, int target) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.emplace_back(path);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            sum += nums[i];
            backtracking(nums, result, path, i, sum, target); // 递归
            path.pop_back();
            sum -= nums[i];
        }
    }
};
//
// Created by m'j'x on 2024/3/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, 0, result, path);
        return result;
    }

    void backtracking(vector<int> &nums, int startIndex, vector<vector<int>> &result, vector<int> path) {
        result.emplace_back(path);
        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, result, path); // 递归
            path.pop_back();
        }
    }
};
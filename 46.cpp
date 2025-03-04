//
// Created by m'j'x on 2024/3/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len) {
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int) nums.size());
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

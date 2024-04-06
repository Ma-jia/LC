//
// Created by m'j'x on 2024/3/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.empty())return 0;
        vector<int> res(nums.size());

        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            res[i] = max(res[i - 2] + nums[i], res[i - 1]);
        }

        return res[nums.size() - 1];
    }
};
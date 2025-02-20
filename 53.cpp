//
// Created by m'j'x on 2024/4/4.
//
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = nums[0];
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            res = max(res, cur);
        }
        return res;
    }

    int maxSubArray2(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result)result = dp[i];
        }
        return result;
    }
};
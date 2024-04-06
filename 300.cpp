//
// Created by m'j'x on 2024/3/26.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])dp[i] = max(dp[j] + 1, dp[i]);
            }
            if (dp[i] > res)res = dp[i];
        }
        return res;
    }
};
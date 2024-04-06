//
// Created by m'j'x on 2024/4/6.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (abs(target) > sum)return 0;
        if ((target + sum) % 2 == 1)return 0;
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j > nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
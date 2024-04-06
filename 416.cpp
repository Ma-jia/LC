//
// Created by m'j'x on 2024/3/27.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};

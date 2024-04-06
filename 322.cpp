//
// Created by m'j'x on 2024/3/25.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c: coins) {
                if (i - c >= 0)dp[i] = min(dp[i - c] + 1, dp[i]);
            }

        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
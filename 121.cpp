//
// Created by m'j'x on 2024/4/2.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int M = 999999999, res = 0;
        for (auto c: prices) {
            M = min(c, M);
            res = max(res, c - M);
        }
        return res;
    }

    int maxProfit2(vector<int> &prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};
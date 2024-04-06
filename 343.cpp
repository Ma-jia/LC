//
// Created by m'j'x on 2024/4/4.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};
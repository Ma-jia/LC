//
// Created by m'j'x on 2025/2/15.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int bagSize = amount;

        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(bagSize + 1, 0));

        // 初始化最上行
        for (int j = 0; j <= bagSize; j++) {
            if (j % coins[0] == 0) dp[0][j] = 1;
        }
        // 初始化最左列
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }

        // 以下遍历顺序行列可以颠倒
        for (int i = 1; i < coins.size(); i++) { // 行，遍历物品
            for (int j = 0; j <= bagSize; j++) { // 列，遍历背包
                if (coins[i] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
        return dp[coins.size() - 1][bagSize];
    }

    int change2(int amount, vector<int> &coins) {
        vector<uint64_t> dp(amount + 1, 0); // 防止相加数据超int
        dp[0] = 1; // 只有一种方式达到0
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount]; // 返回组合数
    }
};
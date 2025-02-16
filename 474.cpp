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
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto &str: strs) {
            int oneNum = 0, zeroNum = 0;
            for (char c: str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i > zeroNum; --i) {
                for (int j = n; j > oneNum; --j) {
                    dp[i][j] = max(dp[i - zeroNum][j - oneNum] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];

    }
};


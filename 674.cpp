//
// Created by m'j'x on 2025/2/19.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                dp[i] = max(dp[i - 1] + 1, dp[i]);
            } else dp[i] = dp[i - 1];
        }
        return dp[nums.size() - 1];
    }
};
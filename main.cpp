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
    int rob(vector<int> &nums) {
        if (nums.size() == 1)return nums[0];
        if (nums.size() == 0)return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
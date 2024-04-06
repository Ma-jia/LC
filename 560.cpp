//
// Created by m'j'x on 2024/3/2.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <hash_set>
//#include <string>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int preSum = 0;  // 前缀和
        int ans = 0;     // 最后答案
        unordered_map<int, int> mp;
        mp[0] = 1;       // mp初始化
        for (int num: nums) {
            preSum += num;  // 遍历到当前数字的前缀和preSum[j]
            if (mp.count(preSum - k)) {   // 判断preSum[i-1] = preSum[j] - k是否存在
                ans += mp[preSum - k];  // 有几个区间前缀和等于preSum-k的区间，答案就加上几
            }
            mp[preSum]++;    // 前缀和为preSum的区间个数+1
        }

        return ans;
    }
};
//
// Created by m'j'x on 2024/4/5.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) { // 遍历物品
            for (int j = target; j >= stones[i]; j--) { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
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
    bool canJump(vector<int> &nums) {
        // 当前能够到达的最远位置
        int k = 0;
        // 遍历数组中的每一个位置
        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前索引 i 超过了能够到达的最远位置 k，则无法继续跳跃，返回 false
            if (i > k) {
                return false;
            }
            // 更新能够到达的最远位置为当前索引i加上该位置可跳跃的最大值，取之前最远位置和新计算的较大值
            k = max(k, i + nums[i]);
        }
        // 如果能够遍历完整个数组，则说明可以到达最后一个位置，返回 true
        return true;
    }
};
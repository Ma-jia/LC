//
// Created by m'j'x on 2023/12/7.
//
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> stk;
        int n = nums.size(), k = INT_MIN;;

        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < k)return true;
            if (!stk.empty() && nums[i] > stk.top()) {
                k = max(k, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
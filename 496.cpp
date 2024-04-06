//
// Created by m'j'x on 2023/12/11.
//
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        std::unordered_map<int, int> f;
        stack<int> stk;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!stk.empty() && num >= stk.top()) {
                stk.pop();
            }
            f[num] = stk.empty() ? -1 : stk.top();
            stk.push(num);
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = f[nums1[i]];
        }
        return ans;
    }
};
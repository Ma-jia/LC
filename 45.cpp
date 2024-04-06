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
    int jump(vector<int> &nums) {
        if (nums[0] == 0)return 0;
        int k = 0;
        int ans = 0;
        int v = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            k = max(k, i + nums[i]);
            if (i == v) {
                v = k;
                ans++;
            }
        }
        return ans;
    }
};
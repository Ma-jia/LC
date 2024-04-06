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
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
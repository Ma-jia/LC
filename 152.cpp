//
// Created by m'j'x on 2024/3/26.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int minP = nums[0], p = 0;
        int maxP = nums[0];


        for (int i = 1; i < nums.size(); ++i) {
            int t = maxP;
            maxP = max(max(maxP * nums[i], nums[i]), minP * nums[i]);
            minP = min(min(minP * nums[i], nums[i]), t * nums[i]);
            p = max(maxP, minP);
        }
        return p;
    }
};
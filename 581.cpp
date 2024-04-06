//
// Created by m'j'x on 2023/12/13.
//
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int max_n = INT_MAX;
        int min_n = INT_MIN;
        int right = -1, left = -1;
        for (int i = 0; i < n; ++i) {
            if (max_n > nums[i]) {
                right = i;
            } else {
                max_n = nums[i];
            }

            if (min_n < nums[n - i - 1]) {
                left = i;
            } else {
                min_n = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};
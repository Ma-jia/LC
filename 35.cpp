//
// Created by m'j'x on 2024/3/31.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return right + 1;
    }
};
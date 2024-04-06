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
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty())
            return result;

        int left = 0, right = nums.size() - 1;

        // Find the first occurrence of the target element
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target)
                right = middle;
            else
                left = middle + 1;
        }

        if (nums[left] != target)
            return result;

        result[0] = left;


        right = nums.size() - 1;
        while (left < right) {
            int middle = left + (right - left + 1) / 2;
            if (nums[middle] <= target)
                left = middle;
            else
                right = middle - 1;
        }

        result[1] = right;

        return result;
    }
};

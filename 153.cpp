//
// Created by m'j'x on 2024/4/1.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int min_m = nums[0];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < min_m)min_m = nums[mid];
            if (nums[left] <= nums[mid]) {
//                if(nums[left]>= min_m){
//                    left=mid+1;
//                } else{
//                    right=mid-1;
//                }
                min_m = min(min_m, nums[left]);
                left = mid + 1;
            } else {
//                if(min_m<=nums[mid+1]){
//                    right=mid-1;
//                } else{
//                    left=mid+1;
//                }
                min_m = min(min_m, nums[mid + 1]);
                right = mid - 1;
            }
        }
        return min_m;
    }
};
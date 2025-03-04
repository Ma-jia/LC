//
// Created by m'j'x on 2025/3/3.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 && k > 0) {
                if (nums[i] == 0) {
                    k = 0;
                    continue;
                }
                k--;
                nums[i] = -nums[i];
                num += nums[i];
            } else if (nums[i] > 0 && k > 0) {
                cout << nums[i];
                int cur = nums[0], a;
                for (int j = 0; j < nums.size(); ++j) {
                    if (nums[j] < cur) {
                        cur = nums[j];
                        a = j;
                    }
                }

                num += -cur;
                if (i != a)num += nums[i];
                k = 0;
            } else {
                num += nums[i];
            }
            cout << num << endl;
        }
        return num;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-8, 3, -5, -3, -5, -2};
    //-4,-3,-1,2,5//-8,-5,-5,-3,-2,3
    int k = 6;
    cout << solution.largestSumAfterKNegations(nums, k);


}
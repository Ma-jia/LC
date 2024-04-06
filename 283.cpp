//
// Created by m'j'x on 2024/3/2.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <hash_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int a = 0, b = 0;
        while (b < nums.size()) {
            if (nums[b]) {
                swap(nums[a], nums[b]);
                b++;
            }
            a++;
        }
    }
};
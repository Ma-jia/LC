//
// Created by m'j'x on 2024/3/2.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <unordered_set>
#include <hash_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;    // 记录最长连续序列的长度
        unordered_set<int> num_set(nums.begin(), nums.end());   // 记录nums中的所有数值
        int seqLen;
        for (int num: num_set) {
            // 如果当前的数是一个连续序列的起点，统计这个连续序列的长度
            if (!num_set.count(num - 1)) {
                seqLen = 1;     // 连续序列的长度，初始为1
                while (num_set.count(++num))seqLen++;    // 不断查找连续序列，直到num的下一个数不存在于数组中
                res = max(res, seqLen);     // 更新最长连续序列长度
            }
        }
        return res;

    }
};
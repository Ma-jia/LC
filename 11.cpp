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
    int maxArea(vector<int> &height) {
        int max_area = 0; // 初始化最大面积为0
        int left = 0; // 左指针从数组起始位置开始
        int right = height.size() - 1; // 右指针从数组末尾开始

        while (left < right) {
            // 计算当前左右指针所形成的矩形面积，并更新最大面积
            max_area = std::max(max_area, std::min(height[left], height[right]) * (right - left));
            // 移动指针，以寻找可能的更大面积
            if (height[left] < height[right]) {
                left++; // 如果左边高度较小，则左指针右移
            } else {
                right--; // 如果右边高度较小或相等，则右指针左移
            }
        }
        return max_area; // 返回最大面积
    }

};
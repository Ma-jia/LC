//
// Created by m'j'x on 2024/2/24.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return fuck(nums, 0, nums.size() - 1);
    }

    TreeNode *fuck(vector<int> &nums, int left, int right) {
        if (left > right)return nullptr;

        int mid = (right + left) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->right = fuck(nums, mid + 1, right);
        root->left = fuck(nums, left, mid - 1);


        return root;
    }

};
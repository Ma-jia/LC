//
// Created by m'j'x on 2024/3/1.
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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        int res = 0;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res++;
            if (res == k)return root->val;
            root = root->right;
        }

        return -1;
    }
};
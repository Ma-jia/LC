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
    void flatten(TreeNode *root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode *res = findRightestNode(curr->left);
                TreeNode *next = curr->right;
                res->right = next;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }

    }

    TreeNode *findRightestNode(TreeNode *root) {
        if (root == nullptr) {
            return nullptr; // 如果节点为空，返回nullptr
        }

        // 如果右子树不为空，递归地找到右子树的最右节点
        if (root->right != nullptr) {
            return findRightestNode(root->right);
        }

        // 如果右子树为空，返回当前节点（因为当前节点是最右节点）
        return root;
    }
};
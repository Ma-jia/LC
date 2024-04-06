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
    TreeNode *balanceBST(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) { // 如果左右子树的高度差大于1，需要进行旋转操作
            if (leftHeight > rightHeight) { // 左旋操作
                root = rightRotation(root);
            } else { // 右旋操作
                root = leftRotation(root);
            }
        }
        root->left = balanceBST(root->left); // 递归平衡左子树
        root->right = balanceBST(root->right); // 递归平衡右子树
        return root;
    }

    // 获取节点的高度
    int getHeight(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    TreeNode *leftRotation(TreeNode *root) {
        TreeNode *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }

    TreeNode *rightRotation(TreeNode *root) {
        TreeNode *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }
};
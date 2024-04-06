//
// Created by m'j'x on 2024/2/20.
//
#include <vector>
#include <stack>

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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        TreeNode *res = root;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            swap(root->right, root->left);
            if (root->right)stk.push(root->right);
            if (root->left)stk.push(root->left);
        }
        return res;
    }
};
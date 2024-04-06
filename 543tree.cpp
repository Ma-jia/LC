//
// Created by m'j'x on 2024/2/24.
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
    int diameterOfBinaryTree(TreeNode *root) {
        int ans = 0;
        if (root == nullptr) return ans;
        fuck(root, ans);
        return ans;
    }

    int fuck(TreeNode *root, int ret) {//计算二叉树节点的最大深度
        if (root == nullptr) {
            return 0;
        } else {
            int leftHeight = fuck(root->left, ret);
            int rightHeight = fuck(root->right, ret);
            ret = max(ret, leftHeight + rightHeight);
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
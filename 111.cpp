//
// Created by m'j'x on 2024/8/8.
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (root->left != nullptr && root->right != nullptr)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else return max(minDepth(root->left), minDepth(root->right)) + 1;
    }


    /*这段代码首先检查根节点是否为空，如果为空则返回0。然后递归地计算左右子树的最小深度。如果根节点的左右子树都不为空，
     * 则返回两个子树中较小的深度加1。如果只有一个子树不为空，则返回该子树的深度加1。如果根节点没有子树，则返回1，因为至少需要一个节点（即根节点本身）。*/

};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};
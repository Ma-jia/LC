//
// Created by m'j'x on 2024/8/7.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>
#include <algorithm>

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
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int max_val = INT_MIN;
            int nb = q.size();
            for (int i = 0; i < nb; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->val >= max_val)max_val = curr->val;
                // 将左子节点入队
                if (curr->left) {
                    q.push(curr->left);
                }
                // 将右子节点入队
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};
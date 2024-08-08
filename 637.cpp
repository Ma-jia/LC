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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        if (root == nullptr)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int nb = q.size();
            double sum = 0;
            for (int i = 0; i < nb; ++i) {
                TreeNode *curr = q.front();
                sum += curr->val;
                q.pop();

                // 将左子节点入队
                if (curr->left) {
                    q.push(curr->left);
                }
                // 将右子节点入队
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(sum / nb);
        }

        return ans;
    }
};
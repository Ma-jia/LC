//
// Created by m'j'x on 2024/4/3.
//
#include <vector>
#include <stack>
#include <climits>
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
    void recoverTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *p = root;
        vector<int> res = inorderTraversal(root);
        sort(res.begin(), res.end());
        recover(p, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }

    void recover(TreeNode *root, vector<int> &rec) {
        if (root == nullptr) {
            return;
        }
        recover(root->left, rec);
        if (root->val == rec[0]) {
            rec.erase(rec.begin());
        } else {
            root->val = rec[0];
            rec.erase(rec.begin());
        };
        recover(root->right, rec);
    }
};
//
// Created by m'j'x on 2024/8/5.
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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> res;
        st.push(root);
        if (root == nullptr)return res;
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            res.push_back(top->val);
            if (top->right != nullptr)st.push(top->right);
            if (top->left != nullptr)st.push(top->left);
        }
        return res;
    }
};
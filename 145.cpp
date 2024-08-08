//
// Created by m'j'x on 2024/8/5.
//
#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> res;
        st.push(root);
        if (root == nullptr)return res;
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            res.push_back(top->val);

            if (top->left != nullptr)st.push(top->left);
            if (top->right != nullptr)st.push(top->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
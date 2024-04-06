//
// Created by m'j'x on 2024/2/25.
//
#include <vector>
#include <stack>
#include <climits>

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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stk;
        long long res = (long long) INT_MIN - 1;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val > res) {
                return false;
            }
            res = root->val;
            root = root->right;
        }

        return true;
    }
};
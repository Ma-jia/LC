//
// Created by m'j'x on 2024/2/21.
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
    bool isSymmetric(TreeNode *root) {
        if (root->right != nullptr && root->left != nullptr) {
            TreeNode *res = invertTree(root->right);
            return isSameTree(root->left, res);
        } else if (root->right != nullptr || root->left != nullptr) {
            return false;
        } else {
            return true;
        }
    }

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

    // 判断两颗二叉树是否相等的函数
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // 如果p和q同时为空，说明当前子树相等
        if (p == NULL && q == NULL) {
            return true;
        }
        // 如果p和q其中一个为空，另一个不为空，说明当前子树不相等
        if (p == NULL || q == NULL) {
            return false;
        }
        // 递归地判断当前节点以及左右子树是否相等
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root) {
        return check(root, root);
    }
};


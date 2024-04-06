//
// Created by m'j'x on 2024/2/24.
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> ret;
            int nb = q.size();
            for (int i = 0; i < nb; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                ret.push_back(curr->val);
                // 将左子节点入队
                if (curr->left) {
                    q.push(curr->left);
                }
                // 将右子节点入队
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(ret);
            ret.clear();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    // Test Case 1: Empty tree
//    TreeNode* root1 = nullptr;
//    vector<vector<int>> result1 = solution.levelOrder(root1);
//    assert(result1.empty());

    // Test Case 2: Tree with only one node
//    TreeNode* root2 = new TreeNode(10);
//    vector<vector<int>> result2 = levelOrder(root2);
//    assert(result2.size() == 1);
//    assert(result2[0].size() == 1);
//    assert(result2[0][0] == 10);

    // Test Case 3: Complete binary tree
    TreeNode *root3 = new TreeNode(3);
    root3->left = new TreeNode(9);
    root3->right = new TreeNode(20);
    root3->right->left = new TreeNode(15);
    root3->right->right = new TreeNode(7);
    vector<vector<int>> result3 = solution.levelOrder(root3);
//    assert(result3.size() == 3);
//    assert(result3[0].size() == 1);
//    assert(result3[0][0] == 3);
//    assert(result3[1].size() == 2);
//    assert(result3[1][0] == 9);
//    assert(result3[1][1] == 20);
//    assert(result3[2].size() == 2);
//    assert(result3[2][0] == 15);
//    assert(result3[2][1] == 7);

    // TODO: Add more test cases...

    // Clean up
//    delete root2;

    cout << "Result 3:" << endl;
    for (const vector<int> &level: result3) {
        for (int val: level) {
            cout << val << " ";
        }
        cout << endl;
    }
//   cout << "All test cases passed!" << endl;
}
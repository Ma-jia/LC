//#include <iostream>
//#include<sstream>
//#include<vector>
//#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void traversal(TreeNode *cur, string path,

    *
    vector<string> &result
    ) {
        path += to_string(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) {
            path += "->";
            traversal(cur->left, path, result); // 左
            path.pop_back(); // 回溯 '>'
            path.pop_back(); // 回溯 '-'
        }
        if (cur->right) {
            path += "->";
            traversal(cur->right, path, result); // 右
            path.pop_back(); // 回溯'>'
            path.pop_back(); // 回溯 '-'
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        traversal(root, path, *result);
        return result;

    }
};
//
// Created by m'j'x on 2024/3/2.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>
#include <unordered_map>

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
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;

        int result = 0;
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // 初始化前缀和为0的次数为1（表示从根节点开始的路径）

        preorderTraversalWithSum(root, 0, targetSum, prefixSumCount, result);

        return result;
    }

    void preorderTraversalWithSum(TreeNode *node, long long currentSum, int targetSum,
                                  unordered_map<long long, int> &prefixSumCount, int &result) {
        if (node == nullptr) return;

        currentSum += node->val; // 更新当前路径和

        long long complement = currentSum - targetSum; // 计算补数（即当前路径和与目标和的差）

        // 检查补数是否在前缀和中出现过（即是否存在另一条路径使得两条路径的和等于目标和）
        if (prefixSumCount.count(complement)) {
            result += prefixSumCount[complement]; // 更新结果（可能有多条路径具有相同的补数）
        }

        // 更新前缀和出现的次数（注意这里要先更新result再更新prefixSumCount，以避免重复计数）
        prefixSumCount[currentSum]++;

        // 递归遍历左子树和右子树
        preorderTraversalWithSum(node->left, currentSum, targetSum, prefixSumCount, result);
        preorderTraversalWithSum(node->right, currentSum, targetSum, prefixSumCount, result);

        // 回溯时恢复前缀和出现的次数（移除当前节点对前缀和的贡献）
        prefixSumCount[currentSum]--;
    }
};
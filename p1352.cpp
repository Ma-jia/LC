//
// Created by m'j'x on 2025/2/26.
//
#include <iostream>
#include <vector>

using namespace std;

// 定义深度优先搜索（DFS）函数，用于计算每个员工对应的动态规划值
void dfs(int u, vector<vector<int>> &children, vector<int> &r, vector<vector<int>> &dp) {
    // 遍历当前员工的所有子员工（直接下属），递归处理子员工
    for (int v: children[u]) {
        dfs(v, children, r, dp);
    }

    // 计算当前员工不被邀请时的最大快乐指数（sum_not）
    int sum_not = 0;
    // 对于每个子员工，累加其最大快乐指数（邀请或不邀请）
    for (int v: children[u]) {
        sum_not += max(dp[v][0], dp[v][1]);
    }
    // 将累加结果存储到当前员工的不邀请状态（dp[u][0]）
    dp[u][0] = sum_not;

    // 计算当前员工被邀请时的最大快乐指数
    // 当前员工的快乐指数加上所有子员工不被邀请时的总快乐指数
    dp[u][1] = r[u];
    for (int v: children[u]) {
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n; // 输入员工总数

    vector<int> r(n + 1); // 存储每个员工的快乐指数（1-based索引）
    // 读取每个员工的快乐指数
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }

    // 构建树结构（员工之间的从属关系）
    vector<vector<int>> children(n + 1); // 存储每个员工的子员工
    vector<int> parent(n + 1, -1); // 存储每个员工的直接上司（根节点的父节点为-1）

    // 读取员工之间的从属关系
    for (int i = 0; i < n - 1; ++i) {
        int l, k;
        cin >> l >> k; // 员工l是员工k的直接下属
        children[k].push_back(l); // 将l添加为k的子员工
        parent[l] = k; // 记录l的父节点为k
    }

    // 查找根节点（校长，即没有上司的员工）
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == -1) {
            root = i; // 找到根节点
            break;
        }
    }

    // 初始化动态规划表
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[u][0]表示不邀请u，dp[u][1]表示邀请u

    // 从根节点开始进行DFS，计算动态规划值
    dfs(root, children, r, dp);

    // 输出最大快乐指数，即根节点两种状态（邀请或不邀请）中的最大值
    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
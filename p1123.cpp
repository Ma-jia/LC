//
// Created by m'j'x on 2025/3/15.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 深度优先搜索函数
void dfs(int x, int y, int currentSum, const vector<vector<int>> &matrix, vector<vector<bool>> &used, int &maxSum) {
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;

    if (x > rows) { // 如果超出矩阵范围
        maxSum = max(maxSum, currentSum); // 更新最大和
        return;
    }

    int nextX = x, nextY = y + 1; // 下一个位置
    if (nextY > cols) { // 如果当前行处理完毕
        nextY = 1;
        nextX = x + 1;
    }

    // 检查当前位置是否可以选取
    if (!used[x - 1][y - 1] && !used[x - 1][y] && !used[x - 1][y + 1] &&
        !used[x][y - 1] && !used[x][y + 1] &&
        !used[x + 1][y - 1] && !used[x + 1][y] && !used[x + 1][y + 1]) {

        used[x][y] = true; // 标记当前位置为已使用
        dfs(nextX, nextY, currentSum + matrix[x][y], matrix, used, maxSum); // 递归处理下一个位置
        used[x][y] = false; // 回溯
    }

    dfs(nextX, nextY, currentSum, matrix, used, maxSum); // 不选取当前位置，直接处理下一个位置
}

int main() {
    int testCases; // 测试用例数量
    cin >> testCases;

    for (int t = 0; t < testCases; ++t) {
        int rows, cols; // 矩阵的行数和列数
        cin >> rows >> cols;

        vector<vector<int>> matrix(rows + 1, vector<int>(cols + 1)); // 矩阵存储
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                cin >> matrix[i][j];
            }
        }

        vector<vector<bool>> used(rows + 2, vector<bool>(cols + 2, false)); // 标记是否使用过
        int maxSum = 0; // 最大和

        dfs(1, 0, 0, matrix, used, maxSum); // 从第一个位置开始搜索
        cout << maxSum << endl; // 输出最大和
    }

    return 0;
}
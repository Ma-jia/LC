//
// Created by m'j'x on 2025/3/7.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>
#include<iostream>
#include<algorithm>

// 定义骑士的8种移动方向
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
//     BFS队列，存储当前点的坐标
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.emplace(x, y);
    // BFS过程
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        // 遍历8种可能的移动方向
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 检查新点是否在棋盘范围内
            if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
                // 如果新点未被访问过
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    // 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j];
            if (j <= m - 1) {
                cout << " "; // 输出格式控制
            }
        }
        cout << endl;
    }

    return 0;

}


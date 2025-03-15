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
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 105; // 最大小岛数量
const int INF = 1e9;  // 无穷大

int N, M;
int dist[MAXN][MAXN]; // 距离矩阵

// 初始化距离矩阵
void initialize() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0; // 自己到自己的距离为0
    }
}

// 动态更新最短路径(优化版本的floyd)
void update(int u, int v, int e) {
    // 更新 u 和 v 之间的直接距离
    if (dist[u][v] > e) {
        dist[u][v] = dist[v][u] = e;
    }

    // 动态更新最短路径
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] > dist[i][u] + dist[u][v] + dist[v][j]) {
                dist[i][j] = dist[i][u] + dist[u][v] + dist[v][j];
            }
            if (dist[i][j] > dist[i][v] + dist[v][u] + dist[u][j]) {
                dist[i][j] = dist[i][v] + dist[v][u] + dist[u][j];
            }
        }
    }
}

int main() {

    cin >> N >> M;
    initialize();

    while (M--) {
        int op;
        cin >> op;
        if (op == 0) {
            // 查询操作
            int s, t;

            cin >> s >> t;
            if (dist[s][t] == INF) {
                cout << "-1\n";
            } else {
                cout << dist[s][t] << endl;
            }
        } else {
            // 新增航线操作
            int u, v, e;
            cin >> u >> v >> e;
            update(u, v, e);
        }
    }

    return 0;
}

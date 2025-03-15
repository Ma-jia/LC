//
// Created by m'j'x on 2025/3/6.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>
#include <cmath> // 包含数学库，用于计算平方根等操作

using namespace std; // 使用标准命名空间

const int N = 5000; // 定义最大节点数
double m[N][N];     // 邻接矩阵，存储边的权值
int n;              // 路口数量
double e, r;        // e - Dirt Road 的单位成本，r - Rome Road 的单位成本
double x[N], y[N];  // 存储每个节点的坐标
double d[N];        // 存储从起点到每个节点的最短距离
bool vis[N][N];     // 标记两个节点之间是否有 Rome Road
bool f[N];          // 标记节点是否已被访问
int dx, dy;         // 用于存储 Rome Road 的两个端点

int main() {
    // 输入参数：Dirt Road 的单位成本、Rome Road 的单位成本、路口数量
    cin >> e >> r >> n;

    // 输入每个路口的坐标
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    // 输入 Rome Road 的连接信息
    while (cin >> dx >> dy && dx != 0 && dy != 0) {
        // 标记两个节点之间有 Rome Road
        vis[dx][dy] = vis[dy][dx] = true;

        // 计算 Rome Road 的长度并存储到邻接矩阵中
        double distance = sqrt((x[dx] - x[dy]) * (x[dx] - x[dy]) + (y[dx] - y[dy]) * (y[dx] - y[dy]));
        m[dx][dy] = m[dy][dx] = r * distance;
    }

    // 输入码头和终点的坐标
    cin >> x[0] >> y[0] >> x[n + 1] >> y[n + 1];

    // 建立 Dirt Road 的邻接矩阵
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= i; j++) {
            // 如果两个节点之间没有 Rome Road，则使用 Dirt Road
            if (!vis[i][j]) {
                double distance = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                m[i][j] = m[j][i] = e * distance;
            }
        }
    }

    // 初始化距离数组，起点到自身的距离为0，其他为无穷大
    d[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        d[i] = 1e6;
    }

    // Dijkstra 算法核心部分
    for (int i = 0; i <= n + 1; i++) {
        int k;          // 当前距离最小的节点
        double min_dist = 1e6; // 初始化为无穷大

        // 找到当前未访问且距离最小的节点
        for (int j = 0; j <= n + 1; j++) {
            if (!f[j] && d[j] < min_dist) {
                min_dist = d[j];
                k = j;
            }
        }
        // 如果所有节点都已访问或无法到达，跳出循环
        if (min_dist == 1e6) {
            break;
        }
        // 标记当前节点为已访问
        f[k] = true;
        // 更新当前节点到其他节点的最短距离
        for (int j = 0; j <= n + 1; j++) {
            if (d[k] + m[k][j] < d[j]) {
                d[j] = d[k] + m[k][j];
            }
        }
    }
    // 输出从码头到终点的最短距离，保留四位小数
    printf("%.4lf", d[n + 1]);

    return 0;
}
//#include <iostream>
//#include<sstream>
//#include<vector>
//#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

#define V 5  // 假设图中有5个顶点
int graph[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
};

// 深度优先搜索（DFS）函数，用于检测图中是否存在回路
bool dfs(int v, int visited[], int *parent) {
    // 标记当前顶点为已访问
    visited[v] = 1;

    // 遍历当前顶点的所有相邻顶点
    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            // 如果相邻顶点未被访问，递归调用DFS
            if (!visited[i] && dfs(i, visited, parent)) {
                return true;
            }
            // 如果相邻顶点在当前路径上（即存在回路），返回true
            if (visited[i] && i != *parent) {
                return true;
            }
        }
    }

    // 将当前顶点的父节点设置为-1，表示当前顶点已经处理完毕
    *parent = -1;
    return false;
}

// 检查图中是否存在回路的函数
bool isCyclic() {
    int visited[V] = {0};  // 初始化所有顶点为未访问
    int parent[V];         // 用于记录每个顶点的父节点

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // 如果顶点未被访问，从该顶点开始进行DFS
            cout << parent[i] << '!!';
            if (dfs(i, visited, &parent[i])) {
                return true;  // 如果存在回路，返回true
            }
        }
    }

    return false;  // 如果所有顶点都被访问过，且没有发现回路，返回false
}

// 邻接矩阵


int main() {
    if (isCyclic()) {
        printf("图中存在回路\n");
    } else {
        printf("图中不存在回路\n");
    }
    return 0;
}
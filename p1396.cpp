//
// Created by m'j'x on 2025/3/7.
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//const int MAXN = 100005;
//
//int n, m, s, t;
//vector<pair<int, int>> edges[MAXN]; // 邻接表
//
//// 并查集
//int parent[MAXN];
//
//int find(int x) {
//    if (parent[x] != x) {
//        parent[x] = find(parent[x]);
//    }
//    return parent[x];
//}
//
//void unite(int x, int y) {
//    x = find(x);
//    y = find(y);
//    if (x != y) {
//        parent[y] = x;
//    }
//}
//
//int kruskal() {
//    // 初始化并查集
//    for (int i = 1; i <= n; i++) {
//        parent[i] = i;
//    }
//
//    // 按边权从小到大排序
//    vector<tuple<int, int, int>> sorted_edges;
//    for (int i = 1; i <= n; i++) {
//        for (auto [v, w] : edges[i]) {
//            sorted_edges.emplace_back(w, i, v);
//        }
//    }
//    sort(sorted_edges.begin(), sorted_edges.end());
//
//    // 构建最小生成树
//    int max_weight = 0;
//    for (auto [w, u, v] : sorted_edges) {
//        if (find(u) != find(v)) {
//            unite(u, v);
//            max_weight = max(max_weight, w);
//        }
//    }
//
//    return max_weight;
//}
//
//int main() {
//    scanf("%d %d %d %d", &n, &m, &s, &t);
//
//    for (int i = 0; i < m; i++) {
//        int u, v, w;
//        scanf("%d %d %d", &u, &v, &w);
//        edges[u].emplace_back(v, w);
//        edges[v].emplace_back(u, w);
//    }
//
//    // 使用 Kruskal 算法构建最小生成树
//    int result = kruskal();
//
//    // 输出结果
//    printf("%d\n", result);
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 100005;

int n, m, s, t;
vector<tuple<int, int, int>> edges; // 存储所有边

// 并查集
int parent[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.emplace_back(w, u, v);//权值在前
    }

    // 按边权从小到大排序
    sort(edges.begin(), edges.end());

    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 逐步添加边，直到 s 和 t 连通
    int result = 0;
    for (auto [w, u, v]: edges) {
        unite(u, v);
        if (find(s) == find(t)) {
            result = w;
            break;
        }
    }

    // 输出结果
    printf("%d\n", result);

    return 0;
}
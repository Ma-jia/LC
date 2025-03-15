//
// Created by m'j'x on 2025/3/11.
//
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const double INF = 1e18;

struct Edge {
    int to;
    double cost;

    Edge(int t, double c) : to(t), cost(c) {}
};

vector<vector<Edge>> graph;

double dijkstra(int start, int end) {
    int n = graph.size();
    vector<double> dist(n, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    dist[start] = 1.0; // 初始时，自己到自己需要支付100元才能收到100元
    pq.emplace(1.0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (u == end) break;
        if (d > dist[u]) continue;
        for (const Edge &e: graph[u]) {
            if (dist[e.to] > dist[u] * e.cost) {
                dist[e.to] = dist[u] * e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist[end];
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1); // 人编号从1到n

    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        double cost = 1.0 / (1.0 - z / 100.0);
        graph[x].emplace_back(y, cost);
        graph[y].emplace_back(x, cost);
    }

    int A, B;
    cin >> A >> B;

    double result = dijkstra(A, B) * 100.0;

    cout << fixed << setprecision(8) << result << endl;

    return 0;
}
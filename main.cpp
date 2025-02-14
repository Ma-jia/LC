//#include <iostream>
//#include<sstream>
//#include<vector>
//#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

#define V 5  // ����ͼ����5������
int graph[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
};

// �������������DFS�����������ڼ��ͼ���Ƿ���ڻ�·
bool dfs(int v, int visited[], int *parent) {
    // ��ǵ�ǰ����Ϊ�ѷ���
    visited[v] = 1;

    // ������ǰ������������ڶ���
    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            // ������ڶ���δ�����ʣ��ݹ����DFS
            if (!visited[i] && dfs(i, visited, parent)) {
                return true;
            }
            // ������ڶ����ڵ�ǰ·���ϣ������ڻ�·��������true
            if (visited[i] && i != *parent) {
                return true;
            }
        }
    }

    // ����ǰ����ĸ��ڵ�����Ϊ-1����ʾ��ǰ�����Ѿ��������
    *parent = -1;
    return false;
}

// ���ͼ���Ƿ���ڻ�·�ĺ���
bool isCyclic() {
    int visited[V] = {0};  // ��ʼ�����ж���Ϊδ����
    int parent[V];         // ���ڼ�¼ÿ������ĸ��ڵ�

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // �������δ�����ʣ��Ӹö��㿪ʼ����DFS
            cout << parent[i] << '!!';
            if (dfs(i, visited, &parent[i])) {
                return true;  // ������ڻ�·������true
            }
        }
    }

    return false;  // ������ж��㶼�����ʹ�����û�з��ֻ�·������false
}

// �ڽӾ���


int main() {
    if (isCyclic()) {
        printf("ͼ�д��ڻ�·\n");
    } else {
        printf("ͼ�в����ڻ�·\n");
    }
    return 0;
}
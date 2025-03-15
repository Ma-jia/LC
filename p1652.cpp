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

double dist(int x1, int y1, int x2, int y2) {//求距离的函数
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));//公式
}

int main() {
    int n;
    cin >> n;
    int a[3][n];
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[1][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[2][i];
    }
    int res = 0, x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; ++i) {
        if ((dist(x1, y1, a[0][i], a[1][i]) < a[2][i]) && (dist(x2, y2, a[0][i], a[1][i]) > a[2][i]))res++;
        else if ((dist(x1, y1, a[0][i], a[1][i]) > a[2][i]) && (dist(x2, y2, a[0][i], a[1][i]) < a[2][i]))res++;
    }
    cout << res;
}
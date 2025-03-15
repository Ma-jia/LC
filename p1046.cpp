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

int main() {
    vector<int> a(10);
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    int h;
    cin >> h;
    int res = 0;
    h = h + 30;
    for (const auto &item: a) {
        if (item <= h)res++;
    }
    cout << res;
}
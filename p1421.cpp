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
#include<algorithm>  //sort嘛......当然要开万能的algorithm

using namespace std;

int main() {
    int cur;
    stack<int> stk;
    cin >> cur;
    while (cur != 0) {
        stk.push(cur);
        cin >> cur;
    }
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

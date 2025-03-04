//
// Created by m'j'x on 2025/2/26.
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
    int flag1, flag2, N;
    cin >> flag1 >> flag2 >> N;
    vector<int> x = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (int i = x.size(); i < x.size() + N; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> dp(x.size());
    dp[0] = 1;
    for (int i = 1; i < x.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (x[i] - x[j] >= flag1 && x[i] - x[j] <= flag2) {
                dp[i] += dp[j];
            }
        }
    }
    cout << dp[x.size() - 1] << endl;
    return 0;

}
//
// Created by m'j'x on 2025/2/20.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
public://给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
    bool isSubsequence(string s, string t) {
        if (s == "")return true;
        if (s.size() > t.size())return false;

        int i = 0, j = 0;
        while (i < t.size()) {
            if (t[i] == s[j]) {
                i++;
                j++;
            } else {
                i++;
            }
            if (j == t.size())return true;
        }
        return false;
    }

    bool isSubsequence2(string s, string t) {
        if (s == "")return true;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                    dp[i][j] = dp[i][j - 1];
            }

        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }

};

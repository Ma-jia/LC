//
// Created by m'j'x on 2025/2/22.
//
#include <iostream>
#include<sstream>
#include <utility>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
private:
    vector<vector<string> > result;
    vector<string> path;

    bool isAns(string s) {
        if (s.empty() || s.size() > 3) return false; // 长度检查
        if (s.size() > 1 && s[0] == '0') return false; // 前导零检查
        int cur = stoi(s);
        if (cur >= 0 && cur <= 255) {
            return true;
        }
        return false;
    }


    void fuck(vector<vector<string> > &result, vector<string> &path, string s) {
        if (path.size() == 4) {
            if (s.empty()) {
                result.push_back(path);
            }
            return;
        }

        if (path.size() > 4)return;
        for (int i = 1; i <= s.size(); ++i) {
            string cur = s.substr(0, i);
            if (cur.size() > 3)break;
            if (isAns(cur)) {
                path.push_back(cur);
                fuck(result, path, s.substr(i));
                path.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        fuck(result, path, std::move(s));
        vector<string> jb;
        for (const auto &item: result) {
            string ip;
            for (size_t i = 0; i < item.size(); ++i) {
                ip += item[i];
                if (i != item.size() - 1) {
                    ip += ".";
                }
            }
            jb.push_back(ip);
        }
        return jb;

    }


};

int main() {
    string s = "25525511135";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    for (const auto &item: res) {
        cout << item << endl;
    }

}
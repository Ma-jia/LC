//
// Created by m'j'x on 2023/12/6.
//
#include <string>
#include <cctype>
#include <stack>

using namespace std;

class NestedInteger {
public:
    void add(const NestedInteger &ni);
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[')return NestedInteger(stoi(s));
        stack<NestedInteger> stk;
        int n = s.size();
        int num = 0;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stk.emplace(NestedInteger());
            } else if (c == '-') {
                flag = true;
            } else if (c == ']' || c == ',') {
                if (isdigit(s[i - 1])) {
                    if (flag) {
                        num *= -1;
                    }
                    stk.top().add(NestedInteger(num));
                }


                num = 0;
                flag = false;
                if (c == ']' && stk.size() > 1) {
                    NestedInteger N = stk.top();
                    stk.pop();
                    stk.top().add(N);
                }
            }
        }
        return stk.top();
    }
};
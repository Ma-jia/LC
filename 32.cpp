//
// Created by m'j'x on 2023/12/1.
//
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_s = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_s = max(max_s, i - stk.top());
                }
            }
        }
        return max_s;
    }
};
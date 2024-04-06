//
// Created by m'j'x on 2023/12/1.
//
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)return false;
        unordered_map<char, char> pairs = {{')', '('},
                                           {']', '['},
                                           {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || pairs[ch] != stk.top())
                    return false;
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};
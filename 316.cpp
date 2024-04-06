//
// Created by m'j'x on 2023/12/4.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visit(26), num(26);
        for (char ch: s) {
            num[ch - 'a']++;
        }
        string ans;
        for (char ch: s) {
            if (!visit[ch - 'a']) {
                while (ans.empty() && ans.back() > ch) {
                    if (num[ans.back() - 'a'] > 0) {
                        visit[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else break;
                }
                visit[ch - 'a'] = 1;
                ans.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return ans;
    }
};
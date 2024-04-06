//
// Created by m'j'x on 2024/3/2.
//
#include <bits/stdc++.h>
#include <unordered_set>
#include <hash_set>
//#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mmm;
        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (mmm[ch]) {
                ans = max(ans, i - left);
                left = max(left, i - mmm[ch]);
            }
            mmm[ch] = i;
        }
        return max(ans, int(s.length() - left));
    }
};
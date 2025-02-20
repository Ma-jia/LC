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

//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//
//回文字符串 是正着读和倒过来读一样的字符串。
//
//子字符串 是字符串中的由连续字符组成的一个序列。
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            left = right = i;

            while (right < n && left >= 0) {
                if (s[left--] == s[right++]) {
                    res++;
                    cout << "a";
                } else { break; }
            }
            left = i;
            right = i + 1;
            while (right < n && left >= 0) {
                if (s[left--] == s[right++]) {
                    res++;
                    cout << "b";
                } else { break; }
            }
        }
        return res;
    }


    void test(string s, int expected) {
        int result = countSubstrings(s);
        cout << "Input: \"" << s << "\"\n";
        cout << "Expected: " << expected << ", Got: " << result << "\n";
        cout << (result == expected ? "PASS" : "FAIL") << "\n\n";
    }
};


int main() {
    Solution solution;
    cout << solution.countSubstrings("leetcode");
//    solution.test("", 0); // Test case 1
//    solution.test("a", 1); // Test case 2
//    solution.test("aa", 2); // Test case 3
//    solution.test("ab", 1); // Test case 4
//    solution.test("aaa", 6); // Test case 5
//    solution.test("abc", 3); // Test case 6
//    solution.test("abba", 4); // Test case 7
//    solution.test("racecar", 8); // Test case 8
//    solution.test("madam", 5); // Test case 9
//    solution.test("abcdef", 6); // Test case 10
//    solution.test("aabbccdd", 12); // Test case 11
//
//    solution.test("AaBbCc", 6); // Test case 13
//    solution.test("aaaaa", 15); // Test case 14


    return 0;
}
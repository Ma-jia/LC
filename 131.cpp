//
// Created by m'j'x on 2024/3/24.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        backtrackingct(result, {}, s);
        return result;
    }

    void backtrackingct(vector<vector<string>> &result, vector<string> path, string s) {
        if (s.size() == 0) {
            result.push_back(path);
            return;
        }
        for (int i = 1; i < s.size(); ++i) {
            string cur = s.substr(0, i);
            if (isPalindrome(cur)) {
                path.push_back(cur);
                backtrackingct(result, path, s.substr(i));
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &str) {
        int start = 0;
        int end = str.length() - 1;
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
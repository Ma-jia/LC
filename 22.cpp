//
// Created by m'j'x on 2024/3/23.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrackingct(result, 0, 0, "", n);
        return result;
    }

    void backtrackingct(vector<string> &result, int left, int right, string path, int n) {
        if (left == right == n) {
            result.emplace_back(path);
            return;
        }
        if (left < n) {
            path.push_back('(');
            backtrackingct(result, left + 1, right, path, n);
            path.pop_back();
        }
        if (right < left) {
            path.push_back(')');
            backtrackingct(result, left, right + 1, path, n);
            path.pop_back();
        }
    }
};
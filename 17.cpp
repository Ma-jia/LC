//
// Created by m'j'x on 2024/3/20.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };
public:

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path;
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0, result, path);
        return result;


    }

    void backtracking(string digits, int startIndex, vector<string> &result, string path) {
        if (startIndex == digits.size()) {
            result.emplace_back(path);
            return;
        }
        int digit = digits[startIndex] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            backtracking(digits, startIndex + 1, result, path);
            path.pop_back();
        }
    }
};
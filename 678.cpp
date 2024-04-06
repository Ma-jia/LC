//
// Created by m'j'x on 2023/12/14.
//
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, size = s.size();
        for (int i = 0; i < size; ++i) {
            left += (s[i] == ')') ? -1 : 1;
            right += (s[size - i - 1] == '(') ? -1 : 1;
            if (left < 0 || right < 0)return false;
        }
        return true;
    }
};
//
// Created by m'j'x on 2023/12/7.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        int num = 0;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (isalpha(c)) {
                ans += c;
            } else if (c == '[') {
                pair<string, int> myPair(ans, num);
                stk.push(myPair);
                num = 0;
                ans = "";
            } else if (c == ']') {
                string first = stk.top().first;
                int second = stk.top().second;
                string op;
                stk.pop();
                for (int j = 0; j < second; ++j) {
                    op += ans;
                }
                ans = first + op;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string input1 = "3[a]2[bc]";
    std::string output1 = solution.decodeString(input1);
    std::cout << "Test Case 1 Output: " << output1 << std::endl; // 期望输出: "aaabcbc"

    // Test case 2
    std::string input2 = "3[a2[c]]";
    std::string output2 = solution.decodeString(input2);
    std::cout << "Test Case 2 Output: " << output2 << std::endl; // 期望输出: "accaccacc"

    // Test case 3
    std::string input3 = "2[abc]3[cd]ef";
    std::string output3 = solution.decodeString(input3);
    std::cout << "Test Case 3 Output: " << output3 << std::endl; // 期望输出: "abcabccdcdcdef"

    return 0;
}
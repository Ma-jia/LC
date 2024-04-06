//
// Created by m'j'x on 2023/12/4.
//
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;

        int ans = 0;
        for (const string &s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                if (st.size() < 2) {
                    // 栈中的数字不足，无法进行运算
                    return -1;
                }
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(num1 + num2);
                } else if (s == "-") {
                    st.push(num1 - num2);
                } else if (s == "*") {
                    st.push(num1 * num2);
                } else if (s == "/") {
                    if (num2 == 0) {
                        // 除数为0，无法进行运算
                        return -1;
                    }
                    st.push(num1 / num2);
                }
            } else {
                st.push(stoi(s));
            }
        }
        if (st.size() != 1) {
            // 栈中的数字数量错误，无法得到最终结果
            return -1;
        }
        return st.top();

    }
};

int main() {
    Solution solution;

    // 测试用例1: 逆波兰表达式: ["2", "1", "+", "3", "*"]，期望结果: 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    int result1 = solution.evalRPN(tokens1);
    cout << "Result1: " << result1 << endl;

    // 测试用例2: 逆波兰表达式: ["4", "13", "5", "/", "+"], 期望结果: 6
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    int result2 = solution.evalRPN(tokens2);
    cout << "Result2: " << result2 << endl;

    // 测试用例3: 逆波兰表达式: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"], 期望结果: 22
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result3 = solution.evalRPN(tokens3);
    cout << "Result3: " << result3 << endl;

    // 测试用例4: 逆波兰表达式: ["2", "1", "*", "3", "+"], 栈中的数字数量错误，无法得到最终结果，返回 -1
    vector<string> tokens4 = {"2", "1", "*", "3", "+"};
    int result4 = solution.evalRPN(tokens4);
    cout << "Result4: " << result4 << endl;

    // 测试用例5: 逆波兰表达式: ["4", "0", "/"], 除数为0，无法进行运算，返回 -1
    vector<string> tokens5 = {"4", "0", "/"};
    int result5 = solution.evalRPN(tokens5);
    cout << "Result5: " << result5 << endl;

    return 0;
}
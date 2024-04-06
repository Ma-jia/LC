//
// Created by m'j'x on 2023/12/4.
//
#include <string>
#include <stack>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int flag = 1; // 用于标记加减号的正负性，默认为正

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                flag = (s[i] == '+') ? 1 : -1; // 设置正负标志
            } else if (s[i] == '*' || s[i] == '/') {
                int num1 = stk.top();
                stk.pop();
                int num2 = 0;
                int j = i + 1;
                while (j < s.size() && isdigit(s[j])) {  // 检查 j 是否在字符串范围内，以及字符是否是数字字符
                    num2 = num2 * 10 + (s[j] - '0');
                    j++;
                }
                if (num2 == 0) {
                    // 处理除数为零的情况
                    // 这里可以抛出异常、返回特定值或进行其他处理
                } else {
                    stk.push((s[i] == '*') ? (num1 * num2) : (num1 / num2));
                }
                i = j - 1; // 将 i 移动到正确的位置
            } else if (s[i] == ' ') {
                continue; // 跳过空格
            } else {
                int num = 0;
                while (isdigit(s[i])) { // 读取操作数
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // 将 i 移回正确的位置
                stk.push(num * flag); // 将数字乘以正负标志后压入栈中
            }
        }

        int result = 0;
        while (!stk.empty()) { // 计算栈中剩余元素
            result += stk.top();
            stk.pop();
        }
        return result; // 返回最终结果
    }
};

int main() {
    Solution sol;
    // 测试普通的算术表达式
    assert(sol.calculate("3+2*2") == 7);  // 3 + 2 * 2 = 7
    assert(sol.calculate(" 3/2 ") == 1);  // 整数除法，结果为 1
    assert(sol.calculate(" 3+5 / 2 ") == 5);  // 3 + 5 / 2 = 5

    // 测试包含负数的情况
    assert(sol.calculate(" 3 - 2") == 1);  // 3 - 2 = 1
    assert(sol.calculate("1-1+1") == 1);  // 1 - 1 + 1 = 1
    // 测试空字符串的情况
    assert(sol.calculate("") == 0);  // 空字符串，返回0
    // 测试只包含空格的情况
    assert(sol.calculate("   ") == 0);  // 只包含空格，返回0

    // 测试包含乘除法的情况
    assert(sol.calculate("2 * 3 - 4 / 2") == 4);  // 2 * 3 - 4 / 2 = 6 - 2 = 4

    cout << "All test cases passed!" << endl;
    return 0;
}
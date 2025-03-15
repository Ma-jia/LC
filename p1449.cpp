//
// Created by m'j'x on 2025/3/10.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    int num = 0;
    bool isNum = false;

    for (char c: s) {
        if (c == '.') {
            if (isNum) {
                st.push(num);
                num = 0;
                isNum = false;
            }
        } else if (c == '@') {
            break;
        } else if (isdigit(c)) {
            num = num * 10 + (c - '0');
            isNum = true;
        } else {
            if (st.size() < 2) {
                // 不合法的表达式
                cout << "Invalid expression" << endl;
                return 0;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch (c) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero" << endl;
                        return 0;
                    }
                    st.push(a / b);
                    break;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Invalid expression" << endl;
        return 0;
    }

    cout << st.top() << endl;
    return 0;
}
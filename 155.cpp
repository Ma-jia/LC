//
// Created by m'j'x on 2023/12/4.
//
#include <stack>
#include <climits>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    stack<int> stk;
    std::stack<int> min_s;
public:
    MinStack() {
        min_s.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        min_s.push(min(min_s.top(), val));
    }

    void pop() {
        min_s.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_s.top();
    }
};

class MinStack_2 {
    long long min_val = INT_MAX;
    stack<long long> stk;
public:
    MinStack() {

    }

    void push(int val) {
        stk.push(val - min_val);
        min_val = min(min_val, (long long) val);
    }

    void pop() {
        if (stk.top() < 0) {
            min_val -= stk.top();
        }
        stk.pop();
    }

    int top() {
        return stk.top() < 0 ? (int) min_val : int(min_val + stk.top());
    }

    int getMin() {
        return (int) min_val;
    }
};
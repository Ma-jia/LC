//
// Created by m'j'x on 2023/12/4.
//
#include <stack>

using namespace std;

class MyQueue {
    stack<int> stack_in;
    stack<int> stack_out;
public:
    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }

        }
        int result = stack_out.top();
        stack_out.pop();
        return result;
    }

    int peek() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }

    bool empty() {
        return stack_out.empty() && stack_in.empty();
    }
};
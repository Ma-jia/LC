//
// Created by m'j'x on 2024/1/28.
//
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> vtr(n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                vtr[stk.top()] = i - stk.top();
                stk.pop();

            }
            stk.push(i);
        }
        return vtr;
    }
};
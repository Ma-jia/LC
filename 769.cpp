//
// Created by m'j'x on 2024/2/5.
//

#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        stack<int> stk;
        for (int ch: arr) {
            if (stk.empty() || ch > stk.top()) {
                stk.push(ch);
            } else {
                int max = stk.top();
                stk.pop();
                while (stk.empty() && stk.top() >= ch) {
                    stk.pop();
                }
                stk.push(max);

            }

        }
        return stk.size();
    }
};
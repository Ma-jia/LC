//
// Created by m'j'x on 2024/4/2.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int M = 999999999, res = 0;
        for (auto c: prices) {
            M = min(c, M);
            res = max(res, c - M);
        }
        return res;
    }
};
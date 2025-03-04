//
// Created by m'j'x on 2025/3/3.
//
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
#include <iostream>
#include <algorithm>
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，
// 我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int res = 0;
        for (int i = 0; i < g.size(); ++i) {
            int min_biscuit = INT_MAX; // 记录满足条件的最小饼干大小
            int position = -1;         // 记录该饼干的位置

            // 遍历饼干数组，寻找满足条件且最小的饼干
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] >= g[i] && s[j] < min_biscuit) {
                    min_biscuit = s[j];
                    position = j;
                }
            }

            // 如果找到合适的饼干
            if (position != -1) {
                res++; // 满足一个儿童
                s[position] = -1; // 标记为已使用
            }
        }
        return res;
    }

    int findContentChildren2(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // 指向孩子的指针
        for (int j = 0; i < g.size() && j < s.size(); ++j) {
            if (s[j] >= g[i]) { // 当前饼干可以满足当前孩子
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << solution.findContentChildren(g, s);
}
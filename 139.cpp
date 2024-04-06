//
// Created by m'j'x on 2024/3/26.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        set<string> wordSet(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.find(word) != wordSet.end())dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
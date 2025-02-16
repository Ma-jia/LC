//
// Created by m'j'x on 2024/3/26.
//
#include <vector>
#include <climits>
#include <string>
#include <set>
#include <unordered_set>

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

    bool wordBreak2(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // 初始化：空字符串可以被拆分

        for (int i = 1; i <= s.size(); i++) { // 遍历字符串的每个位置
            for (int j = 0; j < i; j++) { // 遍历可能的拆分点
                string word = s.substr(j, i - j); // 提取子字符串 s[j:i]
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                    break; // 剪枝：如果当前子字符串可以被拆分，则无需继续检查
                }
            }
        }

        return dp[s.size()]; // 返回整个字符串是否可以被拆分
    }
};
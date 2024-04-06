//
// Created by m'j'x on 2024/4/3.
//
#include <vector>
#include <climits>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> map; //记录char c 和其最后出现位置的 map
        for (int i = 0; i < s.length(); ++i) {
            map[s[i]] = i;
        }
        int k = 0;
        int ver = 0;
        for (int i = 0; i < s.size(); ++i) {
            k = max(k, map[s[i]]);
            if (i == k) {
                result.push_back(ver);
                ver = 0;
            }
            ver++;
        }
        return result;
    }
};
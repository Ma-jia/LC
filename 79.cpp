//
// Created by m'j'x on 2024/3/23.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrackingct(board, i, j, 0, word))return true;
            }
        }
        return false;
    }

    bool backtrackingct(vector<vector<char>> &big, int i, int j, int n, string word) {
        if (i >= big.size() || i < 0 || j >= big[0].size() || j < 0 || big[i][j] != word[n])return false;
        if (n == word.length() - 1)return true;
        big[i][j] = '1';
        int res = backtrackingct(big, i + 1, j, n + 1, word) || backtrackingct(big, i, j + 1, n + 1, word) ||
                  backtrackingct(big, i - 1, j, n + 1, word) || backtrackingct(big, i, j - 1, n + 1, word);
        big[i][j] = word[n];
        return res;
    }
};
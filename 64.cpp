//
// Created by m'j'x on 2024/3/27.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int sum = grid[0][0];
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][0] = sum + grid[i][0];
            sum += grid[i][0];
        }
        sum = grid[0][0];
        for (int j = 0; j < grid[0].size(); ++j) {
            grid[0][j] = sum + grid[0][j];
            sum += grid[j][0];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[grid.size()][grid[0].size()];
    }
};
//
// Created by m'j'x on 2024/3/31.
//
#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rowSize = matrix.size(), columnSize = matrix[0].size();
        int row = 0, column = columnSize - 1;
        while (row < rowSize && column >= 0) {
            if (matrix[row][column] == target)return true;
            else if (matrix[row][column] > target) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
};
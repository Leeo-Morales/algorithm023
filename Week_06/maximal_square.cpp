#include <iostream>

using namespace std;

//Clarification:
//1. 在一个由 '1' 和 '0' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积

//Possible Solusions (optimal through time/space):
//1. 暴力解法：找到边长最大的正方形，再返回其面积，但时间复杂度较高
//2. 动态规划：a. define status array: every element representative max-side as right-lowest angle; b. Dp Function: 
//            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1

// --- 动态规划（递推）
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
        return maxSide * maxSide;
    }
};

int main() {

    cout << "最大正方形" << endl;

    return 0;
}
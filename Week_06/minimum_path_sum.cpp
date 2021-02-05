#include<iostream>

using namespace std;

//Clarification:
//1. 包含非负整数的 m * n 网格 grid
//2. 找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
//3. 每次只能向下或者向右移动一步

//Possible Solusions (optimal through time/space):
//1. 暴力解法：遍历所有路径，求出所有有效路径上的数字总和，找出其中的最小值（超出时间限制）
//2. 动态规划(Memorize / Dp Function -> fable bottom-up):
//   a. define subproblems: every step defines a new array from cur to end, its min-step depend on its available steps
//   b. define status array: define a two-dimension array because it is a m * n array and we need memorize per step
//   c. recursion & up-bottom memorize or bottom-up Dp Function:
//      up-bottom memorize: define a global array, recursion and memorization
//      bottom-up Dp Function: from end to start, curNum += min(rightNum, underNum), Ps: Just two 1 * n array or not

// --- 动态规划（递推）
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        dp[rows - 1][columns - 1] = grid[rows - 1][columns - 1];
        for (int i = rows - 1; i > 0; --i)
            dp[i - 1][columns - 1] = grid[i - 1][columns - 1] + dp[i][columns - 1];
        for (int i = columns - 1; i > 0; --i)
            dp[rows - 1][i - 1] = grid[rows - 1][i - 1] + dp[rows - 1][i];
        for (int i = rows - 2; i >= 0; --i)
            for (int j = columns - 2; j >= 0; --j)
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        return dp[0][0];
    }
};

// --- 动态规划（递归）
class Solution {
public:
    int recursion(vector<vector<int>>& grid, vector<vector<int>>& memoArr, int i, int j) {
        //recursion terminator
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }
        //current logic + drill down
        if (i == grid.size() - 1) 
            if (memoArr[i][j] == 0) {
                memoArr[i][j] = grid[i][j] + recursion(grid, memoArr, i, j + 1);
                return memoArr[i][j];
            } else return memoArr[i][j];
        if (j == grid[0].size() - 1)
            if (memoArr[i][j] == 0) {
                memoArr[i][j] = grid[i][j] + recursion(grid, memoArr, i + 1, j);
                return memoArr[i][j];
            } else return memoArr[i][j];
        if (memoArr[i][j] == 0) {
            memoArr[i][j] = grid[i][j] + min(recursion(grid, memoArr, i, j + 1), recursion(grid, memoArr, i + 1, j));
            return memoArr[i][j];
        } else return memoArr[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        //up-bottom recursion & memorized array
        if (grid.size() == 0) return 0;
        vector<vector<int>> memoArr(grid);
        for (int i = 0; i < memoArr.size(); ++i)
            for (int j = 0; j < memoArr[0].size(); ++j)
                memoArr[i][j] = 0;
        return recursion(grid, memoArr, 0, 0);
    }
};

int main() {

    cout << "最小路径和" << endl;

    return 0;
}
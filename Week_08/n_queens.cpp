#include <iostream>
using namespace std;

//解法一 --- 回溯 + 剪枝
class Solution {
private:
    vector<vector<string>> result;
public:
    void backTracking(int n, int row, vector<string> & chessBoard) {
        //recursion terminator:
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }
        //current logic + drill down:
        for (int col = 0; col < n; ++col)
            if (isValid(n, row, col, chessBoard)) {
                chessBoard[row][col] = 'Q';
                backTracking(n, row + 1, chessBoard);
                chessBoard[row][col] = '.';
            }
    }
    bool isValid(int n, int row, int col, vector<string> & chessBoard) {
        for (int i = 0; i < row; ++i)
            if (chessBoard[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (chessBoard[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (chessBoard[i][j] == 'Q') return false;
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));
        backTracking(n, 0, chessBoard);
        return result;
    }
};

//解法二 --- 回溯 + 记忆数组
class Solution {
private:
    static const int M = 20;
    int col[M], dg[M], udg[M];
    vector<string> chessBoard;
    vector<vector<string>> result;
public:
    void backTracking(int row, int n) {
        //recursion terminator:
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }
        //current logic + drill down:
        for (int i = 0; i < n; ++i)
            if (col[i] == 0 && dg[row - i + n] == 0 && udg[row + i] == 0) {
                chessBoard[row][i] = 'Q';
                col[i] = dg[row - i + n] = udg[row + i] = 1;
                backTracking(row + 1, n);
                chessBoard[row][i] = '.';
                col[i] = dg[row - i + n] = udg[row + i] = 0;
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        //回溯 + 记忆数组
        chessBoard.resize(n, string(n, '.'));
        backTracking(0, n);
        return result;
    }
};

//解法三 --- 回溯 + 位运算
class Solution {
private:
    int size;
    vector<vector<string>> result;
public:
    void backTracking(int n, vector<string> & chessBoard, int row, int col, int ld, int rd) {
        //recursion terminator:
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }
        //current logic + drill down:
        int bits = size & (~(col | ld | rd));
        while (bits != 0) {
            int bit = bits & (-bits);
            bits &= (bits - 1);
            chessBoard[row][log2(bit)] = 'Q';
            backTracking(n, chessBoard, row + 1, col | bit, (ld | bit) << 1, (rd | bit) >> 1);
            chessBoard[row][log2(bit)] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        size = (1 << n) - 1;
        vector<string> chessBoard(n, string(n, '.'));
        backTracking(n, chessBoard, 0, 0, 0, 0);
        return result;
    }
};

int main() {

    cout << "N皇后" << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) { // Try 1 to 9
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; 
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.'; // Reset the cell //backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false; // Check column
            if (board[row][i] == c) return false; // Check row
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; // Check 3x3 box
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution().solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to track which numbers have been seen in each row, column, and 3x3 box
        bool rows[9][9] = {false};    // rows[i][num] = true if number (num+1) is in row i
        bool cols[9][9] = {false};    // cols[j][num] = true if number (num+1) is in column j
        bool boxes[9][9] = {false};   // boxes[box][num] = true if number (num+1) is in box

        // Iterate through each cell in the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    // Convert character digit to array index (0-8)
                    int num = board[i][j] - '1';
                    
                    // Calculate which 3x3 box this cell belongs to
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    // Check if this number already exists in the same row, column, or box
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return false;
                    
                    // Mark this number as seen in the current row, column, and box
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true; // No duplicates found, sudoku is valid
    }
};
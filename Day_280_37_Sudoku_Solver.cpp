#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n = 3, N = 9; // n = size of sub-box, N = size of board
    int rows[9][10] = {}, cols[9][10] = {}, boxes[9][10] = {}; // Track used digits in rows, cols, and 3x3 boxes
    vector<vector<char>>* boardPtr; // Pointer to the board
    bool sudokuSolved = false; // Flag to indicate if sudoku is solved

    // Check if digit d can be placed at position (row, col)
    bool couldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n; // Calculate box index
        return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
    }

    // Place digit d at position (row, col)
    void placeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n; // Calculate box index
        rows[row][d]++; // Mark digit as used in row
        cols[col][d]++; // Mark digit as used in column
        boxes[idx][d]++; // Mark digit as used in box
        (*boardPtr)[row][col] = d + '0'; // Place digit on board
    }

    // Remove digit d from position (row, col) - backtrack step
    void removeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n; // Calculate box index
        rows[row][d]--; // Unmark digit from row
        cols[col][d]--; // Unmark digit from column
        boxes[idx][d]--; // Unmark digit from box
        (*boardPtr)[row][col] = '.'; // Remove digit from board
    }

    // Move to next position after placing a number
    void placeNextNumbers(int row, int col) {
        if (row == N - 1 && col == N - 1) sudokuSolved = true; // Reached end, puzzle solved
        else if (col == N - 1) backtrack(row + 1, 0); // Move to next row
        else backtrack(row, col + 1); // Move to next column
    }

    // Main backtracking function
    void backtrack(int row, int col) {
        if ((*boardPtr)[row][col] == '.') { // If cell is empty
            for (int d = 1; d <= 9; d++) { // Try digits 1-9
                if (couldPlace(d, row, col)) { // If digit can be placed
                    placeNumber(d, row, col); // Place digit
                    placeNextNumbers(row, col); // Move to next position
                    if (!sudokuSolved) removeNumber(d, row, col); // Backtrack if not solved
                }
            }
        } else placeNextNumbers(row, col); // Cell already filled, move to next
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        boardPtr = &board; // Store board reference
        // Initialize tracking arrays with existing numbers on board
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.') placeNumber(board[i][j] - '0', i, j);
        backtrack(0, 0); // Start backtracking from top-left corner
    }
};
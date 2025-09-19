#include <bits/stdc++.h>
using namespace std;
class Spreadsheet {
private:
    // 2D vector to store spreadsheet values (rows x columns)
    vector<vector<int>> sheet;
    
    // Helper function to convert cell reference (e.g., "A1") to row,col indices
    pair<int,int> getIndices(string &cell){
        int n = cell.size();
        int col = cell[0]-'A';  // Convert letter to column index (A=0, B=1, etc.)
        int row = stoi(cell.substr(1,n-1));  // Extract row number from string
        return {row,col};
    }
    
public:
    // Constructor: Initialize spreadsheet with given number of rows and 26 columns (A-Z)
    Spreadsheet(int rows) {
        sheet.assign(rows+1,vector<int>(26,0));  // +1 for 1-indexed rows
    }
    
    // Set a specific cell to the given value
    void setCell(string cell, int value) {
        auto [row,col] = getIndices(cell);  // Parse cell reference
        sheet[row][col] = value;
    }
    
    // Reset a specific cell to 0
    void resetCell(string cell) {
        auto [row,col] = getIndices(cell);  // Parse cell reference
        sheet[row][col] = 0;
    }
    
    // Evaluate a formula and return the result
    // Formula format: "=operand1+operand2" where operands can be cell references or numbers
    int getValue(string formula) {
        int n = formula.size();
        int splitIdx = formula.find('+');  // Find the '+' operator
        
        // Extract operands (skip the '=' at the beginning)
        string x = formula.substr(1,splitIdx-1);        // First operand
        string y = formula.substr(1+splitIdx,n-splitIdx-1);  // Second operand
        
        int num1 = 0, num2 = 0;
        
        // Check if first operand is a cell reference or a number
        if(isalpha(x[0])){
            auto [row1,col1] = getIndices(x);  // Cell reference
            num1 = sheet[row1][col1];
        }else{
            num1 = stoi(x);  // Direct number
        }
        
        // Check if second operand is a cell reference or a number
        if(isalpha(y[0])){
            auto [row2,col2] = getIndices(y);  // Cell reference
            num2 = sheet[row2][col2];
        }else{
            num2 = stoi(y);  // Direct number
        }

        return num1 + num2;  // Return sum of operands
    }
};

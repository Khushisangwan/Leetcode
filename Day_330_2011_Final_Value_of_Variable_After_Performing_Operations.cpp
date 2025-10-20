#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0; // Initialize variable to 0
        
        // Iterate through each operation string
        for(auto& op: operations) {
            // Check the middle character: '+' means increment, '-' means decrement
            x += (op[1] == '+') ? 1 : -1;
        }
        
        return x; // Return final value after all operations
    }
};
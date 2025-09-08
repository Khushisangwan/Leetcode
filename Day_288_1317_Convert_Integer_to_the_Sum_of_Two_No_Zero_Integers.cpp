#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // Lambda function to check if a number contains any zero digits
        auto check = [](int x) {
            while (x > 0) {
                if (x % 10 == 0) return false; // If last digit is 0, return false
                x /= 10; // Remove last digit
            }
            return true; // No zero digits found
        };
        
        // Try all possible pairs (i, n-i) where i goes from 1 to n-1
        for (int i = 1; i < n; ++i) {
            int j = n - i; // Calculate the second number
            // Check if both numbers have no zero digits
            if (check(i) && check(j)) {
                return {i, j}; // Return the valid pair
            }
        }
        return {}; // This should never be reached given the problem constraints
    }
};
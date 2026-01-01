#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Iterate from the last digit to the first
        for (int i = digits.size() - 1; i >= 0; i--) {
            // If digit is not 9, increment it and return
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            // Set 9 to 0 and continue to the next digit
            digits[i] = 0;
        }
        // If all digits were 9, insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;     
    }
};
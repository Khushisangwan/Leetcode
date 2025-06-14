#include<bits/stdc++.h>
using namespace std;
// 2566. Maximum Difference by Remapping a Digit
// This code defines a solution to find the maximum difference by remapping a digit in a number.
// The goal is to replace one digit in the number with another digit to maximize the difference between the new number and the original number.

class Solution {
public:
    // Returns the maximum difference by remapping a digit in num
    int minMaxDifference(int num) {
        const string s = to_string(num);
        // Find the first digit that is not '9' to maximize the number
        const char to9 = s[firstNotNineIndex(s)];
        // The first digit is used to minimize the number
        const char to0 = s[0];
        // Return the difference between the max and min possible numbers
        return getMax(s, to9) - getMin(s, to0);
    }

private:
    // Returns the index of the first digit that is not '9'
    int firstNotNineIndex(const string& s) {
        for (int i = 0; i < s.length(); ++i)
            if (s[i] != '9')
                return i;
        return 0; // If all digits are '9', return 0
    }

    // Replaces all occurrences of 'to9' with '9' to get the maximum number
    int getMax(string s, char to9) {
        for (char& c : s)
            if (c == to9)
                c = '9';
        return stoi(s);
    }

    // Replaces all occurrences of 'to0' with '0' to get the minimum number
    int getMin(string s, char to0) {
        for (char& c : s)
            if (c == to0)
                c = '0';
        return stoi(s);
    }
};
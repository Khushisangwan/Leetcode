#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool doesAliceWin(string s) {
        // Check each character in the string
        for (int i = 0; i < s.size(); i++)
            // Check if current character is a vowel using bit manipulation
            // 0x104111 is a bitmask where bits are set for vowel positions
            // s[i] - 97 converts character to position (a=0, b=1, etc.)
            // If the bit at that position is 1, it's a vowel
            if ((0x104111 >> (s[i] - 97)) & 1)
                return 1; // Alice wins if any vowel is found
        
        // No vowels found, Alice loses
        return 0;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a string is a valid word
// Approach: A valid word must contain at least one vowel and one consonant, and can only consist of alphabetic characters or digits.

// Steps:
// 1. Check if the string length is less than 3, return false if it is.
// 2. Count the number of vowels and consonants in the string.
// 3. If there is at least one vowel and one consonant, return true;
//    Otherwise, return false.
// Assumptions: Vowels are 'a', 'e', 'i', 'o', 'u' (case insensitive), and consonants are all other alphabetic characters.
// 4. If the string contains any character that is not a letter or digit, return false.
// 5. The function should handle both uppercase and lowercase letters.
// 6. Return false if the string contains any invalid characters (non-alphabetic and non-digit).

// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(1), since we are using a fixed amount of space for counting

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 3) return false;

        int vowels = 0, consonants = 0;
        string vowelList = "aeiouAEIOU";

        for (char c : s) {
            if (isalpha(c)) {
                if (vowelList.find(c) != string::npos) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false; // invalid character
            }
        }

        return vowels >= 1 && consonants >= 1;
    }
};
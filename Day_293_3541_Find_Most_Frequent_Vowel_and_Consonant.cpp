#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s) {
        // Initialize frequency array for 26 lowercase letters and max counters
        int freq[26], maxVowel = 0, maxConso = 0;
        
        // Iterate through each character in the string
        for (char c : s) {
            int i = c - 'a'; // Convert character to array index (0-25)
            freq[i]++; // Increment frequency count for this character
            
            // Check if current character is a vowel
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]); // Update max vowel frequency
            }
            else {
                maxConso = max(maxConso, freq[i]); // Update max consonant frequency
            }
        }
        
        // Return sum of highest vowel and consonant frequencies
        return maxVowel + maxConso;
    }
};
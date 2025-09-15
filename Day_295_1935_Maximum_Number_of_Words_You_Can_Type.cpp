#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        // Create a bitmask to represent broken letters
        unsigned mask = 0;
        for(char c: brokenLetters)
            mask |= (1 << (c - 'a')); // Set bit for each broken letter
        
        int cnt = 0;        // Count of typeable words
        bool word = 1;      // Flag to track if current word is typeable
        text.push_back(' '); // Add space at end to process last word
        
        for(char c: text){
            if (c == ' '){
                cnt += word;    // Add to count if word is typeable
                word = 1;       // Reset flag for next word
            }
            else if (mask & (1 << (c - 'a'))) 
                word = 0;       // Mark word as untypeable if broken letter found
        }
        return cnt;
    }
};
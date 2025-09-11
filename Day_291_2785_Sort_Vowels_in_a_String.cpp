#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        // Vector to store all vowels found in the string
        vector<char> vowels;
        
        // First pass: extract all vowels from the string
        for(char c: s){
            if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                vowels.push_back(c);
            }
        }
        
        // Sort the vowels in ascending order
        sort(vowels.begin(), vowels.end());
        
        // Initialize pointers for string traversal and vowel replacement
        int i = 0, j= 0;
        
        // Second pass: replace vowels in original string with sorted vowels
        while(i<s.size() && j<vowels.size()){
            // If current character is a vowel, replace it with next sorted vowel
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = vowels[j];
                j++; // Move to next sorted vowel
            }
            i++; // Move to next character in string
        }
        
        return s;
    }
};
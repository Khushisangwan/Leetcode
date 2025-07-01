#include<bits/stdc++.h>
using namespace std;
// Problem - Find the Original Typed String I
// Approach - Count the number of characters that are different from their previous character

class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int count=n;
        for(int i=1;i<n;i++){
            if(word[i] !=word[i-1]){
                count--;
            }
        }
        return count;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Find the largest 3-digit number with the same digit in a string
// Approach: Iterate through the string, count consecutive identical digits, and track the maximum digit found

// Steps:
// 1. Initialize a counter for consecutive identical digits and a variable to track the maximum digit.
// 2. Traverse the string character by character.
// 3. If the current character is the same as the previous one, increment the counter.
// 4. If it differs, reset the counter to 1.
// 5. If the counter reaches 3, compare the current digit with the maximum digit found so far.
// 6. After the loop, return the largest 3-digit number formed by the maximum digit found, or an empty string if none found.

// Time Complexity: O(n) — where n is the length of the string, as we traverse it once.
// Space Complexity: O(1) — uses only a constant amount of extra memory.

class Solution {
public:
    string largestGoodInteger(string& num) {
        int count=0;
        char prev='X', maxd=' ';
        for(char c: num){
            if (c==prev) count++;
            else count=1;
            if (count==3)
                maxd=max(maxd, c);
            prev=c;
        }
        return (maxd==' ')?"":string(3, maxd);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
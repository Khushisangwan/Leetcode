#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Array to store frequency of each number (0-100)
        uint8_t freq[101] = {0};
        // Track maximum frequency and result sum
        uint8_t max = 0, res = 0;
        
        for (int n : nums) {
            // Increment frequency and get new count
            uint8_t f = ++freq[n];
            
            // If new maximum frequency found
            if (f > max) {
                max = f;
                res = f; // Reset result to this frequency
            } 
            // If frequency equals current maximum
            else if (f == max)
                res += f; // Add to result
        }
        return res;
    }
};

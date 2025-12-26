#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int bestTime = 0;           // Hour when shop should close for minimum penalty
        int minPenalty = 0;         // Minimum penalty found so far
        int prefix = 0;             // Running penalty sum
        
        // Iterate through each customer time slot
        for (int i = 0; i < customers.length(); i++) {
            // Add -1 for 'Y' (dissatisfied if open), +1 for 'N' (dissatisfied if closed)
            prefix += customers[i] == 'Y' ? -1 : 1;
            
            // Update best closing time if we find a lower penalty
            if (prefix < minPenalty) {
                bestTime = i + 1;
                minPenalty = prefix;
            }
        }
        
        return bestTime;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& christmasJoy, int gifts) {
        // Sort children by happiness in descending order to prioritize happiest first
        sort(christmasJoy.begin(), christmasJoy.end(), greater<int>());
        
        long long totalJoy = 0;
        
        // Iterate through each gift to distribute
        for (int turn = 0; turn < gifts; ++turn) {
            // Calculate joy for current child, decremented by turn (happiness decreases each turn)
            int currentJoy = christmasJoy[turn] - turn;
            
            // Stop if joy becomes non-positive
            if (currentJoy <= 0)
                break;
            
            // Add the joy to total
            totalJoy += currentJoy;
        }
        
        return totalJoy;
    }
};
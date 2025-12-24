#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        // Calculate total number of apples to distribute
        int sum = accumulate(apple.begin(), apple.end(), 0);
        
        // Frequency array to count boxes of each capacity
        uint8_t fq[51] = {};
        int high = 0, low = 51;
        
        // Count frequency of each capacity and find min/max
        for (auto& c : cap) {
            fq[c]++;
            high = max(high, c);
            low = min(low, c);
        }

        int res = 0;
        // Greedily use boxes with largest capacity first
        for (int i = high; i >= low && sum > 0; i--) {
            // Use all boxes of capacity i until no apples remain
            while (fq[i]-- > 0 && sum > 0) {
                sum -= i;
                res++;
            }
        }

        return res;
    }
};

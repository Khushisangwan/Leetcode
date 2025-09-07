#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        // Add pairs of positive and negative numbers that cancel out
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        // If n is odd, add 0 to complete the array
        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};
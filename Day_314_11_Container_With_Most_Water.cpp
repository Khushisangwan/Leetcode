#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& h){
        int n = h.size();
        int i = 0, j = n - 1;  // Two pointers at start and end
        int ans = 0;
        
        while(i < j){
            // Calculate area with current pointers
            int x = min(h[i], h[j]);  // Height is limited by shorter line
            ans = max(ans, x * (j - i));  // Width is distance between pointers
            
            // Move pointer with smaller height inward
            if(h[i] > h[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Helper function to find the largest rectangle in histogram
    int RectangleArea(vector<int> h) {
        int n = h.size();
        vector<int> r_s(n);  // Right smaller index for each element
        vector<int> l_s(n);  // Left smaller index for each element
        stack<int> st;
        
        // Find right smaller element for each index
        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] > h[i]){
                r_s[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // For remaining elements, right boundary is end of array
        while(!st.empty()){
            r_s[st.top()] = n;
            st.pop();
        }
        
        // Find left smaller element for each index
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && h[st.top()] > h[i]){
                l_s[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // For remaining elements, left boundary is start of array
        while(!st.empty()){
            l_s[st.top()] = -1;
            st.pop();
        }
        
        // Calculate maximum area
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, h[i] * (r_s[i] - l_s[i] - 1));
        }
        return ans;
    }
    
    // Main function to find maximal rectangle in matrix
    int maximalRectangle(vector<vector<char>>& m) {
        int r = m.size();
        int c = m[0].size();
        int ans = 0;
        vector<int> h(c, 0);  // Height array for histogram
        
        // Process each row
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // Update height: reset if '0', increment if '1'
                if(m[i][j] == '0')
                    h[j] = 0;
                else
                    h[j]++;
            }
            // Find largest rectangle in current histogram
            ans = max(ans, RectangleArea(h));
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to find the largest lucky integer in the array
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map; // Map to store frequency of each number
        int ans = -1; // Initialize answer to -1 (if no lucky integer found)

        // Count the frequency of each number in the array
        for(int i: arr){
            map[i]++;
        }

        // Check for lucky integers
        for(int i: arr){
            // A lucky integer is one whose value is equal to its frequency
            if(i == map[i]){
                if(i > ans) 
                    ans = i; // Update answer if current lucky integer is greater
            }
        }

        return ans; // Return the largest lucky integer, or -1 if none found
    }
};
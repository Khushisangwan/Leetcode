#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& sides) {
        // Sort the array to use two-pointer technique
        sort(sides.begin(), sides.end());
        int n = sides.size();
        int totalTriangles = 0;

        // Iterate from the largest element as the longest side
        for (int longest = n - 1; longest >= 2; --longest) {
            int left = 0, right = longest - 1;
            
            // Use two pointers to find valid triangles
            while (left < right) {
                // Check triangle inequality: sum of two smaller sides > longest side
                if (sides[left] + sides[right] > sides[longest]) {
                    // All pairs from left to right-1 with right will form valid triangles
                    totalTriangles += (right - left);
                    right--;
                } else {
                    // Need larger sum, so move left pointer
                    left++;
                }
            }
        }

        return totalTriangles;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosest(int x, int y, int z) {
        // Calculate absolute distances from z to both x and y
        int distanceToX = abs(x - z);
        int distanceToY = abs(y - z);
        
        // If distances are equal, return 0 (tie)
        // If x is closer, return 1 (index of x)
        // If y is closer, return 2 (index of y)
        return distanceToX == distanceToY ? 0 : (distanceToX < distanceToY ? 1 : 2);
    }
};